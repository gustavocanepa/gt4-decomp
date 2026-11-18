#!/usr/bin/env python3
"""Stack-slot signature of a draft against the original, call by call.

For a large C++ function most of the early differences are not instructions but *where* gcc put
each temporary: a by-value return, a copy, an argument bound to a const reference. Once one slot
differs, every register after it differs too, and the judge's diff is unreadable. This splits both
sides at their calls (jal) and lists, for each call, the stack offsets the code touches since the
previous call, including through registers that hold `$sp + X` (`addiu $s3, $sp, 0xA0` ...
`sw $v0, 0x0($s3)` counts as 0xA0). The first line that differs is where to look.

    slotsig.py ADDR FILE [--all] [--max OFF]   judge FILE (match.py check) and compare
    slotsig.py --diff FILE.diff [--all]        reuse a saved `match.py check` output

`--max` is where the spill area starts (default: the lowest offset the original stores an
incoming argument register to, which is the first pseudo spill); offsets at or above it are left
out, since spill slots follow register allocation, not the source. Calls are compared by position;
a different callee at the same position is shown as such.
"""
import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REG = r'\$(?:[atvsk][0-9]|fp|ra|at|gp|zero)'
ARG_REGS = ['$a0', '$a1', '$a2', '$a3', '$t0', '$t1', '$t2', '$t3', '$v0', '$v1', '$at']


def split_sides(text):
    """The judge's side-by-side lines -> (original lines, my lines)."""
    orig, mine = [], []
    for line in text.split("\n"):
        if not line.startswith(("! ", "  ")) or " | " not in line:
            continue
        left, right = line[2:].split(" | ", 1)
        orig.append(left.strip())
        mine.append(re.sub(r"\s+<[^>]*>$", "", right.strip()))
    return orig, mine


def spill_start(lines):
    """Lowest offset where an incoming argument register is stored (the first spill slot)."""
    offs = [int(m.group(1), 16) for l in lines
            for m in [re.match(r"sw\s+\$(?:a[0-3]|t[0-3]), (0x[0-9A-F]+)\(\$sp\)", l)] if m]
    return min(offs) if offs else 0x10000


def signature(lines, limit):
    """[(callee, sorted offsets)] for each call, the delay slot counted with its call."""
    out, cur, sp_regs = [], set(), {}

    def touch(line):
        for m in re.finditer(r"(-?0x[0-9A-F]+|0)\((" + REG + r"|\$sp)\)", line):
            off = int(m.group(1), 16)
            base = m.group(2)
            if base == "$sp":
                cur.add(off)
            elif base in sp_regs:
                cur.add(sp_regs[base] + off)
        mm = re.match(r"addiu\s+(" + REG + r"), \$sp, (0x[0-9A-F]+)", line)
        md = re.match(r"daddu\s+(" + REG + r"), (" + REG + r"), \$zero", line)
        if mm:
            sp_regs[mm.group(1)] = int(mm.group(2), 16)
            cur.add(int(mm.group(2), 16))
        elif md and md.group(2) in sp_regs:
            sp_regs[md.group(1)] = sp_regs[md.group(2)]
            cur.add(sp_regs[md.group(2)])
        else:
            dest = re.match(r"[a-z][\w.]*\s+(" + REG + r")", line)
            if dest and not line.startswith(("s", "b", "j")):
                sp_regs.pop(dest.group(1), None)

    i = 0
    while i < len(lines):
        m = re.match(r"jalr?\s+(\S+)", lines[i])
        if m:
            if i + 1 < len(lines):
                touch(lines[i + 1])
            name = re.sub(r"^func_0*", "", m.group(1)).upper()
            out.append((name, tuple(sorted(x for x in cur if 0x10 <= x < limit))))
            cur = set()
            for r in ARG_REGS:
                sp_regs.pop(r, None)
            i += 2
            continue
        touch(lines[i])
        i += 1
    out.append(("(end)", tuple(sorted(x for x in cur if 0x10 <= x < limit))))
    return out


def compare(text, show_all=False, limit=None):
    orig, mine = split_sides(text)
    if not orig:
        return None
    limit = limit or min(spill_start(orig), spill_start(mine))
    a, b = signature(orig, limit), signature(mine, limit)
    rows, first, ndiff = [], None, 0
    for k in range(max(len(a), len(b))):
        x = a[k] if k < len(a) else ("-", ())
        y = b[k] if k < len(b) else ("-", ())
        same = x == y
        if not same:
            ndiff += 1
            first = k if first is None else first
        if show_all or not same:
            fx = f"{x[0]} " + " ".join("%X" % o for o in x[1])
            fy = f"{y[0]} " + " ".join("%X" % o for o in y[1])
            rows.append(f"{k:4} {' ' if same else '!'} {fx:48} | {fy}")
    return {"rows": rows, "first": first, "differ": ndiff, "calls": (len(a), len(b)), "limit": limit}


def judge(addr, path):
    return subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", addr, path],
                          capture_output=True, text=True).stdout


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("addr", nargs="?")
    ap.add_argument("file", nargs="?")
    ap.add_argument("--diff", help="a saved `match.py check` output instead of judging")
    ap.add_argument("--all", action="store_true", help="also print the calls that agree")
    ap.add_argument("--max", type=lambda v: int(v, 16), help="first spill offset (hex)")
    a = ap.parse_args()
    if a.diff:
        text = open(a.diff).read()
    elif a.addr and a.file:
        text = judge(a.addr, a.file)
    else:
        ap.error("give ADDR FILE or --diff FILE")
    print(text.split("\n", 1)[0])
    res = compare(text, a.all, a.max)
    if res is None:
        print("no side-by-side output (MATCH, or a compile error)")
        return
    print("\n".join(res["rows"]))
    print(f"calls {res['calls'][0]} / {res['calls'][1]}, {res['differ']} differ, first at "
          f"{res['first']}; slots below 0x{res['limit']:X}")


if __name__ == "__main__":
    main()
