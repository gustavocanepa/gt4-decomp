#!/usr/bin/env python3
"""Siblings of a matched function: unmatched functions whose code differs from a matched one only
in immediates and addresses (a flag bit, an id, a string, a global, a callee) get their source by
substituting those values in the matched source, and are kept when the judge accepts the result.

Where the two originals differ, the words are aligned one to one (same length, same opcode and
registers) and each pair gives a rule: an immediate (andi/ori/addiu/slti..., also the `~mask`
and decimal spellings), a full address rebuilt from its lui/addiu pair (a `D_`/`func_` symbol or
a string literal that is re-read from the data), or a jal target. Every old value must occur in the
source and every old value must map to a single new one; otherwise the sibling is skipped.

    siblings.py scan [-jN] [--min-size N]   every family of build/families.json with a matched member
    siblings.py try MATCHED UNMATCHED       one pair, prints the rules and the judge's verdict
"""
import csv
import json
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

import rabbitizer

import autoloop
import match
import registration

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "siblings")
IMM_OPS = {0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E}      # addi addiu slti sltiu andi ori xori
MEM_OPS = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2B, 0x2E,
           0x31, 0x39, 0x37, 0x3F, 0x1A, 0x1B, 0x1E, 0x3E}
SIGNED = {0x08, 0x09, 0x0A, 0x0B}


class Words:
    def __init__(self, addr, words):
        self.addr = addr
        self.words = words
        self.full = {}        # index -> full address (lui+addiu/ori or lui+load/store)
        hi = {}
        for i, w in enumerate(words):
            op = w >> 26
            rt, rs = (w >> 16) & 31, (w >> 21) & 31
            imm = w & 0xFFFF
            if op == 0x0F:
                hi[rt] = (imm << 16, i)
            elif op in (0x09, 0x0D) and rs in hi:
                base = hi[rs][0]
                self.full[i] = base + (imm - 0x10000 if op == 0x09 and imm & 0x8000 else imm)
                self.full.setdefault(hi[rs][1], None)
                if op == 0x09 and rt != rs:
                    hi.pop(rt, None)
            elif op in MEM_OPS and rs in hi:
                self.full[i] = hi[rs][0] + (imm - 0x10000 if imm & 0x8000 else imm)
                self.full.setdefault(hi[rs][1], None)
            elif op in (0, 0x1C) or op in IMM_OPS or op == 0x0F:
                rd = (w >> 11) & 31 if op in (0, 0x1C) else rt
                if op != 0x0F:
                    hi.pop(rd, None)


def load_all():
    text_addr, text = match.load_text()
    out = {}
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            a = int(row["address"], 16)
            out[a] = match.trim_padding(match.words_at(text_addr, text, a, int(row["max_size"])))
    return out


_data = None


def data_string(addr):
    global _data
    if _data is None:
        _data = open(os.path.join(ROOT, "build", "full", "data.bin"), "rb").read()
    return registration.cstring(_data, addr)


def rules(wm, wu):
    """old->new substitutions from the word differences, or None when the shapes differ."""
    if len(wm.words) != len(wu.words):
        return None
    subs = {}

    def add(old, new):
        if old in subs and subs[old] != new:
            raise ValueError("ambiguous")
        subs[old] = new

    try:
        for i, (a, b) in enumerate(zip(wm.words, wu.words)):
            if a == b:
                continue
            op = a >> 26
            if op != b >> 26 or (a & 0xFFFF0000) != (b & 0xFFFF0000) and op not in (2, 3, 0x0F):
                return None
            if op in (2, 3):
                add(("sym", (a & 0x3FFFFFF) << 2), ("sym", (b & 0x3FFFFFF) << 2))
            elif i in wm.full and wm.full[i] is not None:
                if i not in wu.full or wu.full[i] is None:
                    return None
                add(("sym", wm.full[i]), ("sym", wu.full[i]))
            elif op == 0x0F:
                if i not in wm.full:
                    return None            # lui whose pair we did not see
                continue                   # covered by its addiu/load pair
            elif op in IMM_OPS or op in MEM_OPS:
                ia, ib = a & 0xFFFF, b & 0xFFFF
                if op in SIGNED or op in MEM_OPS:
                    ia, ib = (x - 0x10000 if x & 0x8000 else x for x in (ia, ib))
                add(("imm", ia), ("imm", ib))
            else:
                return None
    except ValueError:
        return None
    return subs


def spellings(v):
    out = []
    if v < 0:
        out += [f"-0x{-v:X}", f"-0x{-v:x}", str(v)]
        out += [f"~0x{~v:X}", f"~0x{~v:x}"]
    else:
        out += [f"0x{v:X}", f"0x{v:x}", str(v)]
    return out


def substitute(src, subs, funcs):
    """Apply the rules to the source text; None when an old value cannot be found."""
    text = src
    marks = {}
    # `~MASK` in the source serves both the mask and its complement: keep one rule for the pair
    covered = set()
    for old, new in subs.items():
        if old[0] == "imm" and old[1] < 0 and ("imm", ~old[1]) in subs and subs[("imm", ~old[1])] == ("imm", ~new[1]):
            if re.search(rf"~0x{~old[1]:X}\b", src, re.I):
                covered.add(old)
    for n, (old, new) in enumerate(subs.items()):
        if old in covered:
            continue
        token = f"@@{n}@@"
        marks[token] = (old, new)
        if old[0] == "sym":
            oa, na = old[1], new[1]
            old_names = [f"D_{oa:08X}", f"func_{oa:08X}"]
            found = False
            for name in old_names:
                if re.search(rf"\b{name}\b", text):
                    text = re.sub(rf"\b{name}\b", token, text)
                    found = True
            if not found:
                s_old = data_string(oa)
                if s_old is not None and f'"{s_old}"' in text:
                    text = text.replace(f'"{s_old}"', token)
                    found = True
            if not found:
                return None
        else:
            found = False
            for sp in spellings(old[1]):
                pat = rf"(?<![\w.]){re.escape(sp)}(?![\w.])"
                if re.search(pat, text):
                    text = re.sub(pat, token, text)
                    found = True
            if not found:
                return None
    for token, (old, new) in marks.items():
        if old[0] == "sym":
            oa, na = old[1], new[1]
            if re.search(rf"func_{oa:08X}", src):
                rep = f"func_{na:08X}"
            elif f"D_{oa:08X}" in src:
                rep = f"D_{na:08X}"
            else:
                s_new = data_string(na)
                if s_new is None:
                    return None
                rep = f'"{s_new}"'
        else:
            v = new[1]
            if old[1] < 0 and f"~0x{~old[1]:X}" in src or old[1] < 0 and f"~0x{~old[1]:x}" in src:
                rep = f"~0x{~v:X}"
            else:
                rep = f"-0x{-v:X}" if v < 0 else f"0x{v:X}"
        text = text.replace(token, rep)
    return text


def judge(addr, text):
    os.makedirs(OUT, exist_ok=True)
    path = os.path.join(OUT, f"{addr:08x}.cpp")
    open(path, "w", newline="\n").write(text)
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    return res.returncode == 0 and "MATCH" in res.stdout, res.stdout + res.stderr, path


def source_path(addr):
    for ext in ("cpp", "c"):
        p = os.path.join(ROOT, "src", f"func_{addr:08X}.{ext}")
        if os.path.exists(p):
            return p
    return None


def attempt(m, u, words, funcs):
    wm, wu = Words(m, words[m]), Words(u, words[u])
    subs = rules(wm, wu)
    if subs is None:
        return None, "shapes differ", None
    sp = source_path(m)
    src = open(sp).read()
    text = substitute(src, subs, funcs)
    if text is None:
        return None, "old value not in source", None
    text = re.sub(rf"\bfunc_{m:08X}\b", f"func_{u:08X}", text)
    ok, out, path = judge(u, text)
    return ok, out, path


def cmd_try(m, u):
    words = load_all()
    wm, wu = Words(m, words[m]), Words(u, words[u])
    subs = rules(wm, wu)
    print("rules:", subs)
    ok, out, path = attempt(m, u, words, set(words))
    print(out[:4000] if out else "")
    if ok:
        print(f"-> {path}")


def cmd_scan(jobs, min_size):
    fams = json.load(open(os.path.join(ROOT, "build", "families.json")))
    words = load_all()
    done = autoloop.done_addrs()
    pairs = []
    for f in fams:
        matched = [int(a, 16) for a in f["members"] if int(a, 16) in done and source_path(int(a, 16))]
        if not matched:
            continue
        for a in f["unmatched_members"]:
            u = int(a, 16)
            if u in done or len(words[u]) * 4 < min_size:
                continue
            # closest matched member: same length, fewest differing words
            best = None
            for m in matched:
                if len(words[m]) != len(words[u]):
                    continue
                d = sum(1 for x, y in zip(words[m], words[u]) if x != y)
                if best is None or d < best[0]:
                    best = (d, m)
            if best:
                pairs.append((best[1], u))
    print(f"{len(pairs)} unmatched functions with a same-length matched sibling", flush=True)
    stats = {"MATCH": 0, "no match": 0, "shapes differ": 0, "old value not in source": 0}
    solved_bytes = 0

    def run(p):
        m, u = p
        try:
            return p, attempt(m, u, words, set(words))
        except Exception as e:  # keep the scan going
            return p, (None, f"error {e}", None)

    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for (m, u), (ok, out, path) in pool.map(run, pairs):
            if ok:
                open(os.path.join(ROOT, "src", f"func_{u:08X}.cpp"), "w", newline="\n").write(open(path).read())
                stats["MATCH"] += 1
                solved_bytes += len(words[u]) * 4
                print(f"{u:08x} MATCH (from {m:08x}, {len(words[u]) * 4} B)", flush=True)
            elif ok is None:
                stats[out if out in stats else "shapes differ"] = stats.get(out if out in stats else "shapes differ", 0) + 1
            else:
                stats["no match"] += 1
                print(f"{u:08x} no (from {m:08x}): {(out.splitlines() or ['?'])[0][:90]}", flush=True)
    print(stats, f"{solved_bytes} bytes matched")


def main():
    if sys.argv[1:2] == ["try"] and len(sys.argv) > 3:
        cmd_try(int(sys.argv[2], 16), int(sys.argv[3], 16))
    elif sys.argv[1:2] == ["scan"]:
        jobs = next((int(a[2:]) for a in sys.argv[2:] if a.startswith("-j")), 2)
        min_size = int(sys.argv[sys.argv.index("--min-size") + 1]) if "--min-size" in sys.argv else 0
        cmd_scan(jobs, min_size)
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
