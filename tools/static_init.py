#!/usr/bin/env python3
"""Static-initialization functions (gcc's __static_initialization_and_destruction_0), from assembly.

Every .cpp that includes a header defining global objects with constructors gets its own copy of
this function, `(s32 init, s32 prio)`, so the game has hundreds that differ only in addresses.
The common header defines 72 objects of a 4-byte class (8 bytes apart in .bss: MIPS aligns structs
to 8) numbered 0, 1, 2, ... 0x47, and an object whose inline constructor registers three callbacks
with func_00325010; other translation units add their own globals (a constructor call, a destructor
under `init == 0`).

What the compiler emits for each object is `if (prio == 0xFFFF && init == 1) ctor(&obj, n);`,
and the priority test is dropped while CSE can follow the path (10 branches, cse.c PATHLENGTH),
which is why it reappears every 10 objects. The inlined constructor evaluates its argument before
the object's address because `this` is a const parameter and is substituted directly; a
`static inline` helper with `T *const self` reproduces that, so the function is written by hand
from the function's own stores and calls, with every global declared extern (the judge can then
check each address). Defining the objects instead (`Id D_008211D8(0); ...`) compiles to the same
bytes plus the 32-byte `_GLOBAL_.I.` wrapper, but puts the objects in the object's own .data.

    static_init.py try ADDR        write and judge one function (prints the diff on failure)
    static_init.py solve [-jN]     every unmatched function with this shape -> src/ when it matches
"""
import csv
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

import rabbitizer

import autoloop
import match

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "static_init")
ARG_REGS = ["$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3"]
MEM = re.compile(r"(-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)")


def function_starts():
    with open(match.FUNCTIONS) as f:
        return {int(row["address"], 16) for row in csv.DictReader(f)}


class Shape:
    """What the function does, in order: ('store', addr, value, guard) and ('call', target, args, guard),
    where guard is 1 (init == 1) or 0 (init == 0) and args are ('addr', a) or ('int', n)."""

    def __init__(self):
        self.items = []


def fail(x):
    if os.environ.get("STATIC_INIT_DEBUG"):
        print(f"stop at {x.vram:08x}: {x.disassemble()}")
    return None


def parse(addr):
    text_addr, text = match.load_text()
    words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
    ins = [rabbitizer.Instruction(w, addr + 4 * i, match.CATEGORY) for i, w in enumerate(words)]
    ops = [(x.getOpcodeName(), [p.strip(",") for p in x.disassemble().split()[1:]], x) for x in ins]
    # The family starts with the priority test: ori v0, 0xFFFF; bne a1, v0
    if not any(op == "bne" for op, _, _ in ops[:8]):
        return None
    const = {"$zero": 0}        # register -> constant
    hi = {}                     # register -> lui value (bits 31..16)
    full = {}                   # register -> full address (lui + addiu)
    init = {"$a0"}              # registers holding `init`
    prio = {"$a1"}              # registers holding `prio`
    guard = 1
    shape = Shape()
    written = []                # argument registers written since the last branch
    has_prio_test = False

    def forget(r):
        for d in (const, hi, full):
            d.pop(r, None)
        init.discard(r)
        prio.discard(r)

    i = 0
    while i < len(ops):
        op, p, x = ops[i]
        i += 1
        if op in ("nop", "jr") or (op == "addiu" and p[0] == "$sp") or op in ("sd", "ld") and MEM.match(p[1]) and MEM.match(p[1]).group(2) == "$sp":
            continue
        if op in ("bne", "bnel", "beq", "beql", "bnez", "beqz", "b"):
            written = []
            a, b = (p[0], p[1]) if op in ("bne", "bnel", "beq", "beql") else (p[0], "$zero")
            if a in init or b in init:
                other = b if a in init else a
                if other == "$zero" or const.get(other) == 0:
                    guard = 0
                elif const.get(other) == 1:
                    guard = 1
                else:
                    return fail(x)
            elif a in prio or b in prio:
                other = b if a in prio else a
                if const.get(other) != 0xFFFF:
                    return fail(x)
                has_prio_test = True
            elif op != "b":
                return fail(x)
            continue
        if op == "lui":
            forget(p[0])
            hi[p[0]] = x.getProcessedImmediate() << 16
        elif op in ("addiu", "ori") and p[1] == "$zero":
            forget(p[0])
            const[p[0]] = x.getProcessedImmediate() & 0xFFFF if op == "ori" else x.getProcessedImmediate()
        elif op in ("addiu", "ori") and p[1] in hi:
            v = hi[p[1]] + x.getProcessedImmediate() if op == "addiu" else hi[p[1]] | x.getProcessedImmediate()
            forget(p[0])
            full[p[0]] = v
        elif op in ("daddu", "addu", "or", "move") and (len(p) == 2 or p[2] == "$zero"):
            src = p[1]
            forget(p[0])
            if src in init:
                init.add(p[0])
            elif src in prio:
                prio.add(p[0])
            elif src in const:
                const[p[0]] = const[src]
            else:
                return fail(x)
        elif op == "sw":
            m = MEM.match(p[1])
            if not m or m.group(2) not in hi:
                return fail(x)
            target = hi[m.group(2)] + int(m.group(1), 0)
            r = p[0]
            if r in const:
                value = const[r]
            elif r in init:
                value = guard
            elif r in hi:
                value = hi[r]
            elif r in full:
                value = ("addr", full[r])
            else:
                return fail(x)
            shape.items.append(("store", target, value, guard))
            continue
        elif op == "jal":
            target = x.getInstrIndexAsVram()
            # The delay slot sets an argument too.
            if i < len(ops):
                sop, sp_, sx = ops[i]
                if sop in ("addiu", "ori") and sp_[1] == "$zero":
                    const[sp_[0]] = sx.getProcessedImmediate() & 0xFFFF if sop == "ori" else sx.getProcessedImmediate()
                    written.append(sp_[0])
                elif sop in ("addiu", "ori") and sp_[1] in hi:
                    full[sp_[0]] = hi[sp_[1]] + sx.getProcessedImmediate()
                    written.append(sp_[0])
                elif sop != "nop":
                    return fail(x)
                i += 1
            args = []
            for r in ARG_REGS:
                if r not in written:
                    break
                if r in full:
                    args.append(("addr", full[r]))
                elif r in const:
                    args.append(("int", const[r]))
                else:
                    return fail(x)
            if any(r in written for r in ARG_REGS[len(args):]):
                return fail(x)
            shape.items.append(("call", target, args, guard))
            # Caller-saved registers are dead after the call.
            for r in list(const) + list(hi) + list(full) + list(init) + list(prio):
                if not r.startswith("$s") and r != "$zero":
                    forget(r)
            written = []
            continue
        else:
            return fail(x)
        if p[0] in ARG_REGS:
            written.append(p[0])
    if not has_prio_test or not shape.items:
        return None
    return shape


def source(addr, shape):
    funcs = function_starts()
    objs, datas, cbs, callees = [], [], [], {}
    for it in shape.items:
        if it[0] == "store":
            if it[1] not in objs:
                objs.append(it[1])
        else:
            _, target, args, _ = it
            sig = []
            for kind, v in args:
                if kind == "int":
                    sig.append("s32")
                elif v in funcs:
                    sig.append("void (*)(void)")
                    cbs.append(v)
                else:
                    sig.append("void *")
                    datas.append(v)
            callees.setdefault(target, sig)
            if callees[target] != sig:
                return None
    out = ["typedef int s32;\n", "struct Obj { s32 v; };\n",
           "static inline void ctor(Obj *const self, s32 n) { self->v = n; }\n"]
    out += [f"extern Obj D_{a:08X};\n" for a in objs]
    out += [f"extern char D_{a:08X}[];\n" for a in dict.fromkeys(datas) if a not in objs]
    out += [f'extern "C" void func_{a:08X}(void);\n' for a in dict.fromkeys(cbs)]
    out += [f'extern "C" void func_{t:08X}({", ".join(sig) or "void"});\n' for t, sig in callees.items()]
    out.append(f'\nextern "C" void func_{addr:08X}(s32 init, s32 prio)\n{{\n')
    for it in shape.items:
        cond = f"prio == 0xFFFF && init == {it[3]}"
        if it[0] == "store":
            value = it[2]
            if isinstance(value, tuple):
                return None
            out.append(f"    if ({cond}) ctor(&D_{it[1]:08X}, {value:#x});\n")
        else:
            _, target, args, _ = it
            words = []
            for kind, v in args:
                if kind == "int":
                    words.append(f"{v:#x}")
                elif v in funcs:
                    words.append(f"func_{v:08X}")
                elif v in objs:
                    words.append(f"&D_{v:08X}")
                else:
                    words.append(f"D_{v:08X}")
            out.append(f"    if ({cond}) func_{target:08X}({', '.join(words)});\n")
    out.append("}\n")
    return "".join(out)


def judge(addr, text):
    os.makedirs(OUT, exist_ok=True)
    path = os.path.join(OUT, f"{addr:08x}.cpp")
    open(path, "w", newline="\n").write(text)
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    return res.returncode == 0 and "MATCH" in res.stdout, res.stdout + res.stderr, path


def attempt(addr):
    shape = parse(addr)
    if shape is None:
        return None, "not this shape", None
    text = source(addr, shape)
    if text is None:
        return None, "unsupported value or call", None
    ok, out, path = judge(addr, text)
    return ok, out, path


def cmd_try(addr):
    ok, out, path = attempt(addr)
    if ok is None:
        sys.exit(out)
    print(out[:8000])
    if ok:
        print(f"-> {path}")


def cmd_solve(jobs):
    text_addr, text = match.load_text()
    done = autoloop.done_addrs()
    cands = []
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            a = int(row["address"], 16)
            if a in done:
                continue
            words = match.trim_padding(match.words_at(text_addr, text, a, int(row["max_size"])))
            if len(words) < 8 or autoloop.other_compiler(words):
                continue
            # ori v0, 0xFFFF then bne a1, v0 within the first eight instructions
            if 0x3402FFFF in words[:4] and any((w >> 16) == 0x14A2 for w in words[1:8]):
                cands.append(a)
    print(f"{len(cands)} unmatched functions start with the priority test", flush=True)
    solved = 0

    def run(addr):
        try:
            return addr, attempt(addr)
        except SystemExit as e:
            return addr, (None, str(e), None)

    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for addr, (ok, out, path) in pool.map(run, sorted(cands)):
            if ok:
                open(os.path.join(ROOT, "src", f"func_{addr:08X}.cpp"), "w", newline="\n").write(open(path).read())
                solved += 1
                print(f"{addr:08x} MATCH", flush=True)
            else:
                print(f"{addr:08x} no: {(out.splitlines() or ['?'])[0][:100]}", flush=True)
    print(f"solved {solved} of {len(cands)}")


def main():
    if sys.argv[1:2] == ["try"] and len(sys.argv) > 2:
        cmd_try(int(sys.argv[2], 16))
    elif sys.argv[1:2] == ["solve"]:
        jobs = next((int(a[2:]) for a in sys.argv[2:] if a.startswith("-j")), 3)
        cmd_solve(jobs)
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
