#!/usr/bin/env python3
"""Type database for m2c: prototypes, globals and class layouts the project already knows,
rendered as the C context file m2c reads with --context (so its drafts call functions with
the right arguments, type globals and read struct fields with the width the original used).

    types_db.py build            -> build/types_db.json, build/types_context.c
    types_db.py show CLASS       the fields recorded for a class and their evidence
    types_db.py context ADDR F   print the part of the context the draft file F needs (what
                                 cpu_solve.py prepends before compiling)
    types_db.py measure [--sample 400] [--jobs 2]
                                 re-draft a fixed sample of unmatched functions with no context,
                                 prototypes only, and the full context; report per size bucket
                                 (results in build/auto/types_bench/bench.jsonl; --report resummarises)

cpu_solve.py --context types (or protos) adds "m2c with context" drafts to its candidates; the
context m2c reads is written per function (its callees, globals, their structs, its own
prototype when its class is known), and the compiled draft gets the same declarations.
Over the queue: `cpu_solve.py --retry --context types --context-only --jobs 2` (the kept draft
competes, only the context drafts are added; resumable in chunks with --limit).

Measured (measure, 400 failed drafts, 150 under 128 B / 150 of 128-512 B / 100 over 512 B):
prototypes alone: 47 closer, 0 farther, 5 newly compiling, 2 matches (both under 128 B);
the full context (structs and globals added): 48 closer, 2 matches; the per-function
difference between the two is noise (3 vs 2). Over the queue (13,553 functions): 91 matches, 1,274 closer drafts.

Sources of evidence, in order of trust:
  1. matched sources (src/func_*.c, .cpp): the definition gives the function's exact prototype;
     extern declarations give the prototypes callers used for not-yet-matched callees (majority
     over callers, disagreements recorded) and the types of globals;
  2. RTTI (config/classes.json): which class a function belongs to (primary vtable slots and
     structors), and the class hierarchy;
  3. the instructions: every load/store at a constant offset from `this` in a function of a
     known class, the vtable pointer stores of constructors, pointers passed as `this` to other
     methods (which tells the class of non-virtual methods too, when every call site agrees).
A field is only emitted when the accesses at that offset agree on one width (75% or more);
the rest stays `char unk_XX[n]`, which m2c may still infer per function.
"""
import csv
import json
import os
import re
import sys
from collections import Counter, defaultdict

import match
import symbols
import project

ROOT = match.ROOT
DB = os.path.join(ROOT, "build", "types_db.json")
CONTEXT = os.path.join(ROOT, "build", "types_context.c")
CLASSES = os.path.join(ROOT, "config", "classes.json")
LIBRARY = 0x5547E8  # library code from here on (other flags, partly another compiler)

PRIMITIVES = {"void", "char", "short", "int", "long", "float", "double", "signed", "unsigned", "const",
              "volatile", "s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64", "s128", "u128",
              "bool", "M2C_UNK", "M2C_UNK8", "M2C_UNK16", "M2C_UNK32", "M2C_UNK64", "size_t"}
SIMPLE_TYPEDEFS = {"bool": "s32", "size_t": "u32"}

# opcodes
LOADS = {0x20: "s8", 0x21: "s16", 0x23: "w", 0x24: "u8", 0x25: "u16", 0x27: "u32", 0x31: "f32",
         0x37: "s64", 0x1E: "u128"}
STORES = {0x28: "b8", 0x29: "b16", 0x2B: "w", 0x39: "f32", 0x3F: "s64", 0x1F: "u128"}
SIZES = {"s8": 1, "u8": 1, "b8": 1, "s16": 2, "u16": 2, "b16": 2, "w": 4, "u32": 4, "f32": 4, "s64": 8, "u128": 16}
CALL_CLOBBER = set(range(1, 16)) | {24, 25, 31}
A0, SP = 4, 29


# ---------------------------------------------------------------- sources

DECL = re.compile(r'(?:extern\s+"C"\s+)?(?:extern\s+)?([^;{}\n/]*?)\b(func_[0-9A-Fa-f]{8})\s*\(([^;{}]*)\)'
                  r'\s*(?:throw\s*\(\s*\))?\s*([;{])')
GLOBAL = re.compile(r'^\s*extern\s+(?:"C"\s+)?([^;=\n]*?\b)(D_[0-9A-Fa-f]{8})\s*((?:\[[^\]]*\])*)\s*;', re.M)
STRUCT = re.compile(r'^(?:typedef\s+)?struct\s+(\w+)\s*\{([^{}]*)\}\s*(\w+)?\s*;', re.M)
COMMENT = re.compile(r'/\*.*?\*/|//[^\n]*', re.S)


def split_params(text):
    """Comma-separated parameters, commas inside parentheses kept (function pointers)."""
    out, depth, cur = [], 0, ""
    for ch in text:
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
            continue
        depth += (ch in "([") - (ch in ")]")
        cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def c_type(text, structs, pos0_class=None):
    """A declaration's type as the context can state it in C: primitives and pointers to them
    kept, pointers/references to a file-local struct become `void *` (or `struct CLASS *` for a
    `this` of a known class), function pointers kept with their pointees voided. None when the
    type cannot be rendered (a struct passed by value)."""
    t = COMMENT.sub("", text).strip()
    t = re.sub(r"\b(register|__restrict|__attribute__\(\([^)]*\)\))\b", "", t)
    t = re.sub(r"\s+", " ", t).strip()
    fp = re.match(r"^(.*?)\(\s*\*\s*(\w*)\s*\)\s*\((.*)\)$", t)
    if fp:  # function pointer: `R (*name)(args)`
        ret = c_type(fp.group(1), structs)
        args = [c_type(a, structs) for a in split_params(fp.group(3))] if fp.group(3).strip() else ["void"]
        if ret is None or None in args:
            return None
        return f"{ret} (*)({', '.join(args)})"
    # drop the declarator name (the last identifier after the type words / pointer stars)
    m = re.match(r"^((?:(?:struct|union|enum)\s+)?[\w ]*?\w)\s*((?:[*&]\s*(?:const\s*)?)*)\s*(\w+)?\s*((?:\[[^\]]*\])*)$", t)
    if not m:
        return None
    base, stars, name, arrays = m.group(1).strip(), m.group(2).replace(" ", ""), m.group(3), m.group(4)
    words = base.split()
    if words and words[0] in ("struct", "union", "enum"):
        words = words[1:]
    # `s32 arg0`: the name was captured as part of base when stars are empty and name is None
    if name is None and not stars and len(words) >= 2 and words[-1] not in PRIMITIVES:
        name = words[-1]
        words = words[:-1]
    elif name is None and len(words) >= 2 and words[-1] not in PRIMITIVES and not base.startswith(("struct", "union")):
        name = words[-1]
        words = words[:-1]
    if not words:
        return None
    is_prim = all(w in PRIMITIVES for w in words)
    if arrays:  # an array parameter is a pointer
        stars += "*"
    if is_prim:
        base = " ".join(SIMPLE_TYPEDEFS.get(w, w) for w in words)
        if stars:
            return base + " " + stars.replace("&", "*")
        return base
    # a struct/class type
    if not stars:
        return None
    if pos0_class and stars in ("*", "&"):
        return f"struct {pos0_class} *"
    return "void " + stars.replace("&", "*")


def parse_source(path):
    """(definition name, its (ret, [params]), {callee: (ret, [params])}, {global: type text})."""
    # Real names (tools/symbols.py) are read as their func_/D_ADDR forms.
    text = symbols.generic_text(COMMENT.sub("", open(path, encoding="utf-8", errors="replace").read()))
    structs = {m.group(1) for m in STRUCT.finditer(text)} | {m.group(3) for m in STRUCT.finditer(text) if m.group(3)}
    structs |= set(re.findall(r"^\s*(?:typedef\s+)?(?:struct|class|union)\s+(\w+)", text, re.M))
    defn, callees, globs = None, {}, {}
    for m in DECL.finditer(text):
        ret, name, params, end = m.group(1).strip(), m.group(2), m.group(3).strip(), m.group(4)
        if not ret or ret.endswith(("return", "=", "(", ",")) or ret.split()[-1] in ("return", "else"):
            continue
        if re.search(r"[=\(]", ret):
            continue
        plist = [] if params in ("", "void") else split_params(params)
        callees[name] = (ret, plist, structs)
        if end == "{":
            defn = name
    for m in GLOBAL.finditer(text):
        globs[m.group(2)] = (m.group(1).strip(), m.group(3).strip(), structs)
    return defn, callees, globs


def render_proto(name, ret, plist, structs, this_class=None):
    """`RET func(params)` in C, or None."""
    r = c_type(ret + " x", structs)
    if r is None:
        return None
    out = []
    for i, p in enumerate(plist):
        if p.strip() == "...":
            out.append("...")
            continue
        t = c_type(p, structs, this_class if i == 0 else None)
        if t is None:
            return None
        out.append(t)
    return f"{r} {name}({', '.join(out) if out else 'void'});"


def collect_sources(owners):
    """Prototypes from matched sources: own definitions win, then the majority of caller
    declarations; globals by majority of their extern declarations."""
    defs, decls, globs = {}, defaultdict(Counter), defaultdict(Counter)
    for _, path in sorted(project.sources(refresh=True).items()):
        defn, callees, g = parse_source(path)
        for name, (ret, plist, structs) in callees.items():
            addr = int(name[5:], 16)
            proto = render_proto(name, ret, plist, structs, owners.get(addr))
            if proto is None:
                continue
            if name == defn:
                defs[name] = proto
            else:
                decls[name][proto] += 1
        for name, (ty, arrays, structs) in g.items():
            t = c_type(ty + " x", structs)
            if t is None:
                # a file-local struct type: keep the symbol typed as bytes
                t = "char"
                arrays = arrays or "[]"
            globs[name][f"extern {t} {name}{arrays};"] += 1
    protos, conflicts = {}, {}
    for name, c in decls.items():
        (best, n), = c.most_common(1)
        protos[name] = best
        if len(c) > 1:
            conflicts[name] = dict(c)
    # A definition drops the parameters it never reads, while a matched caller had to set every
    # register the original prototype asked for: keep the definition's return type with the
    # longest parameter list seen (the definition's on a tie).
    for name, d in defs.items():
        best = protos.get(name)
        if best and best.count(",") + 1 > d.count(",") + 1 and "(void)" not in best:
            params = best[best.index("("):]
            protos[name] = d[:d.index("(")] + params
        else:
            protos[name] = d
    gl = {}
    for name, c in globs.items():
        (best, n), = c.most_common(1)
        gl[name] = best
    return protos, len(defs), conflicts, gl


# ---------------------------------------------------------------- classes

def ident(name):
    return re.sub(r"\W", "_", name)


def load_classes():
    """{class: {'bases': [...], 'vtable': addr, 'functions': {addr: 'virtual'|'structor'}}}."""
    raw = json.load(open(CLASSES))
    classes = {}
    for name, c in raw.items():
        vt = c["vtables"][0]["address"] if c["vtables"] else None
        funcs = {}
        if c["vtables"]:
            for a in c["vtables"][0]["methods"]:
                funcs[a] = "virtual"
        for a in c["structors"]:
            funcs[a] = "structor"
        classes[name] = {"bases": c["bases"], "vtable": vt, "functions": funcs}
    return classes


def ancestors(classes, name):
    out, todo = [], [name]
    while todo:
        n = todo.pop(0)
        for b in classes.get(n, {}).get("bases", []):
            if b not in out:
                out.append(b)
                todo.append(b)
    return out


def assign_owners(classes):
    """Function address -> the class it belongs to: among the classes whose primary vtable holds
    it, the one that is an ancestor of all the others (an inherited slot shows up in every
    derived vtable too)."""
    cands = defaultdict(set)
    for name, c in classes.items():
        for a, kind in c["functions"].items():
            cands[a].add(name)
    owners = {}
    for a, names in cands.items():
        if len(names) == 1:
            owners[a] = next(iter(names))
            continue
        for n in names:
            anc = set(ancestors(classes, n))
            if all(o == n or o in anc or n in ancestors(classes, o) for o in names) and \
               all(n in ancestors(classes, o) for o in names if o != n):
                owners[a] = n
                break
    return owners


def common_base(classes, names):
    """The one class among names that every other one derives from, else None."""
    for n in names:
        if all(o == n or n in ancestors(classes, o) for o in names):
            return n
    return None


# ---------------------------------------------------------------- instructions

def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


def written(w):
    """The GPR an instruction writes (0 for none), approximately."""
    op = w >> 26
    if op == 0:
        f = w & 0x3F
        if f in (0x08, 0x18, 0x19, 0x1A, 0x1B, 0x0C, 0x0D, 0x0F, 0x11, 0x13):  # jr mult div syscall break sync mthi mtlo
            return 0
        return (w >> 11) & 31
    if op == 3:
        return 31
    if 0x08 <= op <= 0x0F or op in LOADS or op in (0x22, 0x26, 0x1A, 0x1B):
        return (w >> 16) & 31
    if op == 0x11 and (w >> 21) & 31 in (0, 2):  # mfc1, cfc1
        return (w >> 16) & 31
    if op == 0x1C:  # MMI
        return (w >> 11) & 31
    if op == 0x12 and (w >> 21) & 31 in (1, 2):  # qmfc2, cfc2
        return (w >> 16) & 31
    return 0


def scan(words, addr):
    """Accesses through `this` ($a0 at entry) in one function: [(offset, kind, extra)] where kind
    is a load/store width, 'ptr' (the loaded word is used as a base), 'vtbl' (used for an
    indirect call), 'vtable_store' (a constructor storing a vtable address, extra = address),
    'this_arg' (the loaded word passed as $a0 to extra = callee); plus the calls whose $a0 is
    `this` itself (extra = callee, kind 'this_call') and 'other_call' when it is not."""
    out = []
    this = {A0}           # registers holding this
    via = {}              # register -> offset of the this-field it was loaded from
    const = {}            # register -> known constant (lui/addiu/ori)
    pending_jal = None
    for i, w in enumerate(words):
        op = w >> 26
        rs, rt, rd = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        imm = sext16(w & 0xFFFF)
        wr = written(w)
        # memory accesses
        if op in LOADS or op in STORES:
            if rs in this:
                kind = LOADS.get(op) or STORES.get(op)
                out.append((imm, kind, None))
            if op == 0x2B and rs in this and rt in const:
                out.append((imm, "vtable_store", const[rt]))
            if rs in via:
                out.append((via[rs], "ptr", None))
        # register copies
        if op == 0 and (w & 0x3F) in (0x2D, 0x21, 0x25) and (rt == 0 or rs == 0) and rd:
            src = rs if rt == 0 else rt
            if src in this:
                this.add(rd)
            elif src in via:
                via[rd] = via[src]
            elif src in const:
                const[rd] = const[src]
            if src not in this:
                this.discard(rd)
            if src not in via:
                via.pop(rd, None)
            if src not in const:
                const.pop(rd, None)
        elif wr:
            this.discard(wr)
            new_via = None
            if op == 0x23 and rs in this:
                new_via = imm
            elif op == 0x09 and rs in via and rs != wr or (op == 0x09 and rs == wr and rs in via):
                new_via = via[rs]
            if new_via is not None:
                via[wr] = new_via
            else:
                via.pop(wr, None)
            if op == 0x0F:
                const[wr] = (w & 0xFFFF) << 16
            elif op == 0x09 and rs in const:
                const[wr] = (const[rs] + imm) & 0xFFFFFFFF
            elif op == 0x0D and rs in const:
                const[wr] = const[rs] | (w & 0xFFFF)
            else:
                const.pop(wr, None)
        # calls: the delay slot executes first, so decide at the slot
        if pending_jal is not None:
            callee = pending_jal
            pending_jal = None
            if callee == "indirect":
                pass
            elif A0 in this:
                out.append((0, "this_call", callee))
            elif A0 in via:
                out.append((via[A0], "this_arg", callee))
            else:
                out.append((0, "other_call", callee))
            for r in CALL_CLOBBER:
                this.discard(r)
                via.pop(r, None)
                const.pop(r, None)
        if op == 3:
            pending_jal = ((w & 0x3FFFFFF) << 2) | (addr & 0xF0000000)
        elif op == 0 and (w & 0x3F) == 0x09:
            if rs in via:
                out.append((via[rs], "vtbl", None))
            pending_jal = "indirect"
        elif op == 0 and (w & 0x3F) == 0x08 and rs != 31 and rs in via:
            out.append((via[rs], "vtbl", None))
    return out


def all_functions():
    text_addr, text = match.load_text()
    out = {}
    for r in csv.DictReader(open(match.FUNCTIONS)):
        a = int(r["address"], 16)
        out[a] = match.trim_padding(match.words_at(text_addr, text, a, int(r["max_size"])))
    return out


def mine(classes, owners, funcs, rounds=3):
    """Field evidence per class from the instructions, extending class membership to callees
    that are only ever called with a `this` pointer."""
    evidence = defaultdict(lambda: defaultdict(Counter))  # class -> offset -> kind counts
    this_arg = defaultdict(Counter)   # callee -> class counts (called with this)
    other_arg = Counter()
    field_class = defaultdict(lambda: defaultdict(Counter))  # class -> offset -> callee classes
    owners = dict(owners)
    scanned = set()
    for _ in range(rounds):
        new = [a for a in owners if a not in scanned and a in funcs]
        if not new:
            break
        for a in new:
            scanned.add(a)
            cls = owners[a]
            for off, kind, extra in scan(funcs[a], a):
                if kind == "this_call":
                    this_arg[extra][cls] += 1
                elif kind == "other_call":
                    other_arg[extra] += 1
                elif kind == "this_arg":
                    if extra in owners:
                        field_class[cls][off][owners[extra]] += 1
                elif kind == "vtable_store":
                    evidence[cls][off]["vtable_store"] += 1
                else:
                    evidence[cls][off][kind] += 1
        # callees called only with a `this` (of classes sharing a base) are methods of that base
        for callee, cnt in this_arg.items():
            if callee in owners or callee in scanned or other_arg[callee] or callee not in funcs:
                continue
            if callee >= LIBRARY:
                continue
            base = common_base(classes, list(cnt))
            if base:
                owners[callee] = base
    return evidence, field_class, owners


def layout(classes, evidence, field_class, name, vtable_addrs):
    """Fields of one class: {offset: (type, size, support, conflicts)} from its own evidence and
    its primary base chain's, keeping an offset only when 75% of its accesses agree."""
    chain = [name]
    n = name
    while classes.get(n, {}).get("bases"):
        n = classes[n]["bases"][0]
        if n in chain:
            break
        chain.append(n)
    merged = defaultdict(Counter)
    fclass = defaultdict(Counter)
    for c in chain:
        for off, cnt in evidence.get(c, {}).items():
            merged[off].update(cnt)
        for off, cnt in field_class.get(c, {}).items():
            fclass[off].update(cnt)
    fields = {}
    for off, cnt in merged.items():
        if off < 0:
            continue
        widths = Counter()
        for kind, n in cnt.items():
            if kind in ("ptr", "vtbl", "vtable_store"):
                continue
            widths[SIZES[kind]] += n
        if not widths:
            continue
        (size, n), = widths.most_common(1)
        total = sum(widths.values())
        if n < 0.75 * total or off % min(size, 8):
            continue
        kinds = Counter({k: v for k, v in cnt.items() if k in SIZES and SIZES[k] == size})
        if size == 4:
            if cnt["vtable_store"] or cnt["vtbl"]:
                ty = "void *"
                if kinds["f32"] > kinds["w"]:
                    continue
            elif kinds["f32"] >= 0.75 * sum(kinds.values()):
                ty = "f32"
            elif kinds["f32"] > 0:
                continue  # int and float at the same offset
            elif fclass.get(off):
                (cl, m), = fclass[off].most_common(1)
                ty = f"struct {ident(cl)} *" if m == sum(fclass[off].values()) else "void *"
            elif cnt["ptr"]:
                ty = "void *"
            elif kinds["u32"]:
                ty = "u32"
            else:
                ty = "s32"
        elif size == 2:
            ty = "u16" if kinds["u16"] > kinds["s16"] else "s16"
            if kinds["u16"] and kinds["s16"]:
                continue
        elif size == 1:
            ty = "u8" if kinds["u8"] > kinds["s8"] else "s8"
            if kinds["u8"] and kinds["s8"]:
                continue
        elif size == 8:
            ty = "s64"
        else:
            ty = "u128"
        fields[off] = (ty, size, n, total - n)
    # overlaps: keep the better supported field
    kept = {}
    for off, (ty, size, n, bad) in sorted(fields.items(), key=lambda kv: -kv[1][2]):
        if any(o < off + size and off < o + s for o, (_, s, _, _) in kept.items()):
            continue
        kept[off] = (ty, size, n, bad)
    return dict(sorted(kept.items()))


def render_struct(name, fields):
    lines = [f"struct {ident(name)} {{"]
    pos = 0
    for off, (ty, size, n, bad) in sorted(fields.items()):
        if off > pos:
            lines.append(f"    char unk_{pos:X}[0x{off - pos:X}];")
        lines.append(f"    {ty} unk{off:X};")
        pos = off + size
    if pos == 0:
        lines.append("    char unk_0[4];")
        pos = 4
    lines.append("};")
    return "\n".join(lines), pos


# ---------------------------------------------------------------- build

def build():
    classes = load_classes()
    owners = assign_owners(classes)
    funcs = all_functions()
    vtable_addrs = {c["vtable"] for c in classes.values() if c["vtable"]}
    evidence, field_class, owners = mine(classes, owners, funcs)
    protos, ndefs, conflicts, globs = collect_sources({a: ident(c) for a, c in owners.items()})
    structs, struct_sizes = {}, {}
    nfields = 0
    for name in classes:
        fields = layout(classes, evidence, field_class, name, vtable_addrs)
        if not fields:
            continue
        text, size = render_struct(name, fields)
        structs[ident(name)] = text
        struct_sizes[ident(name)] = size
        nfields += len(fields)
    # a class pointer type in a prototype needs its struct: declare empty ones for the rest
    for name in classes:
        structs.setdefault(ident(name), f"struct {ident(name)} {{\n    char unk_0[4];\n}};")
    db = {
        "prototypes": protos, "defined": ndefs, "prototype_conflicts": conflicts,
        "globals": globs, "structs": structs,
        "owners": {f"{a:08x}": ident(c) for a, c in owners.items()},
        "fields": {ident(n): {f"0x{o:X}": {"type": t, "support": s, "against": b}
                              for o, (t, _, s, b) in layout(classes, evidence, field_class, n, vtable_addrs).items()}
                   for n in classes},
    }
    os.makedirs(os.path.dirname(DB), exist_ok=True)
    json.dump(db, open(DB, "w"), indent=1)
    with open(CONTEXT, "w", newline="\n") as f:
        f.write("/* generated by tools/types_db.py: what the matched sources, the RTTI and the instructions\n"
                "   say about prototypes, globals and class layouts. Not hand-edited. */\n")
        f.write(PRELUDE_TYPES)
        for name in sorted(structs):
            f.write(structs[name] + "\n")
        for name in sorted(globs):
            f.write(globs[name] + "\n")
        for name in sorted(protos):
            f.write(protos[name] + "\n")
    print(f"prototypes: {len(protos)} ({ndefs} from definitions, {len(conflicts)} with disagreeing callers)")
    print(f"globals: {len(globs)}")
    print(f"classes: {len(classes)}, functions with a class: {len(owners)} "
          f"({len(assign_owners(classes))} from RTTI), classes with fields: {sum(1 for s in db['fields'].values() if s)}, "
          f"fields: {nfields}")
    print(f"written {CONTEXT}")


PRELUDE_TYPES = ("typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;\n"
                 "typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;\n"
                 "typedef float f32; typedef double f64;\n"
                 "typedef int s128 __attribute__((mode(TI))); typedef unsigned int u128 __attribute__((mode(TI)));\n"
                 "typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; "
                 "typedef s64 M2C_UNK64;\n")


# ---------------------------------------------------------------- use

_db = None


def load_db():
    global _db
    if _db is None:
        _db = json.load(open(DB)) if os.path.exists(DB) else {"prototypes": {}, "globals": {}, "structs": {}, "owners": {}}
    return _db


def declarations(names, mode, skip=(), skip_structs=(), extra_structs=()):
    """The context lines for these symbol names: structs first (transitively, those the
    prototypes mention plus extra_structs), then globals and prototypes. mode 'protos' keeps
    no structs (class pointers become `void *`), 'types' keeps them all."""
    db = load_db()
    lines, needed = [], set(extra_structs)
    for n in sorted(names):
        if n in skip:
            continue
        d = db["prototypes"].get(n) or db["globals"].get(n)
        if not d:
            continue
        if mode == "protos":
            d = re.sub(r"\bstruct \w+ \*", "void *", d)
        lines.append(d)
        needed.update(re.findall(r"\bstruct (\w+)", d))
    structs, todo, seen = [], sorted(needed), set(skip_structs)
    while todo and mode != "protos":
        s = todo.pop()
        if s in seen or s not in db["structs"]:
            continue
        seen.add(s)
        text = db["structs"][s]
        structs.append(text)
        todo.extend(set(re.findall(r"\bstruct (\w+) \*", text)) - seen)
    return structs + lines


def context_for(body, addr=None, mode="types"):
    """The declarations a draft needs to compile: the prototypes and globals it names but does
    not declare itself, and the structs those (or the body) use, minus structs the draft
    defines. With addr, the draft's own function is left to its definition in the body."""
    names = set(re.findall(r"\b(func_[0-9A-Fa-f]{8}|D_[0-9A-Fa-f]{8})\b", body))
    declared = set(re.findall(r"^[\w \*]*\b(func_[0-9A-Fa-f]{8})\s*\([^;{]*\)\s*;", body, re.M))
    declared |= set(re.findall(r"^(?:extern\s+)?[\w \*]+\b(D_[0-9A-Fa-f]{8})\b[^;{(]*;", body, re.M))
    skip = declared | ({f"func_{addr:08X}"} if addr is not None else set())
    defined = set(re.findall(r"^struct (\w+) \{", body, re.M))
    used = set(re.findall(r"\bstruct (\w+)\b", body)) - defined
    lines = declarations(names, mode, skip, defined, used)
    return "\n".join(lines) + ("\n" if lines else "")


def referenced_globals(words):
    """Addresses formed by `lui` + a 16-bit low half through the same register (a global, or an
    address inside one), as the DB names them."""
    db = load_db()
    hi, out = {}, set()
    for w in words:
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if op == 0x0F:
            hi[rt] = (w & 0xFFFF) << 16
            continue
        if rs in hi and (op in (0x09, 0x0D) or op in LOADS or op in STORES or op in (0x22, 0x26, 0x1A, 0x1B)):
            a = (hi[rs] + (w & 0xFFFF if op == 0x0D else sext16(w & 0xFFFF))) & 0xFFFFFFFF
            name = f"D_{a:08X}"
            if name in db["globals"]:
                out.add(name)
        wr = written(w)
        if wr:
            hi.pop(wr, None)
    return out


def own_prototype(addr, body, mode):
    """The draft's own signature with `this` typed as its class (from m2c's first, untyped
    draft: the parameter count is m2c's, the first type becomes `struct CLASS *`)."""
    db = load_db()
    cls = db["owners"].get(f"{addr:08x}")
    if not cls or mode == "protos" or not body:
        return None
    m = re.search(r"^([\w ]+?\**) ?(func_%08X)\(([^)]*)\)\s*\{" % addr, body, re.M)
    if not m:
        return None
    params = split_params(m.group(3)) if m.group(3).strip() not in ("", "void") else []
    if not params or not re.match(r"^(void|s8|M2C_UNK|s32|u32) \*?\s*\w+$", params[0]):
        return None
    params[0] = f"struct {cls} *{params[0].split()[-1].lstrip('*')}"
    ret = m.group(1).strip()
    return f"{ret} {m.group(2)}({', '.join(params)});"


def m2c_context(addr, mode, out, plain_body=None):
    """Write the context file m2c reads for one function: typedefs, the prototypes of the
    functions it calls, the globals it addresses, their structs, and its own prototype when
    its class is known. Returns the path, or None when the DB knows nothing about it."""
    db = load_db()
    words = match.trim_padding(match.words_at(*match.load_text(), addr, match.function_span(addr)))
    names = set()
    for w in words:
        if w >> 26 == 3:
            names.add(f"func_{(((w & 0x3FFFFFF) << 2) | (addr & 0xF0000000)):08X}")
    names |= referenced_globals(words)
    own_name = f"func_{addr:08X}"
    own = own_prototype(addr, plain_body, mode) if own_name not in db["prototypes"] else None
    lines = declarations(names | {own_name}, mode, extra_structs=re.findall(r"\bstruct (\w+)", own or ""))
    if own:
        lines.append(own)
    if not lines:
        return None
    path = os.path.join(out, f"{addr:08x}_{mode}.ctx.c")
    open(path, "w", newline="\n").write(PRELUDE_TYPES + "\n".join(lines) + "\n")
    return path


def measure(sample=400, jobs=2, out=None, seed=1, take=0):
    """Re-draft a fixed sample of unmatched functions (cpu_solve's pipeline) without a context,
    with prototypes only and with the full context; report matches and diff sizes per size.
    Resumable: functions already in bench.jsonl are skipped; take > 0 stops after that many."""
    import random
    from concurrent.futures import ThreadPoolExecutor
    import cpu_solve
    out = out or os.path.join(ROOT, "build", "auto", "types_bench")
    latest = {}
    for l in open(cpu_solve.RESULTS):
        if l.strip():
            r = json.loads(l)
            if isinstance(r, dict) and "addr" in r:  # a stray line of an interleaved write
                latest[r["addr"]] = r
    done = {f"{a:08x}" for a in project.sources(refresh=True)}
    sizes = {int(r["address"], 16): int(r["max_size"]) for r in csv.DictReader(open(match.FUNCTIONS))}
    bucket = lambda a: "<128" if sizes.get(a, 0) < 128 else "128-512" if sizes.get(a, 0) < 512 else ">512"
    pool = defaultdict(list)
    for a, r in latest.items():
        if a in done or r["result"] not in ("differs", "does not compile", "m2c could not decompile it"):
            continue
        pool[bucket(int(a, 16))].append(int(a, 16))
    os.makedirs(out, exist_ok=True)
    sample_file = os.path.join(out, "sample.json")
    if os.path.exists(sample_file):  # fixed once: results.jsonl keeps changing under other runs
        chosen = json.load(open(sample_file))
    else:
        random.seed(seed)
        share = {"<128": 0.375, "128-512": 0.375, ">512": 0.25}
        chosen = []
        for b, addrs in sorted(pool.items()):
            addrs.sort()
            chosen += random.sample(addrs, min(len(addrs), int(sample * share[b])))
        json.dump(chosen, open(sample_file, "w"))
    match.function_span(chosen[0])  # load the table before the threads start
    modes = [None, "protos", "types"]
    for m in modes:
        os.makedirs(os.path.join(out, m or "plain"), exist_ok=True)
    bench = os.path.join(out, "bench.jsonl")
    rows = [json.loads(l) for l in open(bench) if l.strip()] if os.path.exists(bench) else []
    seen = {r["addr"] for r in rows}
    chosen = [a for a in chosen if f"{a:08x}" not in seen]
    if take:
        chosen = chosen[:take]
    print(f"{len(chosen)} functions to draft, {len(seen)} done", flush=True)
    log = open(bench, "a")

    def one(addr):
        row = {"addr": f"{addr:08x}", "bucket": bucket(addr), "size": sizes.get(addr, 0)}
        for m in modes:
            try:
                r = cpu_solve.attempt(addr, context=m, out=os.path.join(out, m or "plain"))
            except BaseException as e:
                r = {"result": f"error: {str(e)[:60]}"}
            row[m or "plain"] = r
        return row

    with ThreadPoolExecutor(jobs) as ex:
        for i, row in enumerate(ex.map(one, chosen), 1):
            rows.append(row)
            log.write(json.dumps(row) + "\n")
            log.flush()
            if i % 25 == 0:
                print(f"{i}/{len(chosen)}", flush=True)
    report(rows)


def score(r):
    if r.get("result") == "match":
        return 0
    if r.get("result") == "differs":
        return r["differ"]
    return None


def report(rows):
    """Matches, diff sizes and wins per mode and size bucket."""
    for b in ("<128", "128-512", ">512", "all"):
        sel = [r for r in rows if b == "all" or r["bucket"] == b]
        if not sel:
            continue
        print(f"\n{b}: {len(sel)} functions")
        for m in ("plain", "protos", "types"):
            sc = [score(r[m]) for r in sel if m in r]
            matches = sum(1 for s in sc if s == 0)
            compiled = [s for s in sc if s is not None]
            wins = sum(1 for r in sel if m in r and (r[m].get("how") or "").endswith(("+protos", "+types")))
            print(f"  {m:<7} matches {matches:>3}  compile {len(compiled):>3}/{len(sc)}  "
                  f"mean differing instructions {sum(compiled) / max(1, len(compiled)):6.1f}  "
                  f"best draft from the context {wins:>3}")
        for m in ("protos", "types"):
            better = sum(1 for r in sel if m in r and score(r["plain"]) is not None and score(r[m]) is not None
                         and score(r[m]) < score(r["plain"]))
            worse = sum(1 for r in sel if m in r and score(r["plain"]) is not None and score(r[m]) is not None
                        and score(r[m]) > score(r["plain"]))
            fixed = sum(1 for r in sel if m in r and score(r["plain"]) is None and score(r[m]) is not None)
            shrink = sum(score(r["plain"]) - score(r[m]) for r in sel if m in r and score(r["plain"]) is not None
                         and score(r[m]) is not None)
            print(f"  {m} vs plain: closer {better}, farther {worse}, newly compiling {fixed}, "
                  f"differing instructions removed {shrink}")


def main():
    if len(sys.argv) >= 2 and sys.argv[1] == "build":
        build()
    elif len(sys.argv) >= 3 and sys.argv[1] == "show":
        db = load_db()
        name = ident(sys.argv[2])
        print(db["structs"].get(name, "(no struct)"))
        for off, f in db["fields"].get(name, {}).items():
            print(f"  {off:>6} {f['type']:<24} {f['support']} for, {f['against']} against")
    elif len(sys.argv) >= 4 and sys.argv[1] == "context":
        sys.stdout.write(context_for(open(sys.argv[3]).read(), int(sys.argv[2], 16)))
    elif len(sys.argv) >= 2 and sys.argv[1] == "measure":
        import argparse
        ap = argparse.ArgumentParser()
        ap.add_argument("--sample", type=int, default=400)
        ap.add_argument("--jobs", type=int, default=2)
        ap.add_argument("--take", type=int, default=0, help="stop after this many new functions (resumable)")
        ap.add_argument("--report", action="store_true", help="only summarise build/auto/types_bench/bench.jsonl")
        a = ap.parse_args(sys.argv[2:])
        if a.report:
            path = os.path.join(ROOT, "build", "auto", "types_bench", "bench.jsonl")
            report([json.loads(l) for l in open(path) if l.strip()])
        else:
            measure(a.sample, a.jobs, take=a.take)
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
