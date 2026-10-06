"""Loader for Gran Turismo 4's retail CORE.GT4 (see core2elf.py for the format)."""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from core2elf import drop_duplicates, unpack_core  # noqa: E402


def load(path):
    _, _, entry, sections = unpack_core(open(path, "rb").read())
    return entry, drop_duplicates(sections)
