#!/usr/bin/env python3
"""Recover C++ classes from gcc 2.96 RTTI: names, base classes, vtables and their methods.

gcc 2.96 builds each class's type_info at run time in a function __tf<Name> that passes the
mangled class name ("7mGarage") and the base class's type_info to __rtti_si / __rtti_user. Each
vtable holds [0, __tf<Name>, virtual functions...]. So:

    class name string  ->  __tf function (references the string)
                       ->  own type_info object (first global it uses) and base type_info
    __tf function      ->  vtables (data words pointing at it) -> virtual methods
    vtable             ->  constructors/destructors (functions that store its address)

Writes build/classes.json and config/symbol_addrs.txt (splat's format; names only, no game data).
Needs splat's output (tools/splat.sh).

    rtti.py
"""
import json
import os
import re
import struct

import build
import match

ROOT = match.ROOT
DATA_ADDR = 0x617A80
HI_LO = re.compile(r"%(?:hi|lo)\((D_[0-9A-F]+)\)")
JAL = re.compile(r"\bjal\s+(func_[0-9A-F]{8})")


def main():
    data = open(os.path.join(build.OUT, "data.bin"), "rb").read()
    funcs = build.splat_functions()
    text_lo, text_hi = 0x100000, 0x100000 + 0x517A14

    names = {}
    for m in re.finditer(rb"(?<=\x00)(\d{1,3})([A-Za-z_][A-Za-z0-9_]{2,})\x00", data):
        if int(m.group(1)) == len(m.group(2)):
            names[DATA_ADDR + m.start(1)] = m.group(2).decode()

    # Per function: globals referenced (in order) and calls.
    refs, calls = {}, {}
    for addr, (_, body) in funcs.items():
        r, c = [], []
        for line in body:
            r += [int(s[2:], 16) for s in HI_LO.findall(line)]
            c += [int(s[5:], 16) for s in JAL.findall(line)]
        refs[addr] = list(dict.fromkeys(r))
        calls[addr] = c

    # __tf functions.
    classes = {}
    ti_of = {}
    for addr, r in refs.items():
        named = [a for a in r if a in names]
        if len(named) != 1 or len(r) > 8:
            continue
        name = names[named[0]]
        own = r[0] if r[0] != named[0] else None
        rest = [a for a in r if a not in (own, named[0])]
        classes.setdefault(name, {"tf": addr, "type_info": own, "base_type_info": rest[:2],
                                  "vtables": [], "methods": [], "structors": []})
        if own is not None:
            ti_of[own] = name
    for c in classes.values():
        c["bases"] = [ti_of[t] for t in c.pop("base_type_info") if t in ti_of]

    # Vtables (gcc 2 without thunks): 8-byte entries {short delta, short index, pfn}; the first
    # entry points at __tf, the others at the virtual functions.
    words = struct.unpack(f"<{len(data) // 4}I", data[:len(data) // 4 * 4])
    by_tf = {c["tf"]: n for n, c in classes.items()}
    owner = {}
    for i, w in enumerate(words):
        if w in by_tf and i > 0 and words[i - 1] == 0:
            name = by_tf[w]
            start = DATA_ADDR + 4 * (i - 1)
            methods = []
            j = i + 1
            while j + 1 < len(words) and words[j + 1] in funcs and words[j + 1] not in by_tf:
                methods.append(words[j + 1])
                j += 2
            classes[name]["vtables"].append({"address": start, "methods": methods})
            for slot, f in enumerate(methods):
                # A method inherited unchanged sits in several vtables; the shortest vtable is the
                # most basic class, which is where it was defined.
                prev = owner.get(f)
                if prev is None or len(methods) < prev[2]:
                    owner[f] = (name, slot, len(methods))
    for f, (name, slot, _) in owner.items():
        classes[name]["methods"].append({"address": f, "slot": slot})

    # Constructors / destructors: functions that take a vtable's address.
    vt_owner = {v["address"]: n for n, c in classes.items() for v in c["vtables"]}
    for addr, r in refs.items():
        for a in r:
            if a in vt_owner:
                classes[vt_owner[a]]["structors"].append(addr)

    json.dump(classes, open(os.path.join(ROOT, "build", "classes.json"), "w"), indent=1)

    lines = []
    for name, c in sorted(classes.items()):
        lines.append(f"{name}__tf = 0x{c['tf']:08X}; // type:func")
        for k, v in enumerate(c["vtables"]):
            lines.append(f"{name}__vtable{'' if k == 0 else k} = 0x{v['address']:08X}; // type:data")
        for m in sorted(c["methods"], key=lambda m: m["slot"]):
            lines.append(f"{name}__virtual_{m['slot']:02d} = 0x{m['address']:08X}; // type:func")
        for k, s in enumerate(sorted(set(c["structors"]))):
            lines.append(f"{name}__structor_{k} = 0x{s:08X}; // type:func")
    os.makedirs(os.path.join(ROOT, "config"), exist_ok=True)
    open(os.path.join(ROOT, "config", "symbol_addrs.txt"), "w", newline="\n").write("\n".join(lines) + "\n")

    named = sum(len(c["methods"]) + len(set(c["structors"])) + 1 for c in classes.values())
    print(f"{len(names)} class names, {len(classes)} classes with a type_info function, "
          f"{sum(len(c['vtables']) for c in classes.values())} vtables, "
          f"{sum(len(c['methods']) for c in classes.values())} virtual methods, "
          f"{sum(len(set(c['structors'])) for c in classes.values())} constructors/destructors; "
          f"{named} functions named")


if __name__ == "__main__":
    main()
