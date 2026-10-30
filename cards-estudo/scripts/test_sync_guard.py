import copy
from contextlib import redirect_stderr, redirect_stdout
from datetime import datetime, timedelta, timezone
from io import StringIO
import json
from pathlib import Path
from types import SimpleNamespace
import tempfile
import unittest

from sync_guard import SyncError, assert_same_remote, compare_local, fresh, remote_rows, run


class SyncChecks(unittest.TestCase):
    def setUp(self):
        self.t = datetime.now(timezone.utc)
        self.config = {"account": "study@example.com", "drive_folder_id": "folder",
                       "notebooks": {"book": {"drive_file_id": "book-id", "file_name": "book.pdf"}}}
        self.evidence = {"account": "study@example.com", "folder_id": "folder", "fetched_at": self.t.isoformat(),
                         "files": [{"id": "book-id", "title": "book.pdf", "parent_ids": ["folder"],
                                    "size": "100", "modified_time": self.t.isoformat(), "mime_type": "application/pdf"}]}
        self.row = remote_rows(self.evidence, self.config)["book-id"]
        self.probe = {"size": 100, "mtime_ns": int(self.t.timestamp() * 1e9), "md5": "a", "sha256": "b"}

    def test_valid_copy(self):
        compare_local(self.row, self.probe)

    def test_same_size_but_old_version_is_blocked(self):
        self.probe["mtime_ns"] -= 10_000_000_000
        with self.assertRaises(SyncError): compare_local(self.row, self.probe)

    def test_truncated_copy_is_blocked(self):
        self.probe["size"] -= 1
        with self.assertRaises(SyncError): compare_local(self.row, self.probe)

    def test_wrong_checksum_is_blocked_when_available(self):
        self.row["md5"] = "different"
        with self.assertRaises(SyncError): compare_local(self.row, self.probe)

    def test_stale_remote_evidence_is_blocked(self):
        with self.assertRaises(SyncError): fresh((self.t - timedelta(minutes=6)).isoformat(), self.t)

    def test_wrong_account_is_blocked(self):
        self.evidence["account"] = "other@example.com"
        with self.assertRaises(SyncError): remote_rows(self.evidence, self.config)

    def test_duplicate_file_is_blocked(self):
        self.evidence["files"].append(copy.deepcopy(self.evidence["files"][0]))
        with self.assertRaises(SyncError): remote_rows(self.evidence, self.config)

    def test_remote_change_during_read_is_blocked(self):
        after = copy.deepcopy(self.row)
        after["modified_time"] = (self.t + timedelta(seconds=1)).isoformat()
        with self.assertRaises(SyncError): assert_same_remote(self.row, after)

    def run_in_temp(self, mode, evidence, candidate, status):
        with tempfile.TemporaryDirectory() as directory:
            base = Path(directory)
            values = {"config": self.config, "remote": evidence, "candidate": candidate, "status": status}
            paths = {key: str(base / (key + ".json")) for key in values}
            for key, value in values.items(): Path(paths[key]).write_text(json.dumps(value))
            args = SimpleNamespace(mode=mode, **paths)
            with redirect_stdout(StringIO()), redirect_stderr(StringIO()), self.assertRaises(SystemExit) as failure:
                run(args)
            self.assertEqual(failure.exception.code, 2)
            result = json.loads(Path(paths["status"]).read_text())
            self.assertEqual(result["status"], "blocked")
            self.assertFalse(result["generation_allowed"])
            return Path(paths["candidate"]).exists()

    def test_failed_prepare_revokes_old_success_and_candidate(self):
        self.evidence["account"] = "wrong@example.com"
        exists = self.run_in_temp("prepare", self.evidence, {"run_id": "old"},
                                  {"status": "verified", "generation_allowed": True})
        self.assertFalse(exists)

    def test_confirmation_cannot_reuse_consumed_candidate(self):
        self.run_in_temp("confirm", self.evidence, {"run_id": "old"},
                         {"status": "verified", "generation_allowed": True, "run_id": "old"})


if __name__ == "__main__": unittest.main()
