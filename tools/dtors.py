"""Destructors and constructors of the game's classes (`X__structor_N`) written from the assembly,
no model.

gcc 2.96 (old ABI) gives every class with a virtual destructor one function `X::~X(this, flag)`
in vtable slot 0 of shape

    *(void **)((char *)this + 4) = &X__vtable;   // back to this class's vtable
    ...member cleanups...                        // calls on this+off (flag 2), handle releases,
                                                 // `if (member) release(member);`, stores of 0
    Base__structor_N(this, 0);                   // the base class destructor
    if (flag & 1) return func_00326798(this, sizeof(X), 4, "RefCounter");   // operator delete

and constructors `r = Base__structor_N(this); this->vtbl = &X__vtable; members...; return r;`.

The tool runs a small symbolic executor over the original instructions: registers hold expressions
(this, arguments, float arguments, constants, this+off, loads, call results, ALU results), stores
and calls become statements in the original's instruction order, forward branches become
`if (cond) { ... } [else { ... }]` (nested, delay slots run after the condition is read,
branch-likely slots are a copy of the join's first instruction, registers merged at the join),
backward branches become `while`/`do-while` loops (loop variables become locals), a `j` is a tail
call, a `jalr` through an old-ABI vtable entry an inline vcall helper. Loads still held in a
callee-saved register across a call or a store become a local (`void *p0 = ...;`), call results
used later `void *r0 = f(...);`. Prototypes are written from the use. Data addresses print as their
symbol (`&X__vtable`) or, when the image holds a printable C string there, as the string literal.
Idioms (inlined basic_string release, member helpers) and source variants are listed in VARIANTS
and TOOLS.md; after the variants, the order of independent store runs is searched. Stack locals,
unknown opcodes and irregular control flow give up with a reason.

    dtors.py try ADDR [--show]    one function: source and verdict
    dtors.py scan [--names]       every unmatched vtable slot-0 method of config/classes.json, plus
                                  (--names) every unmatched X__structor_N of the symbol table;
                                  src/ on MATCH (layout.path_for)
    dtors.py scan --structors [--part=K/N] [--range=LO-HI]   every unmatched X__structor_N
                                  (constructors, complete and deleting destructors), optionally
                                  the K-th of N slices or an address range
"""
import itertools
import json
import os
import re
import struct
import subprocess
import sys

import layout
import match
import project
import symbols
from accessors import Insn

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "dtors")
ZERO, V0, SP, RA = 0, 2, 29, 31
STR_ALLOC_NAME, STR_RELEASE_FN = 0x005C11A8, 0x00326798   # basic_string allocator name, release
STR_HELPER = """struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };
"""
STR_RELEASE = """
static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}
"""
ARGS = [4, 5, 6, 7, 8, 9, 10, 11]                  # a0-a3, a4-a7 (EE)
CALLER_SAVED = set(range(1, 16)) | {24, 25}
LOADS = {0x23: "void *", 0x21: "short", 0x25: "unsigned short", 0x20: "signed char", 0x24: "unsigned char"}
STORES = {0x2B: "void *", 0x29: "short", 0x28: "char", 0x39: "float"}


class GiveUp(Exception):
    pass


# ------------------------------------------------------------------ image
_image = None


def image_bytes(addr, n):
    global _image
    if _image is None:
        _image = project.load_image()[1]
    for base, blob in _image:
        if base <= addr < base + len(blob):
            return blob[addr - base:addr - base + n]
    return None


def c_string(addr):
    b = image_bytes(addr, 256)
    if not b or b[0] == 0 or 0 not in b:
        return None
    s = b[:b.index(0)]
    if all(32 <= c < 127 for c in s) and not (symbols.name_of(addr) or "").endswith("vtable"):
        return '"' + s.decode().replace("\\", "\\\\").replace('"', '\\"') + '"'
    return None


# ------------------------------------------------------------------ expressions (tuples)
# ('arg0',) ('arg1',) ('k', n) ('add', e, n) ('ld', e, off, ctype) ('ret', id) ('var', name)
# ('and', e, n)


def add(e, n):
    if n == 0:
        return e
    if e[0] == "add":
        return add(e[1], e[2] + n)
    if e[0] == "k":
        return ("k", (e[1] + n) & 0xFFFFFFFF)
    return ("add", e, n)


def has_load(e):
    if e[0] == "ld":
        return True
    return any(isinstance(x, tuple) and has_load(x) for x in e[1:])


def is_addr(n):
    return 0x100000 <= n < 0x2000000


def refs(e):
    """The offsets from this at which an expression touches the object (None: this itself)."""
    if e[0] == "arg0":
        return [None]
    if e[0] in ("add", "ld") and e[1] == ("arg0",):
        return [e[2]]
    out = []
    for x in e[1:]:
        if isinstance(x, tuple):
            out += refs(x)
    return out


def item_exprs(x):
    k = x["k"]
    if k == "call":
        return list(x["rec"]["args"])
    if k == "decl":
        return [x["expr"]]
    if k == "store":
        return [x["base"], x["val"]] if x["base"] != ("arg0",) else [add(("arg0",), x["off"]) if x["off"] else ("arg0",), x["val"]]
    if k == "str":
        return [x["expr"]]
    if k == "vcall":
        return [x["obj"]] + list(x["args"])
    if k in ("open", "close_do") and "c" in x:
        return [x["c"][1], x["c"][2]]
    if k in ("close", "upd"):
        return []
    return [("arg0",)]


class Func:
    def __init__(self, addr, knobs=()):
        self.addr = addr
        self.knobs = knobs
        text_addr, text = match.load_text()
        self.words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
        self.body = []            # [indent, item dict]
        self.indent = 1
        self.protos = {}          # name -> [ret, [kinds]]
        self.datas = {}           # name -> decl
        self.calls = []           # call records: {"name", "args", "used", "tail"}
        self.vcalls = {}          # (vptr, slot, kinds) -> helper name
        self.nvars = 0
        self.loopvars = set()
        self.subst = None         # (offset, name): inside a member helper, this+offset is `name`
        self.used_args = {0}
        self.used_fargs = set()
        self.fregs = {}
        self.fwritten = set()
        self.ptr_args = set()
        self.returns = []         # v0 at each jr ra
        self.forvars = {}         # for-mode loop variable -> (initial value, stride, steps so far)

    # -------------------------------------------------------- rendering
    def at(self, b, off):
        """C text of the address b + off."""
        if b == ("arg0",) and self.subst:
            d = off - self.subst[0]
            if d < 0:
                raise GiveUp("member helper reaches outside its member")
            return self.subst[1] if d == 0 else f"{self.subst[1]} + {d:#x}"
        if b[0] == "add":
            return self.at(b[1], b[2] + off)
        if b[0] == "var" and b[1] in self.forvars:
            init, stride, bump = self.forvars[b[1]]
            return self.at(init, bump + off) + f" + i * {stride:#x}"
        t = self.r(b)
        return t if off == 0 else f"(char *){t} + {off:#x}"

    def r(self, e):
        k = e[0]
        if k == "arg0":
            if self.subst:
                return self.at(e, 0)
            return "arg0"
        if k.startswith("farg"):
            self.used_fargs.add(int(k[4:]))
            return k
        if k.startswith("arg"):
            self.used_args.add(int(k[3:]))
            return k
        if k == "var":
            if e[1] in self.forvars:
                return self.at(e, 0)
            return e[1]
        if k == "ret":
            self.calls[e[1]]["used"] = True
            return f"r{e[1]}"
        if k == "k":
            n = e[1]
            if is_addr(n):
                s = c_string(n)
                if s:
                    return s
                name = symbols.symbol(n, "data")
                self.datas[name] = f"extern void *{name};"
                return f"&{name}"
            n = n - (1 << 32) if n & 0x80000000 else n
            return f"{n:#x}" if n >= 0 else f"-{-n:#x}"
        if k == "add":
            return self.at(e[1], e[2])
        if k == "sum":
            return f"(char *){self.r(e[1])} + {self.r(e[2])}"
        if k == "ld":
            t = "void **" if e[3] == "void *" else e[3] + " *"
            return f"*({t})({self.at(e[1], e[2])})"
        if k == "and":
            return f"{self.r(e[1])} & {e[2]:#x}"
        if k == "bin":
            o = e[1]
            if o.endswith("u"):
                return f"((unsigned){self.r(e[2])} {o[:-1]} (unsigned){self.r(e[3])})"
            return f"((s32){self.r(e[2])} {o} (s32){self.r(e[3])})"
        if k == "fk":
            # gcc 2.96 does not round decimal float literals correctly: write the value a quarter
            # of an ulp above the float, which both rounding and truncation bring back to it
            f = struct.unpack("<f", struct.pack("<I", e[1]))[0]
            nxt = struct.unpack("<f", struct.pack("<I", e[1] + 1))[0]
            t = repr(f)                                  # exact when short (1.0, 0.5, -2.0)
            if len(t.replace("-", "").replace(".", "").lstrip("0")) > 8 and e[1] & 0x7F800000 != 0x7F800000:
                t = "%.12g" % (f + (nxt - f) / 4)
            if "." not in t and "e" not in t and "inf" not in t and "nan" not in t:
                t += ".0"
            return t + "f"
        raise GiveUp(f"render {e}")

    def kind(self, e):
        if e[0] == "k" and is_addr(e[1]) and c_string(e[1]):
            return "const char *"
        if e[0] == "fk" or e[0] == "ld" and e[3] == "float" or e[0].startswith("farg"):
            return "float"
        if e[0][:3] == "arg" and e[0] != "arg0":
            return "void *" if int(e[0][3:]) in self.ptr_args else "s32"
        if e[0] == "k" and not is_addr(e[1]) or e[0] in ("and", "bin"):
            return "s32"
        if e[0] == "ld" and e[3] != "void *":
            return "s32"
        return "void *"

    def emit(self, x):
        self.body.append([self.indent, x])

    # -------------------------------------------------------- state
    def get(self, r):
        if r == ZERO:
            return ("k", 0)
        if r not in self.regs:
            raise GiveUp(f"read of unset ${r}")
        return self.regs[r]

    def set(self, r, v):
        if r != ZERO:
            self.regs[r] = v
            if r in ARGS:
                self.written.add(r)

    def live(self, r):
        """Is register r read (linearly, from the current instruction on) before it is written?"""
        if self.jal_delay and r in self.written:
            return True                               # an argument of the call this slot precedes
        for j in range(self.pc + 1, len(self.words)):
            a = Insn(self.words[j], self.addr + 4 * j)
            if a.op == 3 or (a.op == 0 and a.fn == 9):
                if r in ARGS and r in self.written | {4, 5, 6, 7}:
                    return True
                if r in CALLER_SAVED:
                    return False
            if a.op in (0x37,) and a.rs == SP:
                if a.rt == r:
                    return False
                continue
            if r in a.gpr_reads():
                return True
            if r in a.gpr_writes():
                return False
            if a.op == 0 and a.fn == 8:
                return r in a.gpr_reads() or (j + 1 < len(self.words) and r in Insn(self.words[j + 1], 0).gpr_reads())
        return False

    def new_var(self, v, ctype=None):
        name = f"p{self.nvars}"
        self.nvars += 1
        ctype = ctype or ("void *" if self.kind(v) != "s32" else "s32")
        self.emit({"k": "decl", "name": name, "ctype": ctype, "expr": v})
        for q, w in list(self.regs.items()):
            if w == v:
                self.regs[q] = ("var", name)
        return name

    def materialize(self, regs):
        """Loads held in these registers (and read later) become locals, declared here."""
        for r in sorted(regs):
            if not self.live(r):
                continue
            v = self.regs.get(r)
            if v is not None and has_load(v) and v[0] != "var":
                self.new_var(v)

    # -------------------------------------------------------- execution
    def proto(self, name, args):
        kinds = [self.kind(a) for a in args]
        for a in args:
            self.r(a)                                 # marks the call results it reads as used
        p = self.protos.setdefault(name, ["void", []])
        for j, k in enumerate(kinds):
            if j >= len(p[1]):
                p[1].append(k)
            elif p[1][j] != k:
                p[1][j] = "s32" if "s32" in (k, p[1][j]) else "const void *"

    def nargs(self):
        n = 0
        for i, a in enumerate(ARGS):
            if a in self.written:
                n = i + 1
        return n

    def after_call(self):
        self.fregs = {r: v for r, v in self.fregs.items() if r >= 20}
        self.fwritten = set()
        for r in list(self.regs):
            if r in CALLER_SAVED:
                del self.regs[r]
        self.written = set()

    def call(self, target, tail):
        name = symbols.symbol(target)
        if not re.fullmatch(r"[A-Za-z_]\w*", name):
            name = f"func_{target:08X}"
        args = [self.get(a) for a in ARGS[:self.nargs()]]
        nf = max((r - 11 for r in self.fwritten), default=0)
        args += [self.fregs[12 + j] for j in range(nf)]       # float arguments after the ints
        self.proto(name, args)
        rec = {"id": len(self.calls), "name": name, "args": args, "used": False, "tail": tail}
        self.calls.append(rec)
        if not tail:
            self.materialize({r for r in self.regs if r not in CALLER_SAVED})
        self.emit({"k": "call", "rec": rec})
        self.after_call()
        if not tail:
            self.regs[V0] = ("ret", rec["id"])

    def vcall(self, rs):
        """jalr through an old-ABI vtable entry {s16 delta; s16 index; fn}: fn(o + delta, ...)."""
        fn = self.get(rs)
        a0 = self.get(4)
        if not (fn[0] == "ld" and fn[2] == 4 and fn[3] == "void *"):
            raise GiveUp("jalr: not a vtable entry")
        e = fn[1]
        vt, slot = (e[1], e[2]) if e[0] == "add" else (e, 0)
        if not (vt[0] == "ld" and vt[3] == "void *"):
            raise GiveUp("jalr: not a vtable entry")
        obj, vp = vt[1], vt[2]
        if not (a0[0] == "sum" and a0[1] == obj and a0[2] == ("ld", e, 0, "short")):
            raise GiveUp("jalr: this adjustment")
        args = [self.get(a) for a in ARGS[1:self.nargs()]]
        while args and args[-1] == obj:
            args.pop()                                # the object kept in an argument register
        kinds = tuple(self.kind(a) for a in args)
        key = (vp, slot, kinds)
        if key not in self.vcalls:
            self.vcalls[key] = f"vcall_{len(self.vcalls)}"
        self.materialize({r for r in self.regs if r not in CALLER_SAVED})
        self.emit({"k": "vcall", "name": self.vcalls[key], "obj": obj, "args": args})
        self.after_call()

    def note_ptr(self, b):
        while b[0] == "add":
            b = b[1]
        if b[0][:3] == "arg" and b[0] != "arg0":
            self.ptr_args.add(int(b[0][3:]))

    def one(self, i):
        """One non-control instruction."""
        self.pc = i
        w = self.words[i]
        op, rs, rt, rd, fn = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, w & 63
        imm = w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if w == 0:
            return
        if op in (0x3F, 0x37) and rs == SP:         # sd/ld of saved registers
            if op == 0x37:
                self.regs.pop(rt, None)
            return
        if op == 0x09 and rs == SP and rt == SP:    # frame
            return
        if op in (0x39, 0x31) and rs == SP and rt >= 20:          # saved FPRs
            if op == 0x31:
                self.fregs.pop(rt, None)
            return
        if op == 0x11 and rs == 0x10 and fn == 6:                 # mov.s
            fs, fd = rd, (w >> 6) & 31
            if fs not in self.fregs:
                raise GiveUp("mov.s of an unset register")
            self.fregs[fd] = self.fregs[fs]
            if 12 <= fd < 20:
                self.fwritten.add(fd)
            return
        if op == 0x11 and rs == 4 and (w & 0x7FF) == 0:          # mtc1
            v = self.get(rt)
            if v[0] != "k":
                raise GiveUp("mtc1 of a non-constant")
            self.fregs[rd] = ("fk", v[1])
            if 12 <= rd < 20:
                self.fwritten.add(rd)
            return
        if op == 0x31:                                            # lwc1
            if rs == SP:
                raise GiveUp("stack load")
            b = self.get(rs)
            if b[0] == "add" and b[1][0] in ("arg0", "var"):
                b, simm = b[1], b[2] + simm
            self.fregs[rt] = ("ld", b, simm, "float")
            if 12 <= rt < 20:
                self.fwritten.add(rt)
            return
        if op == 0x39:                                            # swc1
            if rs == SP or rt not in self.fregs:
                raise GiveUp("float store")
            self.materialize(set(self.regs))
            b = self.get(rs)
            self.note_ptr(b)
            if b[0] == "add":
                b, simm = b[1], b[2] + simm
            self.emit({"k": "store", "t": "float", "base": b, "off": simm, "val": self.fregs[rt]})
            return
        if op == 0x0F:
            self.set(rt, ("k", imm << 16))
        elif op == 0x09:
            if rs == SP:
                raise GiveUp("stack local")
            v = self.get(rs)
            if rs == rt and v[0] == "var" and v[1] in self.loopvars:
                self.emit({"k": "upd", "name": v[1], "n": simm})
                for q, x in list(self.regs.items()):
                    if x == v and q != rs:
                        self.regs[q] = add(v, -simm)      # a copy keeps the old value
                return
            self.set(rt, add(v, simm))
        elif op == 0x0D:
            v = self.get(rs)
            if v[0] != "k":
                raise GiveUp("ori on non-constant")
            self.set(rt, ("k", v[1] | imm))
        elif op == 0x0C:
            self.set(rt, ("and", self.get(rs), imm))
        elif op == 0 and fn in (0x2D, 0x21, 0x25) and (rt == ZERO or rs == ZERO):
            self.set(rd, self.get(rs if rt == ZERO else rt))
        elif op == 0 and fn in (0x24, 0x25, 0x26, 0x23, 0x2F, 0x2A, 0x2B, 0x04, 0x06, 0x07):
            ops = {0x24: "&", 0x25: "|", 0x26: "^", 0x23: "-", 0x2F: "-", 0x2A: "<", 0x2B: "<u",
                   0x04: "<<", 0x06: ">>u", 0x07: ">>"}
            a, b = self.get(rs), self.get(rt)
            if fn in (0x04, 0x06, 0x07):                  # shifts by register: value in rt
                a, b = b, a
            self.set(rd, ("bin", ops[fn], a, b))
        elif op == 0 and fn in (0x00, 0x02, 0x03) and rd != 0:   # shifts by immediate
            sa = (w >> 6) & 31
            self.set(rd, ("bin", {0: "<<", 2: ">>u", 3: ">>"}[fn], self.get(rt), ("k", sa)))
        elif op in (0x0A, 0x0B):                          # slti / sltiu
            self.set(rt, ("bin", "<" if op == 0x0A else "<u", self.get(rs), ("k", simm & 0xFFFFFFFF)))
        elif op == 0x0E:                                  # xori
            self.set(rt, ("bin", "^", self.get(rs), ("k", imm)))
        elif op == 0 and fn in (0x2D, 0x21):
            a, b = self.get(rs), self.get(rt)
            if a[0] == "k" and not is_addr(a[1]):
                self.set(rd, add(b, a[1] - (1 << 32) if a[1] & 0x80000000 else a[1]))
            elif b[0] == "k" and not is_addr(b[1]):
                self.set(rd, add(a, b[1] - (1 << 32) if b[1] & 0x80000000 else b[1]))
            else:
                self.set(rd, ("sum", a, b))
        elif op in LOADS:
            if rs == SP:
                raise GiveUp("stack load")
            b = self.get(rs)
            self.note_ptr(b)
            if b[0] == "add" and b[1][0] in ("arg0", "var"):
                b, simm = b[1], b[2] + simm
            self.set(rt, ("ld", b, simm, LOADS[op]))
        elif op in STORES:
            if rs == SP:
                raise GiveUp("stack store")
            self.materialize(set(self.regs))
            b, v = self.get(rs), self.get(rt)
            self.note_ptr(b)
            if b[0] == "add":
                b, simm = b[1], b[2] + simm
            self.r(v)
            self.emit({"k": "store", "t": STORES[op], "base": b, "off": simm, "val": v})
        else:
            raise GiveUp(f"unsupported {match.disasm(w, self.addr + 4 * i)}")

    NEG = {"==": "!=", "!=": "==", "<": ">=", ">=": "<", "<=": ">", ">": "<="}

    def cond(self, i):
        """The condition under which the branch at i is taken, as data: (rel, a, b, None)."""
        w = self.words[i]
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        op = op & 0xF if op in (0x14, 0x15, 0x16, 0x17) else op
        if op in (4, 5):
            return ("==" if op == 4 else "!=", self.get(rs), self.get(rt), None)
        if op == 6:
            return ("<=", self.get(rs), ("k", 0), None)
        if op == 7:
            return (">", self.get(rs), ("k", 0), None)
        if op == 1 and rt in (0, 1, 2, 3):
            return ("<" if rt & 1 == 0 else ">=", self.get(rs), ("k", 0), None)
        raise GiveUp("unsupported branch")

    def cond_text(self, c, negate=True):
        rel, a, b, _ = c
        if negate:
            rel = self.NEG[rel]
        if b == ("k", 0):
            t = self.r(a)
            if a[0] in ("and", "sum"):
                t = f"({t})"
            return f"{t} {rel} 0"
        if b[0] == "k" and b[1] & 0x80000000 and self.kind(a) != "s32" and rel in ("==", "!="):
            n = (1 << 32) - b[1]                                     # this + off != 0
            return f"(char *){self.r(a)} + {n:#x} {rel} 0"
        return f"{self.r(a)} {rel} {self.r(b)}"

    def string_release(self, i):
        """The inlined basic_string destructor of a member: lw X,OFF(B); addiu Q,X,-0x10; lw Y,8(Q);
        addiu Y,Y,-1; bnez Y,L; sw Y,8(Q); ...jal func_005C11A8...jal func_00326798... L:
        -> str_release((Str *)(B + OFF)); returns L or None. Independent instructions the
        scheduler moved in between run first (e.g. a base class's vtable store)."""
        w0 = Insn(self.words[i], self.addr + 4 * i)
        if w0.op != 0x23 or w0.rs == SP:
            return None
        chain = [w0]
        others = []
        j = i + 1
        while j < len(self.words) and len(chain) < 5 and j < i + 12:
            a = Insn(self.words[j], self.addr + 4 * j)
            n = len(chain)
            if n == 1 and a.op == 0x09 and a.rs == w0.rt and a.simm == -0x10:
                chain.append(a)
            elif n == 2 and a.op == 0x23 and a.rs == chain[1].rt and a.imm == 8:
                chain.append(a)
            elif n == 3 and a.op == 0x09 and a.rs == chain[2].rt and a.rt == a.rs and a.simm == -1:
                chain.append(a)
            elif n == 4 and a.op == 0x05 and a.rs == chain[2].rt and a.rt == ZERO:
                chain.append(a)
                break
            else:
                regs = {c.rt for c in chain}
                if a.op in (2, 3) or (a.op == 0 and a.fn in (8, 9)) or a.op in (1, 4, 5, 6, 7, 0x14, 0x15):
                    return None
                if (a.gpr_reads() | a.gpr_writes()) & regs or w0.rs in a.gpr_writes():
                    return None
                others.append(j)
            j += 1
        if len(chain) != 5:
            return None
        sl = Insn(self.words[j + 1], 0)
        if not (sl.op == 0x2B and sl.imm == 8 and sl.rs == chain[1].rt):
            return None
        s = chain
        tgt = j + 1 + s[4].simm
        calls = [(w & 0x3FFFFFF) << 2 for w in self.words[j + 2:tgt] if w >> 26 == 3]
        if calls != [STR_ALLOC_NAME, STR_RELEASE_FN]:
            return None
        for k in others:
            self.one(k)
        b = self.get(s[0].rs)
        off = s[0].simm
        if b[0] == "add":
            b, off = b[1], b[2] + off
        self.pc = i
        self.materialize({r for r in self.regs if r not in CALLER_SAVED})
        self.r(add(b, off))
        self.emit({"k": "str", "expr": add(b, off)})
        self.str_release = True
        self.protos[f"func_{STR_ALLOC_NAME:08X}"] = ["S00659988 *", []]
        p = self.protos.setdefault(f"func_{STR_RELEASE_FN:08X}", ["void", []])
        p[1] = ["void *", "s32", "s32", "const char *"]
        for j in range(i, tgt):
            for r in Insn(self.words[j], 0).gpr_writes():
                self.regs.pop(r, None)
        self.after_call()
        return tgt

    def branch_target(self, i):
        w = self.words[i]
        imm = w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        return i + 1 + simm

    def is_cbranch(self, j):
        w = self.words[j]
        op = w >> 26
        if op == 1:
            return (w >> 16) & 31 in (0, 1, 2, 3)
        return op in (4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17) and not (op == 4 and (w >> 16) & 0x3FF == 0)

    def merge(self, saved):
        self.regs = {r: v for r, v in self.regs.items() if saved[0].get(r) == v}
        self.written = set()

    def run(self, start, end):
        """Execute [start, end); True when the path returned."""
        i = start
        while i < end:
            bottom = self.do_bottom(i, end)
            if bottom is not None:
                i = self.do_loop(i, bottom)
                continue
            nxt = self.string_release(i)
            if nxt is not None:
                i = nxt
                continue
            w = self.words[i]
            op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
            if op == 3:                                 # jal
                d = Insn(self.words[i + 1], 0)
                dv = self.regs.get(d.rs)
                if d.op == 0x09 and d.rs == d.rt and dv and dv[0] == "var" and dv[1] in self.loopvars:
                    self.pc = i + 1                     # p += n in the delay slot: after the call
                    self.call((w & 0x3FFFFFF) << 2, False)
                    self.regs[d.rs] = dv
                    self.one(i + 1)
                    i += 2
                    continue
                self.jal_delay = True
                self.one(i + 1)
                self.jal_delay = False
                self.pc = i + 1
                self.call((w & 0x3FFFFFF) << 2, False)
                i += 2
            elif op == 0 and (w & 63) == 9:             # jalr: virtual call
                self.jal_delay = True
                self.one(i + 1)
                self.jal_delay = False
                self.pc = i + 1
                self.vcall(rs)
                i += 2
            elif op == 2:                               # j: tail call
                self.one(i + 1)
                self.call((w & 0x3FFFFFF) << 2, True)
                return True
            elif op == 0 and (w & 63) == 8 and rs == RA:  # jr ra
                self.one(i + 1)
                v = self.regs.get(V0)
                self.returns.append(v)
                self.emit({"k": "ret", "val": v, "nested": self.indent > 1})
                return True
            elif self.is_cbranch(i):
                tgt = self.branch_target(i)
                if tgt <= i or tgt > len(self.words):
                    raise GiveUp("backward branch")
                likely = op in (0x14, 0x15, 0x16, 0x17) or op == 1 and (w >> 16) & 2
                join = tgt
                if likely:
                    # the delay slot is a copy of the instruction before the (moved) target
                    if self.words[tgt - 1] != self.words[i + 1]:
                        raise GiveUp("branch-likely delay slot is not the join's copy")
                    join = tgt - 1
                c = self.cond(i)                         # before the delay slot runs
                if not likely:
                    self.one(i + 1)
                bottom = None
                for j in range(join - 2, i + 1, -1):
                    if (self.is_cbranch(j) and i + 2 <= self.branch_target(j) <= i + 8
                            and not any(self.is_cbranch(q) or self.words[q] >> 26 in (2, 3)
                                        for q in range(i + 2, self.branch_target(j)))):
                        bottom = j
                        break
                saved = dict(self.regs), set(self.written)
                if bottom is not None:
                    i = self.loop(i, bottom, join, c, saved)
                    continue
                bw = self.words[join - 2] if join - 2 > i + 1 else None
                if bw is not None and bw >> 16 == 0x1000 and self.branch_target(join - 2) > join:
                    # if (c) { then } else { else }: the then-arm ends in `b` over the else-arm
                    end = self.branch_target(join - 2)
                    copy = self.words[join - 1] == self.words[end - 1] and self.words[join - 1] != 0
                    if copy:
                        end -= 1                         # the b's slot holds the join's first insn
                    self.emit({"k": "open", "kw": "if", "c": c})
                    self.indent += 1
                    ret1 = self.run(i + 2, join - 2)
                    if not ret1 and not copy:
                        self.one(join - 1)
                    self.indent -= 1
                    regs1 = (dict(self.regs), set(self.written))
                    self.emit({"k": "close"})
                    self.emit({"k": "open", "kw": "else"})
                    self.regs, self.written = dict(saved[0]), set(saved[1])
                    self.indent += 1
                    ret2 = self.run(join, end)
                    self.indent -= 1
                    self.emit({"k": "close"})
                    if ret1 and ret2:
                        return True
                    if ret1:
                        pass
                    elif ret2:
                        self.regs, self.written = regs1
                    else:
                        self.merge(regs1)
                    i = end
                    continue
                self.emit({"k": "open", "kw": "if", "c": c})
                self.indent += 1
                ret = self.run(i + 2, join)
                self.indent -= 1
                self.emit({"k": "close"})
                if ret:
                    self.regs, self.written = saved
                else:
                    self.merge(saved)
                i = join
            elif op in (1, 4, 6, 7, 0x14, 0x15, 0x16, 0x17):
                raise GiveUp("unsupported branch")
            else:
                self.one(i)
                i += 1
        return False

    def do_bottom(self, i, end):
        """A backward branch in (i, end) to i: a do-while loop starting here."""
        for j in range(i + 1, end):
            if self.is_cbranch(j) or self.words[j] >> 26 in (1, 6, 7):
                w = self.words[j]
                if w >> 26 == 1 and (w >> 16) & 31 not in (0, 1, 2, 3):
                    continue
                if self.branch_target(j) == i and not (w >> 26 in (0x14, 0x15, 0x16, 0x17)):
                    return j
        return None

    def do_loop(self, i, bottom):
        """`do { body } while (c);`: body [i, bottom), the branch's delay slot ends every pass."""
        written = set()
        for j in range(i, bottom + 2):
            written |= Insn(self.words[j], 0).gpr_writes()
        self.pc = i - 1
        info = {"vars": {}}
        for r in sorted(written):
            v = self.regs.get(r)
            if v is not None and r not in CALLER_SAVED and v[0] != "var":
                name = f"p{self.nvars}"
                self.loopvars.add(name)
                self.new_var(v, "s32" if self.kind(v) == "s32" else "char *")
                self.body[-1][1]["loop"] = info
                info["vars"][name] = v
            elif v is not None and v[0] == "var":
                self.loopvars.add(v[1])
        saved = dict(self.regs), set(self.written)
        self.emit({"k": "open", "kw": "do", "loop": info})
        self.indent += 1
        if self.run(i, bottom):
            raise GiveUp("loop: return")
        c = self.cond(bottom)
        self.one(bottom + 1)
        self.indent -= 1
        self.emit({"k": "close_do", "c": c, "loop": info})
        # registers at the top of the loop must be what the loop leaves in them
        for r, v in saved[0].items():
            if r in self.regs and self.regs[r] != v and r not in CALLER_SAVED:
                raise GiveUp("loop: register not carried")
        return bottom + 2

    def loop(self, i, bottom, join, c, saved):
        """`while (c) { body }`: entry test at i, body [i+2, bottom), backward test at bottom."""
        bw = self.words[bottom]
        bop = bw >> 26
        b_likely = bop in (0x14, 0x15)
        bt = self.branch_target(bottom)
        body = i + 2
        if b_likely:
            # the backward branch-likely's delay slot is a copy of the body's first instruction
            # (nops may follow it before the branch target)
            body = None
            for k in range(bt - 1, i + 1, -1):
                if self.words[k] == self.words[bottom + 1]:
                    body = k
                    break
                if self.words[k] != 0:
                    break
            if body is None:
                raise GiveUp("loop: delay slot")
        else:
            body = bt
        for j in range(i + 2, body):                 # loop-invariant code before the body
            self.one(j)
        written = set()
        for j in range(body, bottom + 2):
            written |= Insn(self.words[j], 0).gpr_writes()
        self.pc = i + 1
        for r in sorted(written):
            v = self.regs.get(r)
            if v is not None and r not in CALLER_SAVED:
                if v[0] == "var":
                    self.loopvars.add(v[1])
                    continue
                name = f"p{self.nvars}"
                self.loopvars.add(name)
                self.new_var(v, "char *")
                c = tuple(("var", name) if x == v else x for x in c)   # the test reads the variable
        self.emit({"k": "open", "kw": "while", "c": c})
        self.indent += 1
        if self.run(body, bottom):
            raise GiveUp("loop: return")
        if not b_likely:
            self.one(bottom + 1)
        self.indent -= 1
        self.emit({"k": "close"})
        self.merge((dict(self.regs) if False else saved[0], saved[1]))
        # the loop exit: code before the join, only on the path that ran the loop (a reload of a
        # register the loop clobbered)
        self.run(bottom + 2, join)
        return join

    # -------------------------------------------------------- output
    def groups(self):
        """Member helpers by knob: [(start, end, offset)] over self.body (top level only)."""
        out = []
        body = self.body
        k = 0
        while k < len(body):
            ind, x = body[k]
            got = None
            if ("member" in self.knobs or "member_wide" in self.knobs) and x["k"] == "str" and k + 1 < len(body):
                nx = body[k + 1][1]
                if (nx["k"] == "call" and len(nx["rec"]["args"]) == 2 and nx["rec"]["args"][1] == ("k", 2)
                        and nx["rec"]["args"][0][0] == "add" and nx["rec"]["args"][0][1] == ("arg0",)
                        and x["expr"][0] == "add" and x["expr"][1] == ("arg0",)
                        and 0 <= x["expr"][2] - nx["rec"]["args"][0][2]
                        < (0x100 if "member_wide" in self.knobs else 0x20)):
                    got = (k, k + 2, nx["rec"]["args"][0][2])
            if "node" in self.knobs and x["k"] not in ("close", "close_do"):
                # a run of statements (blocks included) touching only one 16-byte member and
                # ending in its release: the member's inline destructor (an STL tree/list clear)
                lo = hi = None
                depth = 0
                end = None
                for j in range(k, len(body)):
                    y = body[j][1]
                    if y["k"] == "open":
                        depth += 1
                    elif y["k"] in ("close", "close_do"):
                        depth -= 1
                        if depth < 0:
                            break
                    offs = [o for e in item_exprs(y) for o in refs(e)]
                    if None in offs:
                        break
                    for o in offs:
                        lo = o if lo is None else min(lo, o)
                        hi = o if hi is None else max(hi, o)
                    if lo is not None and hi - lo >= 0x10:
                        break
                    if (depth == 0 and y["k"] == "call" and not y["rec"]["tail"]
                            and y["rec"]["name"] == f"func_{STR_RELEASE_FN:08X}"):
                        end = j + 1
                        break
                if end and lo is not None and end - k >= 2:
                    got = (k, end, lo)
            if "array" in self.knobs and x["k"] == "open" and x["kw"] == "if" and not got:
                # `if (&arr != 0) { destroy the elements }` and the rest of the member holding the
                # array: that member's inline destructor
                a, b = x["c"][1], x["c"][2]
                if a[0] == "add" and a[1] == ("arg0",) and b[0] == "k" and b[1] & 0x80000000:
                    X = a[2]
                    depth = 0
                    ok = True
                    for j in range(k, len(body)):
                        y = body[j][1]
                        depth += y["k"] == "open"
                        depth -= y["k"] in ("close", "close_do")
                        if any(o is None or o < X for e in item_exprs(y) for o in refs(e)):
                            ok = False
                        if depth == 0:
                            break
                    e = j + 1
                    while ok and e < len(body) and body[e][1]["k"] == "call" and not body[e][1]["rec"]["tail"]:
                        offs = [o for ex in item_exprs(body[e][1]) for o in refs(ex)]
                        if not offs or any(o is None or o < X for o in offs):
                            break
                        e += 1
                    if ok:
                        got = (k, e, X)
            if "block" in self.knobs and x["k"] == "open" and not got:
                # a block touching only one 16-byte member (an inline clear() of an STL container)
                depth = 0
                offs = []
                for j in range(k, len(body)):
                    y = body[j][1]
                    depth += y["k"] == "open"
                    depth -= y["k"] in ("close", "close_do")
                    offs += [o for e in item_exprs(y) for o in refs(e)]
                    if depth == 0:
                        break
                if offs and None not in offs and max(offs) - min(offs) < 0x10 and len(set(offs)) > 1:
                    got = (k, j + 1, min(offs))
            if "reset" in self.knobs and x["k"] == "open" and x["kw"] == "if" and not got:
                # `if (p) delete p; p = 0;` on one pointer member: an inline reset helper
                depth = 0
                j = k
                offs = set()
                while j < len(body):
                    y = body[j][1]
                    depth += y["k"] == "open"
                    depth -= y["k"] in ("close", "close_do")
                    offs |= {o for e in item_exprs(y) for o in refs(e)}
                    if depth == 0:
                        break
                    j += 1
                if j + 1 < len(body) and len(offs) == 1 and None not in offs:
                    y = body[j + 1][1]
                    X = offs.pop()
                    if (y["k"] == "store" and y["base"] == ("arg0",) and y["off"] == X
                            and y["val"] == ("k", 0)):
                        got = (k, j + 2, X)
            if got:
                out.append(got)
                k = got[1]
            else:
                k += 1
        return out

    def for_loop(self, info):
        """With the `for` knob: (count, {pointer var: stride}) when the do-while counts a s32 down
        from n-1 to 0 (gcc's reversal of `for (i = 0; i < n; i++)`) and steps each pointer once."""
        if "for" not in self.knobs:
            return None
        if "for" in info:
            return info["for"]
        info["for"] = None
        k0 = next(k for k, (ind, x) in enumerate(self.body) if x.get("loop") is info and x["k"] == "open")
        k1 = next(k for k, (ind, x) in enumerate(self.body) if x.get("loop") is info and x["k"] == "close_do")
        ind0 = self.body[k0][0]
        upds = {}
        for ind, x in self.body[k0 + 1:k1]:
            if x["k"] == "upd":
                if ind != ind0 + 1 or x["name"] in upds:
                    return None
                upds[x["name"]] = x["n"]
        counters = [n for n, v in info["vars"].items() if v[0] == "k" and not is_addr(v[1])]
        if len(counters) != 1 or set(upds) != set(info["vars"]):
            return None
        c = counters[0]
        cond = self.body[k1][1]["c"]
        if upds[c] != -1 or cond != (">=", ("var", c), ("k", 0), None):
            return None
        info["for"] = (info["vars"][c][1] + 1, {n: st for n, st in upds.items() if n != c})
        info["for"][1][c] = 0
        return info["for"]

    def item_text(self, x):
        k = x["k"]
        if k == "decl" and x.get("loop") is not None and self.for_loop(x["loop"]):
            return None
        if k == "upd" and x["name"] in self.forvars:
            init, stride, bump = self.forvars[x["name"]]
            self.forvars[x["name"]] = (init, stride, bump + x["n"])
            return None
        if k == "open":
            if x["kw"] == "else":
                return "else {"
            if x["kw"] == "do":
                f = self.for_loop(x["loop"])
                if f:
                    count, strides = f
                    for name, st in strides.items():
                        self.forvars[name] = (x["loop"]["vars"][name], st, 0)
                    return f"for (s32 i = 0; i < {count}; i++) {{"
                return "do {"
            return f"{x['kw']} ({self.cond_text(x['c'])}) {{"
        if k == "close_do":
            if self.for_loop(x["loop"]):
                for name in x["loop"]["vars"]:
                    self.forvars.pop(name, None)
                return "}"
            return f"}} while ({self.cond_text(x['c'], False)});"
        if k == "close":
            return "}"
        if k == "ret":
            if self.ret_type == "void":
                return "return;" if x.get("nested") else None
            v = x["val"]
            return f"return {self.r(v)};"
        if k == "decl":
            sep = "" if x["ctype"].endswith("*") else " "
            return f"{x['ctype']}{sep}{x['name']} = {self.r(x['expr'])};"
        if k == "upd":
            return f"{x['name']} -= {-x['n']:#x};" if x["n"] < 0 else f"{x['name']} += {x['n']:#x};"
        if k == "store":
            t = "void **" if x["t"] == "void *" else x["t"] + " *"
            val = self.r(x["val"])
            if t == "void **" and self.kind(x["val"]) == "s32" and val != "0x0":
                val = f"(void *)({val})"
            return f"*({t})({self.at(x['base'], x['off'])}) = {val};"
        if k == "str":
            return f"str_release((Str *)({self.r(x['expr'])}));"
        if k == "vcall":
            args = [f"(char *){self.r(x['obj'])}"] + [self.r(a) for a in x["args"]]
            return f"{x['name']}({', '.join(args)});"
        rec = x["rec"]
        kinds = self.protos[rec["name"]][1]
        args = []
        for a, kd in zip(rec["args"], kinds):
            t = self.r(a)
            if kd == "s32" and self.kind(a) != "s32":
                t = f"(s32)({t})"
            args.append(t)
        call = f'{rec["name"]}({", ".join(args)})'
        if rec["tail"]:
            if self.ret_type != "void":
                return f"return {call};"
            return f"return {call};" if self.protos[rec["name"]][0] == "void" else f"{call}; return;"
        if rec["used"]:
            return f'void *r{rec["id"]} = {call};'
        return f"{call};"

    def store_runs(self):
        """Runs of consecutive top-level stores of non-loaded values (their source order is free:
        the scheduler's choice depends on it)."""
        runs = []
        k = 0
        while k < len(self.body):
            j = k
            while (j < len(self.body) and self.body[j][1]["k"] == "store" and self.body[j][0] == self.body[k][0]
                   and not has_load(self.body[j][1]["val"]) and not has_load(self.body[j][1]["base"])):
                j += 1
            if j - k >= 2:
                runs.append((k, j))
            k = max(j, k + 1)
        return runs

    def build(self, perms=None):
        self.regs = {r: (f"arg{n}",) for n, r in enumerate(ARGS)}
        self.fregs = {12 + n: (f"farg{n}",) for n in range(8)}
        self.fwritten = set()
        self.written = {4}
        self.jal_delay = False
        self.str_release = False
        if not self.run(0, len(self.words)):
            raise GiveUp("falls off the end")
        for (k, j), order in (perms or {}).items():
            self.body[k:j] = [self.body[k + q] for q in order]
        # a value is returned only when every return leaves this or a call result in v0
        self.ret_type = "void"
        returning = ("arg0", "ret") if "retcall" in self.knobs else ("arg0",)
        if self.returns and all(v is not None and (v[0] in returning or v[0] == "add" and v[1] == ("arg0",))
                                for v in self.returns):
            self.ret_type = "void *"
            for c in self.calls:
                if c["tail"]:
                    c["used"] = True
        name = symbols.symbol(self.addr)
        if not re.fullmatch(r"[A-Za-z_]\w*", name):
            name = f"func_{self.addr:08X}"
        groups = self.groups()
        if any(k in self.knobs for k in ("member", "member_wide", "node", "reset", "block", "array")) and not groups:
            raise GiveUp("variant does not apply")
        # render everything once so call results in use are known before the prototypes
        helpers = []
        lines = []
        k = 0
        gi = 0
        while k < len(self.body):
            if gi < len(groups) and groups[gi][0] == k:
                s, e, X = groups[gi]
                h = f"member_{gi}"
                self.subst = (X, "m")
                hl = [f"static inline void {h}(char *m) {{"]
                base = self.body[s][0]
                for ind, x in self.body[s:e]:
                    t = self.item_text(x)
                    if t is not None:
                        hl.append("    " * (ind - base + 1) + t)
                hl.append("}")
                self.subst = None
                helpers.append("\n".join(hl))
                lines.append("    " * base + f"{h}((char *)arg0 + {X:#x});")
                k = e
                gi += 1
                continue
            ind, x = self.body[k]
            t = self.item_text(x)
            if t is not None:
                lines.append("    " * ind + t)
            k += 1
        for c in self.calls:
            if c["used"] or "vret" in self.knobs and not c["name"].startswith("func_00326798"):
                self.protos[c["name"]][0] = "void *"
        # second pass with the final prototypes (casts, return types)
        helpers, lines = [], []
        k = gi = 0
        while k < len(self.body):
            if gi < len(groups) and groups[gi][0] == k:
                s, e, X = groups[gi]
                h = f"member_{gi}"
                self.subst = (X, "m")
                hl = [f"static inline void {h}(char *m) {{"]
                base = self.body[s][0]
                for ind, x in self.body[s:e]:
                    t = self.item_text(x)
                    if t is not None:
                        hl.append("    " * (ind - base + 1) + t)
                hl.append("}")
                self.subst = None
                helpers.append("\n".join(hl))
                lines.append("    " * base + f"{h}((char *)arg0 + {X:#x});")
                k = e
                gi += 1
                continue
            ind, x = self.body[k]
            t = self.item_text(x)
            if t is not None:
                lines.append("    " * ind + t)
            k += 1
        out = ["typedef int s32;", ""]
        if self.str_release:
            out.append(STR_HELPER)
        for n, d in sorted(self.datas.items()):
            out.append(d)
        for n, (ret, kinds) in self.protos.items():
            if n == name:
                raise GiveUp("recursive")
            sep = "" if ret.endswith("*") else " "
            out.append(f'extern "C" {ret}{sep}{n}({", ".join(kinds) if kinds else "void"});')
        if self.str_release:
            out.append(STR_RELEASE)
        for (vp, slot, kinds), h in self.vcalls.items():
            params = ", ".join(["void *"] + list(kinds))
            names = "".join(f", {kd}{'' if kd.endswith('*') else ' '}a{j}" for j, kd in enumerate(kinds))
            pass_ = "".join(f", a{j}" for j in range(len(kinds)))
            out.append(f"struct VEntry_{h} {{ short delta; short index; void (*fn)({params}); }};\n"
                       f"static inline void {h}(char *o{names}) {{\n"
                       f"    VEntry_{h} *e = (VEntry_{h} *)(*(char **)(o + {vp:#x}) + {slot:#x});\n"
                       f"    e->fn(o + e->delta{pass_});\n}}")
        out += helpers
        out.append("")
        n = max(self.used_args) + 1
        params = ", ".join(["void *arg0"] + [f"{self.kind((f'arg{j}',))}{'' if self.kind((f'arg{j}',)).endswith('*') else ' '}arg{j}"
                                             for j in range(1, n)]
                           + [f"float farg{j}" for j in range(max(self.used_fargs, default=-1) + 1)])
        sep = "" if self.ret_type.endswith("*") else " "
        out.append(f'extern "C" {self.ret_type}{sep}{name}({params}) {{')
        out += lines
        out.append("}")
        return "\n".join(out) + "\n"

def judge(addr, text):
    os.makedirs(OUT, exist_ok=True)
    path = os.path.join(OUT, f"{addr:08x}.cpp")
    open(path, "w", newline="\n").write(text)
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    return res.returncode == 0 and "MATCH" in res.stdout, res.stdout + res.stderr


VARIANTS = [(), ("member",), ("node",), ("member", "node"), ("reset",), ("reset", "member", "node"),
            ("block", "node"), ("block", "node", "member"), ("block",), ("member_wide",),
            ("member_wide", "node"), ("array",), ("array", "member"), ("array", "node", "member"), ("for",), ("retcall",), ("vret",)]


def solve(addr):
    """(ok, source or reason, judge output): the variants in order, the first MATCH wins."""
    best = None
    seen = set()
    for knobs in VARIANTS:
        try:
            src = Func(addr, knobs).build()
        except GiveUp as e:
            if best is None:
                return None, str(e), ""
            continue
        except (KeyError, IndexError, SystemExit) as e:
            if best is None:
                return None, f"internal {type(e).__name__}: {e}", ""
            continue
        if src in seen:
            continue
        seen.add(src)
        ok, out = judge(addr, src)
        if ok:
            return ok, src, out
        m = re.search(r"(\d+) of (\d+) instructions differ", out)
        score = int(m.group(1)) if m else 10 ** 6
        if best is None or score < best[0]:
            best = (score, src, out, knobs)
    if best is None:
        return False, "", ""
    if addr >= 0x5547E8:                           # Sony's library region: its own compiler first
        src = "/* compiler: ee-gcc2.96-no-strict-aliasing */\n" + best[1]
        ok, out = judge(addr, src)
        if ok:
            return ok, src, out
    # then the order of independent stores, run by run (greedy): all orders of up to 4 stores,
    # single moves for longer runs
    knobs = best[3]
    if best[0] > 12:                               # far off: not a scheduling question
        return False, best[1], best[2]
    f = Func(addr, knobs)
    f.build()
    perms = {}
    budget = 40
    for k, j in f.store_runs():
        n = j - k
        if n <= 4:
            cands = list(itertools.permutations(range(n)))[1:]
        else:
            cands = []
            for a in range(n):
                for b in range(n):
                    if a != b:
                        o = list(range(n))
                        o.insert(b, o.pop(a))
                        cands.append(tuple(o))
        for order in cands:
            budget -= 1
            if budget < 0:
                break
            trial = dict(perms)
            trial[(k, j)] = order
            try:
                src = Func(addr, knobs).build(trial)
            except GiveUp:
                continue
            if src in seen:
                continue
            seen.add(src)
            ok, out = judge(addr, src)
            if ok:
                return ok, src, out
            m = re.search(r"(\d+) of (\d+) instructions differ", out)
            score = int(m.group(1)) if m else 10 ** 6
            if score < best[0]:
                best = (score, src, out, knobs)
                perms = trial
    return False, best[1], best[2]


def is_deleting_dtor(addr):
    """Ends in `if (flag & 1) operator delete` (a j to func_00326798)."""
    try:
        text_addr, text = match.load_text()
        words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
    except SystemExit:
        return False
    return any(w >> 26 == 2 and (w & 0x3FFFFFF) << 2 == 0x00326798 for w in words)


def all_structors():
    out = []
    for line in open(os.path.join(ROOT, "config", "symbol_addrs.txt")):
        m = re.match(r"(\w+__structor_\d+) = 0x([0-9A-Fa-f]+);", line)
        if m:
            a = int(m.group(2), 16)
            if not project.source_for(a):
                out.append(a)
    return sorted(set(out))


def targets(names):
    out = set()
    classes = json.load(open(os.path.join(ROOT, "config", "classes.json")))
    for c in classes.values():
        for vt in c.get("vtables", []):
            if vt.get("methods"):
                out.add(vt["methods"][0])
    if names:
        for line in open(os.path.join(ROOT, "config", "symbol_addrs.txt")):
            m = re.match(r"(\w+__structor_\d+) = 0x([0-9A-Fa-f]+);", line)
            if m:
                out.add(int(m.group(2), 16))
    return sorted(a for a in out if not project.source_for(a) and is_deleting_dtor(a))


def cmd_scan(names, structors=False, part=None):
    todo = all_structors() if structors else targets(names)
    rng = next((a.split("=", 1)[1] for a in sys.argv if a.startswith("--range=")), None)
    if rng:                                        # LO-HI (hex addresses): a stable batch
        lo, hi = (int(x, 16) for x in rng.split("-"))
        todo = [a for a in todo if lo <= a < hi]
    if part:                                       # K/N: the K-th of N slices (foreground batches)
        k, n = map(int, part.split("/"))
        todo = todo[(k - 1) * len(todo) // n:k * len(todo) // n]
    ok = fail = gave = 0
    reasons = {}
    for a in todo:
        res, src, out = solve(a)
        if res:
            path = os.path.join(ROOT, layout.path_for(a))
            os.makedirs(os.path.dirname(path), exist_ok=True)
            open(path, "w", newline="\n").write(src)
            ok += 1
            print(f"{a:08x} MATCH -> {layout.path_for(a)}", flush=True)
        elif res is None:
            gave += 1
            reasons[src] = reasons.get(src, 0) + 1
            print(f"{a:08x} give up: {src}", flush=True)
        else:
            fail += 1
            first = out.splitlines()[0] if out else ""
            print(f"{a:08x} differs: {first}", flush=True)
    print(f"{len(todo)} candidates: {ok} MATCH, {fail} differ, {gave} give up")


def main():
    if len(sys.argv) >= 3 and sys.argv[1] == "try":
        a = int(sys.argv[2], 16)
        res, src, out = solve(a)
        print(src)
        print(out if "--show" in sys.argv or res else out.splitlines()[0] if out else "")
    elif len(sys.argv) >= 2 and sys.argv[1] == "scan":
        part = next((a.split("=", 1)[1] for a in sys.argv if a.startswith("--part=")), None)
        cmd_scan("--names" in sys.argv, "--structors" in sys.argv, part)
    else:
        print(__doc__)


if __name__ == "__main__":
    main()
