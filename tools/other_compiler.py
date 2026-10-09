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
    other_compiler.py climb [ADDR...]      the 2.9 rules (climb) on the saved near misses
    other_compiler.py stats                results of the last run (build/auto/other/results.jsonl)
"""
import json
import os
import re
import sys
from concurrent.futures import ThreadPoolExecutor

import autoloop
import cpu_solve
import families
import match
import near_fix
import project

ROOT = match.ROOT
NL = chr(10)
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


ABS = re.compile(r"\*\((\w+(?: \w+)*) \*\)0x([0-9A-Fa-f]{6,8})\b")
TEXT_ARG = re.compile(r"(?<=[(,] )0x(5[0-9A-Fa-f]{5})(?=[,)])|(?<=\()0x(5[0-9A-Fa-f]{5})(?=[,)])")


def name_addresses(body):
    """Absolute data addresses named: `*(T *)0x657A80` -> `D_00657A80` (`extern T D_00657A80;`), and
    a code address passed as an argument (`f(0x800, 0x5B13F8, p)`) -> the function. ee-gcc 2.9 puts
    the `lui` of a literal address in another register and schedules it elsewhere than a symbol's
    (`lui $v1` + `lw 0x7A80($v1)` before the saves), so unlike 2.96 the literal never matches, even
    when the diff shows no addiu/ori pair for near_fix.addresses to see."""
    head, brace, rest = body.partition("{")
    decls = {}

    def data(m):
        value = int(m.group(2), 16)
        if not 0x100000 <= value < 0x2000000:
            return m.group(0)
        decls[f"D_{value:08X}"] = f"extern {m.group(1)} D_{value:08X};\n"
        return f"D_{value:08X}"

    def code(m):
        value = int(m.group(1) or m.group(2), 16)
        decls[f"func_{value:08X}"] = f"void func_{value:08X}();\n"
        return f"func_{value:08X}"
    new = TEXT_ARG.sub(code, ABS.sub(data, rest))
    if new == rest:
        return None
    decls = {k: v for k, v in decls.items() if not re.search(r"\b" + k + r"\b", head)}
    lines = head.rsplit("\n", 1)
    return lines[0] + "\n" + "".join(decls.values()) + lines[1] + brace + new


def _block_end(text, i):
    """Index just past the brace block opening at text[i] == '{'."""
    depth = 0
    for j in range(i, len(text)):
        depth += (text[j] == "{") - (text[j] == "}")
        if depth == 0:
            return j + 1
    return -1


def _negate(cond):
    if "&&" not in cond and "||" not in cond:
        for a, b in (("!=", "=="), ("==", "!="), (">=", "<"), ("<=", ">"), (" < ", " >= "), (" > ", " <= ")):
            if cond.count(a) == 1:
                return cond.replace(a, b)
    return f"!({cond})"


def swapped_arms(body):
    """Each `if (c) {A} else {B}` written `if (!c) {B} else {A}`, one at a time. ee-gcc 2.9 lays the
    arms out in source order (the else arm is the branch target), so m2c's choice of polarity shows
    as a `bnel`/`beqz` pair with the arms exchanged."""
    for m in re.finditer(r"\bif \((.*)\) \{\n", body):
        open_ = m.end() - 2
        end = _block_end(body, open_)
        if end < 0 or not body.startswith(" else {", end):
            continue
        end2 = _block_end(body, end + 6)
        if end2 < 0:
            continue
        a, b = body[open_ + 1:end - 1], body[end + 7:end2 - 1]
        yield body[:m.start()] + f"if ({_negate(m.group(1))}) {{" + b + "} else {" + a + "}" + body[end2:]


def climb(addr, body, verdict, budget=40):
    """Greedy descent over the 2.9 rules (named addresses, arms swapped, unused results void):
    keep every variant that lowers the count of differing instructions."""
    path = os.path.join(near_fix.OUT, f"{addr:08x}.c")
    best = near_fix.differ(verdict)
    tries = 0
    named = name_addresses(body)
    if named:
        ok, v = near_fix.judge(addr, path, named)
        tries += 1
        if ok:
            return True, named, tries
        if near_fix.differ(v) <= best:
            body, best = named, near_fix.differ(v)
    improved = True
    while improved and tries < budget:
        improved = False
        for variant in list(swapped_arms(body)) + list(near_fix.void_returns(body)):
            if tries >= budget:
                break
            ok, v = near_fix.judge(addr, path, variant)
            tries += 1
            if ok:
                return True, variant, tries
            if near_fix.differ(v) < best:
                body, best, improved = variant, near_fix.differ(v), True
                break
    return False, body, tries


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
        else:
            row = climb_one(addr, row)
    return row


def climb_one(addr, row):
    """climb() from the saved draft; src/func_ADDR.c on MATCH."""
    draft = open(os.path.join(OUT, f"{addr:08x}.c")).read()
    body = draft[len(cpu_solve.PRELUDE):] if draft.startswith(cpu_solve.PRELUDE) else draft
    ok, verdict = near_fix.judge(addr, os.path.join(near_fix.OUT, f"{addr:08x}.c"), body)
    if not ok:
        ok, body, tries = climb(addr, body, verdict)
    if ok:
        dest = os.path.join(ROOT, "src", f"func_{addr:08X}.c")
        if not project.source_for(addr):
            open(dest, "w", newline=NL).write(cpu_solve.PRELUDE + body)
        return dict(row, result="match", how=row.get("how", "") + "+climb")
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


def near_misses(limit=40):
    """The closest drafts of the last runs, best result per function."""
    best = {}
    for line in open(RESULTS) if os.path.exists(RESULTS) else []:
        r = json.loads(line)
        if r["result"] == "differs" and (r["addr"] not in best or r["differ"] < best[r["addr"]]["differ"]):
            best[r["addr"]] = r
    return sorted(best.values(), key=lambda r: r["differ"])[:limit]


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
    elif args[:1] == ["climb"]:
        os.makedirs(near_fix.OUT, exist_ok=True)
        todo = [int(a, 16) for a in args[1:]] or [int(r["addr"], 16) for r in near_misses()]
        done = autoloop.done_addrs()
        for addr in todo:
            if addr in done or project.source_for(addr):
                continue
            row = climb_one(addr, {"addr": f"{addr:08x}"})
            print(f"{addr:08x} {row.get('result', 'differs')}", flush=True)
    elif args[:1] == ["stats"]:
        cmd_stats()
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
