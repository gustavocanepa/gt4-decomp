#!/usr/bin/env python3
"""Write the Status numbers of README.md from progress/report.json and progress/report.meta.json
(tools/report.py), between the markers <!-- progress:start --> and <!-- progress:end -->, so no
number in the README is typed by hand. tools/publish_progress.py calls it; it can also run alone.

    update_readme.py [--check]      --check: exit 1 if the README is not what the report says
"""
import datetime
import json
import os
import sys

import match
import report

ROOT = match.ROOT
README = os.path.join(ROOT, "README.md")
START, END = "<!-- progress:start -->", "<!-- progress:end -->"


def render():
    data = json.load(open(report.OUT))
    meta = json.load(open(report.META))
    m = data["measures"]
    when = datetime.datetime.strptime(meta["generated"][:10], "%Y-%m-%d").strftime("%B %Y")
    commit = (meta.get("commit") or "")[:12]
    described = f", commit `{commit}`" if commit else ""
    matched_data, total_data = int(m["matched_data"]), int(m["total_data"])
    # tools/clean_report.py, stored by tools/report.py; a report made before it has no such line
    c = meta.get("clean")
    clean = (f"  Clean source: {c['clean_percent']:.1f}% of the {c['sources']:,} function sources are free of m2c\n"
             f"  macros, raw offset casts, temp_/var_ names and pasted headers (`tools/clean_report.py`).\n") if c else ""
    return (
        f"- **Progress ({when}{described}): {m['matched_functions']:,} of {m['total_functions']:,} functions match "
        f"({m['matched_functions_percent']:.1f}%), {m['matched_code_percent']:.1f}% of the code bytes"
        + (f"; {c['clean_percent']:.1f}% of the sources are clean" if c else "") + ".**\n"
        + clean +
        f"  The live numbers are on the `progress` branch (objdiff report format); this paragraph is written by\n"
        f"  `tools/update_readme.py` from `progress/report.json`, never by hand.\n"
        f"- **The full build reproduces the original executable** (both loaded segments, SHA-1 checked):\n"
        f"  {meta['linked_functions']:,} functions, {m['complete_code_percent']:.1f}% of the code bytes, are linked from C/C++\n"
        f"  source at their original addresses, and the rest is assembled from splat's disassembly of your own\n"
        f"  executable. {matched_data:,} of {total_data:,} data bytes ({m['matched_data_percent']:.2f}%; `.data` plus `.bss`)\n"
        f"  are the constants of {meta['data_functions']:,} functions, placed from source at their original addresses.\n"
        f"  {meta['asm_functions']} functions that were hand-written assembly in the original are listed in\n"
        f"  [`config/asm_functions.txt`](config/asm_functions.txt) and not counted.\n"
    )


def main():
    # The README states that the full build reproduces the original: only a report of such a
    # build may write it. A build that differs, or a slice, leaves the README as it is.
    meta = json.load(open(report.META))
    b = meta["build"]
    if not (b.get("text_matches") and b.get("data_matches")) or b.get("partial") \
            or b.get("orphan_sources") or b.get("duplicate_sources"):
        sys.exit("README.md not written: the build the report reads does not reproduce the original "
                 "(.text/.data), is a slice, or has orphan/duplicate sources; build again")
    text = open(README, encoding="utf-8").read()
    if START not in text or END not in text:
        sys.exit(f"{README}: markers {START} / {END} missing")
    head, rest = text.split(START, 1)
    _, tail = rest.split(END, 1)
    new = head + START + "\n" + render() + END + tail
    if "--check" in sys.argv:
        if new != text:
            sys.exit("README.md does not say what progress/report.json says: python tools/update_readme.py")
        print("README.md is current")
        return
    if new != text:
        open(README, "w", encoding="utf-8", newline="\n").write(new)
        print(f"README.md updated from {os.path.relpath(report.OUT, ROOT)}")
    else:
        print("README.md already current")


if __name__ == "__main__":
    main()
