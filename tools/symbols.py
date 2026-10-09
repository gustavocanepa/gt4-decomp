#!/usr/bin/env python3
"""The project's symbol table: every name an address is known by, and the address each name
stands for. The judge (match.py) and the build (build.py) resolve every symbol a source uses
through this table, so sources may call functions and globals by their real names.

Names come from:
  config/symbol_addrs.txt   tools/rtti.py: Class__virtual_NN, Class__structor_N, Class__tf (code)
                            and Class__vtable (data), as `name = 0xADDR; // type:func|data`
  config/adhoc_methods.txt  tools/registration.py: `Class method 0xADDR`, the native methods the
                            script engine registers, used as Class__method

and the generic forms always work: func_ADDR, D_ADDR, jtbl_ADDR (also sub_/data_), with or
without a C++ mangling suffix. gcc 2.96 mangling is understood too: `name__F...` (plain
function), `method__NClass...` (member of Class, also Q2-nested names), `__NClass` and `_$_NClass`
(constructor and destructor): they resolve through Class__method, Class__ctor, Class__dtor.

The canonical name of an address (`name_of`) is the script-engine method name when there is one
(what scripts call), else the RTTI name: a constructor/destructor over a vtable slot over the
type_info function, and when several classes claim the same function, the class that is an
ancestor of the others (else the first by name). Addresses without a name stay func_ADDR / D_ADDR.

    symbols.py NAME|ADDR...     what each resolves to, with every alias
    symbols.py stats            how many addresses have names
"""
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SYMBOL_ADDRS = os.path.join(ROOT, "config", "symbol_addrs.txt")
ADHOC = os.path.join(ROOT, "config", "adhoc_methods.txt")
STL = os.path.join(ROOT, "config", "stl_symbols.txt")  # tools/stl.py: mangled names of STL instantiations
CLASSES = os.path.join(ROOT, "config", "classes.json")

# func_ADDR / D_ADDR / jtbl_ADDR, with an optional C++ mangling suffix (func_00100230__Fv).
GENERIC = re.compile(r"^(func|D|jtbl|sub|data)_([0-9A-Fa-f]{8})(?:__.*)?$")
# A generic symbol token inside source text (never followed by more identifier characters).
TOKEN = re.compile(r"\b(func|D|jtbl)_([0-9A-Fa-f]{8})\b(?!\w)")
STRING = r'"(?:[^"\\\n]|\\.)*"'
CHAR = r"'(?:[^'\\\n]|\\.)*'"
RTTI_SUFFIX = re.compile(r"^(.+?)__(virtual_\d+|structor_\d+|tf|vtable\d*)$")
_RANK = {"structor": 0, "virtual": 1, "tf": 2, "vtable": 3}

_table = None


class Table:
    def __init__(self):
        self.names = {}       # name -> (address, kind)
        self.by_addr = {}     # address -> [names]
        self.canonical = {}   # address -> name
        self.kinds = {}       # address -> "func" | "data"


def _load():
    global _table
    if _table is not None:
        return _table
    t = Table()
    bases = {}
    if os.path.exists(CLASSES):
        for cname, c in json.load(open(CLASSES)).items():
            bases[cname] = list(c.get("bases", []))
    rtti = {}
    for path in (SYMBOL_ADDRS, STL):
        if not os.path.exists(path):
            continue
        for line in open(path):
            m = re.match(r"\s*([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]+)\s*;.*type:(func|data)", line)
            if m:
                addr, kind = int(m.group(2), 16), m.group(3)
                t.names[m.group(1)] = (addr, kind)
                t.kinds[addr] = kind
                if path == STL:  # mangled template names resolve, but never name an address (or a file)
                    continue
                t.by_addr.setdefault(addr, []).append(m.group(1))
                rtti.setdefault(addr, []).append(m.group(1))
    if os.path.exists(ADHOC):
        for line in open(ADHOC):
            p = line.split()
            if len(p) == 3 and not line.startswith("#"):
                addr, name = int(p[2], 16), f"{p[0]}__{p[1]}"
                # A global script function is listed under its registration function
                # (func_ADDR method): adhoc__method, the func_ADDR__method spelling kept as an alias
                # (it must not be read as the generic name func_ADDR).
                aliases = []
                if re.match(r"func_[0-9A-Fa-f]{8}$", p[0]):
                    aliases.append(name)
                    name = f"adhoc__{p[1]}"
                if name in t.names and t.names[name][0] != addr:
                    # the same class and method registered at a second address (MMusic play)
                    name = f"{name}_{addr:08X}"
                for n in [name] + aliases:
                    if n not in t.names:
                        t.names[n] = (addr, "func")
                        t.by_addr.setdefault(addr, []).append(n)
                        t.kinds[addr] = "func"
                t.canonical.setdefault(addr, name)   # the first script name listed wins

    def ancestors(cls):
        out, todo = set(), list(bases.get(cls, []))
        while todo:
            b = todo.pop()
            if b not in out:
                out.add(b)
                todo.extend(bases.get(b, []))
        return out

    def rank(name):
        m = RTTI_SUFFIX.match(name)
        cls, suffix = (m.group(1), m.group(2)) if m else (name, "")
        kind = re.sub(r"\d+", "", suffix).rstrip("_")
        return (_RANK.get(kind, 9), cls, name)

    for addr, names in rtti.items():
        if addr in t.canonical:
            continue
        # gcc's own RTTI runtime classes (__builtin_type_info...): every __tf of an unnamed
        # type stores their vtable, so their "structors" are mostly not theirs: aliases only.
        names = [n for n in names if not (rank(n)[0] == _RANK["structor"] and rank(n)[1].endswith("type_info"))]
        if not names:
            continue
        best = sorted(names, key=rank)
        top = [n for n in best if rank(n)[0] == rank(best[0])[0]]
        if len(top) > 1:
            classes = [rank(n)[1] for n in top]
            common = [c for c in classes if all(c == o or c in ancestors(o) for o in classes)]
            if common:
                top = [n for n in top if rank(n)[1] == common[0]]
        t.canonical[addr] = top[0]
    _table = t
    return t


def _demangled(sym):
    """Plain names a gcc 2.96 symbol may stand for, in the order to try them."""
    out = []
    m = re.match(r"^__(\d+)(\w+)$", sym)            # constructor: __10MCarGarage
    if m and len(m.group(2)) >= int(m.group(1)):
        out.append(m.group(2)[:int(m.group(1))] + "__ctor")
    m = re.match(r"^_[$.]_(\d+)(\w+)$", sym)         # destructor: _$_10MCarGarage
    if m and len(m.group(2)) >= int(m.group(1)):
        out.append(m.group(2)[:int(m.group(1))] + "__dtor")
    for m in re.finditer(r"__(?=[FH])", sym):        # plain function: name__Fv
        out.append(sym[:m.start()])
    for m in re.finditer(r"__(?=Q\d|\d)", sym):      # member: method__10MCarGarageiPv
        method, rest = sym[:m.start()], sym[m.end():]
        q = re.match(r"^Q(\d)", rest)
        parts = []
        pos = q.end() if q else 0
        for _ in range(int(q.group(1)) if q else 1):
            n = re.match(r"\d+", rest[pos:])
            if not n:
                parts = []
                break
            ln = int(n.group(0))
            pos += n.end()
            parts.append(rest[pos:pos + ln])
            pos += ln
        if parts and method:
            out.append("::".join(parts) + "__" + method)
            out.append(parts[-1] + "__" + method)
    return out


def address_of(sym):
    """The address a symbol stands for, or None when the project does not know it."""
    t = _load()
    if sym in t.names:  # a real name first: func_ADDR__method aliases look generic
        return t.names[sym][0]
    m = GENERIC.match(sym)
    if m:
        return int(m.group(2), 16)
    for cand in _demangled(sym):
        m = GENERIC.match(cand)
        if m:
            return int(m.group(2), 16)
        if cand in t.names:
            return t.names[cand][0]
    return None


def kind_of(sym):
    """'func' or 'data' for a symbol the table knows (generic names by their prefix), else None."""
    t = _load()
    if sym in t.names:
        return t.names[sym][1]
    m = GENERIC.match(sym)
    if m:
        return "func" if m.group(1) in ("func", "sub") else "data"
    for cand in _demangled(sym):
        if cand in t.names:
            return t.names[cand][1]
    return None


def name_of(addr):
    """The canonical real name of an address, or None."""
    return _load().canonical.get(addr)


def names_of(addr):
    """Every real name of an address (canonical first)."""
    t = _load()
    names = t.by_addr.get(addr, [])
    c = t.canonical.get(addr)
    return ([c] if c else []) + [n for n in names if n != c]


def symbol(addr, kind="func"):
    """What a source should call this address: its canonical name, else func_ADDR / D_ADDR."""
    return name_of(addr) or (f"func_{addr:08X}" if kind == "func" else f"D_{addr:08X}")


def source_token(sym):
    """The identifier a source writes for an object symbol: the symbol itself when it is a plain
    name the table knows, the generic base of func_ADDR__mangling, the table name a mangled
    member resolves to; None when the symbol is unknown."""
    m = GENERIC.match(sym)
    if m:
        return f"{m.group(1)}_{m.group(2)}"
    t = _load()
    if sym in t.names:
        return sym
    for cand in _demangled(sym):
        if GENERIC.match(cand) or cand in t.names:
            return cand
    return None


def generic(sym):
    """The func_/D_ form of a symbol (None when it cannot be resolved)."""
    addr = address_of(sym)
    if addr is None:
        return None
    return f"D_{addr:08X}" if kind_of(sym) == "data" else f"func_{addr:08X}"


def rename_text(text, lookup=None):
    """Source text with every func_/D_ token replaced by its canonical name, string and character
    literals untouched. lookup(addr, kind) -> name or None; default: name_of."""
    lookup = lookup or (lambda addr, kind: name_of(addr))
    pattern = re.compile(STRING + "|" + CHAR + "|" + TOKEN.pattern)

    def sub(m):
        if not m.group(1) or m.group(1) == "jtbl":
            return m.group(0)
        new = lookup(int(m.group(2), 16), "func" if m.group(1) == "func" else "data")
        return new or m.group(0)
    return pattern.sub(sub, text)


def generic_text(text):
    """Source text with every real name written back as func_ADDR / D_ADDR (the inverse of
    rename_text), for tools that reason about the generic names. String and character literals
    are left alone."""
    t = _load()
    pattern = re.compile(STRING + "|" + CHAR + "|" + r"\b[A-Za-z_]\w*\b")

    def sub(m):
        name = m.group(0)
        if name in t.names:
            addr, kind = t.names[name]
            return f"func_{addr:08X}" if kind == "func" else f"D_{addr:08X}"
        return name
    return pattern.sub(sub, text)


def main():
    args = sys.argv[1:]
    if not args:
        sys.exit(__doc__)
    if args == ["stats"]:
        t = _load()
        funcs = [a for a, k in t.kinds.items() if k == "func"]
        data = [a for a, k in t.kinds.items() if k == "data"]
        print(f"{len(t.names)} names for {len(t.by_addr)} addresses ({len(funcs)} functions, {len(data)} data); "
              f"{sum(1 for a in t.by_addr if len(t.by_addr[a]) > 1)} addresses with several names")
        return
    for a in args:
        addr = address_of(a)
        if addr is None and re.fullmatch(r"(0x)?[0-9A-Fa-f]{1,8}", a):
            addr = int(a, 16)
        if addr is None:
            print(f"{a}: unknown")
            continue
        aliases = [n for n in names_of(addr) if n != name_of(addr)]
        print(f"{a}: 0x{addr:08X} {kind_of(a) or ''} canonical {symbol(addr)} aliases {aliases}")


if __name__ == "__main__":
    main()
