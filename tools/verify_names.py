#!/usr/bin/env python3
"""Check that renaming lost nothing: for every source git tracks, the working copy read back
with generic names (tools/symbols.py generic_text) must equal the committed copy read the same
way. A difference means a real name stood for two addresses (or a source really changed).

    verify_names.py [--fix]     list the sources that differ; --fix restores them from HEAD at
                                their current path (tools/organize.py then renames them again)
"""
import os
import re
import subprocess
import sys

import project
import symbols

ROOT = project.ROOT


IDENT = re.compile(symbols.STRING + "|" + symbols.CHAR + r"|\b[A-Za-z_]\w*\b")


def normalized(text):
    """Every symbol the project knows written as @ADDR, whatever its spelling or kind."""
    def sub(m):
        addr = symbols.address_of(m.group(0)) if m.group(0)[0] not in "\"'" else None
        return f"@{addr:08X}" if addr is not None else m.group(0)
    return IDENT.sub(sub, text.replace("\r\n", "\n"))


def main():
    fix = "--fix" in sys.argv
    tracked = subprocess.run(["git", "ls-files", "src"], capture_output=True, text=True, cwd=ROOT).stdout.split()
    by_addr = {}
    for rel in tracked:
        addr = project.source_address(rel)
        if addr is not None:
            by_addr[addr] = rel
    current = project.sources(refresh=True)
    bad = 0
    for addr, rel in sorted(by_addr.items()):
        path = current.get(addr)
        if not path:
            print(f"{rel}: no source for 0x{addr:08x} any more")
            bad += 1
            continue
        head = subprocess.run(["git", "show", f"HEAD:{rel}"], capture_output=True, cwd=ROOT).stdout
        head = head.decode("utf-8", errors="surrogateescape")
        now = open(path, encoding="utf-8", errors="surrogateescape").read()
        if normalized(head) != normalized(now):
            bad += 1
            print(f"{os.path.relpath(path, ROOT)}: differs from HEAD:{rel} beyond names")
            if fix:
                open(path, "w", encoding="utf-8", errors="surrogateescape", newline="\n").write(head)
    print(f"{len(by_addr)} tracked sources checked, {bad} differ" + (" (restored)" if fix and bad else ""))
    sys.exit(1 if bad and not fix else 0)


if __name__ == "__main__":
    main()
