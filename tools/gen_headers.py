#!/usr/bin/env python3
"""Game headers: include/<game>/<Class>.h (include/gt4/ here, include/tt/ in Tourist Trophy), one per
class of config/classes.json, generated, never edited by hand.

    gen_headers.py [--class NAME ...] [--all] [--check]
        write the headers of the classes with a known field (or the named ones; --all: every class,
        also those known only by their vtable); --check: exit 1 if a header is not what the inputs
        say (nothing written)
    gen_headers.py show NAME       print one header
    gen_headers.py stats           classes, member sources, harvested fields, conflicts

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
    path = os.path.join(OUT, f"{cls}.h")
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


def render(cls, classes, fields, protos, memo=None):
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
    lines.append(" */")
    lines += [f"#ifndef {guard}", f"#define {guard}", "", '#include "types.h"', ""]
    if lay:
        lines.append(f"struct {cls} {{")
        at = 0
        for off, variants in lay:
            if off > at:
                lines.append(f"    char pad{at:X}[0x{off - at:X}];")
            named = field_names(off, variants, old)
            if len(named) == 1:
                lines.append(f"    {named[0][0]};")
            else:
                lines.append("    union {")
                lines += [f"        {d};" for d, _ in named]
                lines.append("    };")
            at = off + max(v[1] for v in variants)
        lines.append("};")
    else:
        lines.append(f"struct {cls};")
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


def wanted(classes, fields, a):
    if a.classes:
        return [c for c in a.classes if c in classes]
    if a.all:
        return sorted(classes)
    return sorted(c for c in classes if layout(c, classes, fields)[0])


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", nargs="?", default="write", choices=["write", "show", "stats"])
    ap.add_argument("names", nargs="*")
    ap.add_argument("--class", dest="classes", action="append")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--check", action="store_true")
    a = ap.parse_args()
    classes = load_classes()
    if not classes:
        print(f"no {os.path.relpath(CLASSES, ROOT)}: no class headers for this game yet")
        return
    # --check renders from the table alone; writing adds this run's harvest to it first
    fields = load_fields() if a.check or a.command == "show" else merged_fields(classes)
    protos = load_prototypes()
    memo = {}
    if a.command == "show":
        for n in a.names:
            print(render(n, classes, fields, protos, memo))
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
        text = render(cls, classes, fields, protos, memo)
        path = os.path.join(OUT, f"{cls}.h")
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
