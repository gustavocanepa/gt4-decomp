#!/usr/bin/env python3
"""Judge many source variants of one function in parallel and rank them.

A variant is a list of text replacements applied to a base source. Write them in a spec file:

    ## name of the variant              (a line starting with ##: a new variant)
    <<<                                 (the text to replace, exactly as in the base, any lines)
        Vec a = f();
    ===                                 (its replacement)
        Vec a;
        a = f();
    >>>
    ... more <<< === >>> blocks for the same variant ...

Every variant is written to OUT/NAME.cpp (or .c, like the base) and judged with match.py check,
JOBS at a time (default 8). The table is sorted by differing instructions, then by the calls whose
stack-slot signature differs (tools/slotsig.py), then by `shape` (differing instructions once
register names are masked: schedule and code shape without the allocation) and the first such
call; `1st ins` is the first differing instruction. On a large C++ function the slot calls go to 0
first (temporaries in the right slots), then shape, then the registers.

    variants.py ADDR BASE SPEC [--out DIR] [--jobs 8] [--keep]
    variants.py ADDR BASE --just FILE...     judge existing files (no spec) and rank them

The base itself is judged too (the `(base)` row). A replacement missing from the base is reported
and the variant skipped. With --keep the .diff of each run is saved beside its source.
"""
import argparse
import difflib
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import slotsig  # noqa: E402

ROOT = slotsig.ROOT


def parse_spec(text):
    variants, name, reps = [], None, []
    lines = text.split("\n")
    i = 0
    while i < len(lines):
        line = lines[i]
        if line.startswith("##"):
            if name is not None:
                variants.append((name, reps))
            name, reps = line[2:].strip() or f"v{len(variants)}", []
        elif line.strip() == "<<<":
            j = lines.index("===", i + 1)
            k = lines.index(">>>", j + 1)
            reps.append(("\n".join(lines[i + 1:j]), "\n".join(lines[j + 1:k])))
            i = k
        i += 1
    if name is not None:
        variants.append((name, reps))
    return variants


def slug(name):
    return re.sub(r"[^A-Za-z0-9_.-]+", "_", name).strip("_")[:60] or "v"


MASK = re.compile(r"\$(?:[atvsk][0-9]|fp|ra|at|gp|f[0-9]+)\b")


def shape(text):
    """(first differing instruction, instructions outside the longest alignment of the two sides
    once register names are masked: code shape and schedule without the allocation)."""
    orig, mine = slotsig.split_sides(text)
    first = next((i for i, (a, b) in enumerate(zip(orig, mine)) if a != b), None)
    a = [MASK.sub("R", x) for x in orig]
    b = [MASK.sub("R", x) for x in mine]
    same = sum(blk.size for blk in difflib.SequenceMatcher(None, a, b, autojunk=False).get_matching_blocks())
    return first, max(len(a), len(b)) - same


def judge(addr, path):
    text = slotsig.judge(addr, path)
    head = text.split("\n", 1)[0]
    if "MATCH" in head and "differ" not in head:
        return text, 0, 0, None, "MATCH", None, 0
    m = re.search(r"(\d+) of (\d+) instructions differ", head)
    if not m:
        return text, None, None, None, (text.strip().split("\n") or ["?"])[-1][:100], None, None
    res = slotsig.compare(text) or {"differ": None, "first": None}
    first_ins, masked = shape(text)
    return text, int(m.group(1)), res["differ"], res["first"], head, first_ins, masked


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("addr")
    ap.add_argument("base")
    ap.add_argument("spec", nargs="?")
    ap.add_argument("--just", nargs="*", help="judge these files instead of a spec")
    ap.add_argument("--out", help="directory for the variants (default: BASE's directory/variants)")
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--keep", action="store_true", help="save each judge output as NAME.diff")
    a = ap.parse_args()

    base_text = open(a.base).read()
    ext = os.path.splitext(a.base)[1] or ".cpp"
    out = a.out or os.path.join(os.path.dirname(os.path.abspath(a.base)), "variants")
    os.makedirs(out, exist_ok=True)
    todo = [("(base)", a.base)]
    if a.just:
        todo += [(os.path.basename(f), f) for f in a.just]
    elif a.spec:
        for name, reps in parse_spec(open(a.spec).read()):
            text, missing = base_text, None
            for old, new in reps:
                if old not in text:
                    missing = old.strip().split("\n")[0][:70]
                    break
                text = text.replace(old, new)
            if missing is not None:
                print(f"skip {name}: not in the base: {missing!r}")
                continue
            path = os.path.join(out, slug(name) + ext)
            open(path, "w").write(text)
            todo.append((name, path))

    with ThreadPoolExecutor(max_workers=a.jobs) as ex:
        results = list(ex.map(lambda t: (t[0], t[1]) + judge(a.addr, t[1]), todo))

    def key(r):
        return (r[3] is None, r[4] if r[4] is not None else 1 << 30, r[8] if r[8] is not None else 1 << 30,
                r[3] or 0, -(r[7] or 0))
    print(f"{'variant':40} {'instr':>6} {'calls':>6} {'first':>6} {'shape':>6} {'1st ins':>7}")
    for name, path, text, ninstr, ncalls, first, head, first_ins, masked in sorted(results, key=key):
        if a.keep:
            open(os.path.splitext(path)[0] + ".diff" if path != a.base else path + ".diff", "w").write(text)
        if ninstr is None:
            print(f"{name[:40]:40} {'-':>6} {'-':>6} {'-':>6}  {head}")
        else:
            print(f"{name[:40]:40} {ninstr:6} {ncalls if ncalls is not None else '-':>6} "
                  f"{first if first is not None else '-':>6} {masked if masked is not None else '-':>6} "
                  f"{first_ins if first_ins is not None else '-':>7}{'  MATCH' if head == 'MATCH' else ''}")


if __name__ == "__main__":
    main()
