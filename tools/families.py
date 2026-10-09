#!/usr/bin/env python3
"""Families of similar functions, ranked by the bytes still unmatched, so the next tool can be
aimed at the biggest group: one representative understood by hand, the rest solved on the CPU.

Two levels of similarity on the instruction words with addresses and immediates masked (opcodes
and registers kept, so compiler-generated code with the same shape groups together):
  skeleton  identical masked word sequence (addresses, jump targets and immediates differ)
  near      same skeleton after dropping run-repeats, or MinHash similarity of 4-gram shingles
            >= the threshold (a few inserted or removed instructions)
Matched members count too: a family with matched members has a solved representative to template.

    families.py [--min-size N] [--level skeleton|near] [--top K] [--json FILE]
    families.py show FAMILY_ID        members of one family (from the last --json output)
"""
import csv
import json
import os
import struct
import sys
import zlib
from collections import defaultdict

import autoloop
import match

ROOT = match.ROOT
DEFAULT_JSON = os.path.join(ROOT, "build", "families.json")

# opcode -> which 16-bit immediate field to mask (True) ; everything else keeps its immediate
MASK_IMM = {
    0x0F,                                       # lui
    0x09, 0x0D,                                 # addiu, ori (lo halves, constants)
    0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17, 0x01,  # branches (offset)
    0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B,        # lb lh lw lbu lhu sb sh sw
    0x31, 0x39, 0x37, 0x3F, 0x1A, 0x1B, 0x2A, 0x2E,        # lwc1 swc1 ld sd ldl ldr swl swr
    0x22, 0x26, 0x27, 0x3E, 0x1E, 0x08, 0x0A, 0x0B, 0x0C, 0x0E, 0x19, 0x18,
}


def mask_word(w):
    op = w >> 26
    if op in (2, 3):                       # j, jal
        return w & 0xFC000000
    if op == 0x01:                         # regimm branches: keep rs and the sub-op
        return w & 0xFFFF0000
    if op in MASK_IMM:
        return w & 0xFFFF0000
    return w


def function_words():
    """[(addr, words)] for every function, in address order."""
    text_addr, text = match.load_text()
    out = []
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            a = int(row["address"], 16)
            words = match.trim_padding(match.words_at(text_addr, text, a, int(row["max_size"])))
            if words:
                out.append((a, words))
    return out


def skeleton_key(masked):
    return zlib.crc32(struct.pack(f"<{len(masked)}I", *masked))


def collapsed_key(masked):
    """Masked sequence with immediate repeats of one word dropped (unrolled stores, repeated loads)."""
    out = []
    for w in masked:
        if not out or out[-1] != w:
            out.append(w)
    return zlib.crc32(struct.pack(f"<{len(out)}I", *out))


def shingles(masked, n=4):
    return {zlib.crc32(struct.pack(f"<{n}I", *masked[i:i + n])) for i in range(len(masked) - n + 1)}


class MinHash:
    """Fixed random hashes over 32-bit shingle ids."""

    def __init__(self, k=48, seed=7):
        import random
        rnd = random.Random(seed)
        self.params = [(rnd.randrange(1, 1 << 31), rnd.randrange(0, 1 << 31)) for _ in range(k)]
        self.k = k

    def sign(self, sh):
        p = 0xFFFFFFFB
        return tuple(min(((a * s + b) % p) for s in sh) for a, b in self.params)


class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))

    def find(self, i):
        while self.p[i] != i:
            self.p[i] = self.p[self.p[i]]
            i = self.p[i]
        return i

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a != b:
            self.p[max(a, b)] = min(a, b)


def build(min_size=128, level="near", threshold=0.5, bands=12):
    funcs = [(a, w) for a, w in function_words() if len(w) * 4 >= min_size]
    done = autoloop.done_addrs()
    masked = [[mask_word(w) for w in words] for _, words in funcs]
    n = len(funcs)
    uf = UnionFind(n)
    by_key = defaultdict(list)
    for i, m in enumerate(masked):
        by_key[skeleton_key(m)].append(i)
    for members in by_key.values():
        for i in members[1:]:
            uf.union(members[0], i)
    if level == "near":
        by_key = defaultdict(list)
        for i, m in enumerate(masked):
            by_key[collapsed_key(m)].append(i)
        for members in by_key.values():
            for i in members[1:]:
                uf.union(members[0], i)
        mh = MinHash()
        sigs = []
        shs = []
        for m in masked:
            sh = shingles(m)
            shs.append(sh)
            sigs.append(mh.sign(sh) if sh else None)
        rows = mh.k // bands
        for b in range(bands):
            bucket = defaultdict(list)
            for i, s in enumerate(sigs):
                if s is not None:
                    bucket[s[b * rows:(b + 1) * rows]].append(i)
            for members in bucket.values():
                if len(members) < 2 or len(members) > 400:
                    continue
                first = members[0]
                for i in members[1:]:
                    if uf.find(i) == uf.find(first):
                        continue
                    inter = len(shs[first] & shs[i])
                    union = len(shs[first] | shs[i])
                    if union and inter / union >= threshold:
                        uf.union(first, i)
    groups = defaultdict(list)
    for i in range(n):
        groups[uf.find(i)].append(i)
    fams = []
    for members in groups.values():
        if len(members) < 2:
            continue
        addrs = [funcs[i][0] for i in members]
        sizes = {funcs[i][0]: len(funcs[i][1]) * 4 for i in members}
        unmatched = [a for a in addrs if a not in done]
        matched = [a for a in addrs if a in done]
        if not unmatched:
            continue
        rep = max(matched, key=sizes.get) if matched else max(unmatched, key=sizes.get)
        fams.append({
            "count": len(addrs), "unmatched": len(unmatched), "matched": len(matched),
            "unmatched_bytes": sum(sizes[a] for a in unmatched),
            "big_unmatched": sum(1 for a in unmatched if sizes[a] > 512),
            "min_size": min(sizes.values()), "max_size": max(sizes.values()),
            "representative": f"{rep:08x}", "members": [f"{a:08x}" for a in sorted(addrs)],
            "unmatched_members": [f"{a:08x}" for a in sorted(unmatched)],
        })
    fams.sort(key=lambda f: -f["unmatched_bytes"])
    return fams


def names():
    out = {}
    path = os.path.join(ROOT, "config", "symbol_addrs.txt")
    if os.path.exists(path):
        for line in open(path):
            if "= 0x" in line and "type:func" in line:
                name, rest = line.split("=", 1)
                out.setdefault(int(rest.split(";")[0], 16), name.strip())
    path = os.path.join(ROOT, "config", "adhoc_methods.txt")
    if os.path.exists(path):
        for line in open(path):
            parts = line.split()
            if len(parts) == 3 and parts[2].startswith("0x"):
                out.setdefault(int(parts[2], 16), f"{parts[0]}::{parts[1]}")
    return out


def main():
    args = sys.argv[1:]
    if args[:1] == ["show"]:
        fams = json.load(open(DEFAULT_JSON))
        f = fams[int(args[1])]
        nm = names()
        for a in f["members"]:
            print(a, "matched" if a not in f["unmatched_members"] else "", nm.get(int(a, 16), ""))
        return
    opt = {"--min-size": "128", "--level": "near", "--top": "60", "--json": DEFAULT_JSON, "--threshold": "0.5"}
    for i, a in enumerate(args):
        if a in opt:
            opt[a] = args[i + 1]
    fams = build(int(opt["--min-size"]), opt["--level"], float(opt["--threshold"]))
    json.dump(fams, open(opt["--json"], "w"), indent=1)
    nm = names()
    total = sum(f["unmatched_bytes"] for f in fams)
    print(f"{len(fams)} families with unmatched members, {total} unmatched bytes in them -> {opt['--json']}")
    print(f"{'id':>4} {'n':>4} {'unm':>4} {'mat':>4} {'bytes':>7} {'>512':>4} {'size':>11}  representative")
    for i, f in enumerate(fams[:int(opt["--top"])]):
        rep = int(f["representative"], 16)
        print(f"{i:>4} {f['count']:>4} {f['unmatched']:>4} {f['matched']:>4} {f['unmatched_bytes']:>7} "
              f"{f['big_unmatched']:>4} {f['min_size']:>5}-{f['max_size']:<5}  {f['representative']} {nm.get(rep, '')}")


if __name__ == "__main__":
    main()
