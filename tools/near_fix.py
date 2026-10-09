#!/usr/bin/env python3
"""Fix m2c near misses with rules read from the judge's diff. CPU only.

Grouping the functions m2c misses by one instruction showed the misses are mostly systematic:

- `ori` where the original has `lui/ori` with a one-off low half: a float literal. m2c prints the
  shortest decimal, which ee-gcc 2.96 rounds to the neighbouring float; a hex float literal
  (0x1.999998p-4f) is read exactly. Applied to every float literal, always safe.
- `ori` where the original has `addiu` with the same low half: a literal that is really the
  address of a global (lui/addiu carries a %lo relocation). The literal becomes D_ADDR.
- one commutative operand order (addu/daddu/and/or/xor/mult with the registers swapped): the
  operands of one `+ & | ^ *` are swapped, each occurrence tried in turn.

    near_fix.py [--jobs 2] [--max-differ 8] [--limit N]

Reads build/auto/cpu/results.jsonl (cpu_solve.py's near misses and their drafts); matches go to
src/func_ADDR.c. Tried functions are listed in build/auto/nearfix/tried.txt.
"""
import argparse
import json
import os
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

import autoloop
import cpu_solve
import match
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "nearfix")
TRIED = os.path.join(OUT, "tried.txt")

FLOAT = cpu_solve.FLOAT
HEX = re.compile(r"(?<![\w.])0x([0-9A-Fa-f]{5,8})(?![\w.])")
COMMUTATIVE = {"addu", "daddu", "and", "or", "xor", "mult", "multu", "mul"}


def diff_lines(verdict):
    out = []
    for line in verdict.splitlines():
        if line.startswith("! ") and "|" in line:
            left, right = line[2:].split("|", 1)
            out.append((left.split(), right.split()))
    return out


def addresses(body, diffs):
    """Literals whose low half the original adds with addiu (a %lo relocation) become D_ADDR."""
    lows = set()
    for left, right in diffs:
        # the same low half, compared as 16 bits: addiu shows -0x6570 where ori shows 0x9A90
        if left[:1] == ["addiu"] and right[:1] == ["ori"] and \
                int(left[-1], 16) & 0xFFFF == int(right[-1], 16) & 0xFFFF:
            lows.add(int(right[-1], 16) & 0xFFFF)
    if not lows:
        return None
    names = []

    def named(m):
        value = int(m.group(1), 16)
        if value & 0xFFFF in lows and 0x100000 <= value < 0x2000000:
            names.append(value)
            return f"(s32)D_{value:08X}"
        return m.group(0)
    head, brace, rest = body.partition("{")
    head_lines = head.rsplit("\n", 1)
    new = HEX.sub(named, rest)
    if not names:
        return None
    decls = "".join(f"extern char D_{v:08X}[];\n" for v in sorted(set(names)))
    return head_lines[0] + "\n" + decls + head_lines[1] + brace + new


def _right(text, i):
    """End of the operand starting at i: a name with calls/indexing/fields, or a parenthesised group."""
    j = i
    while j < len(text):
        if text[j] in "([":
            depth, close = 0, {"(": ")", "[": "]"}[text[j]]
            open_ = text[j]
            while j < len(text):
                depth += (text[j] == open_) - (text[j] == close)
                j += 1
                if depth == 0:
                    break
        elif text[j].isalnum() or text[j] == "_":
            j += 1
        elif text.startswith("->", j) or (text[j] == "." and j + 1 < len(text) and text[j + 1].isalpha()):
            j += 2 if text[j] == "-" else 1
        else:
            break
    return j


def _left(text, i):
    """Start of the operand ending at i (exclusive), the mirror of _right."""
    j = i
    while j > 0:
        c = text[j - 1]
        if c in ")]":
            depth, open_ = 0, {")": "(", "]": "["}[c]
            while j > 0:
                depth += (text[j - 1] == c) - (text[j - 1] == open_)
                j -= 1
                if depth == 0:
                    break
        elif c.isalnum() or c == "_":
            j -= 1
        elif text[j - 2:j] == "->" or c == ".":
            j -= 2 if c == ">" else 1
        else:
            break
    return j


def swaps(body):
    """The same body with the operands of one commutative operator swapped, each in turn."""
    head, brace, rest = body.partition("{")
    for m in re.finditer(r" ([+&|^*]) ", rest):
        a0 = _left(rest, m.start())
        b1 = _right(rest, m.end())
        left, right = rest[a0:m.start()], rest[m.end():b1]
        if not left or not right or left == right:
            continue
        yield head + brace + rest[:a0] + right + m.group(0) + left + rest[b1:]


def judge(addr, path, body):
    open(path, "w", newline="\n").write(cpu_solve.PRELUDE + body)
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    return res.returncode == 0 and "could not be checked" not in res.stdout, res.stdout


def attempt(addr):
    draft = open(os.path.join(cpu_solve.OUT, f"{addr:08x}.c")).read()
    body = draft[len(cpu_solve.PRELUDE):] if draft.startswith(cpu_solve.PRELUDE) else draft
    path = os.path.join(OUT, f"{addr:08x}.c")
    tries = 0
    body = cpu_solve.exact_floats(body)
    ok, verdict = judge(addr, path, body)
    tries += 1
    if not ok:
        fixed = addresses(body, diff_lines(verdict))
        if fixed:
            body = fixed
            ok, verdict = judge(addr, path, body)
            tries += 1
    if not ok:
        diffs = diff_lines(verdict)
        if diffs and len(diffs) <= 2 and all(l[:1] == r[:1] and l[0] in COMMUTATIVE for l, r in diffs if l and r):
            for variant in list(swaps(body))[:16]:
                ok, verdict = judge(addr, path, variant)
                tries += 1
                if ok:
                    break
    if ok:
        dest = os.path.join(ROOT, "src", f"func_{addr:08X}.c")
        if not project.source_for(addr):
            open(dest, "w", newline="\n").write(open(path).read())
    return addr, ok, tries


def safe(addr):
    try:
        return attempt(addr)
    except Exception:  # one bad draft must not stop the run
        return addr, False, 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--max-differ", type=int, default=8)
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)
    tried = set(open(TRIED).read().split()) if os.path.exists(TRIED) else set()
    latest = {}
    for line in open(cpu_solve.RESULTS):
        if line.strip():
            r = json.loads(line)
            latest[r["addr"]] = r
    done = autoloop.done_addrs()
    todo = []
    for name, r in latest.items():
        addr = int(name, 16)
        if r["result"] != "differs" or addr in done or name in tried or r["differ"] > a.max_differ:
            continue
        draft = os.path.join(cpu_solve.OUT, f"{name}.c")
        if not os.path.exists(draft):
            continue
        text = open(draft).read()
        # only drafts a rule can change: float literals, address-like literals, or a short miss
        if FLOAT.search(text.split("#endif", 1)[-1]) or HEX.search(text) or r["differ"] <= 2:
            todo.append((r["differ"], addr))
    todo = [x for _, x in sorted(todo)]
    if a.limit:
        todo = todo[:a.limit]
    print(f"{len(todo)} near misses to fix by rule", flush=True)
    hits, t0 = 0, time.time()
    with ThreadPoolExecutor(a.jobs) as pool, open(TRIED, "a") as log:
        for i, (addr, ok, tries) in enumerate(pool.map(safe, todo), 1):
            log.write(f"{addr:08x}\n")
            log.flush()
            if ok:
                hits += 1
                with open(autoloop.LOG, "a") as f:
                    f.write(json.dumps({"addr": f"{addr:08x}", "matched": True, "effort": "near_fix",
                                        "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
            if i % 100 == 0:
                print(f"{i}/{len(todo)} matched {hits} ({(time.time() - t0) / 60:.0f} min)", flush=True)
    print(f"done: {hits} of {len(todo)} matched", flush=True)


if __name__ == "__main__":
    main()
