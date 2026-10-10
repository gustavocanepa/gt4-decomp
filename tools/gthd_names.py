#!/usr/bin/env python3
"""Names, signatures and prototypes for this game's C++ code from Gran Turismo HD (PS3, 2006).

GT HD's debug executables (the public "gthd-ps3-debug-binaries", 1166.elf / 1171.elf) descend
from GT4's code base and keep a full symbol table of Itanium-mangled C++ names. This tool reads
one of them (read only, never executed, never copied into the repository) and carries the names
over to this game's functions:

1. Virtual methods, by vtable slot. Every class here (config/classes.json, g++ 2.96 RTTI) gets its
   GT HD twin: the same name, else the PS3 class standing for a PS2 one (RacePS2Base ->
   RacePS3Base), else the only namespaced class of that name. The two ABIs differ:
     - g++ 2.96 (here): {delta, index, pfn} entries, one destructor slot;
     - Itanium (GT HD): [offset-to-top, typeinfo, fn...], fn -> a .opd descriptor -> code, and two
       destructor slots (D1 complete, D0 deleting) where g++ 2.96 has one (merged here).
   A class keeps its parent's pairing for the parent's slots (when both games have the same
   parent) and must override exactly the slots its twin overrides; its own slots are aligned by a
   global alignment (gaps on both sides: GT HD added and dropped methods) scored with
     - the override pattern: over the descendants with the same class chain in both games, a
       descendant overriding both slots counts for the pair, overriding only one against it;
     - the code size (GT HD's PPC code is ~1.3-2x the EE code, calibrated on agreeing classes);
     - hard checks: a pure virtual (here: the address seen with __cxa_pure_virtual) only with a
       pure virtual, a GT HD destructor only with a constructor/destructor here, the GT HD
       method's class must be the twin or one of its bases (exactly the twin for its new slots).
   A pair is kept when the best alignment using it beats every alternative for that slot (another
   partner, or none) by a margin: high (margin >= 4 and positive evidence), medium (>= 2). An
   address seen in several classes must get the same GT HD function from each; when not, the
   class that introduces the address here decides, else it is a conflict.
2. Other functions, through the call graph and strings (unless --no-calls): for two paired
   functions, their call lists are aligned on the callees already paired; stretches of the same
   length between those anchors pair up position by position (a list that contradicts a known
   pair proposes nothing). A function referencing a string (>= 6 chars) that exactly one function
   references in each game pairs with that one. A candidate proposed with two partners is
   dropped; sizes must be plausible. medium: two callers, an anchored list, a caller with the
   same number of calls, or two strings; low: one weaker witness. Medium pairs propose further
   pairs until nothing changes. Checked by holding out half of the high vtable pairs: 35/36
   medium and 49/49 low recovered correctly (the one miss: the D2 destructor instead of D1).

Output (generated, names only, no game data):
  config/gthd_names.txt       ADDR, name, confidence, applied, GT HD signature, reason (tab
                              separated), one line per function address of this game that got a
                              GT HD name. confidence high / medium / low / conflict.
  config/gthd_prototypes.json one line per class: {"gthd_class", "parent", "gthd_parent",
                              "slots_here", "slots_gthd", "methods": [{"slot", "gthd_slot",
                              "address", "confidence", "name", "params", "const", "owner",
                              "signature", "pure"?}]}, the slots the class declares or overrides.
With --apply, the high vtable names and the medium call-graph/string names (constructors and
destructors excepted: they keep Class__structor_N) go into config/symbol_addrs.txt as
`Class__method = 0xADDR; // type:func gthd`, in one block that a rerun replaces (rerun after
tools/rtti.py rewrites the file); tools/symbols.py ranks them above Class__virtual_NN, so
tools/organize.py renames the sources (Class__virtual_NN stays an alias, sources using it still
resolve). Overloads get _const / _2 suffixes; a name another address already has is refused.

    gthd_names.py [--elf PATH] [--no-calls] [--apply] [--stats]
    gthd_names.py --project ../TT ...     another project with the same tools and a classes.json

The ELF path defaults to $GTHD_ELF or ~/Downloads/gthd-ps3-debug-binaries/1166.elf. Demangling
uses c++filt (native, else WSL's), cached in build/gthd/demangled.json.
"""
import argparse
import math
import csv
import json
import os
import re
import shutil
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
DEFAULT_ELF = os.environ.get("GTHD_ELF") or os.path.join(
    os.path.expanduser("~"), "Downloads", "gthd-ps3-debug-binaries", "1166.elf")
BLOCK_START = "// ---- GT HD names (tools/gthd_names.py --apply; do not edit by hand) ----"
BLOCK_END = "// ---- end of GT HD names ----"


# ------------------------------------------------------------------------------------------
# GT HD: the PPC64 big-endian ELF (32-bit pointers, .opd function descriptors)

class Elf:
    def __init__(self, path):
        d = self.data = open(path, "rb").read()
        if d[:4] != b"\x7fELF" or d[4] != 2 or d[5] != 2:
            sys.exit(f"{path}: not a 64-bit big-endian ELF")
        shoff, = struct.unpack_from(">Q", d, 0x28)
        shentsize, shnum, shstrndx = struct.unpack_from(">HHH", d, 0x3A)
        raw = [struct.unpack_from(">IIQQQQIIQQ", d, shoff + i * shentsize) for i in range(shnum)]
        strtab = raw[shstrndx][4]
        self.sections = []
        for s in raw:
            name = d[strtab + s[0]:d.index(b"\0", strtab + s[0])].decode()
            self.sections.append({"name": name, "type": s[1], "addr": s[3], "off": s[4], "size": s[5],
                                  "link": s[6]})
        self.by_name = {s["name"]: s for s in self.sections}
        self.symbols = []
        sym = self.by_name.get(".symtab")
        if sym:
            names = self.sections[sym["link"]]["off"]
            for i in range(sym["size"] // 24):
                st_name, info, _, shndx, value, size = struct.unpack_from(">IBBHQQ", d, sym["off"] + 24 * i)
                if not st_name:
                    continue
                n = d[names + st_name:d.index(b"\0", names + st_name)].decode("latin-1")
                self.symbols.append((n, value, size, info & 15, shndx))

    def section_of(self, addr):
        for s in self.sections:
            if s["addr"] and s["type"] != 8 and s["addr"] <= addr < s["addr"] + s["size"]:
                return s
        return None

    def read(self, addr, n):
        s = self.section_of(addr)
        if s is None or addr + n > s["addr"] + s["size"]:
            return None
        return self.data[s["off"] + addr - s["addr"]:s["off"] + addr - s["addr"] + n]

    def u32(self, addr):
        b = self.read(addr, 4)
        return struct.unpack(">I", b)[0] if b else None


def demangle_all(names, cache_path):
    """{mangled: demangled} through c++filt, cached on disk."""
    cache = {}
    if os.path.exists(cache_path):
        cache = json.load(open(cache_path))
    todo = sorted({n for n in names if n not in cache})
    if todo:
        flags = getattr(subprocess, "CREATE_NO_WINDOW", 0)
        cmd = ["c++filt"] if shutil.which("c++filt") else ["wsl", "-e", "c++filt"]
        out = subprocess.run(cmd, input="\n".join(todo) + "\n", capture_output=True, text=True,
                             creationflags=flags, check=True).stdout.split("\n")
        for n, dm in zip(todo, out):
            cache[n] = dm
        os.makedirs(os.path.dirname(cache_path), exist_ok=True)
        json.dump(cache, open(cache_path, "w"), indent=0, sort_keys=True)
    return cache


def split_signature(sig):
    """'ns::Cls::method(int, char const*) const' -> (['ns', 'Cls'], 'method', ['int', 'char const*'], const)."""
    sig = sig.strip()
    const = sig.endswith(" const")
    if const:
        sig = sig[:-6]
    depth, start = 0, None
    for i in range(len(sig) - 1, -1, -1):  # the outermost parameter list is the last (...)
        if sig[i] == ")":
            depth += 1
        elif sig[i] == "(":
            depth -= 1
            if depth == 0:
                start = i
                break
    if start is None:
        return None
    head, params = sig[:start], sig[start + 1:-1]
    parts, depth, cur = [], 0, ""
    for ch in head:  # qualified name, split on :: outside template arguments
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        if ch == ":" and depth == 0:
            if cur:
                parts.append(cur)
            cur = ""
            continue
        cur += ch
    parts.append(cur)
    plist, depth, cur = [], 0, ""
    for ch in params:
        if ch in "<(":
            depth += 1
        elif ch in ">)":
            depth -= 1
        if ch == "," and depth == 0:
            plist.append(cur.strip())
            cur = ""
            continue
        cur += ch
    if cur.strip() and cur.strip() != "void":
        plist.append(cur.strip())
    return parts[:-1], parts[-1], plist, const


class GTHD:
    """Functions, vtables and type_info parents of the GT HD executable."""

    def __init__(self, path, cache_dir):
        self.elf = e = Elf(path)
        opd = e.by_name[".opd"]
        self.opd_lo, self.opd_hi = opd["addr"], opd["addr"] + opd["size"]
        text = e.by_name[".text"]
        self.text_lo, self.text_hi = text["addr"], text["addr"] + text["size"]
        self.desc_name = {}   # .opd descriptor address -> mangled name
        self.code_name = {}   # code address -> mangled name (dot symbols, first seen)
        self.code_size = {}
        objects = {}
        for n, value, size, typ, shndx in e.symbols:
            if typ == 2 and self.opd_lo <= value < self.opd_hi and not n.startswith("."):
                self.desc_name.setdefault(value, n)
            elif typ == 2 and n.startswith(".") and self.text_lo <= value < self.text_hi:
                self.code_name.setdefault(value, n[1:])
                self.code_size[value] = max(size, self.code_size.get(value, 0))
            elif typ == 1:
                objects[n] = (value, size)
        self.objects = objects
        wanted = set(self.desc_name.values()) | set(self.code_name.values()) | \
            {n for n in objects if n.startswith(("_ZTV", "_ZTI"))}
        self.dm = demangle_all(wanted, os.path.join(cache_dir, "demangled.json"))
        self.code_of_name = {n: a for a, n in self.code_name.items()}
        self.ti_class = {}  # typeinfo address -> class name
        for n, (value, _) in objects.items():
            if n.startswith("_ZTI"):
                self.ti_class[value] = self.dm.get(n, n).replace("typeinfo for ", "")

    def code_of_desc(self, desc):
        return self.elf.u32(desc)

    def vtables(self):
        """{class name: [descriptor address, ...]} of each _ZTV's primary vtable."""
        out = {}
        for n, (value, size) in self.objects.items():
            if not n.startswith("_ZTV") or size < 8:
                continue
            cls = self.dm.get(n, n).replace("vtable for ", "")
            words = struct.unpack(f">{size // 4}I", self.elf.read(value, size))
            # [offset-to-top, typeinfo, fn...]; the primary group ends at the first word that is
            # not a descriptor (the next group's offset-to-top) or at the end.
            fns = []
            for w in words[2:]:
                if not (self.opd_lo <= w < self.opd_hi):
                    break
                fns.append(w)
            out[cls] = fns
        return out

    def parents(self):
        """{class: [base classes]} from the _ZTI objects: __class_type_info is {vptr, name} (no
        base), __si_class_type_info adds one base pointer, __vmi_class_type_info adds flags, a
        count and {base, offset_flags} pairs."""
        out = {}
        for n, (value, size) in self.objects.items():
            if not n.startswith("_ZTI"):
                continue
            cls = self.ti_class[value]
            words = struct.unpack(f">{size // 4}I", self.elf.read(value, size)) if size >= 8 else ()
            if size == 12:
                out[cls] = [self.ti_class.get(words[2], "?")]
            elif size >= 16 and len(words) >= 4 + 2 * words[3]:
                out[cls] = [self.ti_class.get(words[4 + 2 * i], "?") for i in range(words[3])]
            else:
                out[cls] = []
        return out


# ------------------------------------------------------------------------------------------
# this game

def load_classes(project_root):
    for rel in ("config/classes.json", "build/classes.json"):
        p = os.path.join(project_root, rel)
        if os.path.exists(p):
            c = json.load(open(p))
            if c:
                return c
    return {}


def identifier(owner, method, taken):
    """Class__method spelled as a C identifier (operators and destructors spelled out)."""
    ops = {"==": "eq", "!=": "ne", "<": "lt", ">": "gt", "<=": "le", ">=": "ge", "=": "assign",
           "+": "add", "-": "sub", "*": "mul", "/": "div", "%": "mod", "[]": "index", "()": "call",
           "+=": "add_assign", "-=": "sub_assign", "*=": "mul_assign", "/=": "div_assign",
           "!": "not", "++": "inc", "--": "dec", "<<=": "shl_assign", ">>=": "shr_assign", "%=": "mod_assign",
           "&=": "band_assign", "|=": "bor_assign", "^=": "bxor_assign", "new[]": "new_array",
           "delete[]": "delete_array", ",": "comma", "->*": "arrow_star", "&&": "and", "||": "or", "<<": "shl", ">>": "shr", "&": "band", "|": "bor",
           "^": "bxor", "~": "bnot", "->": "arrow", "new": "new", "delete": "delete"}
    if method.startswith("operator"):
        op = method[8:].strip()
        method = "operator_" + ops.get(op, re.sub(r"\W+", "_", op).strip("_") or "".join(f"{ord(c):02x}" for c in op))
    elif method.startswith("~"):
        method = "dtor"
    return "__".join(re.sub(r"\W+", "_", p) for p in owner) + "__" + re.sub(r"\W+", "_", method)


class Project:
    """This game's side: classes, function sizes and (for the call graph) its code."""

    def __init__(self, root):
        self.root = os.path.abspath(root)
        self.classes = load_classes(self.root)
        self.size = {}
        p = os.path.join(self.root, "build", "functions.csv")
        if os.path.exists(p):
            with open(p) as f:
                for row in csv.DictReader(f):
                    self.size[int(row["address"], 16)] = int(row["max_size"])
        self.kids = {}
        for k, v in self.classes.items():
            for b in v.get("bases", [])[:1]:
                self.kids.setdefault(b, []).append(k)

    def vtable(self, cls):
        v = self.classes.get(cls, {}).get("vtables") or []
        return v[0]["methods"] if v else None

    def parent(self, cls):
        b = self.classes.get(cls, {}).get("bases") or []
        return b[0] if b else None

    def descendants(self, cls):
        out, todo = [], list(self.kids.get(cls, []))
        while todo:
            d = todo.pop()
            out.append(d)
            todo.extend(self.kids.get(d, []))
        return out

    def structors(self):
        out = set()
        for v in self.classes.values():
            out.update(v.get("structors", []))
        return out


# ------------------------------------------------------------------------------------------
# vtable slots


NEG = -1e9


def size_score(size_here, size_gthd):
    """Log-likelihood ratio that two functions are the same method, from their code sizes alone.
    Calibrated on the slots of classes whose vtables agree: GT HD's PPC code is 1.3-2x the EE
    code (log ratio ~N(0.4, 0.45)), random pairs spread ~N(0.2, 1.4)."""
    if not size_here or not size_gthd:
        return 0.0
    x = math.log((size_gthd + 16) / (size_here + 16))

    def gauss(v, mu, sd):
        return math.exp(-0.5 * ((v - mu) / sd) ** 2) / (sd * 2.5066)
    return max(-4.0, min(2.0, math.log((0.9 * gauss(x, 0.4, 0.45) + 0.01) / gauss(x, 0.2, 1.4))))


class Mapper:
    GAP_GTHD = 2.0    # a GT HD slot without a counterpart here (a method GT HD added)
    GAP_HERE = 3.0    # a slot here without a counterpart in GT HD (a method GT HD dropped)
    HIGH, MEDIUM = 4.0, 2.0   # margins of the best pairing over the next best

    def __init__(self, gt, h):
        self.gt, self.h = gt, h
        hv = {cls: self.logical(fns) for cls, fns in h.vtables().items()}
        # This game's class -> GT HD class: the same name, else the PS3 twin of a PS2 class,
        # else the only GT HD class with that name inside a namespace.
        last = {}
        for hc in hv:
            last.setdefault(hc.split("::")[-1], []).append(hc)
        self.twin = {}
        for c in gt.classes:
            if c in hv:
                self.twin[c] = c
            elif c.replace("PS2", "PS3") in hv:
                self.twin[c] = c.replace("PS2", "PS3")
            elif len(last.get(c, [])) == 1:
                self.twin[c] = last[c][0]
        self.hvt = {c: hv[hc] for c, hc in self.twin.items()}
        self.hpar = h.parents()
        self.structors = gt.structors()
        self.pure_h = {d for d, n in h.desc_name.items() if n == "__cxa_pure_virtual"}
        self.align = {}      # class -> {this game's slot: GT HD logical slot}
        self.notes = {}      # class -> [text]
        self.slot_conf = {}  # (class, slot) -> (confidence, reason)
        self.PURE4 = None
        self._lineage, self._masks = {}, {}

    def name(self, desc):
        n = self.h.desc_name.get(desc, "?")
        return self.h.dm.get(n, n)

    def is_dtor(self, desc):
        return "::~" in self.name(desc)

    def logical(self, fns):
        """Itanium slots with the D1/D0 destructor pair merged into one (the D1 descriptor)."""
        out, i = [], 0
        while i < len(fns):
            out.append(fns[i])
            i += 2 if self.is_dtor(fns[i]) and i + 1 < len(fns) and self.is_dtor(fns[i + 1]) else 1
        return out

    def hancestors(self, hcls):
        out = []
        while True:
            p = self.hpar.get(hcls) or []
            if not p or p[0] in out or p[0] == "?":
                return out
            hcls = p[0]
            out.append(hcls)

    def owner(self, desc):
        sp = split_signature(self.name(desc))
        return "::".join(sp[0]) if sp else None

    def gthd_size(self, desc):
        return self.h.code_size.get(self.h.code_of_desc(desc))

    def pure4(self):
        """This game's pure-virtual address: the one most often at a slot GT HD fills with
        __cxa_pure_virtual, over classes whose slot counts agree."""
        votes = {}
        for cls in self.twin:
            g, hl = self.gt.vtable(cls), self.hvt[cls]
            if g and len(g) == len(hl):
                for a, d in zip(g, hl):
                    if d in self.pure_h:
                        votes[a] = votes.get(a, 0) + 1
        return max(votes, key=votes.get) if votes else None

    def same_lineage(self, cls):
        """Descendants of cls known in both games with the same chain of classes up to cls in
        both (a class GT HD moved under a new intermediate class is left out)."""
        if cls not in self._lineage:
            out = []
            for d in self.gt.descendants(cls):
                if not self.gt.vtable(d) or d not in self.twin:
                    continue
                chain4, c = [], d
                while c and c != cls:
                    chain4.append(self.twin.get(c))
                    c = self.gt.parent(c)
                ha = [self.twin[d]] + self.hancestors(self.twin[d])
                if self.twin[cls] in ha and ha[:ha.index(self.twin[cls])] == chain4:
                    out.append(d)
            self._lineage[cls] = out
        return self._lineage[cls]

    def masks(self, cls):
        """Per slot, the set (bit mask) of same-lineage descendants that override it, here and
        in GT HD."""
        if cls not in self._masks:
            g, hl = self.gt.vtable(cls), self.hvt[cls]
            m4, mh = [0] * len(g), [0] * len(hl)
            for k, d in enumerate(self.same_lineage(cls)):
                gd, hd = self.gt.vtable(d), self.hvt[d]
                for s in range(min(len(g), len(gd))):
                    if gd[s] != g[s]:
                        m4[s] |= 1 << k
                for t in range(min(len(hl), len(hd))):
                    if hd[t] != hl[t]:
                        mh[t] |= 1 << k
            self._masks[cls] = (m4, mh)
        return self._masks[cls]

    def score(self, cls, s, t, own_block):
        """(score, why) of pairing slot s here with GT HD slot t; score NEG = impossible."""
        a, d = self.gt.vtable(cls)[s], self.hvt[cls][t]
        if (a == self.PURE4) != (d in self.pure_h):
            return NEG, "pure virtual in one game only"
        m4, mh = self.masks(cls)
        sup, con = bin(m4[s] & mh[t]).count("1"), bin(m4[s] ^ mh[t]).count("1")
        sc, why = 2.0 * sup - 3.0 * con, []
        if sup or con:
            why.append(f"{sup} descendants override both" + (f", {con} only one" if con else ""))
        if d in self.pure_h:
            return sc + 3.0, ", ".join(["pure virtual"] + why)
        if self.is_dtor(d) != (a in self.structors):
            return NEG, "destructor in one game only"
        if self.is_dtor(d):
            sc += 3.0
            why.append("destructor")
        own, hc = self.owner(d), self.twin[cls]
        if own != hc and own not in self.hancestors(hc):
            return NEG, f"GT HD method of {own}, not of {hc} or its bases"
        if own_block and own != hc:
            return NEG, f"new slot of {hc} holds a method of {own}"
        sz = size_score(self.gt.size.get(a), self.gthd_size(d))
        why.append(f"sizes {self.gt.size.get(a)}/{self.gthd_size(d)}")
        return sc + sz, ", ".join(why)

    def run(self):
        self.PURE4 = self.pure4()
        order, seen = [], set()

        def visit(c):
            if c not in seen:
                seen.add(c)
                if self.gt.parent(c):
                    visit(self.gt.parent(c))
                order.append(c)
        for c in sorted(self.gt.classes):
            visit(c)
        for cls in order:
            if self.gt.vtable(cls) and cls in self.twin:
                self.align_class(cls)

    def align_class(self, cls):
        g, hl = self.gt.vtable(cls), self.hvt[cls]
        notes = self.notes.setdefault(cls, [])
        p4 = self.gt.parent(cls)
        ph = (self.hpar.get(self.twin[cls]) or [None])[0]
        good, s0, t0, prefix = {}, 0, 0, False
        if p4 and p4 in self.align and self.twin.get(p4) == ph:
            # The parent's slots keep the parent's pairing; this class must override exactly the
            # slots its GT HD twin overrides, and its own overrides must pass the checks.
            prefix = True
            s0, t0 = len(self.gt.vtable(p4)), len(self.hvt[p4])
            for s, t in sorted(self.align[p4].items()):
                inh4 = g[s] == self.gt.vtable(p4)[s]
                if inh4 != (hl[t] == self.hvt[p4][t]):
                    notes.append(f"slot {s}: overridden in one game only")
                    continue
                if not inh4:
                    sc, why = self.score(cls, s, t, False)
                    if sc < -2:
                        notes.append(f"slot {s}: override fails the checks ({why})")
                        continue
                good[s] = t
                self.slot_conf[(cls, s)] = self.slot_conf[(p4, s)]
        elif p4 or ph:
            notes.append(f"parent here {p4}, in GT HD {ph}: whole vtable aligned as one block")
        bs, bt = list(range(s0, len(g))), list(range(t0, len(hl)))
        if len(bs) != len(bt):
            notes.append(f"own slots: {len(bs)} here, {len(bt)} in GT HD")
        for s, (t, conf, why) in self.align_block(cls, bs, bt, prefix).items():
            good[s] = t
            self.slot_conf[(cls, s)] = (conf, why)
        self.align[cls] = good

    def align_block(self, cls, bs, bt, own_block):
        """{slot here: (GT HD slot, confidence, reason)} for a run of slots: a global alignment
        (gaps allowed on both sides) whose pairs are kept when the best alignment using a pair
        beats the best one pairing that slot otherwise (or leaving it out) by a margin."""
        n, m = len(bs), len(bt)
        if not n or not m:
            return {}
        S, W = [[NEG] * m for _ in range(n)], [[""] * m for _ in range(n)]
        for i, s in enumerate(bs):
            for j, t in enumerate(bt):
                S[i][j], W[i][j] = self.score(cls, s, t, own_block)
        inf = float("-inf")
        D = [[inf] * (m + 1) for _ in range(n + 1)]
        E = [[inf] * (m + 1) for _ in range(n + 1)]
        D[0][0] = E[n][m] = 0.0
        for i in range(n + 1):
            for j in range(m + 1):
                if i or j:
                    best = inf
                    if i and j and S[i - 1][j - 1] > NEG / 2:
                        best = D[i - 1][j - 1] + S[i - 1][j - 1]
                    if i:
                        best = max(best, D[i - 1][j] - self.GAP_HERE)
                    if j:
                        best = max(best, D[i][j - 1] - self.GAP_GTHD)
                    D[i][j] = best
        for i in range(n, -1, -1):
            for j in range(m, -1, -1):
                if i < n or j < m:
                    best = inf
                    if i < n and j < m and S[i][j] > NEG / 2:
                        best = E[i + 1][j + 1] + S[i][j]
                    if i < n:
                        best = max(best, E[i + 1][j] - self.GAP_HERE)
                    if j < m:
                        best = max(best, E[i][j + 1] - self.GAP_GTHD)
                    E[i][j] = best
        out = {}
        for i in range(n):
            vals = [D[i][j] + S[i][j] + E[i + 1][j + 1] if S[i][j] > NEG / 2 else inf for j in range(m)]
            skip = max(D[i][j] - self.GAP_HERE + E[i + 1][j] for j in range(m + 1))
            j = max(range(m), key=lambda k: vals[k])
            rival = max([skip] + [v for k, v in enumerate(vals) if k != j])
            margin = vals[j] - rival
            if margin >= self.HIGH and S[i][j] >= 0.5:
                conf = "high"
            elif margin >= self.MEDIUM:
                conf = "medium"
            else:
                continue
            out[bs[i]] = (bt[j], conf, f"slot {bs[i]} -> GT HD {bt[j]}, margin {margin:.1f}: {W[i][j]}")
        return out


# ------------------------------------------------------------------------------------------
# results

RANK = {"high": 3, "medium": 2, "low": 1}


def virtual_names(mp):
    """{address here: {"desc", "conf", "why", "classes"}} from the aligned vtables, with the
    addresses that got two different GT HD functions as conflicts."""
    seen = {}
    for (cls, s), (conf, why) in mp.slot_conf.items():
        a = mp.gt.vtable(cls)[s]
        d = mp.hvt[cls][mp.align[cls][s]]
        if d in mp.pure_h or a == mp.PURE4:
            continue
        seen.setdefault(a, []).append((cls, s, d, conf, why))
    owner = {}  # address -> the class here that introduces it (classes.json "methods")
    for cls, c in mp.gt.classes.items():
        for meth in c.get("methods", []):
            owner.setdefault(meth["address"], cls)
    out, conflicts = {}, {}
    for a, uses in seen.items():
        names = {mp.h.desc_name[d] for _, _, d, _, _ in uses}
        note = ""
        if len(names) > 1:
            # GT HD overrides in some subclass a method that GT4's subclass inherits (or sits
            # in a class it moved): the class that owns the address here decides.
            own = [u for u in uses if u[0] == owner.get(a)]
            if not own or len({mp.h.desc_name[u[2]] for u in own}) > 1:
                conflicts[a] = uses
                continue
            others = sorted({u[0] for u in uses if mp.h.desc_name[u[2]] != mp.h.desc_name[own[0][2]]})
            note = f"; other GT HD functions in {', '.join(others[:3])}{'...' if len(others) > 3 else ''}"
            uses = own
        best = max(uses, key=lambda u: RANK[u[3]])
        out[a] = {"desc": best[2], "conf": best[3], "why": f"vtable {best[0]}[{best[1]}]: {best[4]}{note}",
                  "classes": sorted({u[0] for u in uses})}
    return out, conflicts


# ------------------------------------------------------------------------------------------
# non-virtual functions: call graph and strings

def printable(blob):
    """The C string at the start of blob when it looks like text (>= 4 printable chars), else None."""
    if not blob:
        return None
    end = blob.find(b"\0")
    if end < 4:
        return None
    s = blob[:end]
    if all(32 <= c < 127 or c in (9, 10) for c in s):
        return s.decode()
    return None


def here_code(gt):
    """{function: ([callees in order], [strings referenced])} of this game, from its executable
    (tools/project.py's loader) and build/functions.csv: jal/j targets that start a function,
    and lui+addiu/ori/load pairs that point at a C string."""
    sys.path.insert(0, os.path.join(gt.root, "tools"))
    import project
    _, sections = project.load_image()

    def read(addr, n):
        for base, blob in sections:
            if base <= addr < base + len(blob):
                return blob[addr - base:addr - base + n]
        return None
    out = {}
    starts = set(gt.size)
    for f, size in gt.size.items():
        code = read(f, size)
        if not code or len(code) < size:
            continue
        calls, strs, hi = [], [], {}
        for k in range(size // 4):
            w, = struct.unpack_from("<I", code, 4 * k)
            op, rs, rt, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
            pc = f + 4 * k
            if op in (2, 3):
                t = ((w & 0x3FFFFFF) << 2) | (pc & 0xF0000000)
                if t in starts and t != f:
                    calls.append(t)
            elif op == 15:          # lui
                hi[rt] = imm << 16
            elif rs in hi and op in (9, 13, 32, 33, 35, 36, 37, 39, 40, 41, 43):
                addr = (hi[rs] + (imm - 0x10000 if imm & 0x8000 and op != 13 else imm)) & 0xFFFFFFFF
                if op == 13:
                    addr = hi[rs] | imm
                s = printable(read(addr, 256)) if op in (9, 13) else None
                if s:
                    strs.append(s)
        out[f] = (calls, strs)
    return out


def gthd_code(h):
    """{code address: ([callees], [strings])} of GT HD: bl/b targets that start a function and
    TOC loads (lwz/addi off r2, the TOC from the function's .opd descriptor) of string pointers."""
    toc_of = {}
    for desc in h.desc_name:
        c = h.code_of_desc(desc)
        if c is not None:
            toc_of.setdefault(c, h.elf.u32(desc + 4))
    out = {}
    for f, size in h.code_size.items():
        blob = h.elf.read(f, size)
        if not blob or f not in toc_of:
            continue
        toc = toc_of[f]
        calls, strs = [], []
        for k in range(size // 4):
            w, = struct.unpack_from(">I", blob, 4 * k)
            op = w >> 26
            if op == 18 and not w & 2:
                li = w & 0x03FFFFFC
                t = f + 4 * k + (li - 0x04000000 if li & 0x02000000 else li)
                if t in h.code_name and t != f:
                    calls.append(t)
            elif op in (32, 14) and ((w >> 16) & 31) == 2:
                d = w & 0xFFFF
                a = toc + (d - 0x10000 if d & 0x8000 else d)
                p = h.elf.u32(a) if op == 32 else a
                s = printable(h.elf.read(p, 256)) if p else None
                if s:
                    strs.append(s)
        out[f] = (calls, strs)
    return out


def anchored_pairs(a, b, known):
    """Positional pairs proposed by two call lists: the known pairs are anchors (in order); the
    stretches between anchors of the same length on both sides pair up. None when the lists
    contradict a known pair (a callee here paired with another GT HD function at an anchor)."""
    inv = {v: k for k, v in known.items()}
    anchors, j0 = [], 0
    for i, x in enumerate(a):
        if x in known:
            try:
                j = b.index(known[x], j0)
            except ValueError:
                continue
            anchors.append((i, j))
            j0 = j + 1
    out = []
    bounds = [(-1, -1)] + anchors + [(len(a), len(b))]
    for (i1, j1), (i2, j2) in zip(bounds, bounds[1:]):
        if i2 - i1 != j2 - j1:
            continue
        for k in range(1, i2 - i1):
            x, y = a[i1 + k], b[j1 + k]
            if x in known or y in inv:
                if known.get(x) != y:
                    return None
                continue
            out.append((x, y, len(anchors), len(a) == len(b)))
    return out


def propagate(seeds, here, there, h, gt):
    """{address here: (GT HD code address, confidence, reason)} for functions paired through the
    call graph and through strings, iterated until nothing changes."""
    known = dict(seeds)
    found = {}
    # strings referenced by exactly one function in each game
    s_here, s_there = {}, {}
    for f, (_, strs) in here.items():
        for s in set(strs):
            s_here.setdefault(s, []).append(f)
    for f, (_, strs) in there.items():
        for s in set(strs):
            s_there.setdefault(s, []).append(f)
    by_string = {}
    for s, fs in s_here.items():
        if len(fs) == 1 and len(s_there.get(s, [])) == 1 and len(s) >= 6:
            by_string.setdefault((fs[0], s_there[s][0]), []).append(s)
    while True:
        votes = {}
        for x, y in known.items():
            if x not in here or y not in there:
                continue
            pairs = anchored_pairs(here[x][0], there[y][0], known)
            for cx, cy, n_anchor, full in pairs or []:
                votes.setdefault((cx, cy), set()).add((x, n_anchor, full))
        for (x, y), strs in by_string.items():
            if x not in known:
                votes.setdefault((x, y), set()).add(("string", len(strs), False))
        # a function proposed with two different partners (either side) is dropped
        part_x, part_y = {}, {}
        for x, y in votes:
            part_x.setdefault(x, set()).add(y)
            part_y.setdefault(y, set()).add(x)
        new = {}
        for (x, y), wit in votes.items():
            if len(part_x[x]) > 1 or len(part_y[y]) > 1 or y in known.values():
                continue
            sz = size_score(gt.size.get(x), h.code_size.get(y))
            if sz < -1.0:
                continue
            callers = [w for w in wit if w[0] != "string"]
            strings = [w for w in wit if w[0] == "string"]
            anchored = any(w[1] for w in callers)
            full = any(w[2] for w in callers)   # the two callers make the same number of calls
            n_str = sum(w[1] for w in strings)
            if len(callers) >= 2 or (callers and (anchored or strings)) or n_str >= 2 or (full and sz >= 0):
                conf = "medium"
            elif callers or strings:
                conf = "low"
            else:
                continue
            why = []
            if callers:
                why.append(f"called at the same place by {len(callers)} paired function(s)"
                           f" ({', '.join(f'0x{w[0]:08X}' for w in callers[:3])})" + (", anchored" if anchored else ", same call count" if full else ""))
            if strings:
                why.append(f"{n_str} string(s) only these two functions use")
            new[x] = (y, conf, "; ".join(why) + f"; sizes {gt.size.get(x)}/{h.code_size.get(y)}")
        added = False
        for x, (y, conf, why) in new.items():
            old = found.get(x)
            if old and RANK[old[1]] >= RANK[conf]:
                continue
            found[x] = (y, conf, why)
            if conf == "medium" and x not in known:
                known[x] = y          # only medium pairs propose further pairs
                added = True
        if not added:
            return found


# ------------------------------------------------------------------------------------------
# output

APPLY = {"high"}            # vtable slots that passed every check
APPLY_CALLS = {"medium"}    # call graph / strings with two witnesses, an anchor, or two strings


def plain_name(h, mangled):
    return h.dm.get(mangled, mangled)


def base_identifier(sig, here_name):
    """(identifier, kind) of a demangled GT HD name; kind is 'ctor', 'dtor' or 'func'. The class
    is spelled as this game's twin class when there is one (RacePS3Base -> RacePS2Base), else
    with its whole GT HD path (Ns::Cls -> Ns__Cls, PS3 read as PS2)."""
    sp = split_signature(sig)
    if sp is None:
        return re.sub(r"\W+", "_", sig).strip("_"), "func"
    owner, method, params, const = sp
    if owner:
        full = "::".join(owner)
        # GT HD's PS3 platform classes stand where GT4 has PS2 ones (RacePS3Base / RacePS2Base)
        owner = [here_name[full]] if full in here_name else             [re.sub(r"\W+", "_", p.replace("PS3", "PS2")).strip("_") for p in owner]
    cls = "__".join(owner)
    if owner and method == re.sub(r"<.*", "", sp[0][-1]):
        return cls + "__ctor", "ctor"
    if method.startswith("~"):
        return cls + "__dtor", "dtor"
    ident = identifier(owner, method, None) if owner else re.sub(r"\W+", "_", method)
    return ident.strip("_"), "func"


def assign_identifiers(rows, taken, here_name):
    """Unique identifiers for rows ({address: row}); an identifier another address already has
    in the project's symbol table is refused (row["clash"])."""
    groups = {}
    for a, r in rows.items():
        ident, kind = base_identifier(r["signature"], here_name)
        r["kind"] = kind
        groups.setdefault(ident, []).append(a)
    for ident, addrs in groups.items():
        if len(addrs) > 1:
            # overloads: the const variant gets _const, the rest _2, _3... by address
            plain = [a for a in addrs if not rows[a]["signature"].endswith(" const")]
            const = [a for a in addrs if rows[a]["signature"].endswith(" const")]
            for lst, suffix in ((sorted(plain), ""), (sorted(const), "_const")):
                for k, a in enumerate(lst):
                    rows[a]["ident"] = ident + suffix + (f"_{k + 1}" if k else "")
        else:
            rows[addrs[0]]["ident"] = ident
    for a, r in rows.items():
        other = taken.get(r["ident"])
        if other is not None and other != a:
            r["clash"] = f"name taken by 0x{other:08X}"


def prototypes(mp):
    """{class: {...}} per class here with a GT HD twin: the paired slots the class declares or
    overrides (inherited ones are in the ancestor's entry) with their GT HD declaration (method
    name, parameter types, const); a pure virtual is named after its first override."""
    out = {}
    for cls, al in sorted(mp.align.items()):
        g, hl, hc = mp.gt.vtable(cls), mp.hvt[cls], mp.twin[cls]
        slots = []
        pg = mp.gt.vtable(mp.gt.parent(cls)) if mp.gt.parent(cls) else None
        for s, t in sorted(al.items()):
            if pg and s < len(pg) and pg[s] == g[s]:
                continue    # inherited: declared by an ancestor's entry
            d = hl[t]
            conf, why = mp.slot_conf[(cls, s)]
            entry = {"slot": s, "gthd_slot": t, "address": f"0x{g[s]:08X}", "confidence": conf}
            if d in mp.pure_h:
                entry["pure"] = True
                for dd in mp.same_lineage(cls):
                    if mp.hvt[dd][t] not in mp.pure_h:
                        d = mp.hvt[dd][t]
                        break
                else:
                    slots.append(entry)
                    continue
            sig = mp.name(d)
            sp = split_signature(sig)
            if sp:
                entry.update({"name": sp[1], "params": sp[2], "const": sp[3], "owner": "::".join(sp[0])})
            entry["signature"] = sig   # for a pure virtual: the first override's declaration
            slots.append(entry)
        out[cls] = {"gthd_class": hc, "parent": mp.gt.parent(cls),
                    "gthd_parent": (mp.hpar.get(hc) or [None])[0],
                    "slots_here": len(g), "slots_gthd": len(hl), "methods": slots}
    return out


def write_block(path, rows):
    """Replace the GT HD block of symbol_addrs.txt with rows [(name, addr)]."""
    text = open(path).read() if os.path.exists(path) else ""
    if BLOCK_START in text:
        head, rest = text.split(BLOCK_START, 1)
        tail = rest.split(BLOCK_END, 1)[1] if BLOCK_END in rest else ""
        text = head.rstrip("\n") + "\n" + tail.lstrip("\n")
    lines = [BLOCK_START] + [f"{n} = 0x{a:08X}; // type:func gthd" for n, a in rows] + [BLOCK_END]
    text = text.rstrip("\n") + "\n" + "\n".join(lines) + "\n"
    open(path, "w", newline="\n").write(text)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--elf", default=DEFAULT_ELF)
    ap.add_argument("--project", default=os.path.dirname(HERE))
    ap.add_argument("--no-calls", action="store_true")
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--stats", action="store_true", help="only print the numbers")
    a = ap.parse_args()
    root = os.path.abspath(a.project)
    if not os.path.exists(a.elf):
        sys.exit(f"{a.elf}: no such file (set --elf or $GTHD_ELF)")
    h = GTHD(a.elf, os.path.join(root, "build", "gthd"))
    gt = Project(root)
    if not gt.classes:
        sys.exit(f"{root}: no classes.json with classes (tools/rtti.py)")
    mp = Mapper(gt, h)
    mp.run()
    virt, conflicts = virtual_names(mp)

    rows = {}
    for addr, v in virt.items():
        rows[addr] = {"code": h.code_of_desc(v["desc"]), "mangled": h.desc_name[v["desc"]],
                      "conf": v["conf"], "why": v["why"], "source": "vtable"}
    for addr, uses in conflicts.items():
        rows[addr] = {"code": None, "mangled": " | ".join(sorted({h.desc_name[u[2]] for u in uses})),
                      "conf": "conflict", "source": "vtable",
                      "why": "; ".join(f"{u[0]}[{u[1]}] -> {mp.name(u[2])}" for u in uses[:4])}
    n_calls = {}
    if not a.no_calls:
        here, there = here_code(gt), gthd_code(h)
        seeds = {x: r["code"] for x, r in rows.items() if r["conf"] == "high"}
        for x, (y, conf, why) in propagate(seeds, here, there, h, gt).items():
            r = rows.get(x)
            if r and r["conf"] != "conflict" and plain_name(h, r["mangled"]) != plain_name(h, h.code_name[y]):
                # the call graph disagrees with a vtable pairing that was not high: neither stays
                r.update(conf="conflict", why=r["why"] + f"; call graph says {plain_name(h, h.code_name[y])} ({why})")
                continue
            if r:
                r["why"] += f"; call graph agrees ({why})"
                continue
            rows[x] = {"code": y, "mangled": h.code_name[y], "conf": conf, "why": why, "source": "calls"}
            n_calls[conf] = n_calls.get(conf, 0) + 1
    # one GT HD function for two addresses here: a conflict
    by_code = {}
    for x, r in rows.items():
        if r["code"] is not None and r["conf"] != "conflict":
            by_code.setdefault(r["code"], []).append(x)
    for code, xs in by_code.items():
        if len(xs) > 1:
            for x in xs:
                rows[x]["conf"] = "conflict"
                rows[x]["why"] += "; the same GT HD function pairs with " + ", ".join(f"0x{y:08X}" for y in xs if y != x)
    for r in rows.values():
        r["signature"] = plain_name(h, r["mangled"].split(" | ")[0])

    sys.path.insert(0, os.path.join(root, "tools"))
    import symbols
    table = symbols._load()
    gthd_names = set()
    if os.path.exists(symbols.SYMBOL_ADDRS):
        for line in open(symbols.SYMBOL_ADDRS):
            m = re.match(r"\s*(\w+)\s*=.*type:func gthd", line)
            if m:
                gthd_names.add(m.group(1))
    taken = {n: v[0] for n, v in table.names.items() if n not in gthd_names}
    assign_identifiers(rows, taken, {hc: c for c, hc in mp.twin.items()})

    def applied(r):
        return (r["conf"] in (APPLY if r["source"] == "vtable" else APPLY_CALLS)
                and r["kind"] == "func" and "clash" not in r)
    out = sorted(rows.items())
    count = {}
    for x, r in out:
        key = (r["source"], r["conf"])
        count[key] = count.get(key, 0) + 1
    n_virtual = len({x for c in gt.classes if gt.vtable(c) for x in gt.vtable(c)} - {mp.PURE4})
    named_virtual = sum(1 for x, r in out if r["source"] == "vtable" and r["conf"] != "conflict")
    print(f"classes: {len(mp.twin)} of {len(gt.classes)} have a GT HD twin, "
          f"{sum(1 for c in mp.align if mp.align[c])} with paired slots")
    print(f"virtual methods here: {n_virtual}; named {named_virtual} "
          f"(high {count.get(('vtable', 'high'), 0)}, medium {count.get(('vtable', 'medium'), 0)}), "
          f"conflicts {count.get(('vtable', 'conflict'), 0)}")
    print(f"other functions: medium {count.get(('calls', 'medium'), 0)}, low {count.get(('calls', 'low'), 0)}, "
          f"conflicts {count.get(('calls', 'conflict'), 0)}")
    apply_rows = [(r["ident"], x) for x, r in out if applied(r)]
    print(f"names to apply: {len(apply_rows)} "
          f"({sum(1 for x, r in out if 'clash' in r)} refused: name taken)")
    if a.stats:
        return
    with open(os.path.join(root, "config", "gthd_names.txt"), "w", newline="\n") as f:
        f.write("# Generated by tools/gthd_names.py from Gran Turismo HD's symbol table (names only).\n"
                "# address\tname\tconfidence\tapplied\tGT HD signature\treason\n")
        for x, r in out:
            reason = r["why"] + (f"; {r['clash']}" if "clash" in r else "")
            f.write(f"0x{x:08X}\t{r['ident']}\t{r['conf']}\t{'yes' if applied(r) else 'no'}\t"
                    f"{r['signature']}\t{reason}\n")
    with open(os.path.join(root, "config", "gthd_prototypes.json"), "w", newline="\n") as f:
        f.write("{\n" + ",\n".join(f"{json.dumps(c)}: {json.dumps(v, separators=(',', ':'))}"
                                   for c, v in prototypes(mp).items()) + "\n}\n")
    if a.apply:
        write_block(symbols.SYMBOL_ADDRS, apply_rows)
        print(f"wrote {len(apply_rows)} names into {os.path.relpath(symbols.SYMBOL_ADDRS, root)}")


if __name__ == "__main__":
    main()
