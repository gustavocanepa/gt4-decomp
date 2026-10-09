#!/usr/bin/env python3
"""Group functions whose code is identical once link-time values are masked out.

C++ produces many identical functions (template instances, inlined constructors, thunks).
Two functions in one group differ only in call targets and global addresses, so one matched
source, with those names swapped, matches every member.

    dedup.py scan                 write build/groups.json and print statistics
    dedup.py apply ADDR           copy src/func_ADDR.* to every other member of its group,
                                  renaming its callees/globals, and keep the copies that match
"""
import csv
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
from collections import defaultdict

import match
import symbols
import project

ROOT = match.ROOT
GROUPS = os.path.join(ROOT, "build", "groups.json")


def normalize(word, pc):
    op = word >> 26
    if op in (2, 3):              # j, jal: target filled by the linker
        return word & 0xFC000000
    if op == 0x0F:                # lui: %hi of an address
        return word & 0xFFFF0000
    return word


def masked_body(words):
    """Mask lui immediates, jumps, and the %lo halves that pair with a lui on the same register."""
    out = []
    hi_regs = set()
    for i, w in enumerate(words):
        op = w >> 26
        rt, rs = (w >> 16) & 31, (w >> 21) & 31
        if op == 0x0F:
            hi_regs.add(rt)
            out.append(w & 0xFFFF0000)
        elif op in (2, 3):
            out.append(w & 0xFC000000)
        elif rs in hi_regs and op in (0x09, 0x0D, 0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B, 0x31, 0x39, 0x37, 0x3F):
            out.append(w & 0xFFFF0000)  # addiu/ori/loads/stores using a %lo
        else:
            out.append(w)
    return out


def scan():
    text_addr, text = match.load_text()
    groups = defaultdict(list)
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            addr, span = int(row["address"], 16), int(row["max_size"])
            words = match.trim_padding(match.words_at(text_addr, text, addr, span))
            if len(words) < 3:
                continue
            key = hashlib.sha1(struct.pack(f"<{len(words)}I", *masked_body(words))).hexdigest()
            groups[key].append(addr)
    multi = {k: sorted(v) for k, v in groups.items() if len(v) > 1}
    with open(GROUPS, "w") as f:
        json.dump({"groups": [[f"{a:08x}" for a in v] for v in multi.values()]}, f)
    total = sum(len(v) for v in groups.values())
    dup = sum(len(v) - 1 for v in multi.values())
    print(f"{total} functions, {len(groups)} distinct bodies; {len(multi)} groups with copies; "
          f"{dup} functions are copies of another ({dup / total:.1%})")
    for v in sorted(multi.values(), key=len, reverse=True)[:8]:
        print(f"  {len(v)} copies, e.g. 0x{v[0]:08x}")


def callee_names(addr):
    """Ordered list of jal targets and %hi/%lo globals the original function references."""
    names = []
    for line in match.gnu_asm(addr).splitlines():
        m = re.search(r"\b(func_[0-9A-F]{8})\b", line)
        if m and "glabel" not in line:
            names.append(m.group(1))
    return names


def apply(addr):
    src = project.source_for(addr)
    if not src:
        sys.exit(f"no source for 0x{addr:08x} in src/")
    groups = json.load(open(GROUPS))["groups"]
    group = next((g for g in groups if f"{addr:08x}" in g), None)
    if not group:
        print("no copies of this function")
        return
    # Reasoned about with generic names (func_/D_ADDR); the copy gets its real names back at the end.
    source = symbols.generic_text(open(src, encoding="utf-8").read())
    ext = src.rsplit(".", 1)[1]
    mine = callee_names(addr)
    for other in group:
        o = int(other, 16)
        if o == addr or project.source_for(o):
            continue
        theirs = callee_names(o)
        text = source.replace(f"func_{addr:08X}", f"func_{o:08X}")
        for a, b in zip(mine, theirs):
            if a != b and a != f"func_{addr:08X}":
                text = re.sub(rf"\b{a}\b", b, text)
        path = os.path.join(ROOT, "build", "auto", f"dup_{o:08x}.{ext}")
        os.makedirs(os.path.dirname(path), exist_ok=True)
        open(path, "w", encoding="utf-8").write(text)
        check = lambda: subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check",
                                        f"{o:x}", path], capture_output=True, text=True)
        res = check()
        if res.returncode != 0 and "wrong address" in res.stdout:
            # Same code, other globals: point the copy at the addresses its original uses.
            renames = match.suggest_renames(o, path)
            if renames:
                open(path, "w", encoding="utf-8").write(match.apply_renames(text, renames))
                res = check()
        if res.returncode == 0:
            text = symbols.rename_text(open(path, encoding="utf-8").read())
            open(path, "w", encoding="utf-8", newline="\n").write(text)
            os.replace(path, os.path.join(ROOT, "src", f"func_{o:08X}.{ext}"))
            print(f"0x{o:08x}: MATCH (copy of 0x{addr:08x})")
        else:
            print(f"0x{o:08x}: copy does not match ({(res.stdout.splitlines() or ['?'])[0]})")


if __name__ == "__main__":
    if len(sys.argv) >= 2 and sys.argv[1] == "scan":
        scan()
    elif len(sys.argv) >= 3 and sys.argv[1] == "apply":
        apply(int(sys.argv[2], 16))
    else:
        sys.exit(__doc__)
