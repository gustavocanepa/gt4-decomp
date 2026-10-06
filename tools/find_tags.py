#!/usr/bin/env python3
"""List the CVS/RCS tags ($Id ... $) and toolchain strings left in a GT4 CORE.

These tags name original source files, revisions, dates and authors, which helps
split the executable into its original translation units.

Usage: find_tags.py CORE.GT4
"""
import re
import sys

from core2elf import unpack_core

TAG = re.compile(rb"\$(?:Id|Header|Revision|Date): [^$\x00\n]{3,200}\$")
TOOLCHAIN = re.compile(rb"Libgcc[\w]*|GNU C[^\x00]{0,40}|gcc2_compiled\.")


def main():
    _, _, _, sections = unpack_core(open(sys.argv[1], "rb").read())
    blob = b"".join(data for _, data in sections[1:])
    tags = sorted(set(TAG.findall(blob)))
    print(f"{len(tags)} CVS tags")
    for tag in tags:
        print("  " + tag.decode("latin-1"))
    print("toolchain strings:", sorted({m.decode("latin-1") for m in TOOLCHAIN.findall(blob)}))


if __name__ == "__main__":
    main()
