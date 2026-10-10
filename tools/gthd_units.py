#!/usr/bin/env python3
"""Translation units and global names for this game from Gran Turismo HD's source-file symbols.

GT HD's 1166.elf (tools/gthd_names.py; read only, never executed, never copied) keeps 1,025
STT_FILE symbols. ELF puts every local symbol before the globals, so a FILE symbol is followed by
the *local* symbols of its translation unit only (static functions, the `_GLOBAL__I_` /
`_GLOBAL__D_` static initialisers, static data, local .opd descriptors), in link order. The
global functions are placed from those:

GT HD side (each code address -> a source file, with a confidence)
  - anchors (high): a local function of file F is in F; so is a function whose TOC loads point
    at a local object of F (static data, a static function's descriptor: statics are private);
  - contiguity: the linker lays the units out in symtab order, so the code between two anchors of
    one file is that file's (high); code after a unit's closing initialiser can still be that
    unit's COMDAT (weak) template/inline instances, nothing else; a gap with one candidate file
    left is that file's;
  - other gaps (between anchors of X and Y; files listed between them without anchors are
    candidates too), medium: the function's TOC entries (each unit has its own, laid out in the
    same order; entries used by two files or from > 2 MB apart are shared and ignored) fall in
    one candidate's TOC range; else its class's name is a candidate's file name (mGame ->
    MGame.cpp); else most of its class's placed functions are in one candidate. Iterated.
  --self-check holds out every other anchor and places it again (2026-10-10: 1,469 high all
  right, 252 medium with 7 wrong, 169 unresolved).

This game's side
  - g++ 2.96 ends every unit with static constructors with a 32-byte `_GLOBAL_.I.` (and
    `_GLOBAL_.D.`) wrapper calling __static_initialization_and_destruction_0(1|0, 0xFFFF):
    every such wrapper is a hard boundary (none is crossed by a GT HD file).
  - Every function paired with GT HD (config/gthd_names.txt, conflicts excepted) whose partner
    has a placed, non-weak file takes that file. Between hard boundaries, the functions are cut
    into runs of one file (a lone non-high label between two runs of one file, or a lone label
    between two runs of >= 3, is an outlier); the boundary between two runs sits between the
    two labels when they are adjacent (high), else at an RTTI boundary of config/units.txt in the
    gap (medium), else right after the earlier run (low). A file that shows up as several runs
    gets `_2`, `_3` (the order of the units differs between the games, the contiguity holds).
  - Every unit lists the compiler profiles of the matched sources in it (first-line marker).
    --check-profiles recompiles, for the named units that mix profiles, the minority sources
    with the majority profile and the majority sources with the minority profile (match.py's
    judge, 2 jobs; build/gthd/profile_check.json).

Globals (--globals, --apply)
  For each pair of functions (high/medium in config/gthd_names.txt), the data its code here
  addresses (lui + addiu/ori/load/store past the code; float constants never stored to and
  string literals left out) and the named GT HD objects its TOC loads point at (symbol, offset)
  vote for "object S starts at A - offset here". high: >= 2 votes, every paired function using
  the address and every paired GT HD function using the object agree, no tie; medium: by
  elimination, a pair of functions with exactly one unexplained datum on each side, no paired
  user of either contradicting it; a medium object that is a static member of the class of every
  paired function using it (mGame::GetClassID and mGame::ClassID_) is high. Names: `::` -> `__`,
  function-local statics `Class__method__var`; vtables / type_info / guards are left to rtti.py;
  a name taken by another address, used in include/ or already used as an identifier in src/ is
  refused. --apply writes the high ones into config/symbol_addrs.txt (`// type:data gthd` block
  that a rerun replaces).

Output (generated, names only, no game data):
  config/units_gthd.txt   START NAME, then tab separated: name confidence, boundary confidence,
                          why, GT HD file, functions, paired functions with a file, profiles
  config/gthd_globals.txt address, name, confidence, applied, GT HD symbol, reason

    gthd_units.py [--elf PATH] [--stats] [--self-check] [--gthd-files OUT.tsv]
    gthd_units.py --check-profiles [N] [--check-from ADDR] [--stats]
    gthd_units.py --globals | --apply
"""
import argparse
import bisect
import collections
import csv
import json
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
from gthd_names import DEFAULT_ELF, GTHD, demangle_all, printable, split_signature  # noqa: E402

ROOT = os.path.dirname(HERE)
BLOCK_START = "// ---- GT HD globals (tools/gthd_units.py --apply; do not edit by hand) ----"
BLOCK_END = "// ---- end of GT HD globals ----"
SOURCE_EXT = re.compile(r"\.(c|cc|cpp|cxx|C)$")


# ------------------------------------------------------------------------------------------
# GT HD: files, functions, TOC references

class Units:
    """GT HD's source files and the file of each of its functions."""

    def __init__(self, h):
        self.h = h
        e = h.elf
        sym = e.by_name[".symtab"]
        d = e.data
        strs = e.sections[sym["link"]]["off"]
        n_sym = sym["size"] // 24
        sh = struct.unpack_from(">IIQQQQIIQQ", d, struct.unpack_from(">Q", d, 0x28)[0]
                                + 64 * e.sections.index(sym))
        first_global = sh[7]
        secname = {i: s["name"] for i, s in enumerate(e.sections)}
        self.files = []          # [{"name", "local_code": [addr], "objects": [(addr, size, name, sec)]}]
        self.weak = set()        # code addresses of weak (COMDAT) functions
        self.data_syms = []      # (addr, size, name, section, file index or None, binding)
        cur = None
        for i in range(n_sym):
            st_name, info, _, shndx, value, size = struct.unpack_from(">IBBHQQ", d, sym["off"] + 24 * i)
            if not st_name:
                continue
            n = d[strs + st_name:d.index(b"\0", strs + st_name)].decode("latin-1")
            bind, typ, sec = info >> 4, info & 15, secname.get(shndx, "")
            if i < first_global and typ == 4:
                cur = len(self.files)
                self.files.append({"name": n, "local_code": [], "objects": []})
                continue
            if sec == ".text":
                if bind == 2 and n.startswith("."):
                    self.weak.add(value)
                if i < first_global and cur is not None and n.startswith("."):
                    self.files[cur]["local_code"].append(value)
                continue
            if sec in (".data", ".bss", ".rodata", ".sbss", ".sdata", ".opd", ".got") and typ in (0, 1):
                f = cur if i < first_global else None
                if f is not None:
                    self.files[f]["objects"].append((value, size, n, sec))
                if sec != ".got":
                    self.data_syms.append((value, size, n, sec, f, bind))
        self.code = sorted(h.code_size)
        self.index = {a: k for k, a in enumerate(self.code)}
        self.toc_refs = self._toc_refs()

    def _toc_refs(self):
        """{code address: [(TOC slot, value)]}: lwz/addi off r2, the TOC from the .opd descriptor.
        For lwz the value is the pointer stored in the slot; for addi it is the address itself."""
        h = self.h
        toc_of = {}
        for desc in h.desc_name:
            c = h.code_of_desc(desc)
            if c is not None:
                toc_of.setdefault(c, h.elf.u32(desc + 4))
        out = {}
        for f in self.code:
            size = h.code_size[f]
            blob = h.elf.read(f, size)
            if not blob or f not in toc_of:
                continue
            toc, refs = toc_of[f], []
            for k in range(size // 4):
                w, = struct.unpack_from(">I", blob, 4 * k)
                op = w >> 26
                if op in (32, 14) and ((w >> 16) & 31) == 2:
                    dd = w & 0xFFFF
                    slot = toc + (dd - 0x10000 if dd & 0x8000 else dd)
                    refs.append((slot, h.elf.u32(slot) if op == 32 else slot))
            out[f] = refs
        return out

    # --- anchors -------------------------------------------------------------------------
    def anchors(self):
        """{code address: (file index, kind)}: local functions and functions using a static."""
        out = {}
        owner = []   # (start, end, file) of local objects
        for fi, f in enumerate(self.files):
            for a in f["local_code"]:
                out[a] = (fi, "local")
            for a, size, n, sec in f["objects"]:
                if sec in (".got",):
                    continue
                # .opd symbols carry no usable size (a descriptor is 8 bytes)
                owner.append((a, a + (8 if sec == ".opd" else max(size, 1)), fi))
                if sec == ".opd":   # a static function's descriptor: its code is local too
                    c = self.h.code_of_desc(a)
                    if c in self.index:
                        out.setdefault(c, (fi, "local"))
        owner.sort()
        starts = [o[0] for o in owner]
        votes = collections.defaultdict(collections.Counter)
        for c, refs in self.toc_refs.items():
            for _, v in refs:
                if v is None:
                    continue
                k = bisect.bisect_right(starts, v) - 1
                if k >= 0 and owner[k][0] <= v < owner[k][1]:
                    votes[c][owner[k][2]] += 1
        for c, cnt in votes.items():
            if c not in out and len(cnt) == 1:
                out[c] = (next(iter(cnt)), "static")
        return out

    def shared_slots(self, known):
        """TOC slots the linker shares between units: used by functions of two known files, or
        from code more than 2 MB apart."""
        users = collections.defaultdict(set)
        span = {}
        for c, refs in self.toc_refs.items():
            for s, _ in refs:
                if c in known:
                    users[s].add(known[c])
                lo, hi = span.get(s, (c, c))
                span[s] = (min(lo, c), max(hi, c))
        return {s for s, fs in users.items() if len(fs) > 1} |             {s for s, (lo, hi) in span.items() if hi - lo > 0x200000}

    def assign(self, holdout=None):
        """{code address: (file index, confidence, how)} for every GT HD function (file None when
        unresolved). high: an anchor, or between two anchors of one file, or a gap with a single
        candidate file; medium: a gap function placed by its TOC entries or its class, or
        between two such of one file. holdout: anchors to ignore (for the self-check)."""
        anchors = {c: v for c, v in self.anchors().items() if not holdout or c not in holdout}
        code = self.code
        cls = self._classes()
        out = {c: (v[0], "high", v[1]) for c, v in anchors.items()}
        for _ in range(6):
            known = {c: v[0] for c, v in out.items() if v[0] is not None and not isinstance(v[0], tuple)}
            shared = self.shared_slots(known)
            own = {c: [s for s, _ in self.toc_refs.get(c, []) if s not in shared] for c in code}
            slot_file = {}
            for c, f in known.items():
                for s in own[c]:
                    slot_file[s] = f
            # each file's TOC range, from its known functions
            rng = {}
            for s, f in slot_file.items():
                lo, hi = rng.get(f, (s, s))
                rng[f] = (min(lo, s), max(hi, s))
            ranges = sorted((lo, hi, f) for f, (lo, hi) in rng.items())
            r_lo = [r[0] for r in ranges]
            # class -> files of its known functions
            cfiles = collections.defaultdict(collections.Counter)
            for c, f in known.items():
                if cls.get(c):
                    cfiles[cls[c]][f] += 1
            ks = [k for k, c in enumerate(code) if c in known]
            changed = False
            for a, b in zip([-1] + ks, ks + [len(code)]):
                inner = range(a + 1, b)
                if not inner:
                    continue
                fa = known[code[a]] if a >= 0 else None
                fb = known[code[b]] if b < len(code) else None
                conf = "high" if all(out[code[x]][1] == "high" for x in (a, b) if 0 <= x < len(code)) else "medium"
                if fa is not None and fa == fb:
                    for k in inner:
                        out[code[k]] = (fa, conf, "between")
                    changed = True
                    continue
                closed = fa is not None and self._closed(fa, code[a])
                base = self._candidates(fa, fb)
                strong_seen = False
                for k in inner:
                    c = code[k]
                    weak = c in self.weak
                    # after a closing initialiser only COMDAT (weak) code can still be fa's:
                    # gcc puts the template / inline instances after it
                    cands = [i for i in base if not (closed and i == fa and (strong_seen or not weak))]
                    strong_seen |= not weak
                    if len(cands) == 1:
                        out[c] = (cands[0], conf, "one candidate")
                        changed = True
                        continue
                    if not cands:
                        out[c] = ((), None, "gap")
                        continue
                    f, how = None, None
                    files = set()
                    for s in own[c]:
                        if s in slot_file:
                            files.add(slot_file[s])
                        else:
                            j = bisect.bisect_right(r_lo, s) - 1
                            if j >= 0 and s <= ranges[j][1]:
                                files.add(ranges[j][2])
                    files &= set(cands)
                    named = [i for i in cands if cls.get(c) and self._stem(i) == self._key(cls[c])]
                    if len(files) == 1:
                        f, how = files.pop(), "TOC"
                    elif len(named) == 1:
                        f, how = named[0], "file name"
                    elif cls.get(c) and cls[c] in cfiles:
                        top = cfiles[cls[c]].most_common(2)
                        if top[0][0] in cands and (len(top) == 1 or top[0][1] >= 3 * top[1][1]):
                            f, how = top[0][0], "class"
                    if f is not None:
                        out[c] = (f, "medium", how)
                        changed = True
                    else:
                        out[c] = (tuple(cands), None, "gap")
            if not changed:
                break
        return out

    def _classes(self):
        """{code address: the C++ class (or namespace) of its function, or None}."""
        dm, out = self.h.dm, {}
        for c in self.code:
            n = self.h.code_name[c]
            sp = split_signature(dm.get(n, n))
            out[c] = "::".join(sp[0]) if sp and sp[0] else None
        return out

    def _candidates(self, fa, fb):
        lo = fa if fa is not None else 0
        hi = fb if fb is not None else len(self.files) - 1
        return [i for i in range(lo, hi + 1) if self._real(i) or i in (fa, fb)]

    def _stem(self, i):
        n = os.path.basename(self.files[i]["name"])
        return self._key(SOURCE_EXT.sub("", n))

    @staticmethod
    def _key(name):
        """A class or file name reduced for comparison: last component, lower case, no
        separators, no leading m (mGame / MGame / mgame.cpp)."""
        n = re.sub(r"[^a-z0-9]", "", name.split("::")[-1].lower())
        return n[1:] if n.startswith("m") and len(n) > 3 else n

    def _real(self, i):
        """A file that can hold code: a source file name (not a header or <built-in>)."""
        n = self.files[i]["name"]
        return bool(SOURCE_EXT.search(n)) and not n.startswith("<")

    def _closed(self, fi, addr):
        """The unit fi ends at addr: its last local function is a `_GLOBAL__I_` / `_GLOBAL__D_`
        static initialiser (gcc emits them after everything else) and addr is at or after it."""
        loc = self.files[fi]["local_code"]
        if not loc:
            return False
        last = max(loc)
        return addr >= last and self.h.code_name.get(last, "").startswith(("_GLOBAL__D_", "_GLOBAL__I_"))


# ------------------------------------------------------------------------------------------
# this game

def here_functions():
    return sorted((int(r["address"], 16), int(r["max_size"]))
                  for r in csv.DictReader(open(os.path.join(ROOT, "build", "functions.csv"))))


def here_reader():
    import project
    _, sections = project.load_image()

    def read(addr, n):
        for base, blob in sections:
            if base <= addr < base + len(blob):
                return blob[addr - base:addr - base + n]
        return None
    return read


def init_wrappers(funcs, read):
    """{address: 'I' | 'D'}: g++ 2.96's `_GLOBAL_.I.` / `_GLOBAL_.D.` wrappers (32 bytes:
    __static_initialization_and_destruction_0(1 or 0, 0xFFFF)), emitted last in their unit."""
    out = {}
    for a, size in funcs:
        if size != 32:
            continue
        w = struct.unpack("<8I", read(a, 32))
        if w[0] == 0x27BDFFF0 and w[2] == 0xFFBF0000 and w[3] >> 26 == 3 and w[4] == 0x3405FFFF                 and w[5:] == (0xDFBF0000, 0x03E00008, 0x27BD0010):
            if w[1] == 0x24040001:
                out[a] = "I"
            elif w[1] == 0x0000202D:
                out[a] = "D"
    return out


def read_pairs():
    """{address here: (confidence, GT HD signature)} from config/gthd_names.txt (no conflicts)."""
    out = {}
    for line in open(os.path.join(ROOT, "config", "gthd_names.txt"), encoding="utf-8"):
        if line.startswith("#"):
            continue
        p = line.rstrip("\n").split("\t")
        if len(p) >= 5 and p[2] != "conflict":
            out[int(p[0], 16)] = (p[2], p[4])
    return out


def labels(u, asg, pairs):
    """{address here: (file index, confidence)} for the functions paired with a GT HD function
    whose file is resolved. COMDAT (weak) functions of GT HD are left out: template and inline
    instances sit wherever the first user put them, in either game."""
    by_sig = collections.defaultdict(list)
    for c, n in u.h.code_name.items():
        by_sig[u.h.dm.get(n, n)].append(c)
    out = {}
    for x, (pconf, sig) in pairs.items():
        cs = by_sig.get(sig)
        if not cs:
            continue
        files = {asg[c][0] for c in cs if asg[c][1] and c not in u.weak}
        if len(files) != 1:
            continue
        f = files.pop()
        fconf = min((asg[c][1] for c in cs if asg[c][1]), key=lambda k: k != "high")
        conf = "low" if pconf == "low" else ("high" if fconf == "high" and pconf == "high" else "medium")
        out[x] = (f, conf)
    return out


def segment(funcs, wrappers, lab, u, old_starts):
    """Units in address order: [{"start", "end", "file", "conf", "why", "labels"}]."""
    addrs = [a for a, _ in funcs]
    # blocks: cut after every static-initialiser wrapper (the D after its I when both)
    blocks, start = [], 0
    for k, a in enumerate(addrs):
        if a in wrappers and not (wrappers[a] == "I" and k + 1 < len(addrs) and wrappers.get(addrs[k + 1]) == "D"):
            blocks.append((start, k + 1))
            start = k + 1
    if start < len(addrs):
        blocks.append((start, len(addrs)))
    units = []
    outliers = []
    for b0, b1 in blocks:
        seq = [(k, lab[addrs[k]][0], lab[addrs[k]][1]) for k in range(b0, b1) if addrs[k] in lab]
        # runs of one file; a lone label (not high) between two runs of one file is an outlier
        while True:
            runs = []
            for item in seq:
                if runs and runs[-1][0][1] == item[1]:
                    runs[-1].append(item)
                else:
                    runs.append([item])
            drop = None
            for i in range(1, len(runs) - 1):
                r = runs[i]
                if runs[i - 1][0][1] == runs[i + 1][0][1] and len(r) <= 2 and                         len(runs[i - 1]) + len(runs[i + 1]) >= 2 * len(r) + 1 and all(c != "high" for _, _, c in r):
                    drop = r
                    break
            if drop is None:
                # the same with a high lone label when its neighbours are long
                for i in range(1, len(runs) - 1):
                    r = runs[i]
                    if runs[i - 1][0][1] == runs[i + 1][0][1] and len(r) == 1 and                             min(len(runs[i - 1]), len(runs[i + 1])) >= 3:
                        drop = r
                        break
            if drop is None:
                # several short runs (<= 2 labels, none high) in a row between two runs of one
                # file with >= 3 labels each: inherited or misnamed slots, not other units
                for i in range(len(runs)):
                    j = i + 1
                    while j < len(runs) and len(runs[j]) <= 2 and all(c != "high" for _, _, c in runs[j]):
                        j += 1
                    if j > i + 1 and j < len(runs) and runs[i][0][1] == runs[j][0][1] and \
                            min(len(runs[i]), len(runs[j])) >= 3:
                        drop = [it for r in runs[i + 1:j] for it in r]
                        break
            if drop is None:
                break
            outliers += [(addrs[k], f) for k, f, _ in drop]
            ids = {k for k, _, _ in drop}
            seq = [it for it in seq if it[0] not in ids]
        init = "static initialiser" if b0 > 0 else "start"
        if not runs:
            units.append({"start": b0, "end": b1, "file": None, "conf": "high", "why": init, "labels": 0})
            continue
        cut = b0
        for i, r in enumerate(runs):
            if i == 0:
                conf, why = "high", init
            else:
                last, first = runs[i - 1][-1][0], r[0][0]
                gap = first - last - 1
                strong = runs[i - 1][-1][2] != "low" and r[0][2] != "low"
                if gap == 0:
                    cut, conf, why = first, "high" if strong else "medium", "adjacent labels"
                else:
                    inside = [k for k in range(last + 1, first + 1) if addrs[k] in old_starts]
                    if inside:
                        cut, conf, why = inside[0], "medium", f"RTTI boundary in a gap of {gap}"
                    else:
                        cut, conf, why = last + 1, "low", f"somewhere in a gap of {gap} function(s)"
                units[-1]["end"] = cut
            units.append({"start": cut, "end": b1, "file": r[0][1], "conf": conf, "why": why,
                          "labels": len(r), "label_confs": [c for _, _, c in r]})
    for un in units:
        # how sure the name is: the number and confidence of the pairs that give it
        lc = un.pop("label_confs", [])
        n_high = lc.count("high")
        size = un["end"] - un["start"]
        if un["file"] is None:
            un["name_conf"] = "-"
        elif len(lc) >= 3 and n_high >= 1 or n_high >= 2:
            un["name_conf"] = "high"
        elif n_high == 1 and size <= 40 or len(lc) >= 2 and "low" not in lc:
            un["name_conf"] = "medium"
        else:
            un["name_conf"] = "low"
    return units, outliers


def profiles_of(units, addrs):
    """Per unit: Counter of the compiler profiles of the sources in it (default = no marker)."""
    import project
    srcs = project.sources()
    out = []
    for un in units:
        cnt = collections.Counter()
        for a in addrs[un["start"]:un["end"]]:
            p = srcs.get(a)
            if p:
                cnt[project.source_compiler(p) or "default"] += 1
        out.append(cnt)
    return out


def read_units(path):
    out = []
    for line in open(path):
        if line.strip() and not line.startswith("#"):
            p = line.split()
            out.append((int(p[0], 16), p[1]))
    return sorted(out)


def old_units(addrs):
    """config/units.txt as the same records as segment() returns."""
    idx = {a: k for k, a in enumerate(addrs)}
    rows = [(idx[a], n) for a, n in read_units(os.path.join(ROOT, "config", "units.txt")) if a in idx]
    return [{"start": k, "end": (rows[i + 1][0] if i + 1 < len(rows) else len(addrs)), "name": n}
            for i, (k, n) in enumerate(rows)]


def mixed(units, profs, ignore=()):
    """Units whose sources use more than one profile (profiles in ignore not counted)."""
    return [i for i, c in enumerate(profs) if len([p for p in c if p not in ignore]) > 1]


# ------------------------------------------------------------------------------------------
# globals

STORES = (40, 41, 43, 57, 61, 63, 31)   # sb sh sw swc1 sdc1 sd sq


def here_data_refs(funcs, read, lo_data, wanted=None):
    """({function: [data address, ...]} in order of first use, {addresses stored to}): lui +
    addiu/ori/load/store pairs whose address is past the code (>= lo_data); only the functions in
    wanted are listed (all are scanned for stores). A register's lui is forgotten when the
    register is written by anything else. Float loads (lwc1/ldc1) of an address nothing stores
    to are constants, and addresses of string literals are literals: GT HD names neither."""
    out, written, floats = {}, set(), {}
    for f, size in funcs:
        code = read(f, size)
        if not code or len(code) < size:
            continue
        refs, hi = [], {}
        for k in range(size // 4):
            w, = struct.unpack_from("<I", code, 4 * k)
            op, rs, rt, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
            if op == 15:
                hi[rt] = imm << 16
                continue
            if rs in hi and op in (9, 13, 32, 33, 35, 36, 37, 39, 49, 53, 55, 30) + STORES:
                addr = (hi[rs] | imm) if op == 13 else (hi[rs] + (imm - 0x10000 if imm & 0x8000 else imm)) & 0xFFFFFFFF
                if addr >= lo_data:
                    if op in STORES:
                        written.add(addr)
                    if addr not in refs:
                        refs.append(addr)
                        floats.setdefault(addr, True)
                    if op not in (49, 53):
                        floats[addr] = False
            # a register written by this instruction loses its lui (rt for I-type, rd for R-type)
            if op == 0:
                hi.pop((w >> 11) & 31, None)
            elif op not in STORES + (4, 5, 1, 2, 3):
                hi.pop(rt, None)
        if wanted is None or f in wanted:
            out[f] = refs
    for f, refs in out.items():
        out[f] = [a for a in refs if not (floats.get(a) and a not in written)
                  and not printable(read(a, 256))]
    return out


def gthd_data_refs(u):
    """{GT HD function: [(symbol index, offset), ...]}: the named data objects its TOC loads point
    at (the pointer in the slot), in order of first use."""
    syms = sorted((a, s, n, sec, f, b) for a, s, n, sec, f, b in u.data_syms
                  if sec in (".data", ".bss", ".rodata", ".sbss", ".sdata") and s > 0)
    starts = [x[0] for x in syms]
    out = {}
    for c, refs in u.toc_refs.items():
        seen = []
        for _, v in refs:
            if v is None:
                continue
            k = bisect.bisect_right(starts, v) - 1
            if k >= 0 and syms[k][0] <= v < syms[k][0] + syms[k][1]:
                key = (k, v - syms[k][0])
                if key not in seen:
                    seen.append(key)
        out[c] = seen
    return syms, out


def pair_globals(pairs_code, here_refs, there_refs, syms):
    """{here address: (symbol index, confidence, votes, support here, support there)}.
    A GT HD object S at offset o used by a paired function y, and a data address A used by its
    partner x, vote for "S starts at A - o here". Kept when the vote is consistent: every paired
    function here that uses A - o + o (support here) and every paired GT HD function that uses S
    at o (support there) agree, and no other candidate ties. high: >= 2 votes; medium: 1 vote
    left once the high pairs are taken out of both functions' lists (elimination)."""
    votes = collections.Counter()
    sup_here = collections.Counter()
    sup_there = collections.Counter()
    used = [(x, y) for x, y in pairs_code if x in here_refs and y in there_refs]
    for x, y in used:
        for a in here_refs[x]:
            sup_here[a] += 1
        for key in there_refs[y]:
            sup_there[key] += 1
        for a in here_refs[x]:
            for (k, o) in there_refs[y]:
                votes[(a - o, k, o, a)] += 1
    # best candidate per here address and per GT HD symbol
    by_addr = collections.defaultdict(list)
    for (start, k, o, a), n in votes.items():
        by_addr[a].append((n, k, o, start))
    chosen = {}
    for a, cands in by_addr.items():
        cands.sort(reverse=True)
        n, k, o, start = cands[0]
        if len(cands) > 1 and cands[1][0] == n:
            continue
        if n < 2 or n != sup_here[a] or n != sup_there[(k, o)]:
            continue
        chosen.setdefault(start, set()).add((k, o, a, n))
    out = {}
    taken = {}
    for start, items in chosen.items():
        ks = {k for k, _, _, _ in items}
        if len(ks) != 1:
            continue
        k = ks.pop()
        if k in taken and taken[k] != start:
            taken[k] = None
            continue
        taken[k] = start
        n = max(i[3] for i in items)
        out[start] = (k, "high", n, max(sup_here[i[2]] for i in items), max(sup_there[(k, i[1])] for i in items))
    for k, start in list(taken.items()):
        if start is None:
            out = {s: v for s, v in out.items() if v[0] != k}
    # elimination: a paired function with exactly one unexplained datum on each side, kept when
    # every other paired function using either one agrees
    users_here = collections.defaultdict(list)
    users_there = collections.defaultdict(list)
    for x, y in used:
        for a in here_refs[x]:
            users_here[a].append((x, y))
        for key in there_refs[y]:
            users_there[key].append((x, y))
    known_sym = {k: s for s, (k, *_rest) in out.items()}
    for _ in range(4):
        new = collections.Counter()
        for x, y in used:
            explained = {known_sym[k] + o for (k, o) in there_refs[y] if k in known_sym}
            ra = [a for a in here_refs[x] if a not in explained]
            rb = [(k, o) for (k, o) in there_refs[y] if k not in known_sym]
            if len(ra) == 1 and len(rb) == 1:
                new[(ra[0], rb[0])] += 1
        a_count = collections.Counter(a for a, _ in new)
        k_count = collections.Counter(key[0] for _, key in new)
        added = False
        for (a, (k, o)), n in new.items():
            start = a - o
            if a_count[a] != 1 or k_count[k] != 1 or start in out or k in known_sym:
                continue
            if any((k, o) not in there_refs[y] for x, y in users_here[a]) or \
                    any(a not in here_refs[x] for x, y in users_there[(k, o)]):
                continue
            out[start] = (k, "medium", n, sup_here[a], sup_there[(k, o)])
            known_sym[k] = start
            added = True
        if not added:
            break
    return out


def global_identifier(dm_name):
    """`mGame::ClassID_` -> mGame__ClassID_, a function-local static `A::f(int) const::x` ->
    A__f__x; `vtable for X` / `typeinfo for X` (tools/rtti.py names those), guard variables and
    other compiler objects -> None. Runs of three or more underscores become two and a trailing
    double underscore one (gcc 2.96 manglings start at `__`, tools/symbols.py reads them)."""
    if dm_name.startswith(("vtable for", "typeinfo", "guard variable", "VTT for", "construction vtable")):
        return None
    m = re.match(r"(.*?)\(.*\)(?: const)?::([^()]+)$", dm_name)
    n = f"{m.group(1)}::{m.group(2)}" if m else dm_name
    n = re.sub(r"<[^<>]*>", "", n).replace("::", "__")
    n = re.sub(r"[^\w]+", "_", n).lstrip("_")
    n = re.sub(r"_{3,}", "__", n)
    if n.endswith("__"):
        n = n[:-1]
    return n if re.match(r"[A-Za-z]\w*$", n) else None


def write_globals_block(path, rows):
    text = open(path, encoding="utf-8").read()
    if BLOCK_START in text:
        a = text.index(BLOCK_START)
        b = text.index(BLOCK_END, a) + len(BLOCK_END)
        text = text[:a].rstrip("\n") + "\n" + text[b:].lstrip("\n")
    text = text.rstrip("\n") + "\n" + BLOCK_START + "\n" + "".join(
        f"{n} = 0x{addr:08X}; // type:data gthd\n" for addr, n in rows) + BLOCK_END + "\n"
    open(path, "w", encoding="utf-8", newline="\n").write(text)


def globals_main(u, asg, funcs, read, apply):
    import symbols
    pairs = read_pairs()
    by_sig = collections.defaultdict(list)
    for c, n in u.h.code_name.items():
        by_sig[u.h.dm.get(n, n)].append(c)
    pairs_code = []
    for x, (pconf, sig) in pairs.items():
        cs = by_sig.get(sig, [])
        if len(cs) == 1 and pconf in ("high", "medium"):
            pairs_code.append((x, cs[0]))
    text_end = max(a + s for a, s in funcs)
    here_refs = here_data_refs(funcs, read, text_end, wanted=dict(pairs_code))
    syms, there_refs = gthd_data_refs(u)
    found = pair_globals(pairs_code, here_refs, there_refs, syms)
    names = [s[2] for s in syms]
    dm = demangle_all(set(names), os.path.join(ROOT, "build", "gthd", "demangled.json"))
    # a medium pair (one function on each side) is high when the object is a static member of
    # the class of every paired GT HD function that uses it (mX::GetClassID and mX::ClassID_)
    cls = u._classes()
    users = collections.defaultdict(set)
    for x, y in pairs_code:
        for k, _ in there_refs.get(y, []):
            users[k].add(y)
    for start, (k, conf, n, sh, st) in list(found.items()):
        owner = dm.get(syms[k][2], syms[k][2]).rsplit("::", 1)[0] if "::" in dm.get(syms[k][2], "") else None
        if conf == "medium" and owner and users[k] and all(cls.get(y) == owner for y in users[k]):
            found[start] = (k, "high", n, sh, st)
    table = symbols._load()
    gthd_data = set()
    for line in open(symbols.SYMBOL_ADDRS, encoding="utf-8"):
        m = re.match(r"\s*(\w+)\s*=.*type:data gthd", line)
        if m:
            gthd_data.add(m.group(1))
    taken = {n: v[0] for n, v in table.names.items() if n not in gthd_data}
    # identifiers already used in headers or sources (a local variable, a field, a type): a global
    # of that name would shadow or be shadowed once tools/organize.py renames D_ADDR
    headers, in_src = set(), set()
    for top, bag in (("include", headers), ("src", in_src)):
        for dirpath, _, files in os.walk(os.path.join(ROOT, top)):
            for f in files:
                bag.update(re.findall(r"\b[A-Za-z_]\w*\b", open(os.path.join(dirpath, f), errors="replace").read()))
    rows = []
    for start, (k, conf, n, sh, st) in sorted(found.items()):
        a, size, mname, sec, fi, bind = syms[k]
        dmn = dm.get(mname, mname)
        ident = global_identifier(dmn)
        note = ""
        if ident is None:
            note = "compiler object"
        elif ident in taken and taken[ident] != start:
            note = f"name taken by 0x{taken[ident]:08X}"
        elif ident in headers:
            note = "name used in include/"
        elif ident in in_src and taken.get(ident) != start:
            note = "name already used in src/"
        here_name = table.canonical.get(start)
        if here_name and here_name not in gthd_data and not note:
            note = f"already named {here_name}"
        rows.append((start, ident, conf, n, sh, st, dmn, sec, size, fi, note))
    cnt = collections.Counter(r[1] for r in rows if r[1] and not r[10])
    out = []
    for r in rows:
        start, ident, conf, n, sh, st, dmn, sec, size, fi, note = r
        if not note and cnt[ident] > 1:
            note = "two addresses would get this name"
        out.append((start, ident, conf, n, sh, st, dmn, sec, size, fi, note))
    path = os.path.join(ROOT, "config", "gthd_globals.txt")
    with open(path, "w", newline="\n") as f:
        f.write("# Generated by tools/gthd_units.py from Gran Turismo HD's symbol table (names only).\n"
                "# address\tname\tconfidence\tapplied\tGT HD symbol\treason\n")
        for start, ident, conf, n, sh, st, dmn, sec, size, fi, note in out:
            applied = conf == "high" and not note
            fname = u.files[fi]["name"] if fi is not None else "global"
            f.write(f"0x{start:08X}\t{ident or '-'}\t{conf}\t{'yes' if applied else 'no'}\t{dmn}\t"
                    f"{n} paired function(s) agree (used by {sh} here, {st} there); {sec}, {size} bytes, "
                    f"{fname}{'; ' + note if note else ''}\n")
    c = collections.Counter(r[2] for r in out)
    apply_rows = [(r[0], r[1]) for r in out if r[2] == "high" and not r[10]]
    print(f"globals: {len(out)} paired ({', '.join(f'{k} {v}' for k, v in sorted(c.items()))}); "
          f"{len(apply_rows)} high to apply; wrote {os.path.relpath(path, ROOT)}")
    if apply:
        write_globals_block(symbols.SYMBOL_ADDRS, apply_rows)
        print(f"wrote {len(apply_rows)} names into {os.path.relpath(symbols.SYMBOL_ADDRS, ROOT)}")


def with_profile(src, profile, out_dir):
    """A copy of src under out_dir whose first-line marker asks for profile (None: default)."""
    import project
    text = open(src, encoding="utf-8", errors="replace").read()
    lines = text.split("\n")
    if lines and project.COMPILER_MARKER.match(lines[0]):
        lines = lines[1:]
    if profile:
        lines = [f"/* compiler: {profile} */"] + lines
    dst = os.path.join(out_dir, f"{profile or 'default'}__{os.path.basename(src)}")
    open(dst, "w", encoding="utf-8", newline="\n").write("\n".join(lines))
    return dst


def check_profiles(units, profs, addrs, jobs=2, limit=None, first=0):
    """For each named unit whose matched sources use several profiles (the STL profile aside):
    recompile the minority sources with the unit's majority profile (A) and the majority sources
    with the minority profile (B). A source of A that still matches did not need its marker; when
    every source of B matches, the whole unit is consistent with the minority profile."""
    import project
    import match
    srcs = project.sources()
    out_dir = os.path.join(ROOT, "build", "gthd", "profile_check")
    os.makedirs(out_dir, exist_ok=True)
    report = []
    todo = [i for i in mixed(units, profs, ignore=("ee-gcc2.96-stl",))
            if units[i]["file"] is not None and units[i]["name_conf"] != "low" and addrs[units[i]["start"]] >= first]
    for i in todo[:limit]:
        un = units[i]
        members = [(a, srcs[a]) for a in addrs[un["start"]:un["end"]] if a in srcs]
        prof = {a: project.source_compiler(p) or "default" for a, p in members}
        prof = {a: p for a, p in prof.items() if p != "ee-gcc2.96-stl"}
        major = collections.Counter(prof.values()).most_common(1)[0][0]
        minors = sorted({p for p in prof.values() if p != major})
        jobs_a = [(a, with_profile(p, None if major == "default" else major, out_dir))
                  for a, p in members if prof.get(a) not in (None, major)]
        res_a = {a: ok for a, _, ok, _ in match.judge_many(jobs_a, jobs)}
        res_b = {}
        if len(minors) == 1:
            jobs_b = [(a, with_profile(p, None if minors[0] == "default" else minors[0], out_dir))
                      for a, p in members if prof.get(a) == major]
            res_b = {a: ok for a, _, ok, _ in match.judge_many(jobs_b, jobs)}
        for _, p in jobs_a + (jobs_b if len(minors) == 1 else []):
            try:
                os.remove(p)
            except OSError:
                pass
        row = {"unit": un["name"], "start": f"{addrs[un['start']]:08X}", "major": major, "minors": minors,
               "minority": {f"{a:08X}": [prof[a], res_a.get(a)] for a in res_a},
               "B": [sum(res_b.values()), len(res_b)] if res_b else None,
               "B_fail": [f"{a:08X}" for a, ok in res_b.items() if not ok][:20]}
        report.append(row)
        print(f"{row['start']} {row['unit']}: majority {major}; minority "
              + ", ".join(f"{k} {v[0]} {'still matches' if v[1] else 'needs it'}" for k, v in row["minority"].items())
              + (f"; all {major} sources with {minors[0]}: {row['B'][0]}/{row['B'][1]} match" if row["B"] else ""),
              flush=True)
    return report


def self_check(u):
    """Hold out every other local anchor and place it again: (confidence, how, ok?) counts."""
    anc = u.anchors()
    held = set(sorted(anc)[::2])
    asg = u.assign(holdout=held)
    res = collections.Counter()
    for c in held:
        f, conf, how = asg[c]
        res[(conf or "unresolved", how, f == anc[c][0])] += 1
    return res


def unit_names(units, u, addrs):
    seen = collections.Counter()
    for un in units:
        if un["file"] is None:
            un["name"] = f"unit_{addrs[un['start']]:08X}"
            continue
        stem = re.sub(r"\W", "_", SOURCE_EXT.sub("", os.path.basename(u.files[un["file"]]["name"])))
        seen[stem] += 1
        un["name"] = stem if seen[stem] == 1 else f"{stem}_{seen[stem]}"


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--elf", default=DEFAULT_ELF)
    ap.add_argument("--stats", action="store_true", help="print the numbers, write nothing")
    ap.add_argument("--self-check", action="store_true", help="hold out half of GT HD's anchors")
    ap.add_argument("--gthd-files", metavar="TSV", help="also write GT HD's code address -> file")
    ap.add_argument("--globals", action="store_true", help="pair globals -> config/gthd_globals.txt")
    ap.add_argument("--apply", action="store_true",
                    help="--globals, and write the high ones into config/symbol_addrs.txt")
    ap.add_argument("--check-profiles", type=int, nargs="?", const=0, metavar="N",
                    help="recompile the sources of (the first N) units that mix profiles with the "
                         "other profile (match.py judge, 2 jobs) -> build/gthd/profile_check.json")
    ap.add_argument("--check-from", default="0", metavar="ADDR", help="--check-profiles from this unit on (adds to the report)")
    a = ap.parse_args()
    if not os.path.exists(a.elf):
        sys.exit(f"{a.elf}: no such file (set --elf or $GTHD_ELF)")
    h = GTHD(a.elf, os.path.join(ROOT, "build", "gthd"))
    u = Units(h)
    asg = u.assign()
    cnt = collections.Counter(v[1] or "unresolved" for v in asg.values())
    print(f"GT HD: {len(u.files)} FILE symbols, {sum(1 for i in range(len(u.files)) if u._real(i))} source files, "
          f"{len(u.code)} functions: " + ", ".join(f"{k} {v}" for k, v in sorted(cnt.items())))
    if a.self_check:
        for k, v in sorted(self_check(u).items(), key=lambda x: -x[1]):
            print("  held-out anchor", k, v)
    if a.gthd_files:
        with open(a.gthd_files, "w", newline="\n") as f:
            for c in u.code:
                fi, conf, how = asg[c]
                name = u.files[fi]["name"] if isinstance(fi, int) else "|".join(u.files[i]["name"] for i in fi)
                sig = h.dm.get(h.code_name[c], h.code_name[c])
                f.write(f"{c:08X}\t{name}\t{conf or '-'}\t{how}\t{sig}\n")

    funcs = here_functions()
    addrs = [x for x, _ in funcs]
    read = here_reader()
    if a.globals or a.apply:
        globals_main(u, asg, funcs, read, a.apply)
        return
    wrappers = init_wrappers(funcs, read)
    pairs = read_pairs()
    lab = labels(u, asg, pairs)
    print(f"here: {len(funcs)} functions, {len(wrappers)} static-initialiser wrappers, "
          f"{len(pairs)} GT HD pairs, {len(lab)} with a file "
          f"({', '.join(f'{k} {v}' for k, v in sorted(collections.Counter(c for _, c in lab.values()).items()))})")
    old = old_units(addrs)
    old_starts = {addrs[o["start"]] for o in old}
    units, outliers = segment(funcs, wrappers, lab, u, old_starts)
    unit_names(units, u, addrs)
    named = [x for x in units if x["file"] is not None]
    cover = sum(x["end"] - x["start"] for x in named)
    bytes_named = sum(funcs[k][1] for x in named for k in range(x["start"], x["end"]))
    by_file = collections.Counter(x["file"] for x in named)
    print(f"units: {len(units)} ({len(named)} named after {len(by_file)} GT HD files, "
          f"{sum(1 for v in by_file.values() if v > 1)} files split over several runs); "
          f"named units cover {cover} of {len(funcs)} functions, {bytes_named} of "
          f"{sum(s for _, s in funcs)} bytes; {len(outliers)} outlier labels")
    for nc in ("high", "medium", "low"):
        xs = [x for x in named if x["name_conf"] == nc]
        print(f"  name {nc}: {len(xs)} units, {sum(x['end'] - x['start'] for x in xs)} functions, "
              f"{sum(funcs[k][1] for x in xs for k in range(x['start'], x['end']))} bytes")
    print("boundaries: " + ", ".join(f"{k} {v}" for k, v in sorted(collections.Counter(
        x["conf"] for x in units[1:]).items())))
    profs = profiles_of(units, addrs)
    old_profs = profiles_of(old, addrs)
    for title, us, ps in (("config/units.txt", old, old_profs), ("proposal", units, profs)):
        m_all = mixed(us, ps)
        m_nostl = mixed(us, ps, ignore=("ee-gcc2.96-stl",))
        print(f"{title}: {len(us)} units, {len(m_all)} mix compiler profiles "
              f"({len(m_nostl)} not counting the STL profile)")
    m_named = [i for i in mixed(units, profs, ignore=("ee-gcc2.96-stl",)) if units[i]["file"] is not None]
    print(f"named units mixing profiles (STL aside): {len(m_named)}")
    for i in m_named[:40]:
        print(f"  {addrs[units[i]['start']]:08X} {units[i]['name']}: {dict(profs[i])}")
    if a.check_profiles is not None:
        report = check_profiles(units, profs, addrs, limit=a.check_profiles or None, first=int(a.check_from, 16))
        out = os.path.join(ROOT, "build", "gthd", "profile_check.json")
        if a.check_from != "0" and os.path.exists(out):
            seen = {r["start"] for r in report}
            report = [r for r in json.load(open(out)) if r["start"] not in seen] + report
        json.dump(sorted(report, key=lambda r: r["start"]), open(out, "w"), indent=1)
        print(f"wrote {os.path.relpath(out, ROOT)}")
    if a.stats:
        return
    path = os.path.join(ROOT, "config", "units_gthd.txt")
    with open(path, "w", newline="\n") as f:
        f.write("# Translation units proposed by tools/gthd_units.py from Gran Turismo HD's source-file\n"
                "# symbols (names only). START NAME, then (tab separated):\n"
                "#   name confidence: high (>= 2 high pairs, or >= 3 pairs with a high one), medium (one\n"
                "#     high pair in <= 40 functions, or 2 pairs), low (one pair: check before using);\n"
                "#   boundary confidence at START: high (after a static initialiser, or between adjacent\n"
                "#     functions of two files), medium (an RTTI boundary of config/units.txt inside the\n"
                "#     gap between two files), low (somewhere in that gap);\n"
                "#   why; GT HD file; functions; functions paired with a file; profiles of the matched\n"
                "#   sources (default = no compiler marker).\n")
        for x, pc in zip(units, profs):
            gf = u.files[x["file"]]["name"] if x["file"] is not None else "-"
            pr = ",".join(f"{k}:{v}" for k, v in sorted(pc.items())) or "-"
            f.write(f"{addrs[x['start']]:08x} {x['name']}\t{x['name_conf']}\t{x['conf']}\t{x['why']}\t{gf}\t"
                    f"{x['end'] - x['start']}\t{x['labels']}\t{pr}\n")
    print(f"wrote {os.path.relpath(path, ROOT)}")


if __name__ == "__main__":
    main()
