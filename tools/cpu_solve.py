#!/usr/bin/env python3
"""Solve functions with the CPU only: m2c's draft, compiled as is, judged as is.

For every function without a source (skipping hand-written assembly and code built by another
compiler), m2c writes compilable C (`--valid-syntax`), which is compiled as C and judged. A match
goes to src/func_ADDR.c; a near miss (few differing instructions) is kept for the permuter
(tools/permute_cpu.py); the rest is listed for the language models. No model is called.

    cpu_solve.py [--jobs 3] [--max-bytes 2048] [--limit N]

Results: build/auto/cpu/results.jsonl (one line per function: matched, or the share that differs).
Resumable: functions already in results.jsonl are skipped.
"""
import argparse
import csv
import json
import os
import re
import struct
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

import autoloop
import inventory
import match

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "cpu")
RESULTS = os.path.join(OUT, "results.jsonl")
M2C = autoloop.M2C
MACROS = open(os.path.join(os.path.dirname(M2C), "m2c_macros.h")).read()
PRELUDE = ("typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;\n"
           "typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;\n"
           "typedef float f32; typedef double f64;\n"
           "typedef int s128 __attribute__((mode(TI))); typedef unsigned int u128 __attribute__((mode(TI)));\n"
           "#define NULL 0\n"
           "void *memcpy(void *, const void *, unsigned int);\n" + MACROS + "\n")

FLOAT = re.compile(r"(?<![\w.])(\d+\.\d*(?:[eE][-+]?\d+)?|\d+[eE][-+]?\d+)(f?)(?![\w.])")


def exact_floats(body):
    """Every float literal as a hex float, which ee-gcc 2.96 reads without rounding."""
    def hexed(m):
        value = float(m.group(1))
        if m.group(2):
            value = struct.unpack("<f", struct.pack("<f", value))[0]
        return value.hex() + m.group(2)
    return FLOAT.sub(hexed, body)


def draft(addr, extra=(), ee=True):
    """m2c's draft; ee=False feeds it rabbitizer's o32 register names instead of the EE's."""
    asm = os.path.join(OUT, f"{addr:08x}{'_'.join(x.strip('-') for x in extra)}{'' if ee else 'o32'}.s")
    open(asm, "w", newline="\n").write(match.m2c_asm(addr) if ee else match.gnu_asm(addr))
    res = subprocess.run([sys.executable, M2C, "-t", "mipsee-gcc-c", "--valid-syntax", *extra, asm],
                         capture_output=True, text=True, timeout=120)
    os.remove(asm)
    return res.stdout if res.returncode == 0 else None


def solve(addr):
    try:
        return attempt(addr)
    except BaseException as e:  # one bad function must not stop the run
        return {"addr": f"{addr:08x}", "result": f"error: {str(e)[:80]}"}


def tail_call(body, addr):
    """The game's rule (knowledge/ee-gcc-2.96.md): a function ending in `j callee` was written
    `return callee(...);` with a non-void return type. m2c writes a plain call."""
    words = match.trim_padding(match.words_at(*match.load_text(), addr, match.function_span(addr)))
    ends = [w for w in words if w][-2:]
    if not ends or ends[0] >> 26 != 2:
        return None
    callee = f"func_{(((ends[0] & 0x3FFFFFF) << 2) | (addr & 0xF0000000)):08X}"
    lines = body.rstrip().split("\n")
    # last statement before the closing brace
    for i in range(len(lines) - 1, -1, -1):
        s = lines[i].strip()
        if s == "}" or not s:
            continue
        if s.startswith(callee + "(") and s.endswith(";"):
            lines[i] = lines[i].replace(callee + "(", "return " + callee + "(", 1)
            break
        return None
    out = "\n".join(lines) + "\n"
    out = re.sub(r"^void (func_%08X\()" % addr, r"M2C_UNK \1", out, flags=re.M)
    out = re.sub(r"^void (%s\()" % callee, r"M2C_UNK \1", out, flags=re.M)
    return out


def missing_params(body, addr):
    """m2c names parameters by register (arg1 = $a1) but drops unused ones, so `f(s32 arg1)`
    compiles arg1 into $a0. Declare every parameter up to the highest one used."""
    m = re.search(r"^(.*\bfunc_%08X)\(([^)]*)\)\s*\{" % addr, body, re.M)
    if not m or m.group(2).strip() in ("", "void"):
        return None
    params = [p.strip() for p in m.group(2).split(",")]
    named = {}
    for p in params:
        n = re.search(r"\barg(\d+)$", p)
        if not n:
            return None
        named[int(n.group(1))] = p
    top = max(named)
    if len(named) == top + 1:
        return None
    full = ", ".join(named.get(i, f"M2C_UNK arg{i}") for i in range(top + 1))
    return body[:m.start(2)] + full + body[m.end(2):]


def variants(addr, body, ee=True):
    """m2c's draft, then the same draft corrected with rules learned on this game."""
    yield "m2c", body
    p = missing_params(body, addr)
    if p:
        body = p
        yield "m2c+params", body
    t = tail_call(body, addr)
    if t:
        yield "m2c+tailcall", t
    try:
        v = draft(addr, ["--void"], ee)
    except subprocess.TimeoutExpired:
        v = None
    if v and "M2C_ERROR" not in v and v != body:
        yield "m2c --void", v


def judge(addr, path):
    return subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                          capture_output=True, text=True)


def compile_fix(addr, body, errors):
    """m2c's draft corrected from ee-gcc's own error messages; None when no rule applies.

    Grouping the drafts that did not compile showed four causes behind almost all of them:
    stack slots m2c reads but never declares (`sp0`), a callee called with fewer arguments than
    m2c's guessed prototype (the original reuses an argument register already set), the result
    of a callee m2c declared void, and `*` applied to an integer expression."""
    lines = body.split("\n")
    skip = PRELUDE.count("\n")
    changed = False
    head = re.search(r"^\w[^\n]*\bfunc_%08X\([^)]*\)\s*\{$" % addr, body, re.M)
    declared = []
    for m in re.finditer(r"^[^\n]*?:(\d+): (.*)$", errors, re.M):
        n, msg = int(m.group(1)) - skip - 1, m.group(2)
        u = re.match(r"`(\w+)' undeclared", msg)
        if u and re.fullmatch(r"(unk)?sp\w*", u.group(1)) and u.group(1) not in declared:
            declared.append(u.group(1))
            continue
        f = re.match(r"too (?:few|many) arguments to function `(\w+)'", msg)
        if f:
            for i, line in enumerate(lines):
                if re.match(r"^[^(]*\b%s\(" % f.group(1), line) and line.rstrip().endswith(("*/", ";")):
                    lines[i] = re.sub(r"\b(%s)\([^)]*\)" % f.group(1), r"\1()", line, count=1)
                    changed = True
            continue
        void = "void value not ignored" in msg or "invalid use of void expression" in msg
        if void and 0 <= n < len(lines):
            fixed_callee = False
            for callee in set(re.findall(r"\b(func_[0-9A-F]{8})\(", lines[n])):
                for i, line in enumerate(lines):
                    if re.match(r"^void %s\(" % callee, line):
                        lines[i] = "M2C_UNK" + line[4:]
                        changed = fixed_callee = True
            if fixed_callee:
                continue
        # `*` on an integer or on a void pointer: read through a pointer of the assigned type
        if (void or "invalid type argument of `unary *'" in msg) and 0 <= n < len(lines):
            lhs = re.match(r"\s*(\w+) = \*\(", lines[n])
            kind = "s32"
            if lhs:
                d = re.search(r"^\s+([\w ]+?) \**%s;" % lhs.group(1), body, re.M)
                kind = d.group(1) if d else kind
            new = re.sub(r"(?<![\w)\]])\*\((?!\w+ \*\))", f"*({kind} *)(", lines[n])
            new = re.sub(r"(?<![\w)\]])\*(?=[a-z_]\w*\b)", f"*({kind} *)", new)
            if new != lines[n]:
                lines[n] = new
                changed = True
    out = "\n".join(lines)
    if declared and head:
        at = head.end() + 1 + (out[:head.end()].count("\n") - body[:head.end()].count("\n"))
        out = out[:at] + "".join(f"    s32 {d};\n" for d in declared) + out[at:]
        changed = True
    return out if changed else None


def differs_by(res):
    """(0 for a match, else the number of differing instructions, 10**6 if it did not compile)."""
    if res.returncode == 0 and "could not be checked" not in res.stdout:
        return 0
    m = re.search(r"(\d+) of (\d+) instructions differ", res.stdout)
    return int(m.group(1)) if m else 10 ** 6


def prepared(addr, body, path):
    """m2c's draft made compilable: local buffer for `sp`, exact floats, compiler errors fixed."""
    # m2c names the address of a stack local `sp` when it cannot name the local itself: give it
    # a local buffer so the draft compiles (the judge or the permuter takes it from there).
    if re.search(r"\bsp\b", body.split("{", 1)[-1]):
        body = re.sub(r"(^\w[^\n]*\bfunc_%08X\([^)]*\)\s*\{\n)" % addr,
                      lambda m: m.group(1) + "    s8 sp[0x10];\n", body, count=1, flags=re.M)
    body = exact_floats(body)
    for _ in range(4):  # ee-gcc's error messages, fixed by rule until it compiles
        open(path, "w", newline="\n").write(PRELUDE + body)
        res = judge(addr, path)
        out = res.stdout + res.stderr
        fixed = compile_fix(addr, body, out) if "compile failed" in out else None
        if not fixed:
            break
        body = fixed
    return body


def attempt(addr):
    path = os.path.join(OUT, f"{addr:08x}.c")
    # EE register names are right for arguments 5-8, but where $8-$11 are only temporaries the
    # o32 names sometimes give m2c a closer draft: try both when they differ, keep the closest.
    namings = [True] + ([False] if match.m2c_asm(addr) != match.gnu_asm(addr) else [])
    best = None  # (differing instructions, text, verdict)
    # the draft kept by an earlier run competes too, so a retry never makes a function farther
    if os.path.exists(path):
        old = open(path).read()
        old = old[len(PRELUDE):] if old.startswith(PRELUDE) else None
        if old:
            res = judge(addr, path)
            best = (differs_by(res), old, res)
    gave_up = True
    for ee in namings:
        try:
            body = draft(addr, ee=ee)
        except subprocess.TimeoutExpired:
            continue
        if not body or "M2C_ERROR" in body:
            continue
        gave_up = False
        for how, text in variants(addr, prepared(addr, body, path), ee):
            open(path, "w", newline="\n").write(PRELUDE + text)
            res = judge(addr, path)
            if best is None or differs_by(res) < best[0]:
                best = (differs_by(res), text, res)
            if best[0] == 0:
                break
        if best and best[0] == 0:
            break
    if gave_up and best is None:
        return {"addr": f"{addr:08x}", "result": "m2c could not decompile it"}
    score, text, res = best
    # keep the closest draft and its verdict for near_fix, the permuter and the report
    open(path, "w", newline="\n").write(PRELUDE + text)
    if score == 0:
        dest = os.path.join(ROOT, "src", f"func_{addr:08X}.c")
        if not any(os.path.exists(os.path.join(ROOT, "src", f"func_{addr:08X}.{e}")) for e in ("c", "cpp")):
            open(dest, "w", newline="\n").write(open(path).read())
        return {"addr": f"{addr:08x}", "result": "match"}
    m = re.search(r"(\d+) of (\d+) instructions differ \(original (\d+), mine (\d+)\)", res.stdout)
    if m:
        return {"addr": f"{addr:08x}", "result": "differs", "differ": int(m.group(1)), "of": int(m.group(2)),
                "same_length": m.group(3) == m.group(4)}
    return {"addr": f"{addr:08x}", "result": "does not compile"}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=3)
    ap.add_argument("--max-bytes", type=int, default=2048)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--retry", action="store_true", help="try earlier failures again")
    a = ap.parse_args()
    a_retry = a.retry
    os.makedirs(OUT, exist_ok=True)
    tried = set()
    if os.path.exists(RESULTS):
        latest = {}
        for l in open(RESULTS):
            if l.strip():
                r = json.loads(l)
                latest[r["addr"]] = r["result"]
        # --retry: try the failures again (after the variants got better)
        tried = {a for a, res in latest.items() if not (a_retry and res in ("differs", "does not compile", "m2c could not decompile it"))}
    done = autoloop.done_addrs()
    asm_only = inventory.asm_functions()
    text_addr, text = match.load_text()
    todo = []
    for r in csv.DictReader(open(match.FUNCTIONS)):
        addr = int(r["address"], 16)
        if addr in done or addr in asm_only or f"{addr:08x}" in tried:
            continue
        words = match.trim_padding(match.words_at(text_addr, text, addr, int(r["max_size"])))
        if len(words) * 4 > a.max_bytes or autoloop.other_compiler(words):
            continue
        todo.append((len(words), addr))
    todo = [x for _, x in sorted(todo)]
    if a.limit:
        todo = todo[:a.limit]
    print(f"{len(todo)} functions to try with m2c alone", flush=True)
    counts = {}
    t0 = time.time()
    with ThreadPoolExecutor(a.jobs) as pool, open(RESULTS, "a") as log:
        for i, r in enumerate(pool.map(solve, todo), 1):
            log.write(json.dumps(r) + "\n")
            log.flush()
            counts[r["result"]] = counts.get(r["result"], 0) + 1
            if r["result"] == "match":
                with open(autoloop.LOG, "a") as f:
                    f.write(json.dumps({"addr": r["addr"], "matched": True, "effort": "m2c",
                                        "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
            if i % 200 == 0:
                print(f"{i}/{len(todo)} {counts} ({(time.time() - t0) / 60:.0f} min)", flush=True)
    print(f"done: {counts}", flush=True)


if __name__ == "__main__":
    main()
