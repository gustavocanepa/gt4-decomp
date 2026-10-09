#!/usr/bin/env python3
"""The functions built by another compiler: m2c drafts compiled with that compiler, no model.

autoloop.other_compiler() recognises ~270 functions (0x3ac140-0x5b9af0, Sony SDK code, 80 KB)
whose prologue saves the callee-saved registers 16 bytes apart; of decomp.me's EE compilers only
the ee-gcc 2.9 releases do that, and their drafts are the closest (tools/compiler_probe.py
--foreign, knowledge/ee-gcc-2.96.md). A source chooses that compiler with a marker on its first
line, `/* compiler: ee-gcc2.9-991111 */` (project.toml [compilers], read by match.py, build.py and
the CI). This tool runs cpu_solve's draft pipeline (m2c, the learned fixes, the closest variant)
and near_fix's diff-driven fixes with that marker in place, so every judge call compiles with the
other compiler; src/func_ADDR.c on MATCH.

    other_compiler.py list                 the functions, with sizes
    other_compiler.py solve [-jN] [--limit N] [--retry]
    other_compiler.py stats                results of the last run (build/auto/other/results.jsonl)
"""
import json
import os
import sys
from concurrent.futures import ThreadPoolExecutor

import autoloop
import cpu_solve
import families
import match
import near_fix

ROOT = match.ROOT
COMPILER = "ee-gcc2.9-991111"
MARKER = f"/* compiler: {COMPILER} */\n"
OUT = os.path.join(ROOT, "build", "auto", "other")
RESULTS = os.path.join(OUT, "results.jsonl")

# Every draft, fix and verdict of the pipeline goes through cpu_solve's prelude and output
# directory: with the marker on top, match.py compiles them with the other compiler.
cpu_solve.PRELUDE = MARKER + cpu_solve.PRELUDE
cpu_solve.OUT = OUT
near_fix.OUT = os.path.join(OUT, "nearfix")

_draft = cpu_solve.draft


def draft(addr, *args, **kw):
    """m2c's draft with the untyped hardware-register accesses of this SDK code (`*(void *)0x12001000`,
    which ee-gcc 2.9 rejects as "invalid use of void expression") read and written as words."""
    text = _draft(addr, *args, **kw)
    return text.replace("*(void *)", "*(u32 *)") if text else text


cpu_solve.draft = draft


def functions():
    """[(addr, size)] of the unmatched functions with the other compiler's prologue."""
    done = autoloop.done_addrs()
    return [(a, len(w) * 4) for a, w in families.function_words()
            if a not in done and autoloop.other_compiler(w)]


def solve_one(addr):
    row = cpu_solve.attempt(addr, out=OUT)
    if row.get("result") == "differs":
        try:
            _, ok, tries = near_fix.attempt(addr)
        except Exception as e:  # one bad draft must not stop the run
            ok, tries = False, 0
        if ok:
            row = dict(row, result="match", how=row.get("how", "") + "+near_fix", near_fix_tries=tries)
    return row


def cmd_solve(jobs, limit, retry):
    os.makedirs(near_fix.OUT, exist_ok=True)
    tried = set()
    if os.path.exists(RESULTS) and not retry:
        for line in open(RESULTS):
            tried.add(json.loads(line)["addr"])
    todo = [a for a, size in functions() if f"{a:08x}" not in tried][:limit]
    print(f"{len(todo)} functions to try with {COMPILER}", flush=True)
    stats = {}
    with ThreadPoolExecutor(max_workers=jobs) as pool, open(RESULTS, "a") as log:
        for row in pool.map(solve_one, todo):
            log.write(json.dumps(row) + "\n")
            log.flush()
            key = row["result"]
            stats[key] = stats.get(key, 0) + 1
            if key == "match":
                print(f"{row['addr']} MATCH ({row.get('how')})", flush=True)
            elif key == "differs":
                print(f"{row['addr']} differs {row['differ']} of {row['of']}", flush=True)
            else:
                print(f"{row['addr']} {key}", flush=True)
    print(stats)


def cmd_stats():
    rows = [json.loads(l) for l in open(RESULTS)] if os.path.exists(RESULTS) else []
    sizes = dict(functions())
    by = {}
    for r in rows:
        by.setdefault(r["result"], []).append(r)
    for key, lst in sorted(by.items(), key=lambda kv: -len(kv[1])):
        print(f"{len(lst):4d} {key}")
    near = sorted((r for r in by.get("differs", [])), key=lambda r: r["differ"])
    for r in near[:30]:
        print(f"  {r['addr']} {r['differ']:3d} of {r['of']:3d} {'same length' if r.get('same_length') else ''}")


def main():
    args = sys.argv[1:]
    if args[:1] == ["list"]:
        total = 0
        for a, size in functions():
            print(f"{a:08x} {size}")
            total += size
        print(f"{len(functions())} functions, {total} bytes")
    elif args[:1] == ["solve"]:
        jobs = next((int(a[2:]) for a in args if a.startswith("-j")), 2)
        limit = int(args[args.index("--limit") + 1]) if "--limit" in args else 10 ** 9
        cmd_solve(jobs, limit, "--retry" in args)
    elif args[:1] == ["stats"]:
        cmd_stats()
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
