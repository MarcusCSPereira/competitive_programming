#!/usr/bin/env python3
"""Bloqueia o processamento até confirmar Drive remoto -> snapshot local.

O agente coleta os metadados pelo conector autenticado; este script não guarda
credenciais nem simula uma consulta remota. Veja sincronizacao.md.
"""
import argparse
from datetime import datetime, timedelta, timezone
import fcntl
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import uuid

ROOT = Path(__file__).resolve().parents[1]
MAX_AGE = 300


class SyncError(ValueError):
    pass


def now():
    return datetime.now(timezone.utc)


def parse_time(value):
    result = datetime.fromisoformat(value.replace("Z", "+00:00"))
    if result.tzinfo is None:
        raise SyncError("Timestamp sem fuso horário")
    return result


def fresh(value, reference=None):
    age = ((reference or now()) - parse_time(value)).total_seconds()
    if age < -5 or age > MAX_AGE:
        raise SyncError("Evidência remota ausente, futura ou expirada; consulte o Drive novamente")


def load(path):
    return json.loads(Path(path).read_text())


def atomic(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, tmp = tempfile.mkstemp(prefix="." + path.name, dir=path.parent)
    try:
        with os.fdopen(fd, "w") as stream:
            json.dump(value, stream, ensure_ascii=False, indent=2)
            stream.write("\n")
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(tmp, path)
    finally:
        Path(tmp).unlink(missing_ok=True)


def remote_rows(evidence, config):
    fresh(evidence["fetched_at"])
    if evidence.get("account") != config["account"]:
        raise SyncError("Conta remota diferente da conta configurada")
    if evidence.get("folder_id") != config["drive_folder_id"]:
        raise SyncError("Pasta remota diferente da pasta configurada")
    rows = {}
    names = set()
    for raw in evidence["files"]:
        key = raw["id"]
        name = raw.get("name", raw.get("title"))
        if key in rows or name in names:
            raise SyncError("Itens duplicados na evidência remota")
        names.add(name)
        parents = raw.get("parents", raw.get("parent_ids", []))
        if config["drive_folder_id"] not in parents:
            raise SyncError("Arquivo fora da pasta de origem")
        row = {"id": key, "name": name, "size": int(raw["size"]),
               "modified_time": raw.get("modifiedTime", raw.get("modified_time", raw.get("updated_at"))),
               "mime_type": raw.get("mimeType", raw.get("mime_type")),
               "md5": raw.get("md5Checksum"), "sha256": raw.get("sha256Checksum")}
        if raw.get("trashed") or row["mime_type"] != "application/pdf":
            raise SyncError("Origem não é um PDF ativo")
        parse_time(row["modified_time"])
        rows[key] = row
    for notebook in config["notebooks"].values():
        row = rows.get(notebook["drive_file_id"])
        if not row or row["name"] != notebook["file_name"]:
            raise SyncError("Arquivo esperado ausente ou renomeado; reconciliar identidade")
    return rows


def compare_local(row, probe):
    if row["size"] != probe["size"]:
        raise SyncError("Drive local ainda não tem o tamanho da versão remota")
    remote_ns = int(parse_time(row["modified_time"]).timestamp() * 1_000_000_000)
    if abs(remote_ns - probe["mtime_ns"]) > 2_000_000:
        raise SyncError("Data da cópia local diverge da versão remota")
    if row.get("md5") and row["md5"] != probe["md5"]:
        raise SyncError("Checksum MD5 remoto e local divergem")
    if row.get("sha256") and row["sha256"] != probe["sha256"]:
        raise SyncError("Checksum SHA-256 remoto e local divergem")


def copy_probe(source, cache):
    """Executada em subprocesso com timeout: leitura pode materializar File Provider."""
    source, cache = Path(source), Path(cache)
    before = source.stat()
    cache.mkdir(parents=True, exist_ok=True)
    fd, tmp = tempfile.mkstemp(prefix="reading-", suffix=".pdf", dir=cache)
    sha, md5 = hashlib.sha256(), hashlib.md5()
    try:
        with source.open("rb") as inp, os.fdopen(fd, "wb") as out:
            first = inp.read(1024 * 1024)
            if not first.startswith(b"%PDF-"):
                raise SyncError("Arquivo sem assinatura PDF")
            chunk = first
            while chunk:
                sha.update(chunk)
                md5.update(chunk)
                out.write(chunk)
                chunk = inp.read(1024 * 1024)
            out.flush()
            os.fsync(out.fileno())
        after = source.stat()
        if (before.st_size, before.st_mtime_ns, before.st_ino) != (after.st_size, after.st_mtime_ns, after.st_ino):
            raise SyncError("Arquivo mudou durante a leitura")
        with Path(tmp).open("rb") as check:
            check.seek(max(0, after.st_size - 2048))
            if b"%%EOF" not in check.read():
                raise SyncError("PDF incompleto, sem marcador final")
        info = subprocess.run(["pdfinfo", tmp], check=True, capture_output=True, text=True, timeout=20)
        count = next(int(line.split(":", 1)[1]) for line in info.stdout.splitlines() if line.startswith("Pages:"))
        destination = cache / (sha.hexdigest() + ".pdf")
        os.replace(tmp, destination)
        return {"source": str(source), "snapshot": str(destination), "size": after.st_size,
                "mtime_ns": after.st_mtime_ns, "page_count": count,
                "sha256": sha.hexdigest(), "md5": md5.hexdigest()}
    finally:
        Path(tmp).unlink(missing_ok=True)


def assert_same_remote(before, after):
    if before != after:
        raise SyncError("Versão remota mudou durante a verificação; repetir a sincronização")


def run(args):
    previous = load(args.status) if Path(args.status).exists() else {}
    report = {"schema_version": 1, "checked_at": now().isoformat(),
              "status": "checking", "generation_allowed": False}
    atomic(args.status, report)  # Invalida autorização anterior antes de tentar.
    if args.mode == "prepare":
        Path(args.candidate).unlink(missing_ok=True)
    try:
        config = load(args.config)
        evidence = load(args.remote)
        rows = remote_rows(evidence, config)
        if args.mode == "prepare":
            candidate = {"run_id": str(uuid.uuid4()), "account": config["account"],
                         "before_at": evidence["fetched_at"], "remote": rows, "files": {}}
            for key, notebook in config["notebooks"].items():
                command = [sys.executable, str(Path(__file__).resolve()), "probe",
                           "--source", notebook["local_path"], "--cache", str(ROOT / ".cache/sync/snapshots")]
                worker = subprocess.run(command, capture_output=True, text=True, check=True, timeout=45)
                probe = json.loads(worker.stdout)
                compare_local(rows[notebook["drive_file_id"]], probe)
                candidate["files"][key] = probe
            candidate["finished_at"] = now().isoformat()
            atomic(args.candidate, candidate)
            report.update(status="awaiting_remote_recheck", candidate=args.candidate, run_id=candidate["run_id"])
        else:
            candidate = load(args.candidate)
            if previous.get("status") != "awaiting_remote_recheck" or previous.get("run_id") != candidate["run_id"]:
                raise SyncError("Sem preparação pendente desta execução; executar prepare novamente")
            fresh(candidate["before_at"])
            if candidate["account"] != config["account"]:
                raise SyncError("Conta do snapshot diverge da configuração")
            if parse_time(evidence["fetched_at"]) < parse_time(candidate["finished_at"]):
                raise SyncError("A segunda consulta remota precisa ocorrer depois da leitura local")
            assert_same_remote(candidate["remote"], rows)
            if set(candidate["files"]) != set(config["notebooks"]):
                raise SyncError("Conjunto de fontes mudou; repetir preparação")
            for key, probe in candidate["files"].items():
                notebook = config["notebooks"][key]
                if probe["source"] != notebook["local_path"]:
                    raise SyncError("Caminho da fonte mudou; repetir preparação")
                current = Path(probe["source"]).stat()
                if (current.st_size, current.st_mtime_ns) != (probe["size"], probe["mtime_ns"]):
                    raise SyncError("Cópia local mudou após a preparação")
                if hashlib.sha256(Path(probe["snapshot"]).read_bytes()).hexdigest() != probe["sha256"]:
                    raise SyncError("Snapshot local alterado")
                compare_local(rows[notebook["drive_file_id"]], probe)
            report.update(status="verified", generation_allowed=True, run_id=candidate["run_id"],
                          valid_until=(now() + timedelta(seconds=MAX_AGE)).isoformat(),
                          files=candidate["files"], remote=rows,
                          verification="fresh_remote_size_mtime_and_stable_local_snapshot",
                          remote_checksum_available=all(r["md5"] or r["sha256"] for r in rows.values()))
        atomic(args.status, report)
        print(json.dumps(report, ensure_ascii=False, indent=2))
    except (OSError, ValueError, KeyError, StopIteration, subprocess.SubprocessError) as exc:
        report.update(status="blocked", generation_allowed=False, error=str(exc))
        atomic(args.status, report)
        print(json.dumps(report, ensure_ascii=False), file=sys.stderr)
        raise SystemExit(2)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("mode", choices=["prepare", "confirm", "probe"])
    parser.add_argument("--remote")
    parser.add_argument("--candidate", default=str(ROOT / ".cache/sync/candidate.json"))
    parser.add_argument("--config", default=str(ROOT / "estado/fontes.json"))
    parser.add_argument("--status", default=str(ROOT / "estado/sincronizacao.json"))
    parser.add_argument("--source")
    parser.add_argument("--cache")
    args = parser.parse_args()
    if args.mode == "probe":
        print(json.dumps(copy_probe(args.source, args.cache)))
        return
    lock_path = Path(args.status).with_suffix(".lock")
    lock_path.parent.mkdir(parents=True, exist_ok=True)
    with lock_path.open("a") as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        run(args)


if __name__ == "__main__":
    main()
