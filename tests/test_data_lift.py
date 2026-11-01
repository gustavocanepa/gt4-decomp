"""data/ sources: the first-line address convention build.py reads, and the typing helpers of
tools/data_lift.py and tools/bss_lift.py (strings, float literals, gaps)."""
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import build
import bss_lift
import data_lift


class DataSourceTests(unittest.TestCase):
    def test_data_at_first_line_gives_the_address(self):
        # inside the repository (relpath across drives fails on Windows); build/ is not versioned,
        # so a fresh checkout (CI) has to create it
        scratch = Path(build.ROOT) / "build"
        scratch.mkdir(exist_ok=True)
        with tempfile.TemporaryDirectory(dir=scratch) as d:
            root = Path(d)
            (root / "a").mkdir()
            (root / "a" / "D_00620FA0.c").write_text('/* data-at: 0x00620FA0 */\nchar D_00620FA0[] = "x";\n')
            (root / "a" / "D_BAD.c").write_text("char D_BAD[1];\n")
            with patch.object(build, "DATA_DIR", str(root)):
                found, problems = build.data_sources()
        self.assertEqual(list(found), [0x00620FA0])
        self.assertEqual(len(problems), 1)

    def test_c_string_escapes(self):
        raw = b"a" + bytes([34]) + b"b" + bytes([92]) + b"c" + bytes([10, 1])
        want = "a" + chr(92) + chr(34) + "b" + chr(92) * 2 + "c" + chr(92) + "n" + chr(92) + "001"
        self.assertEqual(data_lift.c_string(raw), want)

    def test_strings_need_text_and_a_terminator(self):
        blob = b"" + bytes([0]) + b"Hello world" + bytes([0, 1, 2, 3, 4, 0]) + b"ab" + bytes([0])
        self.assertEqual(data_lift.find_strings(blob, 0x1000), [(0x1001, b"Hello world")])

    def test_free_gaps(self):
        self.assertEqual(data_lift.free_gaps(0x100, 0x100, [(0x120, 0x140), (0x130, 0x150)]),
                         [(0x100, 0x120), (0x150, 0x200)])

    def test_float_literal_biases_away_from_zero(self):
        w = struct.unpack("<I", struct.pack("<f", 0.15))[0]
        self.assertTrue(data_lift.float_literal(w).endswith("f"))
        self.assertGreater(float(data_lift.float_literal(w, 17, 0.3)[:-1]), float(data_lift.float_literal(w, 17)[:-1]))

    def test_zero_runs_split_and_trim(self):
        db = bytes([0, 0, 1, 2]) + bytes(40) + bytes([3, 0])
        self.assertEqual(data_lift.split_zero_runs(db, 0x100, 0x100, 0x100 + len(db)),
                         [(0x102, 0x104), (0x12C, 0x12D)])

    def test_bss_type_follows_the_accesses(self):
        hits = {0x6D5E00: {(4, "f")}, 0x6D5E04: {(4, "f")}}
        self.assertEqual(bss_lift.from_accesses(0x6D5E00, 8, hits), "float D_006D5E00[2];")
        self.assertEqual(bss_lift.from_accesses(0x6D5E00, 4, hits), "float D_006D5E00;")
        self.assertIsNone(bss_lift.from_accesses(0x6D5E00, 8, {0x6D5E00: {(4, "i"), (2, "s")}}))


if __name__ == "__main__":
    unittest.main()
