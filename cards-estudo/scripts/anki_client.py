#!/usr/bin/env python3
"""Cliente local do AnkiConnect v1. Não inicia nem reinicia o Anki.

Exemplos (na raiz do repositório C++):
  python3 cards-estudo/scripts/anki_client.py status
  python3 cards-estudo/scripts/anki_client.py call decks.list
  python3 cards-estudo/scripts/anki_client.py call notes.validate --params-file arquivo.json
  python3 cards-estudo/scripts/anki_client.py sync
"""
import argparse
import json
import os
from pathlib import Path
import sys
import time
import urllib.error
import urllib.request

ENDPOINT = "http://127.0.0.1:8765/api/v1"


class AnkiError(RuntimeError):
    pass


class AnkiClient:
    def __init__(self):
        self.transport = urllib.request.build_opener(urllib.request.ProxyHandler({}))
        self.sequence = 0

    def call(self, method, params=None):
        self.sequence += 1
        body = {"jsonrpc": "2.0", "id": self.sequence, "method": method, "params": params or {}}
        headers = {"Content-Type": "application/json"}
        if os.environ.get("ANKICONNECT_API_KEY"):
            headers["Authorization"] = "Bearer " + os.environ["ANKICONNECT_API_KEY"]
        request = urllib.request.Request(ENDPOINT, data=json.dumps(body, ensure_ascii=False).encode(), headers=headers)
        try:
            with self.transport.open(request, timeout=15) as response:
                result = json.load(response)
        except urllib.error.URLError as exc:
            raise AnkiError("AnkiConnect indisponível. Verifique se o Anki está aberto e o complemento ativo.") from exc
        if result.get("id") != self.sequence or result.get("jsonrpc") != "2.0":
            raise AnkiError("Resposta inválida do AnkiConnect")
        if "error" in result:
            raise AnkiError(json.dumps(result["error"], ensure_ascii=False))
        return result["result"]

    def wait(self, handle, timeout=45):
        deadline = time.monotonic() + timeout
        while time.monotonic() < deadline:
            result = self.call("operations.get", {"operationId": handle["operationId"]})
            if result["state"] == "succeeded":
                return result.get("result")
            if result["state"] in {"failed", "cancelled", "waitingForUser"}:
                raise AnkiError(json.dumps(result, ensure_ascii=False))
            time.sleep(0.5)
        raise AnkiError("Operação ainda em andamento: " + handle["operationId"] + ". Consulte operations.get antes de repetir.")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("command", choices=["status", "call", "sync"])
    parser.add_argument("method", nargs="?")
    parser.add_argument("--params-file", type=Path)
    args = parser.parse_args()
    client = AnkiClient()
    try:
        if args.command == "status":
            description = client.call("api.describe")
            result = {"endpoint": ENDPOINT, "api_major": description["apiMajor"],
                      "anki_version": description["ankiVersion"],
                      "profile": client.call("profiles.getActive"),
                      "decks": client.call("decks.list")}
        elif args.command == "sync":
            result = client.wait(client.call("collection.sync"))
        else:
            if not args.method:
                parser.error("call exige o método da API")
            params = json.loads(args.params_file.read_text()) if args.params_file else {}
            result = client.call(args.method, params)
        print(json.dumps(result, ensure_ascii=False, indent=2))
    except (AnkiError, OSError, ValueError, KeyError) as exc:
        print(str(exc), file=sys.stderr)
        raise SystemExit(2)


if __name__ == "__main__":
    main()
