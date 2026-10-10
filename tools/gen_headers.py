#!/usr/bin/env python3
"""Game headers: include/<game>/<Class>.h (include/gt4/ here, include/tt/ in Tourist Trophy), one per
class of config/classes.json, generated, never edited by hand.

    gen_headers.py [--class NAME ...] [--check]
        write the headers of every class (or the named ones); --check: exit 1 if a header is not
        what the inputs say (nothing written)
    gen_headers.py show NAME       print one header
    gen_headers.py stats           classes, member sources, harvested fields, conflicts
    gen_headers.py facts           config/class_layout.json: vptr offsets and sizes from the code
    gen_headers.py test            compile all headers as C and C++ (GT4_CXX, GT4_DECLS) and check
                                   sizeof, field offsets, vptr and vtable slots on the compiler
    gen_headers.py convert CLASS... [--write] [--limit N]
                                   sources' local declarations of those classes' functions replaced
                                   by the headers' prototypes; written only on MATCH
    gen_headers.py rejudge         judge every source that uses GT4_CXX / GT4_DECLS (after a regeneration)

A source opts in: `#define GT4_CXX` before the include gives the C++ class (base class, own fields,
the vptr where g++ 2.96 puts it, the virtual methods in slot order with GT HD names and parameter
types, the non-virtual GT HD methods, padding to the size), `#define GT4_DECLS` the C prototypes of
the class's functions under their symbol names. Without them a header is the C struct below, as
before (the 1,100+ sources that include one do not change).

What a header holds:
  - the class as a C struct (usable from .c and .cpp sources): the fields its member functions are
    seen to use, at their offsets, with char padding between them; the fields of its primary base
    chain too (a derived object starts with its base). Fields are named unk<OFFSET>; one offset
    read as several types becomes an anonymous union (unk10, unk10_f32...). Where two fields
    overlap, the later one is left out and the source that needs it keeps its own struct.
  - as comments: the bases, the vtable (address, slot count), type_info and structor addresses,
    and every vtable slot (address, source, and the GT HD name and signature when
    config/gthd_prototypes.json has it).
The fields come from the structs tools/cleanup.py fields wrote for the first parameter (`this`) of
the class's own functions (addresses in its methods/structors in classes.json, each owned by one
class); the size of a class is not known (classes.json has none), only how far its fields go.

tools/cleanup.py classes then makes those sources use the header (judged, kept only on MATCH).
config/gthd_names.txt / config/gthd_prototypes.json come from tools/gthd_names.py; when they are
missing the headers simply carry no GT HD names.
"""
import argparse
import json
import os
import re
import sys

import project

ROOT = project.ROOT
CLASSES = os.path.join(ROOT, "config", "classes.json")
PROTOTYPES = os.path.join(ROOT, "config", "gthd_prototypes.json")
# {class: {"0xOFF": [declaration, ...]}}: every field type ever harvested, in the order first seen
# (the first is the field's plain name unk<OFF>, later ones unk<OFF>_<type> in a union). Kept, not
# recomputed: a source converted to the header no longer has its own struct to harvest from.
FIELDS = os.path.join(ROOT, "config", "class_fields.json")
GAME = project.BASENAME  # include/<game>/: gt4, tt
OUT = os.path.join(ROOT, "include", GAME)

SIZES = {"s8": 1, "u8": 1, "char": 1, "s16": 2, "u16": 2, "short": 2, "s32": 4, "u32": 4, "f32": 4,
         "int": 4, "float": 4, "long": 4, "s64": 8, "u64": 8, "f64": 8, "double": 8, "s128": 16, "u128": 16}
# words a field's declaration may use: the header includes only types.h
ALLOWED = set(SIZES) | {"void", "const", "unsigned", "signed", "volatile"}
FIELD = re.compile(r"^\s*(.+?)\s*;\s*$")
PAD = re.compile(r"^\s*(?:char|u8|s8)\s+pad[0-9A-Fa-f]*\s*\[[^\]]*\]\s*;\s*$")


_cache = {}


def header_file(cls, classes=None):
    """The header's file name: CLASS.h, except for a class whose name differs from another's
    only in case (HObject / hObject: one file on Windows): the one starting with a capital
    gets CLASS_.h (the other kept the plain name it has had since the first headers)."""
    if classes is None:
        classes = _cache.get("classes") or _cache.setdefault("classes", load_classes())
    twins = [c for c in classes if c.lower() == cls.lower() and c != cls]
    return f"{cls}_.h" if twins and cls[:1].isupper() and not all(t[:1].isupper() for t in twins) else f"{cls}.h"


def load_classes():
    return json.load(open(CLASSES)) if os.path.exists(CLASSES) else {}


def load_prototypes():
    """{class: {slot: method}} from config/gthd_prototypes.json, or {} while it does not exist."""
    if not os.path.exists(PROTOTYPES):
        return {}
    try:
        data = json.load(open(PROTOTYPES, encoding="utf-8"))
    except ValueError:
        return {}
    return {c: {m["slot"]: m for m in v.get("methods", []) if "slot" in m} for c, v in data.items()}


def owners(classes):
    """{address: class} of the functions exactly one class lists as its own (methods, structors)."""
    seen = {}
    for name, c in classes.items():
        for a in [m["address"] for m in c.get("methods", [])] + list(c.get("structors", [])):
            seen.setdefault(a, set()).add(name)
    return {a: next(iter(cs)) for a, cs in seen.items() if len(cs) == 1}


SPELLINGS = [(r"\bunsigned\s+long\s+long\b", "u64"), (r"\blong\s+long\b", "s64"), (r"\bunsigned\s+int\b", "u32"),
             (r"\bunsigned\s+short\b", "u16"), (r"\bunsigned\s+char\b", "u8"), (r"\bsigned\s+char\b", "s8"),
             (r"\bunsigned\b", "u32"), (r"\bint\b", "s32"), (r"\bshort\b", "s16"), (r"\blong\b", "s32"),
             (r"\bfloat\b", "f32"), (r"\bdouble\b", "f64")]


def normalize(decl):
    """A field declaration with the C type names spelled as types.h names (int -> s32, float -> f32...):
    the same types, so one field, not two."""
    for pat, rep in SPELLINGS:
        decl = re.sub(pat, rep, decl)
    return re.sub(r"\s+", " ", decl).strip()


def field_size(decl):
    """(size, alignment) of a field declaration, or None."""
    if "(" in decl or "*" in decl:
        return 4, 4
    words = decl.split()[:-1]
    base = " ".join(w for w in words if w not in ("const", "volatile"))
    base = {"unsigned int": "int", "signed char": "char", "unsigned char": "char", "unsigned short": "short",
            "long long": "s64", "unsigned long long": "s64", "unsigned": "int"}.get(base, base)
    size = SIZES.get(base)
    return (size, size) if size else None


def this_struct(text):
    """(struct name, its definition's (start, end), [(offset, declaration, size)], first parameter
    name) for the struct a source's function takes as its first parameter, when tools/cleanup.py
    wrote it (padding and unk<OFFSET> fields only); else None."""
    import cleanup
    code = cleanup.strip_comments(text)
    funcs = cleanup.functions(code)
    if not funcs:
        return None
    fname, h0, b0, _, _ = funcs[-1]
    # the first parameter: `struct S *p` (the variable retyped), or `void *p` with the accesses
    # cast to the struct cleanup.py named after the function and the parameter
    m = re.search(r"\(\s*(?:const\s+)?struct\s+(\w+)\s*\*\s*(\w+)\s*[,)]", code[h0:b0])
    if m:
        name, param = m.group(1), m.group(2)
    else:
        m = re.search(r"\(\s*(?:const\s+)?void\s*\*\s*(\w+)\s*[,)]", code[h0:b0])
        if not m:
            return None
        param = m.group(1)
        name = f"{re.sub(r'[^0-9A-Za-z_]', '_', fname)}_{param}"
    d = re.search(r"^struct %s \{\n(.*?)^\};\n" % re.escape(name), text, re.M | re.S)
    if not d:
        return None
    fields = []
    for line in d.group(1).splitlines():
        if not line.strip() or PAD.match(line):
            continue
        f = FIELD.match(line)
        n = re.search(r"\bunk([0-9A-F]+)\b", f.group(1)) if f else None
        if not n:
            return None  # a hand-written struct: not ours to merge
        decl = f.group(1)
        size = field_size(decl)
        if size is None:
            return None
        fields.append((int(n.group(1), 16), decl, size[0]))
    return name, (d.start(), d.end()), fields, param


def suffix(decl, name):
    """A name for another type at the same offset: unk10 -> unk10_f32, unk10_pvoid (void *),
    unk10_ppvoid (void **), unk10_fn (a function pointer)."""
    t = decl.replace(name, "").strip()
    if "(" in t:
        return name + "_fn"
    if "*" in t:
        return name + "_" + "p" * t.count("*") + re.sub(r"\W+", "_", t.replace("*", "")).strip("_").split("_")[-1]
    return name + "_" + re.sub(r"\W+", "_", t).strip("_")


def harvest(classes=None):
    """{class: {offset: [declaration, ...]}} of the fields the class's own functions use through
    the struct tools/cleanup.py fields gave their first parameter, most used first."""
    classes = load_classes() if classes is None else classes
    own = owners(classes)
    srcs = project.sources(refresh=True)
    counts = {}
    for addr, cls in own.items():
        path = srcs.get(addr)
        if not path:
            continue
        try:
            text = open(path, encoding="utf-8", errors="replace").read().replace("\r\n", "\n")
        except OSError:
            continue
        found = this_struct(text)
        if not found:
            continue
        for off, decl, size in found[2]:
            decl = normalize(decl)
            words = set(re.findall(r"[A-Za-z_]\w*", decl)) - {f"unk{off:X}"}
            if not words <= ALLOWED:
                continue
            per = counts.setdefault(cls, {}).setdefault(off, {})
            per[decl] = per.get(decl, 0) + 1
    return {c: {o: sorted(v, key=lambda d: (-v[d], d)) for o, v in offs.items()} for c, offs in counts.items()}


def load_fields():
    if not os.path.exists(FIELDS):
        return {}
    return {c: {int(o, 16): list(v) for o, v in offs.items()} for c, offs in json.load(open(FIELDS)).items()}


def save_fields(fields):
    data = {c: {f"0x{o:X}": v for o, v in offs.items()} for c, offs in sorted(fields.items()) if offs}
    open(FIELDS, "w", encoding="utf-8", newline="\n").write(json.dumps(data, indent=1, sort_keys=False) + "\n")


def merged_fields(classes):
    """The field table with this run's harvest added (new types at an offset go last)."""
    fields = load_fields()
    for cls, offs in harvest(classes).items():
        for off, decls in offs.items():
            have = fields.setdefault(cls, {}).setdefault(off, [])
            have += [d for d in decls if d not in have]
    return fields


MEMBER = re.compile(r"^\s+(.*\bunk([0-9A-F]+)(?:_\w+)?\b.*?);\s*$")


def header_names(cls):
    """{(offset, declaration with its name as unk<OFF>): name} of the fields the class's header has
    now: the names sources use, which a regenerated header keeps."""
    path = os.path.join(OUT, header_file(cls))
    out = {}
    if not os.path.exists(path):
        return out
    for line in open(path, encoding="utf-8"):
        m = MEMBER.match(line)
        if not m:
            continue
        decl, off = m.group(1), int(m.group(2), 16)
        name = re.search(r"\bunk%s(?:_\w+)?\b" % m.group(2), decl).group(0)
        out[(off, normalize(decl.replace(name, f"unk{off:X}")))] = name
    return out


def layout(cls, classes, fields, memo=None):
    """([(offset, [(declaration, size)])], [dropped offsets]) of the class: its own fields and its
    primary bases' (a derived object starts with its base), in table order at each offset. Where
    fields overlap, the ones the current header has win, then the class's own before its bases',
    then table order; the others are left out."""
    memo = {} if memo is None else memo
    if cls in memo:
        return memo[cls]
    merged, rank = {}, {}
    chain, c = [], cls
    while c and c not in chain:
        chain.append(c)
        bases = classes.get(c, {}).get("bases", [])
        c = bases[0] if bases else None
    for c in chain:
        for off, decls in fields.get(c, {}).items():
            have = merged.setdefault(off, [])
            have += [d for d in decls if d not in have]
            rank.setdefault(off, len(rank))
    present = {off for off, _ in header_names(cls)}
    chosen, taken = [], []
    for off in sorted(merged, key=lambda o: (o not in present, rank[o])):
        vs = [(d, field_size(d)[0]) for d in merged[off] if field_size(d)]
        if not vs:
            continue
        end = off + max(v[1] for v in vs)
        if any(off < e and s < end for s, e in taken):
            continue
        taken.append((off, end))
        chosen.append((off, vs))
    dropped = sorted(set(merged) - {o for o, _ in chosen})
    memo[cls] = (sorted(chosen), dropped)
    return memo[cls]


def field_names(off, variants, old=None):
    """[(declaration with its name in the header, name)] for the variants at one offset: the names
    the current header gives them (old: header_names), else unk<OFF> for the first, a type suffix
    for the others (and a number if two would still clash)."""
    base = f"unk{off:X}"
    old = old or {}
    names = {}
    for decl, _ in variants:
        if (off, normalize(decl)) in old:
            names[decl] = old[(off, normalize(decl))]
    used = set(names.values())
    for k, (decl, _) in enumerate(variants):
        if decl in names:
            continue
        name = base if base not in used else suffix(decl, base)
        n = 2
        while name in used:
            name = f"{suffix(decl, base)}_{n}"
            n += 1
        used.add(name)
        names[decl] = name
    return [(re.sub(r"\b%s\b" % base, names[d], d), names[d]) for d, _ in variants]


# ---------------------------------------------------------------- the C++ class and the prototypes

LAYOUT = os.path.join(ROOT, "config", "class_layout.json")
PURE_VIRTUAL = 0x5BC5C0  # __pure_virtual
ALLOCATORS = {0x326750, 0x326588}  # the engine's allocation entries, size in $a0 (knowledge/gt4.md)
CXX = f"{GAME.upper()}_CXX"      # a source defines it to get the C++ classes instead of the C structs
DECLS = f"{GAME.upper()}_DECLS"  # ... and this one for the prototypes of the classes' functions
IDENT = re.compile(r"^[A-Za-z_]\w*$")
RC_SIZE_SLOT = 4  # RefCounter's `rc_size() const`: `return sizeof(*this)` (classes.md virtual_04)


def chain_of(classes, cls):
    chain, n = [], cls
    while n and n not in chain:
        chain.append(n)
        b = classes.get(n, {}).get("bases", [])
        n = b[0] if b else None
    return chain


def compute_layout(classes):
    """{class: {'vptr', 'size', 'size_from'}} from the code: the offset the class's own structors
    store its vtable address at (a class without a store of its own takes its base's, or its
    descendants' when they agree); the size from `rc_size` where the class overrides it (8 bytes:
    `jr $ra; li $v0, N`), else the smallest constant allocation right before a call of one of its
    structors (func_00326750(size, ...) / func_00326588(size)) for classes nothing derives from."""
    import types_db
    funcs = types_db.all_functions()
    vt = {c["vtables"][0]["address"]: n for n, c in classes.items() if c.get("vtables")}
    out = {n: {} for n in classes}
    for n, c in classes.items():
        offs = {}
        for s in c.get("structors", []):
            for off, kind, extra in types_db.scan(funcs.get(s, ()), s):
                if kind == "vtable_store" and vt.get(extra) == n:
                    offs[off] = offs.get(off, 0) + 1
        if len(offs) == 1:
            out[n]["vptr"] = next(iter(offs))
            out[n]["vptr_from"] = "structors"
    kids = {}
    for n, c in classes.items():
        for b in c.get("bases", [])[:1]:
            kids.setdefault(b, []).append(n)

    def below(n):
        todo, seen = list(kids.get(n, [])), set()
        while todo:
            k = todo.pop()
            if k in seen:
                continue
            seen.add(k)
            yield k
            todo += kids.get(k, [])
    for _ in range(3):
        for n, c in classes.items():
            if "vptr" in out[n] or not c.get("vtables"):
                continue
            b = c["bases"][0] if c.get("bases") else None
            if b and "vptr" in out.get(b, {}):
                out[n]["vptr"], out[n]["vptr_from"] = out[b]["vptr"], "base"
                continue
            seen = {out[k]["vptr"] for k in below(n) if "vptr" in out[k]}
            if len(seen) == 1:
                out[n]["vptr"], out[n]["vptr_from"] = seen.pop(), "derived classes"
    for n, c in classes.items():
        if not c.get("vtables") or len(c["vtables"][0]["methods"]) <= RC_SIZE_SLOT or "RefCounter" not in chain_of(classes, n):
            continue
        a = c["vtables"][0]["methods"][RC_SIZE_SLOT]
        b = c["bases"][0] if c.get("bases") else None
        bvt = classes.get(b, {}).get("vtables") if b else None
        if bvt and len(bvt[0]["methods"]) > RC_SIZE_SLOT and bvt[0]["methods"][RC_SIZE_SLOT] == a:
            continue  # inherited: the base's size
        w = list(funcs.get(a, ()))
        while w and not w[-1]:
            w.pop()
        if len(w) == 2 and w[0] == 0x03E00008 and w[1] >> 16 == 0x2402:
            out[n]["size"], out[n]["size_from"] = w[1] & 0xFFFF, "rc_size"
    ctor_of = {}
    for n, c in classes.items():
        for s in c.get("structors", []):
            ctor_of.setdefault(s, set()).add(n)
    votes = {}
    for a, words in funcs.items():
        for i, w in enumerate(words):
            if w >> 26 != 3:
                continue
            t = types_db._callee(w, a)
            if len(ctor_of.get(t, ())) != 1:
                continue
            for j in range(i - 1, max(-1, i - 14), -1):
                if words[j] >> 26 != 3:
                    continue
                if types_db._callee(words[j], a) in ALLOCATORS:
                    for k in range(j + 1, max(-1, j - 10), -1):
                        x = words[k]
                        if x >> 26 in (0x09, 0x0D) and (x >> 21) & 31 == 0 and (x >> 16) & 31 == 4:
                            votes.setdefault(next(iter(ctor_of[t])), []).append(x & 0xFFFF)
                            break
                        if types_db.written(x) == 4 and k != j:
                            break
                break
    for n, v in votes.items():
        # only for a class nothing derives from: a derived class constructed inline calls its
        # base's structor right after allocating the derived size (RefCounter: 8 bytes, the
        # allocations before its constructor are 32)
        if "size" not in out[n] and not kids.get(n):
            out[n]["size"] = min(v)
            out[n]["size_from"] = f"allocation, {len(v)} site{'s' if len(v) > 1 else ''}"
    return {n: f for n, f in sorted(out.items()) if f}


def load_layout():
    return json.load(open(LAYOUT)) if os.path.exists(LAYOUT) else {}


def round_up(x, a):
    return (x + a - 1) // a * a


def align_of(decls):
    a = 4
    for d in decls:
        sz = field_size(d)
        if sz:
            a = max(a, min(sz[1], 16))
    return a


class Cxx:
    """What the C++ forms need across classes: the layout facts (config/class_layout.json), the
    fields (config/class_fields.json), the GT HD slot signatures, and from the code the return
    types and the argument registers."""

    def __init__(self, classes, fields, protos, lay):
        import types_db
        self.classes, self.fields, self.protos, self.lay = classes, fields, protos, lay
        self.types_db = types_db
        self.funcs = types_db.all_functions()
        self.uses = types_db.result_uses(self.funcs)
        self.rmemo = {}
        self.cmap = types_db.gthd_class_map(classes)
        self.gthd = types_db.gthd_functions(classes)  # high, and the applied medium ones
        self.forms, self.virts = {}, {}
        self.vt_addrs = {a for c in classes.values() for v in c.get("vtables", []) for a in v["methods"]}

    def nslots(self, cls):
        vt = self.classes.get(cls, {}).get("vtables")
        return len(vt[0]["methods"]) if vt else 0

    def base(self, cls):
        """The primary base the C++ form derives from (an empty one is left out: form())."""
        b = self.classes[cls].get("bases", [])
        b = b[0] if b and b[0] in self.classes else None
        if b and cls in self.forms and self.forms[cls] is not None:
            return self.forms[cls]["base"]
        return b

    def form(self, cls):
        """The class's C++ layout or None (a base without one, a vptr the code does not show):
        {'start', 'size', 'size_known', 'align', 'vptr', 'introduces', 'split', 'fields', ...}."""
        if cls in self.forms:
            return self.forms[cls]
        self.forms[cls] = None
        c = self.classes[cls]
        b = self.base(cls)
        bf = self.form(b) if b else None
        if b and bf is None:
            return None
        notes = []
        if bf and bf["size"] == 0:
            # an empty base takes a byte of its own in g++ 2.96 where the original's took none
            # (or had members nobody touches): the C++ form leaves it out
            notes.append(f"base {b} has no known member: left out of the C++ form")
            b, bf = None, None
        info = self.lay.get(cls, {})
        vptr = info.get("vptr") if c.get("vtables") else None
        if c.get("vtables") and vptr is None:
            return None
        if bf and bf["vptr"] is not None and vptr != bf["vptr"]:
            return None
        start = bf["size"] if bf else 0
        introduces = vptr is not None and not (bf and bf["vptr"] is not None)
        if introduces and (vptr < start or vptr % 4):
            return None
        reserved = [(vptr, vptr + 4)] if vptr is not None else []
        own = {o: [d for d in v if field_size(d)] for o, v in self.fields.get(cls, {}).items()}
        chosen, taken, dropped = [], [], []
        for off in sorted(own):
            if not own[off]:
                continue
            end = off + max(field_size(d)[0] for d in own[off])
            if off < start or any(off < e and s < end for s, e in taken + reserved):
                dropped.append(off)
                continue
            taken.append((off, end))
            chosen.append((off, own[off]))
        align = max([bf["align"] if bf else 4] + [align_of(d) for _, d in chosen])
        end = max([start] + [e for _, e in taken] + ([vptr + 4] if vptr is not None else []))
        size = info.get("size")
        if size is not None and (size < end or size % align):
            notes.append(f"size 0x{size:X} ({info.get('size_from')}) is smaller than the fields need: not used")
            size = None
        known = size is not None
        size = size if known else round_up(end, align)
        split = introduces and (any(o > vptr for o, _ in chosen) or size > round_up(vptr + 4, align))
        f = {"start": start, "size": size, "size_known": known, "size_from": info.get("size_from") if known else None,
             "align": align, "vptr": vptr, "introduces": introduces, "split": split, "fields": chosen,
             "dropped": dropped, "notes": notes, "base": b}
        self.forms[cls] = f
        return f

    def slot_impls(self, cls, slot):
        """The functions at this slot in the class's vtable and its descendants' (pure ones out)."""
        out = []
        for n, c in self.classes.items():
            vt = c.get("vtables")
            if vt and len(vt[0]["methods"]) > slot and cls in chain_of(self.classes, n):
                a = vt[0]["methods"][slot]
                if a != PURE_VIRTUAL and a not in out:
                    out.append(a)
        return out

    def ret_of(self, addrs, direct=False):
        """void / f32 / s32 over the implementations (direct calls: the callers' use first)."""
        votes = set()
        for a in addrs:
            votes.add(self.types_db.result_type(a, self.funcs, self.uses, self.rmemo) if direct
                      else self.types_db.return_type(a, self.funcs, self.rmemo))
        votes.discard(None)
        if votes == {"void"}:
            return "void"
        if "f32" in votes and "s32" not in votes:
            return "f32"
        return "s32"

    def code_params(self, addrs):
        """Parameters from the registers the implementations read: s32 for $a1.. (after
        `this`), f32 for $f12..; ints first (the EE counts the two kinds apart)."""
        ni = nf = 0
        for a in addrs:
            gi, gf = self.types_db.live_args(self.funcs.get(a, ()))
            ni = max([ni] + [r - 4 for r in gi])
            nf = max([nf] + [r - 11 for r in gf])
        return ["s32"] * ni + ["f32"] * nf

    def gthd_params(self, plist, cxx=True):
        out, used = [], set()
        for t in plist:
            r = self.types_db.gthd_type(t, self.cmap, cxx=cxx)
            if r is None:
                return None, set()
            out.append(r[0])
            if r[1]:
                used.add(r[1])
        return out, used

    def fits(self, params, addrs, member=True):
        """True when no implementation reads an argument register the parameters do not have."""
        ni = sum(1 for p in params if p != "f32") + (1 if member else 0)
        nf = sum(1 for p in params if p == "f32")
        for a in addrs:
            gi, gf = self.types_db.live_args(self.funcs.get(a, ()))
            if (gi and max(gi) - 4 >= ni) or (gf and max(gf) - 12 >= nf):
                return False
        return True

    def virtuals(self, cls):
        """[(slot, name, return, params, const, comment, classes used)] for the slots the class
        adds to its base's vtable (all of them in the class that introduces the vptr). A name
        that would override an inherited declaration (same name and parameters) gets the slot
        number appended: a new slot must stay a new slot."""
        if cls in self.virts:
            return self.virts[cls]
        b = self.base(cls)
        first = self.nslots(b) if b and self.form(b) and self.form(b)["vptr"] is not None else 0
        vt = self.classes[cls]["vtables"][0]["methods"] if self.classes[cls].get("vtables") else []
        p = self.protos.get(cls, {})
        inherited = set()
        n = b
        while n:
            inherited |= {(v[1], tuple(v[3]), v[4]) for v in self.virtuals(n)}
            n = self.base(n)
        out, keys = [], set()
        for slot in range(first, len(vt)):
            impls = self.slot_impls(cls, slot)
            m = p.get(slot)
            name, params, const, comment, used = None, None, False, "", set()
            if m and m.get("confidence") == "high" and m.get("name", "").startswith("~"):
                name, params, comment = "~" + cls, [], m.get("signature", "")  # (this, delete flag) in g++ 2.96
            elif m and m.get("confidence") == "high" and "params" in m:
                gp, gu = self.gthd_params(m["params"])
                if gp is not None and self.fits(gp, impls):
                    name, params, const, comment, used = m.get("name", ""), gp, bool(m.get("const")), m.get("signature", ""), gu
                else:
                    comment = f"GT HD {m.get('signature', '')}: its parameters do not fit GT4's code"
            elif m and m.get("signature"):
                comment = f"GT HD ({m.get('confidence')}): {m['signature']}"
            if name and name.startswith("~") and slot > 0 and first > 0:
                name = None  # a second destructor slot (GT HD's D0/D1 pair): a destructor here would override
            if name and name.startswith("~"):
                name, params = "~" + cls, []
            elif name and not IDENT.match(name):
                name = None
            if name is None:
                name, params, used = f"virtual_{slot}", self.code_params(impls), set()
                comment = (comment + "; " if comment else "") + "parameters from the code"
            ret = "" if name.startswith("~") else self.ret_of(impls)
            key = (name, tuple(params), const)
            if not name.startswith("~") and (key in inherited or key in keys):
                name = f"{name}_{slot}"
                key = (name, tuple(params), const)
            keys.add(key)
            out.append((slot, name, ret, params, const, comment, used))
        self.virts[cls] = out
        return out

    def methods(self, cls, virtual_keys):
        """[(address, name, return, params, const, static, classes used)]: the class's
        non-virtual functions GT HD names (high), parameters checked against the code."""
        out, keys = [], set(virtual_keys)
        for addr, g in sorted(self.gthd.items()):
            if g["class"] != cls or addr in self.vt_addrs or g.get("symbol") is None or not IDENT.match(g["name"]):
                continue
            params, used = self.gthd_params(g["params"])
            if params is None or not self.fits(params, [addr], member=g["member"]):
                continue
            key = (g["name"], tuple(params), g["const"])
            if key in keys:
                continue
            keys.add(key)
            out.append((addr, g["name"], self.ret_of([addr], direct=True), params, g["const"], not g["member"], used))
        return out


def field_lines(fields, at, old, indent="    "):
    """(lines, end) of fields from offset `at` on, padded with char arrays."""
    lines = []
    for off, variants in fields:
        if off > at:
            lines.append(f"{indent}char pad{at:X}[0x{off - at:X}];")
        named = field_names(off, [(d, field_size(d)[0]) for d in variants], old)
        if len(named) == 1:
            lines.append(f"{indent}{named[0][0]};")
        else:
            lines.append(f"{indent}union {{")
            lines += [f"{indent}    {d};" for d, _ in named]
            lines.append(f"{indent}}};")
        at = off + max(field_size(d)[0] for d in variants)
    return lines, at


def decl(ret, name, params, const=False, virtual=False, static=False):
    q = "virtual " if virtual else "static " if static else ""
    r = f"{ret} " if ret else ""
    return f"{q}{r}{name}({', '.join(params)}){' const' if const and not static else ''};"


def render_cxx(cls, cx, old):
    """(lines, classes the declarations use) of the C++ class, with the hidden base that
    introduces the vptr when the class has fields after it; (None, set()) when the layout is
    not known well enough."""
    f = cx.form(cls)
    if f is None:
        return None, set()
    virt = cx.virtuals(cls) if cx.classes[cls].get("vtables") else []
    meths = cx.methods(cls, {(v[1], tuple(v[3]), v[4]) for v in virt})
    used = set().union(*[v[6] for v in virt], *[m[6] for m in meths]) if virt or meths else set()
    vlines = [f"    {decl(ret, name, params, const, virtual=True)}  /* {slot}{': ' + comment if comment else ''} */"
              for slot, name, ret, params, const, comment, _ in virt]
    mlines = [f"    {decl(ret, name, params, const, static=st)}  /* 0x{addr:08X} */"
              for addr, name, ret, params, const, st, _ in meths]
    base = f["base"]
    lines = []
    if f["split"]:
        head = f"{cls}_vbase"
        before = [(o, d) for o, d in f["fields"] if o < f["vptr"]]
        after = [(o, d) for o, d in f["fields"] if o > f["vptr"]]
        lines.append(f"/* g++ 2.96 puts the vptr after the own fields of the class that introduces it; {cls} "
                     f"has fields after 0x{f['vptr']:X}, so a base without RTTI introduced it */")
        lines.append(f"class {head}{' : public ' + base if base else ''} {{")
        lines.append("public:")
        fl, at = field_lines(before, f["start"], old)
        lines += fl
        if f["vptr"] > at:
            lines.append(f"    char pad{at:X}[0x{f['vptr'] - at:X}];")
        lines += [re.sub(r"virtual ~%s\(" % re.escape(cls), f"virtual ~{head}(", v) for v in vlines]
        lines += ["};", "", f"class {cls} : public {head} {{", "public:"]
        valign = max([cx.form(base)["align"] if base else 4] + [align_of(d) for _, d in before])
        fl, at = field_lines(after, round_up(f["vptr"] + 4, valign), old)
        lines += fl
        lines += mlines
        if f["size"] > at:
            lines.append(f"    char pad{at:X}[0x{f['size'] - at:X}];")
    else:
        lines += [f"class {cls}{' : public ' + base if base else ''} {{", "public:"]
        fl, at = field_lines(f["fields"], f["start"], old)
        lines += fl
        if f["introduces"]:
            # every data member goes before the vptr, the vptr ends the class
            if f["vptr"] > at:
                lines.append(f"    char pad{at:X}[0x{f['vptr'] - at:X}];")
        elif f["size"] > at:
            lines.append(f"    char pad{at:X}[0x{f['size'] - at:X}];")
        lines += vlines
        lines += mlines
    lines.append("};")
    return lines, used


def render_decls(cls, cx):
    """C prototypes of the class's functions under their symbol names (`this` first), from the
    GT HD signatures checked against the code: what sources call them as."""
    import symbols
    own = owners(cx.classes)
    rows, seen = [], set()
    for addr, g in sorted(cx.gthd.items()):
        if (own.get(addr) or g["class"]) != cls:
            continue
        sym = symbols.name_of(addr)
        if not sym or sym in seen:
            continue
        params, _ = cx.gthd_params(g["params"], cxx=False)
        if params is None or any(p in ("s64", "u64", "f64") for p in params):
            continue
        if not cx.fits(params, [addr], member=g["member"]):
            continue
        if g["member"]:
            params = [f"struct {cls} *"] + params
        seen.add(sym)
        rows.append(f"{cx.ret_of([addr], direct=True)} {sym}({', '.join(params) if params else 'void'});")
    return rows


def render(cls, classes, fields, protos, memo=None, cx=None):
    c = classes[cls]
    lay, dropped = layout(cls, classes, fields, memo)
    old = header_names(cls)
    guard = f"{GAME.upper()}_{cls}_H"
    vt = c.get("vtables", [])
    lines = [f"/* {GAME}/{cls}.h: generated by tools/gen_headers.py from config/classes.json and the fields the",
             " * class's functions use (tools/cleanup.py fields). Do not edit: change the inputs and regenerate.",
             f" * class {cls}" + (f" : {', '.join(c.get('bases', []))}" if c.get("bases") else ""),
             f" * type_info 0x{c['type_info']:08X}, type_info function 0x{c['tf']:08X}"
             + (", structors " + ", ".join(f"0x{a:08X}" for a in c.get("structors", [])) if c.get("structors") else ""),
             ]
    for v in vt:
        lines.append(f" * vtable 0x{v['address']:08X}: {len(v['methods'])} slots")
    if lay:
        last = lay[-1]
        lines.append(f" * size: not known; the fields seen reach 0x{last[0] + max(x[1] for x in last[1]):X}")
    if dropped:
        lines.append(" * left out (overlapping another field): " + ", ".join(f"0x{o:X}" for o in dropped))
    cxx, used = render_cxx(cls, cx, old) if cx else (None, set())
    f = cx.form(cls) if cx else None
    if f and cxx:
        lines.append(f" * C++ ({CXX}): size 0x{f['size']:X} "
                     + (f"({f['size_from']})" if f["size_known"] else "(not known: up to the last field seen)")
                     + (f", vptr at 0x{f['vptr']:X}" + (" (introduced here)" if f["introduces"] else "")
                        if f["vptr"] is not None else "")
                     + (", fields left out (overlap, or in the base's part): " + ", ".join(f"0x{o:X}" for o in f["dropped"])
                        if f["dropped"] else ""))
        for n in f["notes"]:
            lines.append(f" * {n}")
    lines.append(" */")
    lines += [f"#ifndef {guard}", f"#define {guard}", "", '#include "types.h"', ""]
    cstruct = []
    if lay:
        cstruct.append(f"struct {cls} {{")
        at = 0
        for off, variants in lay:
            if off > at:
                cstruct.append(f"    char pad{at:X}[0x{off - at:X}];")
            named = field_names(off, variants, old)
            if len(named) == 1:
                cstruct.append(f"    {named[0][0]};")
            else:
                cstruct.append("    union {")
                cstruct += [f"        {d};" for d, _ in named]
                cstruct.append("    };")
            at = off + max(v[1] for v in variants)
        cstruct.append("};")
    else:
        cstruct.append(f"struct {cls};")
    if cxx:
        b = f.get("base")
        pre = [f'#include "{GAME}/{header_file(b, classes)}"'] if b else []
        pre += [f"class {u};" for u in sorted(used - {cls}) if u in classes]
        lines += [f"#if defined(__cplusplus) && defined({CXX})"] + pre + [""] + cxx + ["#else"] + cstruct + ["#endif"]
    else:
        lines += cstruct
    decls = render_decls(cls, cx) if cx else []
    if decls:
        lines += ["", f"#ifdef {DECLS}", "#ifdef __cplusplus", 'extern "C" {', "#endif"] + decls + \
                 ["#ifdef __cplusplus", "}", "#endif", f"#endif /* {DECLS} */"]
    p = protos.get(cls, {})
    if vt:
        lines += ["", f"/* virtual functions (slot: address; the GT HD name when tools/gthd_names.py found it)"]
        for slot, addr in enumerate(vt[0]["methods"]):
            m = p.get(slot)
            sig = (m.get("signature") or m.get("name")) if m else None
            same = m and str(m.get("address", "")).lower() in (f"0x{addr:08x}", str(addr))
            gthd = f"  {sig} [{m.get('confidence', '?')}]" if sig and same else ""
            lines.append(f" * {slot:3d}: 0x{addr:08X}{gthd}")
        lines.append(" */")
    lines += ["", f"#endif /* {guard} */", ""]
    return "\n".join(lines)


def test_headers(classes):
    """Compile every header as C++ with the classes and the prototypes on (ee-gcc 2.96, -S) and
    check the layout the compiler gives against the inputs: sizeof, every field's offset, the
    vptr offset and the vtable entry of the last virtual slot (a call through it). 0 when all
    agree."""
    import subprocess
    fields, protos = load_fields(), load_prototypes()
    cx = Cxx(classes, fields, protos, load_layout())
    src = [f"#define {CXX}", f"#define {DECLS}", '#include "types.h"']
    src += [f'#include "{GAME}/{header_file(c, classes)}"' for c in sorted(classes)
            if os.path.exists(os.path.join(OUT, header_file(c, classes)))]
    expect = {}
    branch = re.compile(r"^#if defined\(__cplusplus\) && defined\(%s\)\n(.*?)^#else\n" % CXX, re.M | re.S)
    for cls in sorted(classes):
        f = cx.form(cls)
        path = os.path.join(OUT, header_file(cls, classes))
        if f is None or not os.path.exists(path):
            continue
        m = branch.search(open(path, encoding="utf-8").read())
        if not m:
            continue
        src.append(f'extern "C" int size_{cls}(void) {{ return sizeof({cls}); }}')
        expect[f"size_{cls}"] = f["size"] or 1  # an empty class is a byte
        for k, name in enumerate(sorted(set(re.findall(r"\b(unk([0-9A-F]+)(?:_\w+)?)\s*;", m.group(1))))):
            src.append(f'extern "C" int off_{cls}_{k}(void) {{ return (int)&(({cls} *)0)->{name[0]}; }}')
            expect[f"off_{cls}_{k}"] = int(name[1], 16)
        n = cls
        while n and not (cx.form(n) and cx.virtuals(n) if classes[n].get("vtables") else False):
            n = cx.base(n)
        if n:
            slot, name, ret, params, const, _, _ = cx.virtuals(n)[-1]
            if not name.startswith("~"):
                args = [f"*({p[:-1].strip()} *)0" if p.endswith("&") else f"({p})0" for p in params]
                obj = f"((const {cls} *)p)" if const else "p"  # the const overload when it is one
                src.append(f'extern "C" void vcall_{cls}({cls} *p) {{ {obj}->{name}({", ".join(args)}); }}')
                expect[f"vcall_{cls}"] = (f["vptr"], 8 * (slot + 1))
    rel = lambda p: os.path.relpath(p, ROOT).replace("\\", "/")
    command = project.compiler_command().replace(" -c ", " -S ")

    def compile_s(name, text):
        test = os.path.join(ROOT, "build", name)
        open(test, "w", newline="\n").write(text)
        asm = test.rsplit(".", 1)[0] + ".s"
        if os.path.exists(asm):
            os.remove(asm)
        args = project.with_include_stamp(["bash", "tools/cc_wsl.sh", rel(test), rel(asm), command])
        if os.name == "nt":
            args = ["wsl", "-d", "Ubuntu", "--cd", "/mnt/" + ROOT[0].lower() + ROOT[2:].replace("\\", "/"), "--"] + args
        res = subprocess.run(args, capture_output=True, text=True, env=dict(os.environ, MSYS_NO_PATHCONV="1"), cwd=ROOT)
        if res.returncode != 0 or not os.path.exists(asm):
            print((res.stdout + res.stderr)[-6000:])
            return None
        return asm
    # as C: the structs and the prototypes (the C++ branch is off without __cplusplus)
    if not compile_s("gen_headers_test_c.c", "\n".join(src[:3 + len(classes)]) + "\n"):
        return "the headers do not compile as C with the prototypes"
    asm = compile_s("gen_headers_test.cpp", "\n".join(src) + "\n")
    if not asm:
        return "the headers do not compile as C++"
    funcs, cur = {}, None
    for line in open(asm):
        lab = re.match(r"^(\w+):", line)
        if lab:
            cur = lab.group(1)
            funcs[cur] = []
        elif cur and line.startswith("\t") and not line.startswith("\t."):
            funcs[cur].append(line.split("#")[0].strip())
    bad = []
    for name, want in expect.items():
        body = funcs.get(name, [])
        if name.startswith("vcall_"):
            lw = next((re.match(r"lw\t\$\d+,(\d+)\(", x) for x in body if re.match(r"lw\t\$\d+,(\d+)\(", x)), None)
            add = next((re.match(r"addu\t\$\d+,\$\d+,(\d+)$", x) for x in body if re.match(r"addu\t\$\d+,\$\d+,(\d+)$", x)), None)
            lh = next((re.match(r"lh\t\$\d+,(\d+)\(", x) for x in body if re.match(r"lh\t\$\d+,(\d+)\(", x)), None)
            got = (int(lw.group(1)) if lw else None, (int(add.group(1)) if add else 0) + (int(lh.group(1)) if lh else 0))
        else:
            v = 0
            for x in body:
                m = re.match(r"(li|lui|ori|addu)\t\$2,(?:\$\d+,)?(-?\w+)", x)
                if m:
                    n = int(m.group(2), 0)
                    v = (n << 16) if m.group(1) == "lui" else (v | n) if m.group(1) == "ori" else (v + n) if m.group(1) == "addu" else n
            got = v
        if got != want:
            bad.append((name, want, got))
    for b in bad[:40]:
        print(f"  {b[0]}: expected {b[1]}, the compiler says {b[2]}")
    print(f"{len(expect)} checks over {sum(1 for k in expect if k.startswith('size_'))} classes: {len(bad)} disagree")
    return 1 if bad else 0


DECL_BLOCK = re.compile(r"^#ifdef %s\n(.*?)^#endif /\* %s \*/" % (DECLS, DECLS), re.M | re.S)
# a prototype on one line at file level: a return type (words, stars), the name, the parameters
LOCAL_DECL = re.compile(r'^(?:extern[ \t]+"C"[ \t]+)?(?:extern[ \t]+)?(?:(?:const|unsigned|signed|struct)[ \t]+)*\w+'
                        r'[ \t\*]+(\w+)[ \t]*\([^;{}\n]*\)[ \t]*;[ \t]*(?:/\*[^\n]*?\*/)?[ \t]*\n', re.M)


def header_decls(classes):
    """{symbol: class} of the functions the headers' prototype blocks declare."""
    out = {}
    for cls in classes:
        path = os.path.join(OUT, header_file(cls, classes))
        if not os.path.exists(path):
            continue
        m = DECL_BLOCK.search(open(path, encoding="utf-8").read())
        if m:
            for name in re.findall(r"\b(\w+)\(", m.group(1)):
                out.setdefault(name, cls)
    return out


def convert_text(text, decls, classes):
    """The source using the headers' prototypes instead of its own declarations of those
    functions: the local declarations removed, `#define GT4_DECLS` and the headers included
    (after a `/* compiler: */` first line). None when it declares none of them."""
    # only at file level (brace depth 0): a call statement inside a body looks the same
    depth, top = 0, {0}
    for i, ch in enumerate(text):
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
        elif ch == "\n" and depth == 0:
            top.add(i + 1)
    names = {m.group(1) for m in LOCAL_DECL.finditer(text) if m.start() in top and m.group(1) in decls}
    if not names:
        return None, set()
    out = LOCAL_DECL.sub(lambda m: "" if m.start() in top and m.group(1) in names else m.group(0), text)
    need = sorted({decls[n] for n in names})
    incl = [f'#include "{GAME}/{header_file(c, classes)}"' for c in need
            if f'#include "{GAME}/{header_file(c, classes)}"' not in out]
    head = [f"#define {DECLS}"] + incl
    lines = out.split("\n")
    at = 1 if lines and lines[0].startswith("/* compiler:") else 0
    # after the first include block when there is one (types.h first)
    for i, l in enumerate(lines):
        if l.startswith("#include"):
            at = i
            break
    lines[at:at] = head
    return "\n".join(lines), set(need)


def convert(classes, targets, write=False, limit=0):
    """Re-judge the matched sources that declare functions of the target classes with those
    declarations replaced by the headers' (convert_text); a source changes only on MATCH.
    Returns (matched, tried)."""
    import subprocess
    import symbols
    decls = {n: c for n, c in header_decls(classes).items() if c in targets}
    srcs = project.sources(refresh=True)
    work = os.path.join(ROOT, "build", "convert")
    os.makedirs(work, exist_ok=True)
    ok, tried, report = 0, 0, []
    for addr, path in sorted(srcs.items()):
        text = open(path, encoding="utf-8").read()
        # every name in its canonical spelling first (what tools/organize.py does anyway)
        new, used = convert_text(symbols.rename_text(symbols.generic_text(text)), decls, classes)
        if new is None:
            continue
        tried += 1
        cand = os.path.join(work, os.path.basename(path))
        open(cand, "w", encoding="utf-8", newline="\n").write(new)
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", cand],
                             capture_output=True, text=True)
        verdict = (res.stdout.strip().splitlines() or ["?"])[0]
        good = res.returncode == 0 and "MATCH" in verdict
        report.append((addr, os.path.relpath(path, ROOT), "MATCH" if good else verdict[:90]))
        if good:
            ok += 1
            if write:
                open(path, "w", encoding="utf-8", newline="\n").write(new)
        if limit and tried >= limit:
            break
    for a, p, v in report:
        print(f"  0x{a:08X} {p}: {v}")
    print(f"{ok} of {tried} sources match with the headers' prototypes" + ("" if write else " (nothing written: --write)"))
    return ok, tried



def rejudge():
    """Judge every source that turns the headers' C++ classes or prototypes on (#define
    GT4_CXX / GT4_DECLS): after a regeneration they must all still match. Returns the failures."""
    import subprocess
    bad, n = [], 0
    for addr, path in sorted(project.sources(refresh=True).items()):
        text = open(path, encoding="utf-8", errors="replace").read()
        if not re.search(r"^#define (%s|%s)\b" % (CXX, DECLS), text, re.M):
            continue
        n += 1
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                             capture_output=True, text=True)
        if res.returncode != 0 or "MATCH" not in (res.stdout.splitlines() or [""])[0]:
            bad.append(path)
            print(f"  0x{addr:08X} {os.path.relpath(path, ROOT)}: {(res.stdout.strip().splitlines() or ['?'])[0][:90]}")
    print(f"{n} sources use the headers' C++ classes or prototypes: {len(bad)} do not match")
    return bad


def wanted(classes, fields, a):
    if a.classes:
        return [c for c in a.classes if c in classes]
    return sorted(classes)  # every class: a C++ class includes its base's header


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", nargs="?", default="write", choices=["write", "show", "stats", "facts", "test", "convert", "rejudge"])
    ap.add_argument("names", nargs="*")
    ap.add_argument("--class", dest="classes", action="append")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--write", action="store_true", help="convert: write the sources that still match")
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args()
    classes = load_classes()
    if not classes:
        print(f"no {os.path.relpath(CLASSES, ROOT)}: no class headers for this game yet")
        return
    # --check renders from the table alone; writing adds this run's harvest to it first
    if a.command == "facts":
        lay = compute_layout(classes)
        open(LAYOUT, "w", encoding="utf-8", newline="\n").write(json.dumps(lay, indent=1) + "\n")
        print(f"{os.path.relpath(LAYOUT, ROOT)}: vptr offsets {sum(1 for v in lay.values() if 'vptr' in v)}, "
              f"sizes {sum(1 for v in lay.values() if 'size' in v)} "
              f"(rc_size {sum(1 for v in lay.values() if v.get('size_from') == 'rc_size')})")
        return
    if a.command == "test":
        sys.exit(test_headers(classes))
    if a.command == "rejudge":
        sys.exit(1 if rejudge() else 0)
    if a.command == "convert":
        convert(classes, a.names, write=a.write, limit=a.limit)
        return
    fields = load_fields() if a.check or a.command == "show" else merged_fields(classes)
    protos = load_prototypes()
    memo = {}
    cx = Cxx(classes, fields, protos, load_layout()) if a.command != "stats" else None
    if a.command == "show":
        for n in a.names:
            print(render(n, classes, fields, protos, memo, cx))
        return
    if a.command == "stats":
        own = owners(classes)
        withf = [c for c in classes if layout(c, classes, fields, memo)[0]]
        nf = sum(len(layout(c, classes, fields, memo)[0]) for c in withf)
        unions = sum(1 for c in withf for _, v in layout(c, classes, fields, memo)[0] if len(v) > 1)
        drops = sum(len(layout(c, classes, fields, memo)[1]) for c in withf)
        print(f"classes: {len(classes)}, functions owned by one class: {len(own)}, "
              f"classes with fields: {len(withf)}, fields: {nf}, unions: {unions}, left out: {drops}, "
              f"GT HD prototypes: {len(protos)} classes")
        return
    if not a.check:
        save_fields(fields)
    os.makedirs(OUT, exist_ok=True)
    stale = []
    names = wanted(classes, fields, a)
    for cls in names:
        text = render(cls, classes, fields, protos, memo, cx)
        path = os.path.join(OUT, header_file(cls, classes))
        old = open(path, encoding="utf-8").read() if os.path.exists(path) else None
        if old != text:
            stale.append(cls)
            if not a.check:
                open(path, "w", encoding="utf-8", newline="\n").write(text)
    if a.check:
        if stale:
            sys.exit(f"{len(stale)} headers are not what the inputs say ({', '.join(stale[:5])}...): python tools/gen_headers.py")
        print(f"{len(names)} headers current")
        return
    print(f"{len(names)} headers in {os.path.relpath(OUT, ROOT)}, {len(stale)} written")


if __name__ == "__main__":
    main()
