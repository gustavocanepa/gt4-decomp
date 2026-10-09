#!/usr/bin/env python3
"""Put the sources in order: real names in the code, files by subsystem and translation unit.

    organize.py            rename and move every source that is not where tools/layout.py puts it
    organize.py --check    only report what would change (exit 1 if anything)
    organize.py --names    rename symbols only, leave the files where they are

Names: every func_ADDR / D_ADDR token (definitions, declarations, comments; never string
literals) becomes the address's canonical name (tools/symbols.py: the script-engine method name,
else the RTTI name) when there is one. The judge and the build resolve both spellings, so a
renamed source matches exactly as before; tools/build.py is the proof after a run (it recompiles
every changed source and compares the image).

Files: src/<subsystem>/<unit>/<Name>.<ext> (tools/layout.py). New matches written flat as
src/func_ADDR.* by the solving tools are picked up by the next run, so this is safe to repeat.
"""
import os
import sys

import layout
import project
import symbols

ROOT = project.ROOT


def plan():
    """[(address, current path, planned path, old text, new text)] for every source."""
    out = []
    for addr, path in sorted(project.sources(refresh=True).items()):
        ext = os.path.splitext(path)[1]
        planned = os.path.join(ROOT, layout.path_for(addr, ext).replace("/", os.sep))
        text = open(path, encoding="utf-8", errors="surrogateescape").read()
        # Back to the generic names first, so a name that changed in the configs is replaced too.
        new = symbols.rename_text(symbols.generic_text(text))
        out.append((addr, path, planned, text, new))
    return out


def prune(root):
    """Remove the directories left empty under root."""
    for dirpath, dirs, files in os.walk(root, topdown=False):
        if dirpath != root and not dirs and not files:
            try:
                os.rmdir(dirpath)
            except OSError:
                pass


def main():
    check = "--check" in sys.argv
    names_only = "--names" in sys.argv
    renamed, moved = 0, 0
    for addr, path, planned, text, new in plan():
        if new != text:
            renamed += 1
            if check:
                print(f"rename symbols in {os.path.relpath(path, ROOT)}")
        if os.path.normcase(path) != os.path.normcase(planned) and not names_only:
            moved += 1
            if check:
                print(f"move {os.path.relpath(path, ROOT)} -> {os.path.relpath(planned, ROOT)}")
        if check:
            continue
        if new != text:
            open(path, "w", encoding="utf-8", errors="surrogateescape", newline="\n").write(new)
        if os.path.normcase(path) != os.path.normcase(planned) and not names_only:
            if os.path.exists(planned):
                sys.exit(f"{planned} exists already (two sources for 0x{addr:08x}?)")
            os.makedirs(os.path.dirname(planned), exist_ok=True)
            os.replace(path, planned)
    if not check:
        prune(project.SRC)
    total = len(project.sources(refresh=True))
    named = sum(1 for a in project.sources() if symbols.name_of(a))
    print(f"{total} sources, {named} with a real name; {renamed} renamed inside, {moved} moved")
    sys.exit(1 if check and (renamed or moved) else 0)


if __name__ == "__main__":
    main()
