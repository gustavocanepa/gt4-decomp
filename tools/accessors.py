#!/usr/bin/env python3
"""Script-bound accessors (the MListBox / MCarGarage / MCarData getter and setter families) written
from the assembly, no model: a tiny symbolic executor for straight-line code plus templates for the
idioms every member shares (the handle constructor and destructor, the virtual-call argument
conversion, the result-handle assignment, the string build and release), emitted statement by
statement in the original's instruction order so that pointer locals (`p1 = buf1;`), temporaries
and call arguments land where the original compiled them. The struct layout is read from the loads
and stores themselves (offset, width, signedness) and written as casts, so no struct declaration
has to be guessed.

What is recognised: a prologue/epilogue with up to four saved registers and 16-byte stack slots,
one `if (argc ...)` split into a setter and a getter path (or a single path), loads/stores/ALU
ops, direct calls with up to eight integer and four float arguments, the idioms above. Anything
else (a loop, a backward or unstructured branch, a jump register, an unknown opcode) gives up with
a reason, counted by `scan`. Other forward branches become `if (cond) { ... } [else { ... }]`
(do_if: nested, delay slots and branch-likely handled, registers merged at the join).

    accessors.py try ADDR [--show]       one function: source, verdict (and the diff)
    accessors.py scan [-jN] [--families 1,2,...] [--min-size N] [--max-size N] [--all|--inventory]
                                          every unmatched member of the chosen families (default:
                                          every family of build/families.json; --inventory: every
                                          unmatched function in the size range); src/ on MATCH
"""
import json
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

import autoloop
import match
import families

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "accessors")

REG = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]
SP, RA, ZERO, V0, V1, A0, F0, F12 = 29, 31, 0, 2, 3, 4, 0, 12
STRING_REP = 0x00659FA8          # the empty string's Rep (string build idiom)
STR_RETAIN, STR_RELEASE_FN = 0x005C2560, 0x00326798
STRLEN, STR_ASSIGN, STR_ALLOC_NAME = 0x0057F260, 0x005C2630, 0x005C11A8
RETAIN, RELEASE = 0x003285A8, 0x003285F8   # handle refcount
LOAD_TYPES = {0x23: "s32", 0x21: "s16", 0x25: "u16", 0x20: "s8", 0x24: "u8", 0x37: "s64", 0x31: "f32"}
STORE_TYPES = {0x2B: "s32", 0x29: "s16", 0x28: "s8", 0x3F: "s64", 0x39: "f32"}
C_TYPES = {"s32": "s32", "s16": "s16", "u16": "u16", "s8": "s8", "u8": "u8", "s64": "s64", "f32": "f32",
           "ptr": "char *", "bool": "s32"}

HEADER = """typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};
"""


class GiveUp(Exception):
    pass


class Val:
    """An expression with its C type; `call` marks a side effect (must not be reordered)."""

    def __init__(self, text, typ="s32", call=False):
        self.text, self.typ, self.call = text, typ, call

    def c(self, typ=None):
        if typ is None or (typ == self.typ and typ != "ptr"):
            return self.text
        if typ == "ptr":
            if self.text.startswith("(char *)"):
                return self.text
            return f"(char *){self.text}" if re.fullmatch(r"&?\w+(\[\d+\])?", self.text) else f"(char *)({self.text})"
        return f"({C_TYPES[typ]}){self.text}"


class Insn:
    def __init__(self, word, addr):
        self.w, self.addr = word, addr
        self.op = word >> 26
        self.rs = (word >> 21) & 31
        self.rt = (word >> 16) & 31
        self.rd = (word >> 11) & 31
        self.sa = (word >> 6) & 31
        self.fn = word & 0x3F
        self.imm = word & 0xFFFF
        self.simm = self.imm - 0x10000 if self.imm & 0x8000 else self.imm
        self.ft, self.fs, self.fd = self.rt, self.rd, self.sa

    def is_nop(self):
        return self.w == 0

    def gpr_reads(self):
        op = self.op
        if self.is_nop():
            return set()
        if op in (2, 3):
            return set()
        if op == 0:
            if self.fn in (0, 2, 3):                 # shifts by immediate
                return {self.rt}
            return {self.rs, self.rt}
        if op == 0x11:
            return {self.rt} if self.rs == 4 else set()   # mtc1
        if op == 0x0F:
            return set()
        if op in STORE_TYPES or op in (0x04, 0x05, 0x14, 0x15):
            return {self.rs, self.rt}
        return {self.rs}

    def gpr_writes(self):
        op = self.op
        if self.is_nop() or op in (2, 3) or op in STORE_TYPES or op in (0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17, 1):
            return set()
        if op == 0:
            return {self.rd}
        if op == 0x11:
            return {self.rt} if self.rs == 0 else set()      # mfc1
        return {self.rt}

    def fpr_reads(self):
        if self.op == 0x39:
            return {self.ft}
        if self.op == 0x11 and self.rs in (0x10, 0x14):
            return {self.fs} if self.fn in (6, 0x24, 0x20, 7, 5, 4) else {self.fs, self.ft}
        if self.op == 0x11 and self.rs == 0:
            return {self.fs}
        return set()

    def fpr_writes(self):
        if self.op == 0x31:
            return {self.ft}
        if self.op == 0x11 and self.rs == 4:
            return {self.fs}
        if self.op == 0x11 and self.rs in (0x10, 0x14):
            return {self.fd}
        return set()

    def target(self):
        return self.addr + 4 + self.simm * 4

    def __repr__(self):
        return match.disasm(self.w, self.addr)


class Func:
    def __init__(self, addr, knobs=()):
        self.knobs = set(knobs)
        self.addr = addr
        text_addr, text = match.load_text()
        words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
        while words and words[-1] == 0:
            words.pop()
        self.ins = [Insn(w, addr + 4 * i) for i, w in enumerate(words)]
        self.n = len(self.ins)
        self.slots = {}           # sp offset -> name
        self.slot_types = {}      # sp offset -> "s32[4]" | "Str"
        self.frame = 0
        self.locals = {}          # name -> C type text
        self.protos = {}          # callee name -> (ret, [arg types])
        self.helpers = {}         # helper name -> text
        self.used_syms = set()
        self.body = []            # (indent, text) lines
        self.args_used = 0        # how many of a0..a3 the function reads
        self.regs = {}            # reg -> Val
        self.fregs = {}
        self.written = set()      # int regs written since the last call
        self.fwritten = []
        self.first_call = True
        self.ntemp = 0
        self.indent = 1
        self.prologue_end = 0
        self.epilogue_start = self.n
        self.ret_type = "void"

    # ---------------------------------------------------------------- analysis of the frame
    def scan_frame(self):
        ins = self.ins
        if not (ins[0].op == 0x09 and ins[0].rs == SP and ins[0].rt == SP and ins[0].simm < 0):
            raise GiveUp("no frame")
        self.frame = -ins[0].simm
        # epilogue: ld restores + jr ra + addiu sp
        if not (ins[-2].w == 0x03E00008 and ins[-1].op == 0x09 and ins[-1].rt == SP):
            raise GiveUp("no plain epilogue")
        e = self.n - 2
        while e > 0 and ins[e - 1].op == 0x37 and ins[e - 1].rs == SP:
            e -= 1
        self.epilogue_start = e
        self.saved = {}
        for i in ins:
            if i.op == 0x3F and i.rs == SP:              # sd reg, off(sp)
                self.saved[i.rt] = i.imm
        if RA not in self.saved:
            raise GiveUp("leaf function")
        lowest_save = min(self.saved.values())
        # stack slots: 16-byte regions below the saves, named in ascending order
        for off in range(0, lowest_save, 16):
            self.slots[off] = f"buf{off // 16}"
            self.slot_types[off] = "s32[4]"
        self.locals_order = []

    # ---------------------------------------------------------------- helpers
    def slot_of(self, off):
        base = off - off % 16
        if base not in self.slots:
            raise GiveUp(f"stack access outside the slots: {off:#x}")
        return base, off - base

    def slot_addr(self, off):
        """The C expression for `sp + off`."""
        base, rem = self.slot_of(off)
        name = self.slots[base]
        if self.slot_types[base] == "Str":
            if rem:
                raise GiveUp("address inside a string slot")
            return Val(f"&{name}", "ptr")
        if rem:
            return Val(f"(char *){name} + {rem:#x}", "ptr")
        return Val(name, "ptr")

    def temp(self, typ):
        self.ntemp += 1
        name = f"t{self.ntemp}"
        self.locals[name] = C_TYPES[typ]
        return name

    def emit(self, text):
        self.body.append((self.indent, text))

    def flush_calls(self, keep=None):
        """Materialise pending call results before a statement is emitted (statement order)."""
        keep = keep if isinstance(keep, set) else {keep}
        for table in (self.regs, self.fregs):
            for r, v in list(table.items()):
                if v.call and (r if table is self.regs else 32 + r) not in keep:
                    t = self.temp(v.typ)
                    self.emit(f"{t} = {v.text};")
                    nv = Val(t, v.typ)
                    for k, old in list(table.items()):
                        if old is v:
                            table[k] = nv

    def get(self, r):
        if r == ZERO:
            return Val("0", "s32")
        if r == SP:
            return self.slot_addr(0)
        if r not in self.regs:
            if 4 <= r <= 7 and self.first_call:
                self.args_used = max(self.args_used, r - 3)
                return Val(f"arg{r - 4}", ARG_TYPES[r - 4])
            raise GiveUp(f"read of unset register ${REG[r]}")
        return self.regs[r]

    def set(self, r, v):
        if r == ZERO:
            return
        self.consume(v)
        self.regs[r] = v
        self.written.add(r)

    def consume(self, v):
        """An expression built from a call result takes the call with it: the result register is
        dropped so the call is never evaluated twice."""
        for table in (self.regs, self.fregs):
            for k, old in list(table.items()):
                if old.call and old is not v and old.text in v.text:
                    del table[k]
                    v.call = True
                elif old is v and v.call:
                    del table[k]

    def setf(self, r, v):
        self.consume(v)
        self.fregs[r] = v
        if r not in self.fwritten:
            self.fwritten.append(r)

    def local_for(self, r, v):
        """A value moved into a saved register becomes a named local assigned here."""
        name = f"v_{REG[r]}"
        ctype = C_TYPES[v.typ]
        if name in self.locals and self.locals[name] != ctype:
            name = f"{name}_{v.typ}"
        if name not in self.locals:
            self.locals[name] = ctype
        self.flush_calls(keep={k for k, old in self.regs.items() if old is v})
        self.emit(f"{name} = {v.c('ptr') if v.typ == 'ptr' else v.c()};")
        if re.search(r"0x[0-9a-f]{5,}", v.text) and v.typ == "ptr":
            self.big_sum_locals.add(name)
        if v.call:
            for k, old in list(self.regs.items()):
                if old is v:
                    del self.regs[k]
        self.regs[r] = Val(name, v.typ)
        self.written.add(r)

    def mem(self, base, off, typ):
        """Load/store target expression."""
        b = self.get(base)
        if base == SP or (b.text.startswith("buf") and b.typ == "ptr" and re.fullmatch(r"buf\d+", b.text)):
            soff = off if base == SP else off + 0
            if base == SP:
                sbase, rem = self.slot_of(soff)
                name = self.slots[sbase]
            else:
                name, rem = b.text, off
            if self.slot_types.get(self.slot_off(name)) == "Str":
                if rem == 0 and typ == "s32":
                    return f"{name}.p"
                raise GiveUp("typed access into a string slot")
            if typ == "s32" and rem % 4 == 0:
                return f"{name}[{rem // 4}]"
            return f"*({C_TYPES[typ]} *)((char *){name} + {rem:#x})"
        if re.fullmatch(r"p_s\d", b.text) and typ == "s32" and off % 4 == 0 and b.typ == "ptr":
            tgt = self.pointer_targets.get(b.text)
            if tgt is not None and self.slot_types.get(tgt) == "Str":
                if off == 0:
                    return f"{b.text}->p"
                raise GiveUp("typed access through a string pointer")
            return f"{b.text}[{off // 4}]" if off else f"*{b.text}"
        if off == 0:
            return f"*({C_TYPES[typ]} *){b.c('ptr')}"
        return f"*({C_TYPES[typ]} *)({b.c('ptr')} {'+' if off > 0 else '-'} {abs(off):#x})"

    def slot_off(self, name):
        for off, nm in self.slots.items():
            if nm == name:
                return off
        return None

    def call_args(self):
        """Argument expressions set for the call about to be made (a0.. then a4..a7, floats)."""
        ints = []
        top = -1
        for k, r in enumerate(range(4, 12)):
            if r in self.written:
                top = k
        for k, r in enumerate(range(4, 12)):
            if k > top:
                break
            if r in self.written or (self.first_call and r <= 7):
                ints.append(self.get(r))
            else:
                raise GiveUp(f"argument ${REG[r]} not set")
        floats = [self.fregs[r] for r in self.fwritten if r in self.fregs]
        return ints, floats

    def after_call(self, ret, use=None):
        self.written = set()
        self.fwritten = []
        self.first_call = False
        for r in list(self.regs):
            if r < 16 or r > 23:
                del self.regs[r]
        self.fregs = {}
        if use == "v0":
            self.regs[V0] = ret
        elif use == "f0":
            self.fregs[F0] = ret
        elif ret.call:
            self.emit(f"{ret.text};")

    def result_use(self, i):
        """Which result register of the call at i is read before being overwritten: "v0", "f0" or None."""
        k = i + 2
        while k < self.n:
            a = self.ins[k]
            if V0 in a.gpr_reads():
                return "v0"
            if F0 in a.fpr_reads():
                return "f0"
            if V0 in a.gpr_writes() or F0 in a.fpr_writes():
                return None
            if a.op in (2, 3) or a.op == 0 and a.fn == 9:
                # the delay slot still runs before the call
                b = self.ins[k + 1]
                if V0 in b.gpr_reads():
                    return "v0"
                if F0 in b.fpr_reads():
                    return "f0"
                return None
            if a.op in (0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17, 1) and not (a.rs == ZERO and a.rt == ZERO):
                b = self.ins[k + 1]
                return "v0" if V0 in b.gpr_reads() else None
            k += 1
        return None

    def do_call(self, name, ints, floats, i):
        argt = ["void *" if v.typ == "ptr" else C_TYPES[v.typ] for v in ints] + ["f32"] * len(floats)
        text = f"{name}({', '.join(v.c() for v in ints + floats)})"
        use = self.result_use(i)
        ret = {"v0": "s32", "f0": "f32", None: "void"}[use]
        if (use is None and "ctor_ptr" in self.knobs and ints and re.fullmatch(r"buf\d+|p_s\d|&s\d", ints[0].text)
                and not (len(ints) == 2 and ints[1].text == "0x2")):
            ret = "void *"
        if name not in self.protos:
            self.protos[name] = [ret, argt]
        elif self.protos[name][0] == "void" and ret != "void":
            self.protos[name][0] = ret
        self.after_call(Val(text, ret if use else "s32", True), use)

    # ---------------------------------------------------------------- idioms
    def try_vcall(self, i):
        """lw vt,4(obj); addiu e,vt,SLOT; lh d,0(e); lw fn,4(e); jalr fn; addu aN,obj,d"""
        ins = self.ins
        a = ins[i]
        if not (a.op == 0x23 and a.imm == 4) or i + 5 >= self.n:
            return None
        seq = ins[i:i + 6]
        if not (seq[1].op == 0x09 and seq[1].rs == a.rt and seq[2].op == 0x21 and seq[2].rs == seq[1].rt
                and seq[2].imm == 0 and seq[3].op == 0x23 and seq[3].rs == seq[1].rt and seq[3].imm == 4
                and seq[4].op == 0 and seq[4].fn == 9 and seq[4].rs == seq[3].rt
                and seq[5].op == 0 and seq[5].fn == 0x21 and seq[5].rs == a.rs and seq[5].rt == seq[2].rt):
            return None
        slot = seq[1].simm
        obj = self.get(a.rs)
        dest = seq[5].rd
        if dest == A0:
            # plain virtual call: result in v0/f0, the type is decided by the first use
            name = f"vcall_{slot:x}"
            self.flush_calls()
            text = f"{name}({obj.c('ptr')})"
            use = self.result_use(i + 4)
            ret = {"v0": "s32", "f0": "f32", None: "void"}[use]
            self.after_call(Val(text, ret if use else "s32", True), use)
            self.vcall_slots[name] = (slot, ret)
        elif dest == 5:
            # hidden-pointer struct return: fn(ret, obj + delta)
            name = f"vcall_{slot:x}_ret"
            ret = self.get(A0)
            self.flush_calls()
            self.emit(f"{name}({ret.c('ptr')}, {obj.c('ptr')});")
            self.after_call(Val("0", "s32"))
            self.vcall_slots[name] = (slot, "ret")
        else:
            return None
        return i + 6

    def try_assign(self, i):
        """if (arg0 != pw) { newVal = *pw; if (newVal) retain; oldVal = *arg0; if (oldVal) release; *arg0 = newVal; }"""
        ins = self.ins
        a = ins[i]
        if not (a.op in (0x04, 0x14) and i + 12 < self.n):
            return None
        # optional `daddu a0, pw, zero` in the branch slot, then the fixed shape
        start = 2 if ins[i + 1].op == 0 and ins[i + 1].fn == 0x2D and ins[i + 1].rd == A0 else 1
        if i + start + 11 > self.n:
            return None
        seq = ins[i:i + start + 11]
        shape = [(0x23, 0), (0x14, 0), (0x23, 0), (3, RETAIN), (0, 0x2D), (0x23, 0), (0x14, 0), (0x2B, 0),
                 (3, RELEASE), (None, 0), (0x2B, 0)]
        for k, (op, extra) in enumerate(shape):
            s = seq[k + start]
            if op is None:
                if not s.is_nop():
                    return None
            elif s.op != op or (op == 3 and (s.w & 0x3FFFFFF) << 2 != extra):
                return None
        x, y = self.get(a.rs), self.get(a.rt)
        if x.text == "arg0":
            arg, pw = x, y
        elif y.text == "arg0":
            arg, pw = y, x
        else:
            return None
        self.flush_calls()
        self.locals.setdefault("newVal", "s32")
        self.locals.setdefault("oldVal", "s32")
        slot = pw.text if re.fullmatch(r"buf\d+", pw.text) else None
        deref = f"{pw.text}[0]" if slot else f"*{pw.text}"
        self.used_syms.update({RETAIN, RELEASE})
        self.protos.setdefault(f"func_{RETAIN:08X}", ["void", ["s32"]])
        self.protos.setdefault(f"func_{RELEASE:08X}", ["void", ["s32"]])
        self.emit(f"if (arg0 != {pw.c()}) {{")
        self.indent += 1
        self.emit(f"newVal = {deref};")
        self.emit("if (newVal != 0) {")
        self.emit(f"    func_{RETAIN:08X}(newVal);")
        self.emit("}")
        self.emit("oldVal = *arg0;")
        self.emit("if (oldVal != 0) {")
        self.emit(f"    func_{RELEASE:08X}(oldVal);")
        self.emit("}")
        self.emit("*arg0 = newVal;")
        self.indent -= 1
        self.emit("}")
        self.after_call(Val("0", "s32"))
        # the saved register that held newVal keeps it (the original's $s0 is dead afterwards)
        self.regs[seq[start].rt] = Val("newVal", "s32")
        return i + start + 11

    def try_string_build(self, i):
        """branch on D_00659FA8.sel: ps->p = (sel ? func_5C2560(&rep) : (char *)(rep + 1), rep->ref++).
        The idiom's own words are skipped; the block is emitted where the built pointer is stored
        (that store may sit in the delay slot of the next call), the other words run in order."""
        ins = self.ins
        a = ins[i]
        if a.op not in (0x04, 0x14) or a.rt != ZERO:
            return None
        sel = self.regs.get(a.rs)
        if sel is None or sel.text != f"D_{STRING_REP:08X}.sel":
            return None
        rep_reg = sel.base
        d_reg = ref_reg = None
        skip = {i}
        for k in range(i + 1, min(i + 16, self.n)):
            b = ins[k]
            if b.op == 0x09 and b.rs == rep_reg and b.imm == 0x10:
                d_reg = b.rt
            if b.op == 0x23 and b.rs == rep_reg and b.imm == 8:
                ref_reg = b.rt
        if d_reg is None or ref_reg is None:
            return None
        store = None
        for k in range(i + 1, min(i + 18, self.n)):
            b = ins[k]
            if b.is_nop() or (b.op == 0x04 and b.rs == ZERO and b.rt == ZERO):
                skip.add(k)
            elif b.op == 3 and (b.w & 0x3FFFFFF) << 2 == STR_RETAIN:
                skip.add(k)
            elif b.op == 0 and b.fn == 0x2D and b.rt == ZERO and (b.rs == rep_reg and b.rd == A0 or b.rs == V0 and b.rd == d_reg):
                skip.add(k)
            elif b.op in (0x23, 0x2B) and b.rs == rep_reg and b.imm == 8:
                skip.add(k)
            elif b.op == 0x09 and (b.rs == rep_reg and b.imm == 0x10 or b.rt == ref_reg and b.rs == ref_reg and b.imm == 1):
                skip.add(k)
            elif b.op == 0x2B and b.rt == d_reg and b.imm == 0 and b.rs != SP:
                skip.add(k)
                store = k
                break
            elif b.op == 0x2B and b.rt == d_reg and b.rs == SP:
                skip.add(k)
                store = k
                break
        if store is None:
            return None
        self.skip |= skip
        self.deferred[store] = (self.emit_string_build, ins[store])
        # the selector and the Rep pointer are the idiom's own, never call arguments
        for r in (a.rs, rep_reg):
            self.written.discard(r)
            self.regs.pop(r, None)
        for r, v in list(self.regs.items()):
            if getattr(v, "lui", None) == STRING_REP & 0xFFFF0000:
                self.written.discard(r)
                del self.regs[r]
        self.used_syms.add(STRING_REP)
        self.protos.setdefault(f"func_{STR_RETAIN:08X}", ["char *", ["Rep *"]])
        return i + 1

    def emit_string_build(self, st):
        if st.rs == SP:
            base, rem = self.slot_of(st.simm)
            target = f"{self.slots[base]}.p"
        else:
            target = f"{self.get(st.rs).text}->p"
        self.flush_calls()
        self.emit("{")
        self.emit(f"    Rep *r = &D_{STRING_REP:08X};")
        self.emit("    char *d;")
        self.emit("    if (r->sel != 0) {")
        self.emit(f"        d = func_{STR_RETAIN:08X}(r);")
        self.emit("    } else {")
        self.emit("        d = (char *)(r + 1);")
        self.emit("        r->ref++;")
        self.emit("    }")
        self.emit(f"    {target} = d;")
        self.emit("}")

    def try_string_release(self, i):
        """lw X,0(P); addiu Q,X,-0x10; lw Y,8(Q); addiu Y,Y,-1; bnez Y; sw Y,8(Q); jal name; lw Z,4(Q);
        lw a3,0(v0); daddu a0,Q; addiu Z,Z,0x10; addiu a2,4; jal release; daddu a1,Z"""
        ins = self.ins
        if i + 13 >= self.n:
            return None
        s = ins[i:i + 14]
        ok = (s[0].op == 0x23 and s[0].imm == 0 and s[1].op == 0x09 and s[1].rs == s[0].rt and s[1].simm == -0x10
              and s[2].op == 0x23 and s[2].rs == s[1].rt and s[2].imm == 8 and s[3].op == 0x09 and s[3].simm == -1
              and s[4].op == 0x05 and s[4].rt == ZERO and s[5].op == 0x2B and s[5].imm == 8
              and s[6].op == 3 and (s[6].w & 0x3FFFFFF) << 2 == STR_ALLOC_NAME
              and s[12].op == 3 and (s[12].w & 0x3FFFFFF) << 2 == STR_RELEASE_FN)
        if not ok:
            return None
        if s[0].rs == SP:
            base, rem = self.slot_of(s[0].simm)
            if self.slot_types[base] != "Str":
                return None
            p = Val(f"&{self.slots[base]}", "ptr")
        else:
            p = self.get(s[0].rs)
            if p.text.startswith("buf"):
                return None
        self.flush_calls()
        self.helpers["str_release"] = True
        self.used_syms.update({STR_ALLOC_NAME, STR_RELEASE_FN})
        self.protos.setdefault(f"func_{STR_ALLOC_NAME:08X}", ["struct S00659988 *", []])
        self.protos.setdefault(f"func_{STR_RELEASE_FN:08X}", ["void", ["void *", "s32", "s32", "const char *"]])
        self.emit(f"str_release({p.text});")
        self.after_call(Val("0", "s32"))
        return i + 14

    def try_c_str(self, i):
        """len = *(s32 *)(s->p - 0x10); if (len == 0) c = D_EMPTY; else { s->p[len] = 0; c = s->p; }"""
        return None

    # ---------------------------------------------------------------- generic execution
    def exec_index(self, k):
        if k in self.deferred:
            fn, arg = self.deferred.pop(k)
            fn(arg)
            return
        if k in self.skip:
            return
        self.exec_one(self.ins[k])

    def step(self, i):
        """Execute instruction i (and its delay slot when it is a call/branch); returns next index."""
        ins = self.ins
        a = ins[i]
        if i in self.skip or i in self.deferred:
            self.exec_index(i)
            return i + 1
        for idiom in (self.try_string_release, self.try_vcall, self.try_assign, self.try_string_build):
            nxt = idiom(i)
            if nxt is not None:
                return nxt
        if a.op == 3:                                        # jal
            self.exec_index(i + 1)
            target = (a.w & 0x3FFFFFF) << 2
            name = f"func_{target:08X}"
            self.used_syms.add(target)
            # pending call results that are not arguments of this call go to temporaries first
            self.flush_calls(keep=set(self.written) | {32 + r for r in self.fwritten})
            ints, floats = self.call_args()
            self.do_call(name, ints, floats, i)
            return i + 2
        if a.op in (0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17) or (a.op == 1):
            return self.do_if(i)
        if i == self.epilogue_start - 1 and self.is_ret_move(i):
            self.emit_return(a.rs)
            return i + 1
        if a.op == 0 and a.fn in (8, 9):
            raise GiveUp(f"jump register at {a.addr:#x}")
        if a.op == 2:
            raise GiveUp("tail jump")
        self.exec_one(a)
        return i + 1

    def exec_one(self, a):
        op = a.op
        if a.is_nop():
            return
        if op == 0x3F and a.rs == SP and a.rt in self.saved:      # sd save
            return
        if op == 0x37 and a.rs == SP and a.rt in self.saved:      # ld restore
            return
        if op == 0x0F:                                             # lui
            self.set(a.rt, Val(f"{a.imm << 16:#x}", "s32"))
            self.regs[a.rt].lui = a.imm << 16
            return
        if op == 0x09:                                             # addiu
            if a.rs == SP:
                if a.rt == SP:
                    return
                v = self.slot_addr(a.simm)
                if 16 <= a.rt <= 23:
                    self.pointer_local(a.rt, a.simm)
                else:
                    self.set(a.rt, v)
                return
            if a.rs == ZERO:
                self.set_maybe_local(a.rt, Val(f"{a.simm:#x}" if a.simm >= 0 else f"-{-a.simm:#x}", "s32"))
                return
            src = self.get(a.rs)
            lui = getattr(src, "lui", None)
            if lui is not None:
                addr = lui + a.simm
                self.used_syms.add(addr)
                v = Val(f"&D_{addr:08X}", "ptr")
                v.sym = addr
                self.set_maybe_local(a.rt, v)
                return
            if a.simm == 0:
                self.set_maybe_local(a.rt, src)
                return
            if src.typ == "ptr":
                v = Val(f"{src.c('ptr')} {'+' if a.simm > 0 else '-'} {abs(a.simm):#x}", "ptr")
            else:
                v = Val(f"{src.c()} {'+' if a.simm > 0 else '-'} {abs(a.simm):#x}", "s32")
            self.set_maybe_local(a.rt, v)
            return
        if op == 0x0D:                                             # ori
            src = self.get(a.rs)
            lui = getattr(src, "lui", None)
            if lui is not None:
                self.set_maybe_local(a.rt, Val(f"{lui | a.imm:#x}", "s32"))
            else:
                self.set_maybe_local(a.rt, Val(f"({src.c()} | {a.imm:#x})", "s32"))
            return
        if op == 0x0C:                                             # andi
            self.set_maybe_local(a.rt, Val(f"({self.get(a.rs).c()} & {a.imm:#x})", "s32"))
            return
        if op == 0x0E:                                             # xori
            src = self.get(a.rs)
            if a.imm == 1 and src.typ == "bool":
                self.set_maybe_local(a.rt, Val(f"!{src.text}", "bool"))
            else:
                self.set_maybe_local(a.rt, Val(f"({src.c()} ^ {a.imm:#x})", "s32"))
            return
        if op in (0x0A, 0x0B):                                     # slti / sltiu
            src = self.get(a.rs)
            cmp = "<" if op == 0x0A else "<"
            t = "s32" if op == 0x0A else "u32"
            self.set_maybe_local(a.rt, Val(f"({src.c('s32') if op == 0x0A else '(unsigned)' + src.c('s32')} < {a.simm:#x})", "bool"))
            return
        if op in LOAD_TYPES:
            typ = LOAD_TYPES[op]
            base = self.get(a.rs)
            lui = getattr(base, "lui", None)
            if lui is None and getattr(base, "sym", None) is not None:
                lui = base.sym
            if lui is not None:
                addr = lui + a.simm
                self.used_syms.add(addr)
                v = Val(f"D_{addr:08X}", typ)
                if addr == STRING_REP + 0xC:
                    v = Val(f"D_{STRING_REP:08X}.sel", "s32")
                    v.base = a.rs
                    self.used_syms.add(STRING_REP)
                self.globals[addr] = typ
            else:
                v = Val(self.mem(a.rs, a.simm, typ), typ)
            if op == 0x31:
                self.setf(a.ft, v)
            else:
                if "ptr_locals" in self.knobs and typ == "s32" and 16 <= a.rt <= 23:
                    v = Val(v.text, "ptr")
                self.set_maybe_local(a.rt, v)
            return
        if op in STORE_TYPES:
            typ = STORE_TYPES[op]
            base = self.get(a.rs)
            lui = getattr(base, "lui", None)
            if op == 0x39:
                v = self.fregs.get(a.ft)
                if v is None:
                    raise GiveUp("store of an unset float register")
            else:
                v = self.get(a.rt)
            self.flush_calls(keep=None if "store_temp" in self.knobs or op == 0x39 else a.rt)
            v = self.fregs.get(a.ft) if op == 0x39 else self.get(a.rt)
            if lui is not None:
                addr = lui + a.simm
                self.used_syms.add(addr)
                self.globals[addr] = typ
                dst = f"D_{addr:08X}"
            else:
                base_v = self.get(a.rs)
                m = re.fullmatch(r"(.*) \+ (0x[0-9a-f]+)", base_v.text) if base_v.typ == "ptr" else None
                if m and int(m.group(2), 16) > 0x7FFF or base_v.text in self.big_sum_locals:
                    helper = f"store_{typ}_{a.simm:x}"
                    self.helpers[helper] = (f"static inline void {helper}(char *p, {C_TYPES[typ]} v) {{\n"
                                            f"    *({C_TYPES[typ]} *)(p + {a.simm:#x}) = v;\n}}")
                    self.emit(f"{helper}({base_v.c('ptr')}, {v.c(typ) if v.typ != 'bool' else v.text});")
                    return
                dst = self.mem(a.rs, a.simm, typ)
            self.emit(f"{dst} = {v.c(typ) if v.typ != 'bool' else v.text};")
            return
        if op == 0:
            fn = a.fn
            if fn == 0x2D and a.rt == ZERO:                        # daddu rd, rs, zero (move)
                if a.rs == SP:
                    v = self.slot_addr(0)
                    if 16 <= a.rd <= 23:
                        self.pointer_local(a.rd, 0)
                        return
                else:
                    v = self.get(a.rs)
                self.set_maybe_local(a.rd, v)
                return
            if fn == 0x2D and a.rs == ZERO:
                self.set_maybe_local(a.rd, Val("0", "s32"))
                return
            if fn == 0x2B and a.rs == ZERO:                        # sltu rd, zero, rt  -> rt != 0
                src = self.get(a.rt)
                if re.search(r"& 0x[0-9a-f]+\)$", src.text):
                    # a masked flag tested as a call argument: the mask goes to a temporary first
                    # (`(x & 2) != 0` inline compiles to sra/andi instead of andi/sltu)
                    t = self.temp("s32")
                    self.flush_calls()
                    self.emit(f"{t} = {src.text};")
                    src = Val(t, "s32")
                self.set_maybe_local(a.rd, Val(f"{src.c()} != 0", "bool"))
                return
            if fn in (0x21, 0x2D, 0x23, 0x2F, 0x24, 0x25, 0x26, 0x2A, 0x2B):
                x, y = self.get(a.rs), self.get(a.rt)
                sym = {0x21: "+", 0x2D: "+", 0x23: "-", 0x2F: "-", 0x24: "&", 0x25: "|", 0x26: "^", 0x2A: "<", 0x2B: "<"}[fn]
                if fn in (0x21, 0x2D) and (x.typ == "ptr" or y.typ == "ptr"):
                    p, q = (x, y) if x.typ == "ptr" else (y, x)
                    self.set_maybe_local(a.rd, Val(f"{p.c('ptr')} + {q.c('s32')}", "ptr"))
                else:
                    self.set_maybe_local(a.rd, Val(f"({x.c('s32')} {sym} {y.c('s32')})", "bool" if fn in (0x2A, 0x2B) else "s32"))
                return
            if fn in (0, 2, 3):                                    # sll srl sra
                src = self.get(a.rt)
                if fn == 0 and a.sa == 0:
                    self.set_maybe_local(a.rd, Val(src.c("s32"), "s32"))
                    return
                sym = "<<" if fn == 0 else ">>"
                cast = "(unsigned)" if fn == 2 else ""
                self.set_maybe_local(a.rd, Val(f"({cast}{src.c('s32')} {sym} {a.sa})", "s32"))
                return
            raise GiveUp(f"unsupported special at {a.addr:#x}: {a}")
        if op == 0x11:                                             # COP1
            fmt = a.rs
            if fmt == 4:                                           # mtc1
                self.setf(a.fs, Val(self.get(a.rt).c("s32"), "s32"))
                return
            if fmt == 0:                                           # mfc1
                self.set_maybe_local(a.rt, Val(self.fregs[a.fs].c("f32"), "f32"))
                return
            if fmt == 0x10:                                        # .s arithmetic
                if a.fn == 6:                                      # mov.s
                    self.setf(a.fd, self.fregs[a.fs])
                    return
                if a.fn == 0x24:                                   # cvt.w.s
                    self.setf(a.fd, Val(f"(s32){self.fregs[a.fs].c('f32')}", "s32"))
                    return
                if a.fn in (0, 1, 2, 3):
                    sym = "+-*/"[a.fn]
                    x, y = self.fregs[a.fs], self.fregs[a.ft]
                    self.setf(a.fd, Val(f"({x.c('f32')} {sym} {y.c('f32')})", "f32"))
                    return
            if fmt == 0x14 and a.fn == 0x20:                       # cvt.s.w
                self.setf(a.fd, Val(f"(f32){self.fregs[a.fs].c('s32')}", "f32"))
                return
        raise GiveUp(f"unsupported at {a.addr:#x}: {a}")

    def set_maybe_local(self, r, v):
        if 16 <= r <= 23 and not re.fullmatch(r"arg\d", v.text):
            self.local_for(r, v)
        else:
            self.set(r, v)

    def pointer_local(self, r, off):
        base, rem = self.slot_of(off)
        if rem:
            raise GiveUp("pointer local inside a slot")
        name = f"p_{REG[r]}"
        self.pointer_targets[name] = base
        ctype = "Str *" if self.slot_types[base] == "Str" else "s32 *"
        self.locals[name] = ctype
        self.flush_calls()
        self.emit(f"{name} = {self.slot_addr(off).text};")
        self.regs[r] = Val(name, "ptr")
        self.written.add(r)

    # ---------------------------------------------------------------- structure
    def pre_scan(self):
        """Slot types: a slot whose address is the base of the string build's store is a Str."""
        ptr = {}
        for k, a in enumerate(self.ins):
            if a.op == 0x09 and a.rs == SP and a.rt != SP:
                ptr[a.rt] = a.simm
            elif a.op == 0 and a.fn == 0x2D and a.rs == SP and a.rt == ZERO:
                ptr[a.rd] = 0
            elif a.op == 3 and (a.w & 0x3FFFFFF) << 2 == STR_ASSIGN:
                # a0 of the string assign is the Str
                for j in range(k - 1, max(k - 8, 0), -1):
                    b = self.ins[j]
                    if b.op == 0 and b.fn == 0x2D and b.rd == A0 and b.rt == ZERO and b.rs in ptr:
                        self.slot_types[ptr[b.rs] - ptr[b.rs] % 16] = "Str"
                        break
                    if b.op == 0x09 and b.rt == A0 and b.rs == SP:
                        self.slot_types[b.simm - b.simm % 16] = "Str"
                        break
        for k, a in enumerate(self.ins):
            # release idiom: lw X,0(P); addiu Q,X,-0x10; lw Y,8(Q); addiu Y,Y,-1; bnez Y
            if (a.op == 0x23 and a.imm == 0 and k + 4 < self.n and self.ins[k + 1].op == 0x09
                    and self.ins[k + 1].simm == -0x10 and self.ins[k + 1].rs == a.rt
                    and self.ins[k + 2].op == 0x23 and self.ins[k + 2].imm == 8
                    and self.ins[k + 3].op == 0x09 and self.ins[k + 3].simm == -1 and self.ins[k + 4].op == 0x05):
                if a.rs == SP:
                    self.slot_types[a.simm - a.simm % 16] = "Str"
                elif a.rs in ptr:
                    self.slot_types[ptr[a.rs] - ptr[a.rs] % 16] = "Str"
        for off, t in self.slot_types.items():
            if t == "Str":
                self.slots[off] = f"s{off // 16}"

    def run_region(self, start, end):
        outer = self.region_end
        self.region_end = end
        i = start
        while i < end:
            i = self.step(i)
        if i != end:
            raise GiveUp(f"region overran at {self.ins[end].addr:#x}")
        self.region_end = outer
        if end == self.epilogue_start and outer is None and self.ret_type != "void" and not self.dead:
            # a path that reaches the epilogue without its own return: v0 as the branch left it
            if V0 not in self.regs:
                raise GiveUp("return value unknown on one path")
            self.emit_return_val(self.regs[V0])

    def is_ret_move(self, k):
        a = self.ins[k]
        return a.op == 0 and a.fn == 0x2D and a.rd == V0 and a.rt == ZERO and k not in self.skip

    def emit_return(self, rs):
        self.emit_return_val(self.get(rs))

    def emit_return_val(self, v):
        self.flush_calls(keep={k for k, old in self.regs.items() if old is v})
        rt = "void *" if v.typ == "ptr" else C_TYPES[v.typ]
        if self.ret_type not in ("void", rt):
            raise GiveUp("return types differ between paths")
        self.ret_type = rt
        self.emit(f"return {v.c()};")
        self.dead = True

    # ---------------------------------------------------------------- one `if` (with or without else)
    def state(self):
        return (dict(self.regs), dict(self.fregs), set(self.written), list(self.fwritten), self.first_call,
                self.dead)

    def restore(self, st):
        self.regs, self.fregs = dict(st[0]), dict(st[1])
        self.written, self.fwritten = set(st[2]), list(st[3])
        self.first_call, self.dead = st[4], st[5]

    def merge(self, x, y):
        """The join: a register keeps its value only when both paths agree (a dead path, one that
        returned, does not count)."""
        if x[5]:
            return self.restore(y)
        if y[5]:
            return self.restore(x)
        self.regs = {k: v for k, v in x[0].items() if k in y[0] and y[0][k].text == v.text and not v.call}
        self.fregs = {k: v for k, v in x[1].items() if k in y[1] and y[1][k].text == v.text and not v.call}
        self.written = x[2] & y[2] & set(self.regs)
        self.fwritten = [r for r in x[3] if r in y[3] and r in self.fregs]
        self.first_call = x[4] and y[4]
        self.dead = False

    def cond_text(self, a, x, y):
        """The C condition under which the fall-through (the `then` arm) runs."""
        op = a.op - 0x10 if a.op in (0x14, 0x15, 0x16, 0x17) else a.op
        if op in (4, 5) and a.rt == ZERO:
            if x.typ == "bool":
                return x.text if op == 4 else f"!({x.text})"
            return f"{x.c()} {'!=' if op == 4 else '=='} 0"
        if op in (4, 5):
            t = "ptr" if "ptr" in (x.typ, y.typ) else None
            return f"{x.c(t)} {'!=' if op == 4 else '=='} {y.c(t)}"
        if op == 6:
            return f"{x.c('s32')} > 0"
        if op == 7:
            return f"{x.c('s32')} <= 0"
        if op == 1 and a.rt in (0, 2):
            return f"{x.c('s32')} >= 0"
        if op == 1 and a.rt in (1, 3):
            return f"{x.c('s32')} < 0"
        raise GiveUp(f"branch kind at {a.addr:#x}: {a}")

    def do_if(self, i):
        """`if (cond) { block } [else { block }]` then the join: arms are regions (nested ifs recurse)."""
        ins = self.ins
        a = ins[i]
        likely = a.op in (0x14, 0x15, 0x16, 0x17) or (a.op == 1 and a.rt in (2, 3))
        if a.op in (4, 0x14) and a.rs == ZERO and a.rt == ZERO:
            raise GiveUp(f"branch at {a.addr:#x}: {a}")
        t = (a.target() - self.addr) // 4
        end = self.region_end if self.region_end is not None else self.epilogue_start
        if not (i + 2 <= t <= end):
            raise GiveUp(f"branch at {a.addr:#x}: {a}")
        x = self.get(a.rs)
        y = self.get(a.rt) if a.op in (4, 5, 0x14, 0x15) else Val("0")
        self.flush_calls(keep={k for k, v in self.regs.items() if v is x or v is y})
        for k, v in list(self.regs.items()):
            if (v is x or v is y) and v.call:
                del self.regs[k]
        else_first = None
        if likely:
            if t - 1 >= i + 2 and ins[t - 1].w == ins[i + 1].w:
                t -= 1                       # the delay slot is a copy of the target's first insn
            elif not ins[i + 1].is_nop():
                else_first = i + 1           # executed only when taken: the else arm's first insn
        else:
            n0 = len(self.body)
            self.exec_index(i + 1)
            if len(self.body) > n0 and (x.call or y.call):
                for v in [w for w in (x, y) if w.call]:
                    tmp = self.temp(v.typ)
                    self.body.insert(n0, (self.indent, f"{tmp} = {v.text};"))
                    if v is x:
                        x = Val(tmp, v.typ)
                    else:
                        y = Val(tmp, v.typ)
        cond = self.cond_text(a, x, y)
        # if/else: the then arm ends with `b join`
        then_end, then_extra, else_rng, join = t, None, None, t
        if t - 2 >= i + 2 and ins[t - 2].op == 4 and ins[t - 2].rs == ZERO and ins[t - 2].rt == ZERO:
            jn = (ins[t - 2].target() - self.addr) // 4
            if t < jn <= end:
                then_end, join = t - 2, jn
                d = t - 1
                if not ins[d].is_nop():
                    if jn - 1 >= t and ins[jn - 1].w == ins[d].w:
                        join = jn - 1                    # delay slot = copy of the join's first insn
                    else:
                        then_extra = d
                else_rng = (t, join)
        if else_first is not None and else_rng is None:
            else_rng = (t, t)
        pre = self.state()
        self.emit(f"if ({cond}) {{")
        self.indent += 1
        n_then = len(self.body)
        self.run_region(i + 2, then_end)
        if then_extra is not None:
            if join == self.epilogue_start and self.is_ret_move(then_extra):
                self.emit_return(ins[then_extra].rs)
            elif not (ins[then_extra].op == 0x37 and ins[then_extra].rs == SP):
                self.exec_index(then_extra)
        if len(self.body) == n_then:
            raise GiveUp(f"empty then arm at {a.addr:#x}")
        self.indent -= 1
        st_then = self.state()
        st_else = pre
        if else_rng is not None:
            self.restore(pre)
            self.emit("} else {")
            self.indent += 1
            n_else = len(self.body)
            if else_first is not None:
                self.exec_index(else_first)
            self.run_region(*else_rng)
            self.indent -= 1
            if len(self.body) == n_else:
                self.body[-1] = (self.indent, "}")       # nothing visible: no else
            else:
                self.emit("}")
            st_else = self.state()
        else:
            self.emit("}")
        self.merge(st_then, st_else)
        return join

    def reset_regs(self, keep):
        """Entering the second arm: only the prologue's registers are known."""
        self.regs = dict(keep[0])
        self.fregs = {}
        self.written = set(keep[1])
        self.fwritten = []
        self.first_call = keep[2]
        self.dead = False

    def build(self):
        self.scan_frame()
        self.pointer_targets = {}
        self.globals = {}
        self.vcall_slots = {}
        self.skip = set()
        self.deferred = {}
        self.big_sum_locals = set()
        self.dead = False
        self.region_end = None
        self.pre_scan()
        ins = self.ins
        # prologue up to the first branch (if any) on a2
        split = None
        for k in range(self.epilogue_start):
            a = ins[k]
            if a.op in (0x04, 0x05, 0x06, 0x07, 0x14, 0x15) and (a.rs == 6 or a.rt == 6):
                split = k
                break
            if a.op == 3:
                break
        if split is None:
            self.run_region(0, self.epilogue_start)
        else:
            self.run_region(0, split)
            br = ins[split]
            self.exec_one(ins[split + 1]) if not (ins[split + 1].op == 0x37) else None
            saved = (dict(self.regs), set(self.written), self.first_call)
            target = (br.target() - self.addr) // 4
            tested = self.regs.get(6)
            if br.op == 0x06 and br.rs == 6:                         # blez a2 -> if (arg2 > 0) else
                cond = "arg2 > 0"
            elif tested is not None and tested.typ == "bool" and br.rt == ZERO and br.op in (0x04, 0x05):
                m = re.fullmatch(r"\((arg2) < (0x[0-9a-f]+)\)", tested.text)
                if not m:
                    raise GiveUp(f"argc branch {br}")
                cond = f"arg2 >= {m.group(2)}" if br.op == 0x05 else f"arg2 < {m.group(2)}"
                self.written.discard(6)
                self.regs.pop(6, None)
                saved = (dict(self.regs), set(self.written), self.first_call)
            elif br.op == 0x05 and br.rs == 6 and br.rt == ZERO:     # bnez a2
                cond = "arg2 == 0"
            elif br.op == 0x04 and br.rs == 6 and br.rt == ZERO:     # beqz a2
                cond = "arg2 != 0"
            elif br.op == 0x05 and br.rs == 6:                       # bne a2, rt
                cond = f"arg2 == {self.get(br.rt).c()}"
            elif br.op == 0x04 and br.rs == 6:
                cond = f"arg2 != {self.get(br.rt).c()}"
            else:
                raise GiveUp(f"argc branch {br}")
            self.args_used = max(self.args_used, 3)
            # first arm: split+2 .. the `b epilogue` (or the target when it falls into the epilogue)
            end1 = None
            for k in range(split + 2, self.epilogue_start):
                a = ins[k]
                if a.op == 0x04 and a.rs == ZERO and a.rt == ZERO and (a.target() - self.addr) // 4 >= self.epilogue_start:
                    end1 = k
                    break
            if target >= self.epilogue_start:
                self.emit(f"if ({cond}) {{")
                self.indent += 1
                self.run_region(split + 2, self.epilogue_start)
                self.indent -= 1
                self.emit("}")
            else:
                if end1 is None:
                    raise GiveUp("no join before the second arm")
                self.emit(f"if ({cond}) {{")
                self.indent += 1
                self.run_region(split + 2, end1)
                # the b's delay slot: an epilogue ld, or a real instruction
                if not (ins[end1 + 1].op == 0x37 and ins[end1 + 1].rs == SP):
                    self.exec_one(ins[end1 + 1])
                self.indent -= 1
                self.emit("} else {")
                self.indent += 1
                self.reset_regs(saved)
                # nops between the arms are alignment
                k = end1 + 2
                while k < target and ins[k].is_nop():
                    k += 1
                if k != target:
                    raise GiveUp("code between the arms")
                self.second_arm(target)
                self.indent -= 1
                self.emit("}")
        return self.source()

    def second_arm(self, target):
        ins = self.ins
        # a nested argc test (`else if (arg2 == 1)`) at the start of the second arm
        k = target
        if (ins[k].op == 0x09 and ins[k].rs == ZERO and ins[k + 1].op == 0x05 and ins[k + 1].rs == 6
                and ins[k + 1].rt == ins[k].rt and (ins[k + 1].target() - self.addr) // 4 >= self.epilogue_start):
            self.exec_one(ins[k])
            self.emit(f"if (arg2 == {ins[k].simm}) {{")
            self.indent += 1
            if not (ins[k + 2].op == 0x37 and ins[k + 2].rs == SP):
                self.exec_one(ins[k + 2])
            self.run_region(k + 3, self.epilogue_start)
            self.indent -= 1
            self.emit("}")
            return
        self.run_region(target, self.epilogue_start)

    # ---------------------------------------------------------------- output
    def source(self):
        out = [HEADER]
        # virtual-call helpers: return type from the use of the result
        vt = {}
        for name, (slot, kind) in self.vcall_slots.items():
            vt[name] = kind
        for name in self.vcall_slots:
            slot, kind = self.vcall_slots[name]
            if kind == "ret":
                out.append("struct VEntry_%x { s16 delta; s16 index; void (*fn)(void *, void *); };" % slot)
                out.append("struct VObj_%x { char pad0[4]; VEntry_%x *vtbl; };" % (slot, slot))
                out.append(f"static inline void {name}(void *ret, char *o) {{\n"
                           f"    VEntry_{slot:x} *e = (VEntry_{slot:x} *)((char *)((VObj_{slot:x} *)o)->vtbl + {slot:#x});\n"
                           f"    e->fn(ret, o + e->delta);\n}}")
            else:
                rt = C_TYPES[kind] if kind != "void" else "void"
                out.append("struct VEntry_%x { s16 delta; s16 index; %s (*fn)(void *); };" % (slot, rt))
                out.append("struct VObj_%x { char pad0[4]; VEntry_%x *vtbl; };" % (slot, slot))
                out.append(f"static inline {rt} {name}(char *o) {{\n"
                           f"    VEntry_{slot:x} *e = (VEntry_{slot:x} *)((char *)((VObj_{slot:x} *)o)->vtbl + {slot:#x});\n"
                           f"    return e->fn(o + e->delta);\n}}")
        for addr in sorted(self.used_syms):
            if addr in self.globals:
                out.append(f"extern {C_TYPES[self.globals[addr]]} D_{addr:08X};")
            elif addr == STRING_REP:
                out.append(f"extern Rep D_{addr:08X};")
            elif f"func_{addr:08X}" not in self.protos:
                out.append(f"extern char D_{addr:08X}[];")
        for name, (ret, args) in self.protos.items():
            out.append(f'extern "C" {ret} {name}({", ".join(args) if args else "void"});')
        for name, text in self.helpers.items():
            if isinstance(text, str):
                out.append(text)
        if self.helpers.get("str_release"):
            out.append(f"""
static inline void str_release(Str *s) {{
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {{
        s32 size = q->cap + 0x10;
        func_{STR_RELEASE_FN:08X}(q, size, 4, func_{STR_ALLOC_NAME:08X}()->name);
    }}
}}""")
        params = ["s32 *arg0", "void *arg1", "s32 arg2", "char **arg3"][:max(1, self.args_used)]
        out.append(f'\nextern "C" {self.ret_type} func_{self.addr:08X}({", ".join(params)}) {{')
        for off in sorted(self.slots):
            if self.slot_types[off] == "Str":
                out.append(f"    Str {self.slots[off]};")
            else:
                out.append(f"    s32 {self.slots[off]}[4];")
        for name, ctype in self.locals.items():
            out.append(f"    {ctype}{'' if ctype.endswith('*') else ' '}{name};")
        for indent, text in self.body:
            out.append("    " * indent + text)
        out.append("}")
        return "\n".join(out) + "\n"


ARG_TYPES = ["ptr", "ptr", "s32", "ptr"]


def judge(addr, text):
    os.makedirs(OUT, exist_ok=True)
    path = os.path.join(OUT, f"{addr:08x}.cpp")
    open(path, "w", newline="\n").write(text)
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    return res.returncode == 0 and "MATCH" in res.stdout, res.stdout + res.stderr, path


VARIANTS = [(), ("ctor_ptr",), ("store_temp",), ("ctor_ptr", "store_temp"), ("ptr_locals",),
            ("ptr_locals", "ctor_ptr")]


def solve(addr, variants=VARIANTS):
    """(ok, source or reason, judge output): the variants in order, the first MATCH wins; otherwise
    the closest (fewest differing instructions)."""
    best = None
    for knobs in variants:
        try:
            f = Func(addr, knobs)
            src = f.build()
        except GiveUp as e:
            return None, str(e), ""
        except (KeyError, IndexError, AttributeError) as e:
            return None, f"internal {type(e).__name__}: {e}", ""
        ok, out, path = judge(addr, src)
        if ok:
            return True, src, out
        m = re.search(r"(\d+) of (\d+) instructions differ", out)
        score = int(m.group(1)) if m else 10 ** 6
        if best is None or score < best[0]:
            best = (score, src, out)
    return False, best[1], best[2]


def cmd_try(addr, show):
    ok, src, out = solve(addr)
    if ok is None:
        print(f"{addr:08x}: give up: {src}")
        return
    print(src)
    print(out if show or ok else out.splitlines()[0])


def cmd_scan(jobs, fam_ids, min_size, max_size, everything):
    fams = json.load(open(families.DEFAULT_JSON))
    done = autoloop.done_addrs()
    words = dict(families.function_words())
    todo = []
    if everything == "inventory":
        for u, w in words.items():
            if u not in done and min_size <= len(w) * 4 <= max_size:
                todo.append(u)
    else:
        chosen = fams if everything or fam_ids is None else [fams[i] for i in fam_ids]
        for f in chosen:
            for a in f["unmatched_members"]:
                u = int(a, 16)
                if u in done or u in todo:
                    continue
                size = len(words[u]) * 4
                if min_size <= size <= max_size:
                    todo.append(u)
    print(f"{len(todo)} functions", flush=True)
    stats = {"MATCH": 0, "no match": 0}
    reasons = {}
    solved_bytes = 0

    def run(u):
        try:
            return u, solve(u)
        except Exception as e:  # keep the scan going
            return u, (None, f"error {type(e).__name__}: {e}", "")

    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for u, (ok, src, out) in pool.map(run, todo):
            if ok:
                open(os.path.join(ROOT, "src", f"func_{u:08X}.cpp"), "w", newline="\n").write(src)
                stats["MATCH"] += 1
                solved_bytes += len(words[u]) * 4
                print(f"{u:08x} MATCH ({len(words[u]) * 4} B)", flush=True)
            elif ok is None:
                key = re.sub(r"0x[0-9a-f]+|\$\w+|:.*", "", src).strip()
                reasons[key] = reasons.get(key, 0) + 1
            else:
                stats["no match"] += 1
                print(f"{u:08x} no: {(out.splitlines() or ['?'])[0][:100]}", flush=True)
    print(stats, f"{solved_bytes} bytes matched")
    for k, n in sorted(reasons.items(), key=lambda kv: -kv[1])[:20]:
        print(f"{n:4d}  {k}")


def main():
    args = sys.argv[1:]
    if args[:1] == ["try"] and len(args) >= 2:
        cmd_try(int(args[1], 16), "--show" in args)
    elif args[:1] == ["scan"]:
        jobs = next((int(a[2:]) for a in args if a.startswith("-j")), 2)
        fam_ids = None
        if "--families" in args:
            fam_ids = [int(x) for x in args[args.index("--families") + 1].split(",")]
        min_size = int(args[args.index("--min-size") + 1]) if "--min-size" in args else 0
        max_size = int(args[args.index("--max-size") + 1]) if "--max-size" in args else 1 << 30
        cmd_scan(jobs, fam_ids, min_size, max_size, "inventory" if "--inventory" in args else "--all" in args)
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
