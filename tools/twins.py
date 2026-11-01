#!/usr/bin/env python3
"""Matched donors for unmatched functions whose code is shaped alike but not equal.

siblings.py needs a donor of the same length whose words differ only in immediates. Many unmatched
functions have a matched relative that differs in a few statements (an extra argument, one more
global, a different field): their opcode sequences still line up. This lists, for every unmatched
function of the work queue, the matched function with the most similar opcode sequence (registers
and immediates ignored), and the matched functions that call exactly the same callees in the same
order. Reading the donor's source and adapting it by hand matched 0054B4F8, 00525190, 0011E198 and
00562E90 on the first try (2026-10-31).

    twins.py [--min 0.8] [--max-size 1200]   opcode-similarity donors (difflib ratio >= --min)
    twins.py --calls                          donors with the same callee sequence (2+ calls)
"""
import argparse
import difflib
import json
import os
import sys
from collections import defaultdict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import match  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def functions():
    out = []
    with open(os.path.join(ROOT, "build", "functions.csv")) as f:
        next(f)
        for line in f:
            if line.strip():
                a, s, _ = line.split(",")
                out.append((int(a, 16), int(s)))
    return out


def opcode(w):
    op = w >> 26
    if op == 0:
        return ("S", w & 0x3F)
    if op == 0x1C:
        return ("M", w & 0x3F)
    if op in (0x11, 0x12):
        return (op, (w >> 21) & 0x1F, w & 0x3F)
    if op == 1:
        return ("R", (w >> 16) & 0x1F)
    return op


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min", type=float, default=0.8)
    ap.add_argument("--max-size", type=int, default=1200)
    ap.add_argument("--calls", action="store_true")
    args = ap.parse_args()
    text_addr, text = match.load_text()
    queue = {int(i["addr"], 16) for i in json.load(open(os.path.join(ROOT, "build", "queue.json")))}
    words = {}
    for a, s in functions():
        if s <= args.max_size:
            try:
                words[a] = match.trim_padding(match.words_at(text_addr, text, a, s))
            except Exception:
                pass
    if args.calls:
        donors = defaultdict(list)
        calls = {a: tuple((w & 0x3FFFFFF) << 2 for w in ws if w >> 26 == 3) for a, ws in words.items()}
        for a, c in calls.items():
            if a not in queue and len(c) >= 2:
                donors[c].append(a)
        for a in sorted(queue):
            c = calls.get(a)
            if c and len(c) >= 2 and c in donors:
                print("%08x  %s" % (a, " ".join("%08x" % b for b in donors[c][:3])))
        return
    sigs = {a: tuple(opcode(w) for w in ws) for a, ws in words.items()}
    bylen = defaultdict(list)
    for a, g in sigs.items():
        if a not in queue:
            bylen[len(g)].append(a)
    rows = []
    for a in queue:
        g = sigs.get(a)
        if not g:
            continue
        best = (0.0, None)
        for n in range(int(len(g) * 0.8), int(len(g) * 1.25) + 1):
            for b in bylen.get(n, []):
                r = difflib.SequenceMatcher(None, g, sigs[b], autojunk=False).ratio()
                if r > best[0]:
                    best = (r, b)
        if best[0] >= args.min:
            rows.append((best[0], a, best[1]))
    for r, a, b in sorted(rows, reverse=True):
        print("%08x  %08x  %.3f" % (a, b, r))


if __name__ == "__main__":
    main()
