#!/usr/bin/env python3
"""Clean m2c's leftovers out of matched sources, keeping a rewrite only where the judge still says
MATCH (tools/match.py judge_many: the same judge as `match.py check`, compiled in batches).

    cleanup.py headers [FILES...] [--max N] [--jobs 2] [--dry-run] [--retry]
        the pasted m2c macro block -> #include "m2c_macros.h" (or nothing, when the source uses
        none of its macros); the pasted sized-type typedefs -> #include "types.h"
    cleanup.py fields [FILES...] [--max N] [--jobs 2] [--dry-run] [--retry] [--cast-only]
        M2C_FIELD(p, T *, OFF) and *(T *)((char *)p + OFF) -> p->unkOFF, through a struct with the
        fields the function uses at their offsets (char padding between them). First choice: the
        variable itself gets the struct type (C sources, `void *` variables never used in pointer
        arithmetic); second choice: ((struct S *)p)->unkOFF. Shared layouts (include/gt4/, tools/
        gen_headers.py) replace these per-function structs later.
    cleanup.py show FILE [--pass headers|fields]
        print the candidate rewrites of one file (nothing is judged or written)

Each candidate is written under build/cleanup/<pass>/stage/ with the source's own file name (the
judge reads the address and the link check from it), all candidates of a run are judged together,
and a candidate replaces the source only on MATCH; a source with several candidates tries the next
one where the first differs. Every verdict goes to build/cleanup/<pass>.jsonl; a source whose
candidates all failed is skipped by later runs while its text is unchanged, unless --retry.
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import sys

import match
import project

ROOT = project.ROOT
OUT = os.path.join(ROOT, "build", "cleanup")
INCLUDE = os.path.join(ROOT, "include")

# ---------------------------------------------------------------- text helpers

M2C_BLOCK = re.compile(r"/\*\n \* This header contains macros emitted by m2c.*?\n#ifndef M2C_MACROS_H\n.*?\n#endif\n", re.S)
MEMCPY_NAMES = ("M2C_MEMCPY_ALIGNED", "M2C_MEMCPY_UNALIGNED", "M2C_STRUCT_COPY")
TYPEDEFS = ("typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;\n"
            "typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;\n"
            "typedef float f32; typedef double f64;\n")
TYPEDEFS_128 = "typedef int s128 __attribute__((mode(TI))); typedef unsigned int u128 __attribute__((mode(TI)));\n"
INCLUDE_MACROS = '#include "m2c_macros.h"\n'
INCLUDE_TYPES = '#include "types.h"\n'


def canonical_block():
    """The macro block as m2c pastes it (memcpy for the copy patterns), from tools/ext/m2c."""
    import cpu_solve
    return cpu_solve.MACROS.replace("\r\n", "\n").rstrip("\n") + "\n"


def macro_names():
    """Every name include/m2c_macros.h defines (macros and typedefs)."""
    text = open(os.path.join(INCLUDE, "m2c_macros.h"), encoding="utf-8").read()
    names = set(re.findall(r"^#define (\w+)", text, re.M)) | set(re.findall(r"^typedef [^;]*?(\w+);", text, re.M))
    return names - {"M2C_MACROS_H"}


def strip_comments(text):
    """text with comments and string/char literals blanked (same length), for searching code."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append(re.sub(r"[^\n]", " ", text[i:j]))
            i = j
        elif text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i))
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            j = min(j + 1, n)
            out.append(c + " " * (j - i - 2) + (c if j - i >= 2 else ""))
            i = j
        else:
            out.append(c)
            i += 1
    return "".join(out)


MEMCPY_DEFINES = re.compile(r"^#define (?:M2C_MEMCPY_ALIGNED|M2C_MEMCPY_UNALIGNED|M2C_STRUCT_COPY) \w+\n", re.M)


def without_unused_macros(text):
    """text without #include "m2c_macros.h" (and the copy-routine #defines made for it) when the
    code uses nothing the header defines."""
    if INCLUDE_MACROS not in text:
        return text
    rest = MEMCPY_DEFINES.sub("", text.replace(INCLUDE_MACROS, "", 1))
    return text if uses_macros(rest) else rest


def uses_macros(text, names=None):
    """Whether code (outside comments, the m2c block itself and its include line) names any of
    m2c_macros.h's definitions."""
    names = names or macro_names()
    code = strip_comments(M2C_BLOCK.sub("", text))
    words = set(re.findall(r"\b[A-Za-z_]\w*\b", code))
    return bool(words & names)


# ---------------------------------------------------------------- pass: headers

def headers_candidates(text, path):
    """[new text] for the headers pass, or []."""
    new = text
    m = M2C_BLOCK.search(new)
    if m:
        block = m.group(0)
        canon = canonical_block()
        defines = ""
        if block != canon:
            # the same block with another copy routine for the memcpy patterns (TT: func_005A4724)
            routine = re.search(r"#define M2C_MEMCPY_ALIGNED (\w+)\n", block)
            if not routine or block != canon.replace(" memcpy\n", f" {routine.group(1)}\n"):
                return []
            defines = "".join(f"#define {n} {routine.group(1)}\n" for n in MEMCPY_NAMES)
        rest = new[:m.start()] + new[m.end():]
        if uses_macros(rest):
            new = new[:m.start()] + defines + INCLUDE_MACROS + new[m.end():]
        else:
            new = rest
    else:
        new = without_unused_macros(new)
    # the pasted typedef lines (all four, or the first two or three of them) -> types.h, which
    # declares all four; a declaration nobody uses changes no code
    lines = (TYPEDEFS + TYPEDEFS_128).splitlines(keepends=True)
    # tools/trivial.py's shorter second line (until 2026-10-10) counts as the second line too
    seconds = (lines[1], "typedef int s32; typedef unsigned int u32; typedef long long s64;\n")
    run = re.search("^" + re.escape(lines[0]) + "(?:" + "|".join(re.escape(l) for l in lines[1:] + [seconds[1]]) + ")+",
                    new, re.M)
    if run and any(s in run.group(0) for s in seconds):
        new = new[:run.start()] + INCLUDE_TYPES + new[run.end():]
    return [new] if new != text else []


# ---------------------------------------------------------------- pass: fields

SIZES = {"s8": 1, "u8": 1, "char": 1, "signed char": 1, "unsigned char": 1, "M2C_UNK8": 1,
         "s16": 2, "u16": 2, "short": 2, "unsigned short": 2, "M2C_UNK16": 2,
         "s32": 4, "u32": 4, "f32": 4, "int": 4, "unsigned int": 4, "float": 4, "long": 4,
         "unsigned long": 4, "M2C_UNK": 4, "M2C_UNK32": 4,
         "s64": 8, "u64": 8, "f64": 8, "double": 8, "long long": 8, "unsigned long long": 8, "M2C_UNK64": 8,
         "s128": 16, "u128": 16}
BYTE_PTR = r"(?:char|s8|u8|signed char|unsigned char)\s*\*"
NUM = r"(?:0x[0-9A-Fa-f]+|\d+)"


def split_args(s):
    """Split a macro argument list at top-level commas."""
    out, depth, cur = [], 0, []
    for c in s:
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
        if c == "," and depth == 0:
            out.append("".join(cur))
            cur = []
        else:
            cur.append(c)
    out.append("".join(cur))
    return [a.strip() for a in out]


def matching_paren(code, i):
    """Index of the parenthesis closing the one at code[i]."""
    depth = 0
    for j in range(i, len(code)):
        if code[j] == "(":
            depth += 1
        elif code[j] == ")":
            depth -= 1
            if depth == 0:
                return j
    return -1


def field_decl(ptr_type, name):
    """(declaration of a field called name whose address type is ptr_type, size, alignment), or
    None for a type whose size is not known here."""
    t = re.sub(r"\s+", " ", ptr_type.strip())
    fp = re.fullmatch(r"(.*?)\(\s*\*(\**)\s*\)(\s*\(.*\))", t)  # R (**)(ARGS): a function pointer field
    if fp:
        if not fp.group(2):
            return None  # R (*)(ARGS): the field would be a function, not a pointer to one
        return f"{fp.group(1).strip()} ({fp.group(2)}{name}){fp.group(3).strip()}", 4, 4
    sp = re.fullmatch(r"((?:const )?[A-Za-z_][\w ]*?) ?(\*+)", t)
    if not sp:
        return None
    base, stars = sp.group(1).strip(), sp.group(2)[:-1]
    if stars:
        return f"{base} {stars}{name}", 4, 4
    size = SIZES.get(base.replace("const ", ""))
    if size is None:
        return None
    return f"{base} {name}", size, size


def functions(code):
    """[(name, header start, body open brace, body close brace)] of the function definitions in
    code (comments already blanked). extern "C" { } blocks are looked into."""
    out, i, depth, stmt_start = [], 0, 0, 0
    linkage = []  # depths of the extern "C" blocks open
    while i < len(code):
        c = code[i]
        if c == "#" and (i == 0 or code[code.rfind("\n", 0, i) + 1:i].strip() == ""):
            j = i
            while True:  # a preprocessor line, with its continuations
                j = code.find("\n", j)
                if j < 0 or code[j - 1] != "\\":
                    break
                j += 1
            i = len(code) if j < 0 else j + 1
            if depth == len(linkage):
                stmt_start = i
            continue
        if c == "{":
            header = code[stmt_start:i]
            if depth == len(linkage) and re.search(r'extern\s+"\s*C?\s*"\s*$', header):
                linkage.append(depth)
                depth += 1
                stmt_start = i + 1
                i += 1
                continue
            m = re.search(r"([A-Za-z_][\w:~]*)\s*\(", header)
            if depth == len(linkage) and m and re.search(r"\)\s*(const\s*)?(throw\s*\([^)]*\)\s*)?$", header):
                end, d = i, 0
                for k in range(i, len(code)):
                    if code[k] == "{":
                        d += 1
                    elif code[k] == "}":
                        d -= 1
                        if d == 0:
                            end = k
                            break
                lead = len(header) - len(header.lstrip())
                c_linkage = bool(linkage) or re.match(r'\s*extern\s+"\s*C?\s*"', header) is not None
                out.append((m.group(1), stmt_start + lead, i, end, c_linkage))
                i = end + 1
                stmt_start = i
                continue
            depth += 1
        elif c == "}":
            if linkage and linkage[-1] == depth - 1:
                linkage.pop()
            depth -= 1
            if depth == len(linkage):
                stmt_start = i + 1
        elif c == ";" and depth == len(linkage):
            stmt_start = i + 1
        i += 1
    return out


def accesses(code, lo, hi):
    """[(start, end, base identifier, pointer type, offset)] of the raw field accesses in
    code[lo:hi]: M2C_FIELD(ID, T *, OFF) and *(T *)((char *)ID + OFF)."""
    out = []
    for m in re.finditer(r"\bM2C_FIELD\s*\(", code[lo:hi]):
        s = lo + m.start()
        open_ = lo + m.end() - 1
        close = matching_paren(code, open_)
        if close < 0:
            continue
        args = split_args(code[open_ + 1:close])
        if len(args) != 3 or not re.fullmatch(r"[A-Za-z_]\w*", args[0]) or not re.fullmatch(NUM, args[2]):
            continue
        out.append((s, close + 1, args[0], args[1], int(args[2], 0)))
    pat = re.compile(r"\*\s*\(\s*([^()]*?\*|[^()]*?\(\s*\*+\s*\)\s*\([^()]*\)\s*\*?)\s*\)\s*\(\s*\(\s*" + BYTE_PTR
                     + r"\s*\)\s*([A-Za-z_]\w*)\s*\+\s*(" + NUM + r")\s*\)")
    for m in pat.finditer(code[lo:hi]):
        # *(T *)(...) whose operand is exactly the byte-pointer sum; a deref of a bigger expression
        # (e.g. `x * (s32 *)...`) is not this: the * must start an operand
        before = code[:lo + m.start()].rstrip()
        if before and (before[-1].isalnum() or before[-1] in "_)]") \
                and not re.search(r"\b(return|case|else|do)$", before):
            continue
        out.append((lo + m.start(), lo + m.end(), m.group(2), m.group(1), int(m.group(3), 0)))
    return sorted(out)


def declaration(text, code, name, header, body):
    """(start, end, type) of the declaration of `name` as a parameter of the function whose header
    is code[header[0]:header[1]] or as a local at the top of its body, or None."""
    h0, h1 = header
    # the parameter list: the top-level (...) the header ends with (before const / throw())
    po = code.rfind("(", h0, h1)
    while po > h0:
        pc = matching_paren(code, po)
        if pc >= 0 and re.fullmatch(r"\s*(const\s*)?(throw\s*\([^)]*\)\s*)?", code[pc + 1:h1]):
            break
        po = code.rfind("(", h0, po)
    if po > h0:
        pc = matching_paren(code, po)
        k = po + 1
        for part in split_args(code[po + 1:pc]):
            raw_start = code.find(part, k) if part else k
            if part and re.search(r"\b%s$" % re.escape(name), part):
                return raw_start, raw_start + len(part), part[:-len(name)].strip()
            k = (raw_start + len(part)) if part else k
    b0, b1 = body
    for m in re.finditer(r"^[ \t]*((?:const\s+|unsigned\s+|signed\s+|struct\s+)*[A-Za-z_]\w*[\s\*]*?)\s*\b%s\s*;" % re.escape(name),
                         code[b0:b1], re.M):
        s = b0 + m.start(1)
        return s, b0 + m.end() - 1, m.group(1).strip()
    return None


def only_plain_uses(code, name, lo, hi, skip, cpp=False):
    """Whether every use of name in code[lo:hi] outside the spans in skip neither does pointer
    arithmetic nor dereferences it (so it may change from void * to a struct pointer)."""
    for m in re.finditer(r"\b%s\b" % re.escape(name), code[lo:hi]):
        p = lo + m.start()
        if any(s <= p < e for s, e in skip):
            continue
        before = code[:p].rstrip()[-2:]
        after = code[p + len(name):].lstrip()[:2]
        if after[:1] in ("[", "+") or after[:1] == "-" and after != "->":
            return False  # indexing, arithmetic, ++/--, += / -=
        if before.endswith(("+", "-")) and not before.endswith("->"):
            return False
        if before.endswith("*") and not re.search(r"[\w)\]]\s*\*$", code[:p].rstrip()):
            return False  # a dereference, not a multiplication
        if before.endswith("&") and not re.search(r"[\w)\]]\s*&$", code[:p].rstrip()):
            return False  # its address: a pointer to the variable would change type too
        if after.startswith("->") or after[:1] == "." or after[:1] == "(":
            return False
        if cpp and after[:1] == "=" and after != "==":
            return False  # C++ does not convert void * to a struct pointer on assignment
    return True


def fields_candidates(text, path, cast_only=False):
    """[candidate texts] of the fields pass: retyped variables first, then casts."""
    code = strip_comments(text)
    is_c = path.endswith(".c")
    plans = []  # per function: (function name, header span, body span, {id: [accesses]})
    for name, h0, b0, b1, c_linkage in functions(code):
        found = accesses(code, b0, b1)
        if not found:
            continue
        by_id = {}
        for a in found:
            by_id.setdefault(a[2], []).append(a)
        plans.append((name, (h0, b0), (b0, b1), by_id, c_linkage))
    if not plans:
        return []

    def build(retype):
        edits = []  # (start, end, replacement)
        inserts = {}  # position -> struct definitions to insert there
        changed = False
        for fname, header, body, by_id, c_linkage in plans:
            for ident, accs in by_id.items():
                fields = {}
                ok = True
                for _, _, _, ptr, off in accs:
                    decl = field_decl(ptr, f"unk{off:X}")
                    if decl is None or off < 0 or off % decl[2]:
                        ok = False
                        break
                    if off in fields and fields[off][0] != decl[0]:
                        ok = False  # the same offset read as two types: a union, not for this pass
                        break
                    fields[off] = decl
                if not ok:
                    continue
                spans = sorted(fields.items())
                if any(o + d[1] > spans[k + 1][0] for k, (o, d) in enumerate(spans[:-1])):
                    continue  # overlapping fields
                sname = f"{re.sub(r'[^\w]', '_', fname)}_{ident}"
                lines, at = [], 0
                for off, (decl, size, _) in spans:
                    if off > at:
                        lines.append(f"    char pad{at:X}[0x{off - at:X}];")
                    lines.append(f"    {decl};")
                    at = off + size
                struct = f"struct {sname} {{\n" + "\n".join(lines) + "\n};\n"
                use_retype = False
                # C++: only functions with C linkage (the parameter types are not in the symbol)
                if retype and (is_c or c_linkage):
                    d = declaration(text, code, ident, header, body)
                    if d and re.sub(r"\s+", " ", d[2]) in ("void *", "void*"):
                        skip = [(s, e) for s, e, *_ in accs]
                        if only_plain_uses(code, ident, header[0], body[1], skip + [(d[0], d[1])], cpp=not is_c):
                            use_retype = True
                            edits.append((d[0], d[0] + len(text[d[0]:d[1]]) - len(ident),
                                          f"struct {sname} *"))
                if not use_retype and retype:
                    continue  # the retype candidate changes only what it can retype
                for s, e, _, _, off in accs:
                    edits.append((s, e, f"{ident}->unk{off:X}" if use_retype else f"((struct {sname} *){ident})->unk{off:X}"))
                inserts.setdefault(header[0], []).append(struct)
                changed = True
        if not changed:
            return None
        for pos, structs in inserts.items():
            edits.append((pos, pos, "".join(structs) + "\n"))
        new = text
        for s, e, rep in sorted(edits, key=lambda x: (x[0], x[1]), reverse=True):
            new = new[:s] + rep + new[e:]
        return without_unused_macros(new)

    out = []
    if not cast_only:
        r = build(True)
        if r:
            out.append(r)
    c = build(False)
    if c and c not in out:
        out.append(c)
    return out


# ---------------------------------------------------------------- driver

# ---------------------------------------------------------------- pass: chains

def chains_candidates(text, path):
    """[candidate], or []: M2C_FIELD(V->unkN, T *, OFF) where V is a `struct S *` and S (defined in
    this file by the fields pass) has `void *unkN`: unkN becomes a pointer to a new struct S_unkN
    with the fields used through it, and the access V->unkN->unkOFF. Run it again for deeper chains.
    Only where every other use of unkN (through any struct S variable) neither does arithmetic on it
    nor dereferences it."""
    code = strip_comments(text)
    is_c = path.endswith(".c")
    found = []  # (start, end, struct, var, field, ptr type, offset)
    for m in re.finditer(r"\bM2C_FIELD\s*\(", code):
        open_ = m.end() - 1
        close = matching_paren(code, open_)
        if close < 0:
            continue
        args = split_args(code[open_ + 1:close])
        if len(args) != 3 or not re.fullmatch(NUM, args[2]):
            continue
        c = re.fullmatch(r"([A-Za-z_]\w*)->(unk[0-9A-F]+)", args[0])
        if not c:
            continue
        found.append((m.start(), close + 1, c.group(1), c.group(2), args[1], int(args[2], 0)))
    if not found:
        return []
    # the struct type of each variable: `struct S *V` declarations anywhere in the file
    types = {}
    for d in re.finditer(r"\bstruct\s+(\w+)\s*\*\s*(\w+)\s*[,;)=]", code):
        types.setdefault(d.group(2), set()).add(d.group(1))
    groups = {}
    for s, e, var, field, ptr, off in found:
        ss = types.get(var, set())
        if len(ss) != 1:
            continue
        groups.setdefault((next(iter(ss)), field), []).append((s, e, var, ptr, off))
    edits, inserts = [], {}
    for (sname, field), accs in groups.items():
        sdef = re.search(r"^struct %s \{\n(.*?)^\};\n" % re.escape(sname), text, re.M | re.S)
        if not sdef:
            continue  # S comes from a header: not this pass's to change
        line = re.search(r"^(\s+)void \*%s;\n" % field, sdef.group(1), re.M)
        if not line:
            continue
        fields, ok = {}, True
        for _, _, _, ptr, off in accs:
            decl = field_decl(ptr, f"unk{off:X}")
            if decl is None or off % decl[2] or (off in fields and fields[off][0] != decl[0]):
                ok = False
                break
            fields[off] = decl
        spans = sorted(fields.items())
        if not ok or any(o + d[1] > spans[k + 1][0] for k, (o, d) in enumerate(spans[:-1])):
            continue
        holders = {v for v, ss in types.items() if sname in ss}
        skip = [(s, e) for s, e, *_ in accs]
        if not all(only_plain_uses(code, f"{v}->{field}", 0, len(code), skip, cpp=not is_c) for v in holders):
            continue
        new_name = f"{sname}_{field}"
        if re.search(r"\bstruct\s+%s\b" % re.escape(new_name), code):
            continue
        body, at = [], 0
        for off, (decl, size, _) in spans:
            if off > at:
                body.append(f"    char pad{at:X}[0x{off - at:X}];")
            body.append(f"    {decl};")
            at = off + size
        inserts.setdefault(sdef.start(), []).append(f"struct {new_name} {{\n" + "\n".join(body) + "\n};\n")
        ls = sdef.start(1) + line.start()
        edits.append((ls, ls + len(line.group(0)), f"{line.group(1)}struct {new_name} *{field};\n"))
        for s, e, var, _, off in accs:
            edits.append((s, e, f"{var}->{field}->unk{off:X}"))
    if not edits:
        return []
    for pos, structs in inserts.items():
        edits.append((pos, pos, "".join(structs)))
    new = text
    for s, e, rep in sorted(edits, key=lambda x: (x[0], x[1]), reverse=True):
        new = new[:s] + rep + new[e:]
    return [without_unused_macros(new)]


# ---------------------------------------------------------------- the other game's view

GAME_INCLUDE = re.compile(r'^#include "(gt4|tt)/(\w+)\.h"\n', re.M)


def portable(text):
    """text with the game's own class headers (#include "<game>/<Class>.h") inlined, so that the
    sister game, which has its own include/<game>/, can compile it (tools/crossgame.py)."""
    def one(m):
        path = os.path.join(INCLUDE, m.group(1), m.group(2) + ".h")
        if not os.path.exists(path):
            return m.group(0)
        return open(path, encoding="utf-8").read().replace("\r\n", "\n").rstrip("\n") + "\n"
    return GAME_INCLUDE.sub(one, text)


def struct_fields(text):
    """{struct: {field name: (offset, pointer type of the field)}} of the structs in text written by
    this tool or tools/gen_headers.py (char padding, unk<OFF> fields, anonymous unions)."""
    out = {}
    for d in re.finditer(r"^struct (\w+) \{\n(.*?)^\};", text, re.M | re.S):
        fields = {}
        for line in d.group(2).splitlines():
            m = re.match(r"^\s+(.*\b(unk([0-9A-F]+)(?:_\w+)?)\b.*?);\s*$", line)
            if not m:
                continue
            decl, name, off = m.group(1), m.group(2), int(m.group(3), 16)
            fp = re.fullmatch(r"(.*?)\(\s*(\**)\s*%s\s*\)(\s*\(.*\))" % name, decl)
            if fp:
                ptr = f"{fp.group(1).strip()} (*{fp.group(2)}){fp.group(3).strip()}"
            else:
                ptr = re.sub(r"\b%s\b" % name, "", decl).strip()
                ptr = re.sub(r"\s*\*\s*$", " **", ptr + " ") if ptr.endswith("*") else ptr + " *"
                ptr = re.sub(r"\s+", " ", ptr).replace("* *", "**").strip()
            fields[name] = (off, ptr)
        if fields:
            out[d.group(1)] = fields
    return out


def raw_form(text):
    """The struct field accesses of text written back as M2C_FIELD(p, T *, OFF), the offsets as
    literals (and the class headers inlined): what tools/neartwin.py adapts, offset by offset, for
    the sister game's twin of a function. The struct definitions stay (unused)."""
    text = portable(text)
    structs = struct_fields(text)
    if not structs:
        return text
    code = strip_comments(text)
    var_type = {}
    for d in re.finditer(r"\bstruct\s+(\w+)\s*\*\s*(\w+)\s*[,;)=]", code):
        if d.group(1) in structs:
            var_type.setdefault(d.group(2), d.group(1))
    chain = re.compile(r"(\(\(struct (\w+) \*\)(\w+)\)|\b(\w+))((?:->unk[0-9A-F]+(?:_\w+)?)+)")
    edits = []
    for m in chain.finditer(code):
        sname = m.group(2) or var_type.get(m.group(4))
        expr = m.group(3) or m.group(4)
        if not sname:
            continue
        ok = True
        for name in re.findall(r"->(unk[0-9A-F]+(?:_\w+)?)", m.group(5)):
            f = structs.get(sname, {}).get(name)
            if not f:
                ok = False
                break
            off, ptr = f
            expr = f"M2C_FIELD({expr}, {ptr}, 0x{off:X})"
            nxt = re.fullmatch(r"struct (\w+) \*\*", ptr)
            sname = nxt.group(1) if nxt else None
        if ok:
            edits.append((m.start(), m.end(), expr))
    for s, e, rep in reversed(edits):
        text = text[:s] + rep + text[e:]
    if edits and INCLUDE_MACROS not in text:
        text = text.replace(INCLUDE_TYPES, INCLUDE_TYPES + INCLUDE_MACROS, 1) if INCLUDE_TYPES in text \
            else INCLUDE_MACROS + text
    return text


# ---------------------------------------------------------------- pass: unknown types

UNK_TYPES = {"M2C_UNK": "s32", "M2C_UNK8": "s8", "M2C_UNK16": "s16", "M2C_UNK32": "s32", "M2C_UNK64": "s64"}


def unktypes_candidates(text, path):
    """[text with m2c's unknown-type names replaced by the types they are typedefs of], or []; the
    macro include goes too when nothing else of it is used. A typedef name is not part of a C++
    mangled name, so the symbols stay the same."""
    code = strip_comments(text)
    hits = [m for m in re.finditer(r"\bM2C_UNK(?:8|16|32|64)?\b", code)
            if not code[code.rfind("\n", 0, m.start()) + 1:m.start()].lstrip().startswith("#")]
    if not hits:
        return []
    new = text
    for m in reversed(hits):
        new = new[:m.start()] + UNK_TYPES[m.group(0)] + new[m.end():]
    return [without_unused_macros(new)]


# ---------------------------------------------------------------- pass: class headers

_class_data = {}


def class_data():
    """(classes.json, {address: class}, field table) of tools/gen_headers.py, read once."""
    if not _class_data:
        import gen_headers
        classes = gen_headers.load_classes()
        _class_data.update(classes=classes, owners=gen_headers.owners(classes), fields=gen_headers.load_fields(), memo={})
    return _class_data


def classes_candidates(text, path):
    """[text using include/<game>/<Class>.h instead of its own struct for `this`], or []: for a
    function of one class (config/classes.json) whose first parameter has the struct tools/cleanup.py
    fields wrote, when the class header has every field of it (same offset and type)."""
    import gen_headers
    addr = project.source_address(path)
    data = class_data()
    cls = data["owners"].get(addr)
    if not cls or not os.path.exists(os.path.join(gen_headers.OUT, f"{cls}.h")):
        return []
    found = gen_headers.this_struct(text)
    if not found:
        return []
    sname, (d0, d1), fields, param = found
    names = gen_headers.header_names(cls)  # what the header file has, as written
    renames = {}
    for off, decl, _ in fields:
        name = names.get((off, gen_headers.normalize(decl)))
        if name is None:
            return []  # the header does not have this field (yet): regenerate it first
        if name != f"unk{off:X}":
            renames[f"unk{off:X}"] = name
    # every variable of that struct type (the parameter, and copies such as `struct S *s0 = arg0`)
    holders = {param} | set(re.findall(r"\bstruct\s+%s\s*\*\s*(\w+)" % re.escape(sname), text))
    new = text[:d0] + text[d1:].lstrip("\n") if text[d1:d1 + 1] == "\n" else text[:d0] + text[d1:]
    new = re.sub(r"\bstruct\s+%s\b" % re.escape(sname), f"struct {cls}", new)
    for old, name in renames.items():
        for v in holders:
            new = re.sub(r"(\b%s|\(struct %s \*\)%s\))->%s\b" % (re.escape(v), re.escape(cls), re.escape(v), old),
                         lambda m: f"{m.group(1)}->{name}", new)
    line = f'#include "{gen_headers.GAME}/{cls}.h"\n'
    if INCLUDE_TYPES in new:
        new = new.replace(INCLUDE_TYPES, INCLUDE_TYPES + line, 1)
    elif project.COMPILER_MARKER.match(new.split("\n", 1)[0]):
        first, rest = new.split("\n", 1)
        new = first + "\n" + line + rest
    else:
        new = line + new
    return [new]


PASSES = {"headers": headers_candidates, "fields": fields_candidates, "unktypes": unktypes_candidates,
          "classes": classes_candidates, "chains": chains_candidates}


def candidates(pass_name, text, path, cast_only=False):
    """The pass's candidate rewrites of text; a source with CRLF line ends is rewritten with LF
    and given its CRLF back (line ends do not change the code)."""
    crlf = "\r\n" in text
    plain = text.replace("\r\n", "\n") if crlf else text
    out = fields_candidates(plain, path, cast_only) if pass_name == "fields" else PASSES[pass_name](plain, path)
    return [c.replace("\n", "\r\n") for c in out] if crlf else out


def digest(text):
    return hashlib.sha1(text.encode("utf-8", "surrogateescape")).hexdigest()


def failed_before(pass_name):
    """{path: text digest} of sources whose candidates all failed in an earlier run."""
    log = os.path.join(OUT, f"{pass_name}.jsonl")
    out = {}
    if os.path.exists(log):
        for line in open(log, encoding="utf-8"):
            r = json.loads(line)
            if r.get("final") == "failed":
                out[r["file"]] = r["digest"]
            elif r.get("final") == "kept":
                out.pop(r["file"], None)
    return out


def run(pass_name, files, a):
    sources = project.sources(refresh=True)
    by_path = {os.path.normcase(os.path.abspath(p)): addr for addr, p in sources.items()}
    if files:
        paths = [os.path.abspath(f) for f in files]
    else:
        paths = sorted(sources.values())
    skip = {} if a.retry else failed_before(pass_name)
    todo = []  # (addr, path, original text, [candidates])
    for p in paths:
        addr = by_path.get(os.path.normcase(os.path.abspath(p)))
        if addr is None:
            continue
        rel = os.path.relpath(p, ROOT).replace("\\", "/")
        try:
            with open(p, encoding="utf-8", errors="surrogateescape", newline="") as f:
                text = f.read()
        except OSError:  # moved or deleted by another job since the scan
            continue
        if skip.get(rel) == digest(text):
            continue
        cands = candidates(pass_name, text, p, a.cast_only)
        if cands:
            todo.append((addr, p, text, cands))
        if a.max and len(todo) >= a.max:
            break
    print(f"{pass_name}: {len(todo)} sources with a rewrite to judge", flush=True)
    if a.dry_run or not todo:
        for addr, p, text, cands in todo[:5]:
            print(f"--- {os.path.relpath(p, ROOT)} ({len(cands)} candidates)")
        return
    stage = os.path.join(OUT, pass_name, "stage")
    os.makedirs(OUT, exist_ok=True)
    log = open(os.path.join(OUT, f"{pass_name}.jsonl"), "a", encoding="utf-8")
    kept = failed = 0
    pending = [(addr, p, text, cands, 0) for addr, p, text, cands in todo]
    while pending:
        shutil.rmtree(stage, ignore_errors=True)
        jobs = []
        for n, (addr, p, text, cands, k) in enumerate(pending):
            # one directory per source: two sources may share a file name (different units)
            d = os.path.join(stage, str(n))
            os.makedirs(d, exist_ok=True)
            sp = os.path.join(d, os.path.basename(p))
            with open(sp, "w", encoding="utf-8", errors="surrogateescape", newline="") as f:
                f.write(cands[k])
            jobs.append((addr, sp))
        verdicts = {sp: (ok, report) for _, sp, ok, report in match.judge_many(jobs, a.jobs)}
        nxt = []
        for (addr, p, text, cands, k), (_, sp) in zip(pending, jobs):
            ok, report = verdicts[sp]
            rel = os.path.relpath(p, ROOT).replace("\\", "/")
            row = {"file": rel, "addr": f"{addr:08x}", "candidate": k, "digest": digest(text),
                   "result": "match" if ok else "differs", "first": (report or "").splitlines()[0][:160] if report else ""}
            if ok:
                # the source must still be what was read (no other agent changed it meanwhile)
                try:
                    with open(p, encoding="utf-8", errors="surrogateescape", newline="") as f:
                        current = f.read()
                except OSError:  # moved or deleted by another job meanwhile
                    current = None
                if current == text:
                    with open(p, "w", encoding="utf-8", errors="surrogateescape", newline="") as g:
                        g.write(cands[k])
                    kept += 1
                    row["final"] = "kept"
                else:
                    row["final"] = "source changed meanwhile"
            elif k + 1 < len(cands):
                nxt.append((addr, p, text, cands, k + 1))
            else:
                failed += 1
                row["final"] = "failed"
            log.write(json.dumps(row) + "\n")
        log.flush()
        pending = nxt
    shutil.rmtree(stage, ignore_errors=True)
    print(f"{pass_name}: judged {len(todo)} sources, kept {kept} rewrites (MATCH), {failed} left as they were")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("pass_name", choices=sorted(PASSES) + ["show"])
    ap.add_argument("files", nargs="*")
    ap.add_argument("--max", type=int, default=0, help="judge at most N sources this run")
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--retry", action="store_true", help="also sources whose rewrites failed before")
    ap.add_argument("--cast-only", action="store_true", help="fields: only the cast form")
    ap.add_argument("--pass", dest="show_pass", default="fields", help="show: which pass")
    a = ap.parse_args()
    if a.pass_name == "show":
        for f in a.files:
            text = open(f, encoding="utf-8", errors="surrogateescape", newline="").read()
            cands = candidates(a.show_pass, text, f, a.cast_only)
            for k, c in enumerate(cands):
                print(f"===== {f}: candidate {k}")
                print(c)
            if not cands:
                print(f"{f}: no rewrite")
        return
    run(a.pass_name, a.files, a)


if __name__ == "__main__":
    main()
