#!/usr/bin/env python3
"""One address range, one compiler: m2c drafts and near_fix's rules judged with that compiler.

Sony's libraries were not built with the game's flags: libstdc++ (basic_string, the STL) and
expat match only with `-fno-strict-aliasing` (knowledge/gt4.md), and the ~270 SDK functions with
the 16-byte register-save spacing need ee-gcc 2.9 (tools/other_compiler.py). This runs the CPU
pipeline (cpu_solve's drafts, variants and compile fixes, then near_fix) on every unmatched
function of a range with a compiler named in project.toml [compilers]; matches keep the
`/* compiler: NAME */` marker on their first line, so match.py, build.py and CI use it too.

    region_compiler.py solve --compiler NAME --lo 0x5547e8 [--hi 0x700000] [-jN] [--max-bytes 2048] [--limit N]
    region_compiler.py stats --compiler NAME

Results: build/auto/region/NAME/results.jsonl (resumable).
"""
import argparse
import json
import os
from concurrent.futures import ThreadPoolExecutor

import autoloop
import cpu_solve
import families
import inventory
import match
import near_fix

ROOT = match.ROOT


def setup(compiler):
    """Point cpu_solve and near_fix at this compiler: every judge call compiles the marked prelude."""
    out = os.path.join(ROOT, "build", "auto", "region", compiler)
    cpu_solve.PRELUDE = f"/* compiler: {compiler} */\n" + cpu_solve.PRELUDE
    cpu_solve.OUT = out
    near_fix.OUT = os.path.join(out, "nearfix")
    os.makedirs(near_fix.OUT, exist_ok=True)
    return out


def functions(lo, hi, max_bytes):
    """[(addr, size)] unmatched in [lo, hi), not hand-written assembly, not ee-gcc 2.9 code."""
    done = autoloop.done_addrs()
    asm_only = inventory.asm_functions()
    out = []
    for a, w in families.function_words():
        if lo <= a < hi and a not in done and a not in asm_only and len(w) * 4 <= max_bytes \
                and not autoloop.other_compiler(w):
            out.append((a, len(w) * 4))
    return sorted(out, key=lambda x: x[1])


def solve_one(addr):
    try:
        row = cpu_solve.attempt(addr, out=cpu_solve.OUT)
        if row.get("result") == "differs":
            _, ok, _ = near_fix.attempt(addr)
            if ok:
                row = dict(row, result="match", how="near_fix")
    except Exception as e:  # one bad function must not stop the run
        row = {"addr": f"{addr:08x}", "result": f"error: {str(e)[:80]}"}
    return row


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("cmd", choices=["solve", "stats"])
    ap.add_argument("--compiler", required=True)
    ap.add_argument("--lo", type=lambda x: int(x, 0), default=0)
    ap.add_argument("--hi", type=lambda x: int(x, 0), default=0x7FFFFFFF)
    ap.add_argument("-j", "--jobs", type=int, default=2)
    ap.add_argument("--max-bytes", type=int, default=2048)
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args()
    out = setup(a.compiler)
    results = os.path.join(out, "results.jsonl")
    rows = [json.loads(l) for l in open(results) if l.strip()] if os.path.exists(results) else []
    if a.cmd == "stats":
        by = {}
        for r in rows:
            by[r["result"]] = by.get(r["result"], 0) + 1
        print(by)
        return
    tried = {r["addr"] for r in rows}
    todo = [x for x, _ in functions(a.lo, a.hi, a.max_bytes) if f"{x:08x}" not in tried]
    if a.limit:
        todo = todo[:a.limit]
    print(f"{len(todo)} functions in {a.lo:#x}-{a.hi:#x} with {a.compiler}", flush=True)
    stats = {}
    log = os.open(results, os.O_WRONLY | os.O_APPEND | os.O_CREAT)
    with ThreadPoolExecutor(a.jobs) as pool:
        for i, row in enumerate(pool.map(solve_one, todo), 1):
            os.write(log, (json.dumps(row) + "\n").encode())
            stats[row["result"]] = stats.get(row["result"], 0) + 1
            if i % 200 == 0:
                print(f"{i}/{len(todo)} {stats}", flush=True)
    print(f"done: {stats}", flush=True)


if __name__ == "__main__":
    main()
