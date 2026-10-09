#!/usr/bin/env python3
"""Make file-scope declarations of the game's globals (D_XXXXXXXX) extern.

`int D_0065AF28;` at file scope in C++ defines the variable, so the object gets its own copy in
.bss instead of referring to the game's; the full build cannot link it. The code generated for the
function is the same either way (-G0), so adding `extern` only fixes the link.

    fix_extern.py [FILE...]     default: every source in src/
"""
import glob
import os
import re
import sys

import match
import project

DECL = re.compile(r"^(?!\s*(?:extern|typedef|return)\b)(\s*)(?:static\s+)?([A-Za-z_][\w\s\*]*?\b(D_[0-9A-Fa-f]{8})\s*(?:\[[^\]]*\])*\s*;.*)$")


def fix(text):
    # Only top-level lines: track braces line by line.
    lines = text.split("\n")
    depth = 0
    for i, line in enumerate(lines):
        if depth == 0:
            m = DECL.match(line)
            if m and "(" not in line and "=" not in line:
                lines[i] = f"{m.group(1)}extern {m.group(2)}"
        depth += line.count("{") - line.count("}")
    return "\n".join(lines)


def main():
    files = sys.argv[1:] or sorted(project.sources(refresh=True).values())
    changed = 0
    for path in files:
        text = open(path, encoding="utf-8").read()
        new = fix(text)
        if new != text:
            open(path, "w", encoding="utf-8", newline="\n").write(new)
            changed += 1
    print(f"{changed} sources changed")


if __name__ == "__main__":
    main()
