#!/usr/bin/env python3
"""How much of src/ is clean source rather than m2c's raw output: a source is clean when it has
none of the marks below (comments and string literals are not looked at).

    m2c macros     uses a name of include/m2c_macros.h (M2C_FIELD, M2C_UNK, M2C_ERROR...) or
                   includes that header
    raw offsets    a byte-pointer cast plus an offset, ((char *)p + 0x10) / ((u8 *)p + 16)
    temp names     m2c's temp_xx / var_xx variable names
    pasted header  m2c's macro block or the sized-type typedefs pasted into the file instead of
                   #include "m2c_macros.h" / "types.h" (tools/cleanup.py headers)

    clean_report.py [--json] [--list MARK] [--by-dir]

tools/report.py stores summary() in progress/report.meta.json and tools/update_readme.py prints the
clean percentage next to the matched one.
"""
import json
import os
import re
import sys

import project

ROOT = project.ROOT
MARKS = ("m2c macros", "raw offsets", "temp names", "pasted header")
# (char *)p + 0x10, (u8 *)(p) - 4, (char *)a->b + 8; not (char *)(r + 1), which steps over a whole struct
RAW_OFFSET = re.compile(r"\(\s*(?:const\s+)?(?:char|s8|u8|signed char|unsigned char)\s*\*\s*\)\s*"
                        r"(?:\(\s*[A-Za-z_][\w.>-]*\s*\)|[A-Za-z_][\w.>-]*)\s*[-+]\s*(?:0x[0-9A-Fa-f]+|\d+)")
TEMP = re.compile(r"\b(?:temp|var)_[A-Za-z0-9_]+\b")
PASTED = ("This header contains macros emitted by m2c", "typedef signed char s8; typedef unsigned char u8;")
_names = []


def macro_names():
    if not _names:
        text = open(os.path.join(ROOT, "include", "m2c_macros.h"), encoding="utf-8").read()
        names = set(re.findall(r"^#define (\w+)", text, re.M)) | set(re.findall(r"^typedef [^;]*?(\w+);", text, re.M))
        _names.append(names - {"M2C_MACROS_H"})
    return _names[0]


def marks(text):
    """The set of MARKS a source text has."""
    import cleanup
    out = set()
    if any(p in text for p in PASTED):
        out.add("pasted header")
    code = cleanup.strip_comments(cleanup.M2C_BLOCK.sub("", text))
    if '#include "m2c_macros.h"' in text or set(re.findall(r"\b[A-Za-z_]\w*\b", code)) & macro_names():
        out.add("m2c macros")
    if RAW_OFFSET.search(code):
        out.add("raw offsets")
    if TEMP.search(code):
        out.add("temp names")
    return out


def scan():
    """{relative path: set of marks} of every function source."""
    out = {}
    for path in sorted(project.sources(refresh=True).values()):
        try:
            text = open(path, encoding="utf-8", errors="replace").read()
        except OSError:
            continue
        out[os.path.relpath(path, ROOT).replace("\\", "/")] = marks(text)
    return out


def summary(found=None):
    found = scan() if found is None else found
    total = len(found)
    clean = sum(1 for m in found.values() if not m)
    return {"sources": total, "clean": clean,
            "clean_percent": round(100.0 * clean / total, 2) if total else 0.0,
            "marks": {k: sum(1 for m in found.values() if k in m) for k in MARKS}}


def main():
    found = scan()
    s = summary(found)
    if "--json" in sys.argv:
        print(json.dumps(s, indent=1))
        return
    if "--list" in sys.argv:
        mark = sys.argv[sys.argv.index("--list") + 1]
        for path, m in found.items():
            if mark in m or mark == "clean" and not m:
                print(path)
        return
    print(f"clean: {s['clean']:,} of {s['sources']:,} sources ({s['clean_percent']:.1f}%)")
    for k in MARKS:
        n = s["marks"][k]
        print(f"  {k:<14} {n:>6,} ({100.0 * n / max(1, s['sources']):.1f}%)")
    if "--by-dir" in sys.argv:
        dirs = {}
        for path, m in found.items():
            d = "/".join(path.split("/")[:2])
            t = dirs.setdefault(d, [0, 0])
            t[0] += 1
            t[1] += not m
        for d, (n, c) in sorted(dirs.items(), key=lambda x: -x[1][0]):
            print(f"  {d:<40} {c:>6,} / {n:<6,} ({100.0 * c / n:.0f}%)")


if __name__ == "__main__":
    main()
