#!/usr/bin/env python3
"""Retry m2c near misses as C++ with every callee declared nothrow. CPU only.

g++ 2.96 marks a callee TREE_NOTHROW when its type says `throw()`, and reorg then fills branch
delay slots across calls to it (beql/bnel, hoisted argument loads); calls to any other function in
C++ stop its liveness scan (knowledge/ee-gcc-2.96.md, "throw() on the declaration"). The game's
own code is C++ whose callees were mostly defined above in the same unit, so a C draft that
differs only in delay slots often matches once compiled as C++ with `throw()` callees.

The draft (build/auto/cpu/ADDR.c) is wrapped in `extern "C" { ... }`; each top-level prototype
gets `throw()`, and its parameter list becomes `...` unless it names a float type (C's `()` means
"no parameters" in C++, and `...` keeps the draft's untyped calls compiling); `void *` becomes
`char *` (same arithmetic, fewer C++ conversion errors). Matches go to src/func_ADDR.cpp.

    nothrow.py [--limit N] [--max-differ 40] [--max-fraction 0.3] [--addrs A,B,...]

Scratch and the log (results.jsonl, tried.txt) live in build/auto/throw/.
"""
import argparse
import json
import os
import re
import subprocess
import sys
import time

import autoloop
import cpu_solve
import match
import near_fix
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "throw")
LOG = os.path.join(OUT, "results.jsonl")
TRIED = os.path.join(OUT, "tried.txt")

PROTO = re.compile(r"^(?P<head>[A-Za-z_][\w \t\*]*?\b(?P<name>[A-Za-z_]\w*)\s*)\((?P<args>[^;{}]*)\)\s*;(?P<tail>\s*(/\*.*\*/)?\s*)$")
FLOATY = re.compile(r"\b(f32|f64|float|double)\b")


def differ(verdict):
    m = re.search(r"(\d+) of \d+ instructions differ", verdict)
    return int(m.group(1)) if m else None


def to_cpp(draft, keep_args=False):
    body = draft[len(cpu_solve.PRELUDE):] if draft.startswith(cpu_solve.PRELUDE) else draft
    out, depth = [], 0
    for line in body.split("\n"):
        m = PROTO.match(line) if depth == 0 else None
        if m and not m.group("head").lstrip().startswith(("return", "typedef")):
            args = m.group("args").strip()
            if not keep_args and not FLOATY.search(args):
                args = "..."
            elif args == "":
                args = "..."
            line = f"{m.group('head').rstrip()}({args}) throw();"
        depth += line.count("{") - line.count("}")
        out.append(line)
    body = "\n".join(out).replace("void *", "char *")
    return 'extern "C" {\n' + cpu_solve.PRELUDE + body + '\n}\n'


def judge(addr, path, text):
    open(path, "w", newline="\n").write(text)
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    out = res.stdout + res.stderr
    if res.returncode == 0 and "could not be checked" not in out and "MATCH" in out:
        return "match", 0, out
    if "compile failed" in out:
        return "compile", None, out
    return "differs", differ(out), out


def attempt(addr, rec):
    draft = open(os.path.join(cpu_solve.OUT, f"{addr:08x}.c")).read()
    path = os.path.join(OUT, f"{addr:08x}.cpp")
    best = None
    for keep in (False, True):
        kind, n, verdict = judge(addr, path, to_cpp(draft, keep_args=keep))
        if kind == "match":
            if not project.source_for(addr):
                open(os.path.join(ROOT, "src", f"func_{addr:08X}.cpp"), "w", newline="\n").write(open(path).read())
            return {"addr": f"{addr:08x}", "result": "match", "was": rec["differ"], "keep_args": keep}
        if best is None or (n is not None and (best[1] is None or n < best[1])):
            best = (kind, n)
        if kind == "differs" and not keep:
            break  # the `...` form compiled; the typed one rarely helps then
    if best[0] == "differs" and best[1] <= 4:
        # chain with near_fix's diff rules, each variant of the C draft converted the same way
        body = draft[len(cpu_solve.PRELUDE):] if draft.startswith(cpu_solve.PRELUDE) else draft
        diffs = near_fix.diff_lines(verdict)
        variants = [v for v in [near_fix.addresses(body, diffs), near_fix.derefs(body)] if v]
        for rule in (near_fix.swaps, near_fix.member_arrays, near_fix.this_passthrough, near_fix.void_returns):
            variants += list(rule(body))[:6]
        for v in variants[:20]:
            kind, n, _ = judge(addr, path, to_cpp(cpu_solve.PRELUDE + v))
            if kind == "match":
                if not project.source_for(addr):
                    open(os.path.join(ROOT, "src", f"func_{addr:08X}.cpp"), "w", newline="\n").write(open(path).read())
                return {"addr": f"{addr:08x}", "result": "match", "was": rec["differ"], "rule": True}
            if n is not None and n < best[1]:
                best = (kind, n)
    return {"addr": f"{addr:08x}", "result": best[0], "differ": best[1], "was": rec["differ"], "of": rec.get("of")}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--limit", type=int, default=100)
    ap.add_argument("--max-differ", type=int, default=40)
    ap.add_argument("--max-fraction", type=float, default=0.3)
    ap.add_argument("--addrs", default="")
    ap.add_argument("--minutes", type=float, default=0, help="stop after this long")
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)
    tried = set(open(TRIED).read().split()) if os.path.exists(TRIED) else set()
    latest = {}
    for line in open(cpu_solve.RESULTS):
        if line.strip():
            r = json.loads(line)
            latest[r["addr"]] = r
    done = autoloop.done_addrs()
    if a.addrs:
        todo = [(int(x, 16), latest[x.lower().rjust(8, "0")]) for x in a.addrs.split(",")]
    else:
        todo = sorted(((int(k, 16), r) for k, r in latest.items()
                       if r["result"] == "differs" and r.get("same_length") and k not in tried
                       and int(k, 16) not in done and r["differ"] <= a.max_differ
                       and r["differ"] <= a.max_fraction * r.get("of", 0)
                       and os.path.exists(os.path.join(cpu_solve.OUT, f"{k}.c"))),
                      key=lambda t: (t[1]["differ"], t[0]))
        todo = todo[:a.limit] if a.limit else todo
    start, wins = time.time(), 0
    for i, (addr, rec) in enumerate(todo):
        if a.minutes and time.time() - start > a.minutes * 60:
            break
        try:
            res = attempt(addr, rec)
        except Exception as e:  # one bad draft must not stop the run
            res = {"addr": f"{addr:08x}", "result": f"error: {e}"}
        wins += res["result"] == "match"
        with open(LOG, "a") as f:
            f.write(json.dumps(res) + "\n")
        with open(TRIED, "a") as f:
            f.write(f"{addr:08x}\n")
        print(f"[{i + 1}/{len(todo)}] {res}  matches={wins}", flush=True)


if __name__ == "__main__":
    main()
