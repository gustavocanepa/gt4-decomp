#!/usr/bin/env python3
"""Unaligned block copies (ldl/ldr, sdl/sdr) as struct assignments. CPU only.

m2c refuses functions with `ldl/ldr/sdl/sdr` ("unknown instruction"), the biggest reason it
gives up in the library region (0x494578+). The sequence is gcc's expansion of a struct
assignment for a struct with alignment < 8: `ldl rt, off+7(base); ldr rt, off(base)` loads one
doubleword from an unaligned address, N pairs of loads then N pairs of stores copy 8*N bytes.

Three steps per function:
1. the assembly fed to m2c has each ldl/ldr pair rewritten as `ld` and each sdl/sdr pair as
   `sd` (likewise lwl/lwr -> lw, swl/swr -> sw), so m2c decompiles it;
2. in the draft, a run of 64-bit loads from consecutive offsets of one base followed by the
   64-bit stores of the same values to consecutive offsets of another base becomes one
   assignment `*(BlockN *)(dst) = *(BlockN *)(src)` with `typedef struct { char b[N]; } BlockN;`
   (the element type u16/u32 tried as well: the alignment decides the instruction order);
3. the drafts are judged with every library compiler profile (the first-line marker): functions
   whose unaligned pairs are right half first (`ldr; ldl`, right_first) only with
   ee-gcc2.96-nsa-nosib-rf, the others only with the left-first profiles; the closest is kept, src/func_ADDR.c is written on a match (cpu_solve/near_fix do the judging).

    blockcopy.py queue                 # list the m2c failures with ldl/ldr in 0x494578+
    blockcopy.py solve [-j2] [--limit N] [--compilers a,b,c] [--list FILE]
    blockcopy.py one ADDR              # one function, verbose

Results: build/auto/blockcopy/results.jsonl (resumable), drafts in build/auto/blockcopy/COMPILER/.
"""
import argparse
import glob
import json
import os
import re
import sys
import time
from concurrent.futures import ThreadPoolExecutor

import autoloop
import cpu_solve
import match
import near_fix
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "blockcopy")
RESULTS = os.path.join(OUT, "results.jsonl")
QUEUE = os.path.join(OUT, "queue.txt")
LO = 0x494578
COMPILERS = ["ee-gcc2.96-nsa-nosib", "ee-gcc2.96-no-strict-aliasing", "default"]

INSN = re.compile(r"^(/\* [0-9A-F]{8} [0-9A-F]{8} \*/\s+)(\w+)\s+(\$\w+), (-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)\s*$")
PAIRS = {("ldl", "ldr"): ("ld", 7), ("sdl", "sdr"): ("sd", 7), ("lwl", "lwr"): ("lw", 3), ("swl", "swr"): ("sw", 3)}


def rewrite_asm(asm):
    """Each `xxl rt, off+k(base)` + `xxr rt, off(base)` pair (either order, adjacent or separated
    by other instructions) as one aligned load/store at off, the second half as a nop (deleting
    it emptied delay slots: `jr $ra` + `sdr` made m2c give up). Returns (asm, [(op, off, base)])."""
    lines = asm.split("\n")
    parsed = [INSN.match(l) for l in lines]
    found = []
    used = set()
    for i, m in enumerate(parsed):
        if not m or i in used:
            continue
        op = m.group(2)
        for (left, right), (new, k) in PAIRS.items():
            if op not in (left, right):
                continue
            other = right if op == left else left
            for j in range(i + 1, min(i + 12, len(parsed))):
                n = parsed[j]
                if not n or j in used or n.group(2) != other or n.group(3) != m.group(3) or n.group(5) != m.group(5):
                    continue
                lo = min(int(m.group(4), 0), int(n.group(4), 0))
                hi = max(int(m.group(4), 0), int(n.group(4), 0))
                if hi - lo != k:
                    continue
                used.add(i)
                used.add(j)
                lines[i] = f"{m.group(1)}{new:<12}{m.group(3)}, {lo:#x}({m.group(5)})"
                # a nop keeps the other half's slot: it may be a branch delay slot
                lines[j] = f"{n.group(1)}nop"
                found.append((new, lo, m.group(5)))
                break
            break
    return "\n".join(l for l in lines if l is not None), found


# ---- step 2: the draft's load/store runs as one struct assignment ----------------------------

MEM = [re.compile(r"M2C_FIELD\((\w+), (?:s64|u64|f64) \*, (-?0x[0-9A-Fa-f]+|-?\d+)\)"),
       re.compile(r"\*\((?:s64|u64|f64) \*\) ?\((\w+) \+ (-?0x[0-9A-Fa-f]+|-?\d+)\)"),
       re.compile(r"\*\((?:s64|u64|f64) \*\) ?(\w+)()")]
CAST = r"(?:\((?:s64|u64|f64)\) )?"


def mem(expr):
    """A 64-bit memory operand as (base, offset), else None."""
    e = expr.strip()
    for rx in MEM:
        m = rx.fullmatch(e)
        if m:
            return m.group(1), int(m.group(2) or "0", 0)
    return None


def copy_stmt(line):
    """`DST = (s64) SRC;` with both 64-bit memory operands -> (indent, dst, src)."""
    m = re.fullmatch(r"(\s*)(.+?) = " + CAST + r"(.+?);\s*", line)
    if not m:
        return None
    d, s = mem(m.group(2)), mem(m.group(3))
    return (m.group(1), d, s) if d and s else None


def load_stmt(line):
    m = re.fullmatch(r"(\s*)(\w+) = " + CAST + r"(.+?);\s*", line)
    if not m:
        return None
    s = mem(m.group(3))
    return (m.group(1), m.group(2), s) if s else None


def store_stmt(line):
    m = re.fullmatch(r"(\s*)(.+?) = " + CAST + r"(\w+);\s*", line)
    if not m:
        return None
    d = mem(m.group(2))
    return (m.group(1), d, m.group(3)) if d else None


def consecutive(ops):
    """Every (base, off) in ops has the first one's base and off + 8 * index."""
    b0, o0 = ops[0]
    return all(b == b0 and o == o0 + 8 * x for x, (b, o) in enumerate(ops))


def block_runs(lines):
    """[(first line, last line, (src base, off), (dst base, off), n)] for each run of n direct
    copies `dst = src` of consecutive doublewords, or of n loads into temporaries followed by
    the n stores of the same temporaries, both in the same order."""
    runs = []
    i = 0
    while i < len(lines):
        # direct copies
        j = i
        copies = []
        while j < len(lines):
            c = copy_stmt(lines[j])
            if not c:
                break
            copies.append(c)
            j += 1
        if copies and consecutive([c[1] for c in copies]) and consecutive([c[2] for c in copies]):
            runs.append((i, j - 1, copies[0][2], copies[0][1], len(copies)))
            i = j
            continue
        # loads into temporaries, then the stores
        j = i
        loads = []
        while j < len(lines):
            l = load_stmt(lines[j])
            if not l:
                break
            loads.append(l)
            j += 1
        if loads:
            stores = []
            k = j
            while k < len(lines) and len(stores) < len(loads):
                st = store_stmt(lines[k])
                if not st:
                    break
                stores.append(st)
                k += 1
            if len(stores) == len(loads) and all(s[2] == l[1] for s, l in zip(stores, loads))                     and consecutive([l[2] for l in loads]) and consecutive([s[1] for s in stores]):
                runs.append((i, k - 1, loads[0][2], stores[0][1], len(loads)))
                i = k
                continue
        i += 1
    return runs


def with_blocks(body, elem="char"):
    """The draft with every load/store run replaced by a struct assignment; None when none."""
    lines = body.split("\n")
    runs = block_runs(lines)
    if not runs:
        return None
    sizes = set()
    for first, last, (sb, so), (db, do), n in reversed(runs):
        size = 8 * n
        sizes.add(size)
        indent = re.match(r"\s*", lines[first]).group(0)
        src = f"((char *){sb} + {so:#x})" if so else sb
        dst = f"((char *){db} + {do:#x})" if do else db
        lines[first:last + 1] = [f"{indent}*(Block{size} *){dst} = *(Block{size} *){src};"]
    width = {"char": 1, "u16": 2, "u32": 4}[elem]
    defs = "".join(f"typedef struct {{ {elem} b[{s // width}]; }} Block{s};\n" for s in sorted(sizes))
    return defs + "\n".join(lines)


# ---- step 3: judging with each library compiler --------------------------------------------

_real_m2c_asm = match.m2c_asm
_real_gnu_asm = match.gnu_asm


def m2c_asm(addr, count=None):
    return rewrite_asm(_real_m2c_asm(addr, count))[0]


def gnu_asm(addr, count=None):
    return rewrite_asm(_real_gnu_asm(addr, count))[0]


def install():
    """cpu_solve.draft reads match.m2c_asm at call time: the rewritten assembly goes to m2c,
    the judge (match.py check, a subprocess) still compares against the original bytes."""
    match.m2c_asm = m2c_asm
    match.gnu_asm = gnu_asm


BASE_PRELUDE = cpu_solve.PRELUDE


def setup(compiler):
    out = os.path.join(OUT, compiler)
    os.makedirs(out, exist_ok=True)
    marker = "" if compiler == "default" else f"/* compiler: {compiler} */\n"
    cpu_solve.PRELUDE = marker + BASE_PRELUDE
    cpu_solve.OUT = out
    near_fix.OUT = os.path.join(out, "nearfix")
    os.makedirs(near_fix.OUT, exist_ok=True)
    return out


def global_literals(body, verdict):
    """near_fix's addresses rule without the line alignment: the judge's diff misaligns the
    columns when a literal costs an instruction, so the low halves are matched anywhere
    (lui/addiu on the original side, lui/ori on ours)."""
    left, right = set(), set()
    for line in verdict.splitlines():
        if not line.startswith("! ") or "|" not in line:
            continue
        l, r = (s.split() for s in line[2:].split("|", 1))
        if l[:1] == ["addiu"] and len(l) == 4 and l[1] == l[2]:
            left.add(int(l[3], 16) & 0xFFFF)
        if r[:1] == ["ori"] and len(r) == 4:
            right.add(int(r[3], 16) & 0xFFFF)
    lows = left & right
    if not lows:
        return None
    # near_fix inserts the declarations before the function's `{`: the Block typedefs go first
    defs = "".join(l + "\n" for l in body.split("\n") if l.startswith("typedef struct {"))
    rest = "".join(l + "\n" for l in body.split("\n") if not l.startswith("typedef struct {"))
    fixed = near_fix.addresses(rest, [(["addiu", "x", "x", f"{v:#x}"], ["ori", "x", "x", f"{v:#x}"]) for v in lows])
    return defs + fixed if fixed else None


def judge_text(addr, path, text):
    open(path, "w", newline="\n").write(cpu_solve.PRELUDE + text)
    res = cpu_solve.judge(addr, path)
    return cpu_solve.differs_by(res), res


def attempt(addr, compiler, verbose=False):
    """cpu_solve's pipeline with this compiler's marker, then the block-assignment variants of
    the kept draft, then near_fix's rules on the closest text. setup(compiler) must have run
    (the globals are per phase, so a run is one compiler at a time)."""
    out = os.path.join(OUT, compiler)
    path = os.path.join(out, f"{addr:08x}.c")
    if os.path.exists(path):
        os.remove(path)  # a fresh judgement of this run's drafts (cpu_solve keeps old ones)
    row = cpu_solve.attempt(addr, out=out)
    row["compiler"] = compiler
    if verbose:
        print(compiler, row, flush=True)
    if row["result"] in ("match", "m2c could not decompile it"):
        return row
    text = open(path).read()
    text = cpu_solve.strip_prelude(text, cpu_solve.PRELUDE) or cpu_solve.strip_prelude(text) or text
    best = (row.get("differ", 10 ** 6), "plain:" + row["how"], text)
    for elem in ("char", "u16", "u32"):
        blk = with_blocks(text, elem)
        if not blk:
            break
        score, res = judge_text(addr, path, blk)
        if verbose:
            print(compiler, elem, score, flush=True)
        if score < best[0]:
            best = (score, f"block:{elem}", blk)
        # a literal that is really a global's address shows up in every variant's diff (lui/ori
        # for lui/addiu): near_fix's rule on this variant, before comparing
        fixed = global_literals(blk, res.stdout) if score else None
        if fixed:
            score, res = judge_text(addr, path, fixed)
            if verbose:
                print(compiler, elem, "+addresses", score, flush=True)
            if score < best[0]:
                best = (score, f"block:{elem}+addresses", fixed)
        if best[0] == 0:
            break
    open(path, "w", newline="\n").write(cpu_solve.PRELUDE + best[2])
    if 0 < best[0] <= 8:
        _, ok, _ = near_fix.attempt(addr)
        if ok:
            best = (0, best[1] + "+near_fix", None)
    if best[0] == 0:
        # near_fix writes its own match to src/; a block variant's match is written here and
        # judged again in place (the marker is the prelude's first line)
        dest = os.path.join(ROOT, "src", f"func_{addr:08X}.c")
        if best[2] is not None and not project.source_for(addr):
            open(dest, "w", newline="\n").write(cpu_solve.PRELUDE + best[2])
            if cpu_solve.differs_by(cpu_solve.judge(addr, dest)) != 0:
                os.remove(dest)
                return {"addr": f"{addr:08x}", "result": "differs", "differ": -1, "compiler": compiler,
                        "how": best[1] + " (src/ re-judge failed)"}
        return {"addr": f"{addr:08x}", "result": "match", "compiler": compiler, "how": best[1]}
    return {"addr": f"{addr:08x}", "result": "differs", "differ": best[0], "compiler": compiler, "how": best[1]}


def safe(args):
    addr, compiler = args
    try:
        return attempt(addr, compiler)
    except Exception as e:  # one bad function must not stop the run
        return {"addr": f"{addr:08x}", "result": f"error: {str(e)[:80]}", "compiler": compiler}


# the right half then the left half of the SAME access kind on one register (`ldr X` then `sdl X`
# is a left-first load followed by its left-first store: 130 such functions were wrongly excluded)
RIGHT_FIRST = re.compile(r"\b([ls])([dw])r\s+(\$\w+), [^\n]*\n[^\n]*\b\1\2l\s+\3,")
RF_COMPILER = "ee-gcc2.96-nsa-nosib-as2004"  # tools/cc_as.sh: gcc -S, then the 2004 ee-as


def right_first(asm):
    """An unaligned pair in `xxr; xxl` order. gcc writes `uld/usd/ulw/usw` and every GNU as we
    have (ee 2.9 and 2.96) expands them left half first, as does gcc's own block move: 284
    library functions (the 0x5c2b60.. pointer-to-member thunks among them) went through an
    assembler expanding them right first; they are judged only with RF_COMPILER
    (knowledge/ee-gcc-2.96.md)."""
    return bool(RIGHT_FIRST.search(asm))


def fits(addr, compiler):
    """Right-first functions only with RF_COMPILER, the others only with the left-first ones."""
    return right_first(_real_gnu_asm(addr)) == (compiler == RF_COMPILER)


def queue():
    """m2c failures of the region runs (by address, smallest first) with ldl/ldr/sdl/sdr."""
    failed = set()
    for f in glob.glob(os.path.join(ROOT, "build", "auto", "region", "*", "results.jsonl")):
        for l in open(f):
            r = json.loads(l)
            if r.get("result") == "m2c could not decompile it":
                failed.add(int(r["addr"], 16))
    done = autoloop.done_addrs()
    out = []
    for a in sorted(failed):
        if a < LO or a in done:
            continue
        asm = _real_gnu_asm(a)  # the real text: m2c_asm goes through the patched gnu_asm
        if re.search(r"\b(ldl|ldr|sdl|sdr|lwl|lwr|swl|swr)\b", asm):
            out.append((asm.count("\n"), a))
    return [a for _, a in sorted(out)]


def best_rows(rows):
    """The closest row per function (a match beats everything)."""
    best = {}
    for r in rows:
        k = r["addr"]
        score = 0 if r["result"] == "match" else r.get("differ", 10 ** 6)
        if k not in best or score < best[k][0]:
            best[k] = (score, r)
    return {k: v[1] for k, v in best.items()}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("cmd", choices=["queue", "solve", "one", "stats"])
    ap.add_argument("addr", nargs="?")
    ap.add_argument("-j", "--jobs", type=int, default=2)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--compilers", default=",".join(COMPILERS + [RF_COMPILER]))
    ap.add_argument("--list", help="solve these addresses (one hex per line) instead of the queue")
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)
    compilers = a.compilers.split(",")
    install()
    if a.cmd == "one":
        for c in [c for c in compilers if fits(int(a.addr, 16), c)]:
            setup(c)
            r = attempt(int(a.addr, 16), c, verbose=True)
            print(json.dumps(r))
            if r["result"] == "match":
                break
        return
    if a.cmd == "queue":
        q = queue()
        open(QUEUE, "w").write("\n".join(f"{x:08x}" for x in q))
        print(f"{len(q)} functions -> {QUEUE}")
        return
    rows = [json.loads(l) for l in open(RESULTS) if l.strip()] if os.path.exists(RESULTS) else []
    if a.cmd == "stats":
        by = {}
        for r in best_rows(rows).values():
            k = r["result"] + (f" ({r['compiler']}, {r['how']})" if r["result"] == "match" else "")
            by[k] = by.get(k, 0) + 1
        for k, v in sorted(by.items(), key=lambda x: -x[1]):
            print(f"{v:5} {k}")
        return
    done = autoloop.done_addrs()
    if a.list:
        todo = [int(x, 16) for x in open(a.list).read().split()]
    else:
        todo = [int(x, 16) for x in open(QUEUE).read().split()] if os.path.exists(QUEUE) else queue()
    todo = [x for x in todo if x not in done]
    if a.limit:
        todo = todo[:a.limit]
    log = os.open(RESULTS, os.O_WRONLY | os.O_APPEND | os.O_CREAT)
    t0 = time.time()
    for compiler in compilers:  # one compiler per phase: cpu_solve's globals carry the marker
        matched = {r["addr"] for r in rows if r["result"] == "match"}
        tried = {r["addr"] for r in rows if r.get("compiler") == compiler}
        phase = [x for x in todo if f"{x:08x}" not in matched and f"{x:08x}" not in tried and fits(x, compiler)]
        print(f"{len(phase)} functions with {compiler}", flush=True)
        setup(compiler)
        stats = {}
        with ThreadPoolExecutor(a.jobs) as pool:
            for i, row in enumerate(pool.map(safe, [(x, compiler) for x in phase]), 1):
                os.write(log, (json.dumps(row) + "\n").encode())
                rows.append(row)
                stats[row["result"]] = stats.get(row["result"], 0) + 1
                if row["result"] == "match":
                    with open(autoloop.LOG, "a") as f:
                        f.write(json.dumps({"addr": row["addr"], "matched": True, "effort": "blockcopy",
                                            "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
                if i % 25 == 0:
                    print(f"{i}/{len(phase)} {stats} ({(time.time() - t0) / 60:.0f} min)", flush=True)
        print(f"{compiler}: {stats}", flush=True)
    by = {}
    for r in best_rows(rows).values():
        by[r["result"]] = by.get(r["result"], 0) + 1
    print(f"done: {by}", flush=True)


if __name__ == "__main__":
    main()
