#!/usr/bin/env python3
"""The register allocator's view of a function, read from the compiler's RTL dumps
(tools/rtl_dumps.py), side by side with the original's registers.

    alloc_table.py ADDR [FILE]        the source of ADDR (or FILE judged as ADDR): one line per
                                      pseudo register, in the allocator's order
    alloc_table.py ... --fresh        recompile even when build/rtl/ADDR is newer than the source
    alloc_table.py ... --sched        also the scheduler's clock tables (sched2, after reload)
    alloc_table.py ... --dbr          also reorg's delay-slot summary
    alloc_table.py ... --insns        also the pre-allocation insns, compactly rendered

Columns: the pseudo (rN), its role (its first definition, compact RTL), refs / live length /
sets / calls crossed (lreg dump: what the priority is computed from), the priority
floor(log2(refs)) * refs / length * 10000 * size (for local pseudos local-alloc's own length: twice
the span i<first>-<last> in the scheduled block, not lreg's live length), who allocated it (local = local-alloc.c,
block-local; global = global.c with its rank in `N regs to allocate`), the hard register it got,
and what the original has in that register's place where the two listings differ (the judge's
position-by-position alignment of instructions with the same opcode: "$s1->$s0 x5" means five
differing instructions use $s0 where mine uses $s1).

How to read it (knowledge/gcc296-codegen-map.md has the mechanisms and the source levers):
- global.c allocates in the printed order and takes the lowest free hard register (numeric
  order, pass 0 only among registers already in use: all call-used ones plus what local-alloc
  took); a call-crossing pseudo takes the first free callee-saved one ($s0, $s1, ...). So two
  s-registers swapped = the two pseudos' priority order swapped: change refs or live length.
- a pseudo in $v1 where the original has $v0: $v0 was in use (a live call result or return
  value, or local-alloc gave it to an earlier, higher-priority quantity of the same block).
- local-alloc works block by block, quantities with a copy-suggested hard register first
  (`sugg $a0`: the pseudo is copied from/to that register), then by the same priority.
"""
import argparse
import math
import os
import re
import sys
from collections import Counter, defaultdict

import project
import rtl_dumps

ROOT = project.ROOT

GPR = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]


def hard_name(n):
    n = int(n)
    if n < 32:
        return "$" + GPR[n]
    if n < 64:
        return f"$f{n - 32}"
    return {64: "$hi", 65: "$lo", 66: "$fpcc", 67: "$fp(virt)", 75: "$ap"}.get(n, f"$h{n}")


# ---------------------------------------------------------------- RTL reading

def sexprs(text):
    """Top-level s-expressions of a dump: [(first line number, text)]."""
    out = []
    depth = 0
    cur = []
    start = 0
    in_str = False
    for ln, line in enumerate(text.splitlines()):
        if depth == 0:
            if not line.startswith("("):
                continue
            start = ln
        cur.append(line)
        for ch in line:
            if in_str:
                if ch == '"':
                    in_str = False
                continue
            if ch == '"':
                in_str = True
            elif ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
        if depth <= 0:
            out.append((start, "\n".join(cur)))
            cur, depth = [], 0
    return out


def parse(text):
    """Parse one RTL s-expression into nested lists (atoms are strings)."""
    tokens = re.findall(r'\(|\)|\[|\]|"(?:[^"\\]|\\.)*"|[^\s()\[\]]+', text)
    pos = 0

    def node():
        nonlocal pos
        tok = tokens[pos]
        pos += 1
        if tok in ("(", "["):
            items = []
            close = ")" if tok == "(" else "]"
            while tokens[pos] != close:
                items.append(node())
            pos += 1
            return items
        return tok
    return node()


def _head(x):
    return x[0].split(":")[0].split("/")[0] if isinstance(x, list) and x and isinstance(x[0], str) else None


def reg_token(x):
    """("r85", 85, None) for a pseudo, ("$a0", 4, "a0") for a hard reg, else None."""
    if _head(x) != "reg":
        return None
    num = int(x[1])
    if num < 76:
        return hard_name(num), num, True
    return f"r{num}", num, False


BIN = {"plus": "+", "minus": "-", "mult": "*", "and": "&", "ior": "|", "xor": "^", "ashift": "<<",
       "ashiftrt": ">>", "lshiftrt": ">>>", "div": "/", "udiv": "/u", "mod": "%", "umod": "%u",
       "eq": "==", "ne": "!=", "lt": "<", "le": "<=", "gt": ">", "ge": ">=", "ltu": "<u", "leu": "<=u",
       "gtu": ">u", "geu": ">=u", "compare": "cmp", "smin": "min", "smax": "max", "rotate": "rol"}
UN = {"neg": "-", "not": "~", "sign_extend": "sext", "zero_extend": "zext", "truncate": "trunc",
      "float_extend": "fext", "float_truncate": "ftrunc", "float": "float", "fix": "fix", "sqrt": "sqrt",
      "abs": "abs", "unsigned_float": "ufloat", "unsigned_fix": "ufix"}


def render(x):
    """A compact rendering of an RTL expression: r85 = [r97+4], $a0 = call g, ..."""
    if isinstance(x, str):
        return x
    h = _head(x)
    if h == "reg":
        return reg_token(x)[0]
    if h == "const_int":
        v = int(x[1])
        return str(v) if -256 < v < 256 else hex(v)
    if h == "const_double":
        return "dbl" + ("".join(t for t in x if isinstance(t, str) and t.startswith("[")) or "")
    if h == "symbol_ref":
        # (symbol_ref:SI ("name") ...): the string sits in its own parentheses
        s = x[1] if len(x) > 1 else "sym"
        while isinstance(s, list):
            s = s[0] if s else "sym"
        return s.strip('"')
    if h == "label_ref":
        return f"L{x[1]}"
    if h == "pc":
        return "pc"
    if h == "cc0":
        return "cc0"
    if h == "mem":
        return f"[{render(x[1])}]"
    if h == "subreg":
        return f"{render(x[1])}[{x[2]}]" if len(x) > 2 else render(x[1])
    if h == "set":
        return f"{render(x[1])} = {render(x[2])}"
    if h == "call":
        return f"call {render(x[1])}"
    if h == "use":
        return f"use {render(x[1])}"
    if h == "clobber":
        return f"clobber {render(x[1])}"
    if h == "return":
        return "return"
    if h == "parallel":
        return "{" + "; ".join(render(e) for e in x[1]) + "}"
    if h == "if_then_else":
        return f"if {render(x[1])} goto {render(x[2])} else {render(x[3])}"
    if h == "lo_sum":
        return f"lo({render(x[1])},{render(x[2])})"
    if h == "high":
        return f"hi({render(x[1])})"
    if h == "asm_operands":
        return "asm"
    if h == "unspec" or h == "unspec_volatile":
        return f"unspec{x[2] if len(x) > 2 else ''}"
    if h in BIN and len(x) >= 3:
        return f"({render(x[1])} {BIN[h]} {render(x[2])})"
    if h in UN and len(x) >= 2:
        return f"{UN[h]}({render(x[1])})"
    if h:
        return h + "(" + ", ".join(render(e) for e in x[1:] if isinstance(e, list)) + ")"
    return "?"


INSN_KINDS = ("insn", "jump_insn", "call_insn")


def insns(text):
    """[(uid, kind, body list, raw)] of the real insns of a dump."""
    out = []
    for _, raw in sexprs(text):
        node = parse(raw)
        if not isinstance(node, list) or not node or node[0] not in INSN_KINDS:
            continue
        uid = int(node[1])
        body = node[4] if len(node) > 4 else None
        out.append((uid, node[0], body, raw))
    return out


def regs_in(body):
    """Every reg token of a body, in textual order: [(name, number, is_hard)]."""
    out = []

    def walk(x):
        if isinstance(x, list):
            if _head(x) == "reg":
                out.append(reg_token(x))
                return
            for e in x:
                walk(e)
    walk(body)
    return out


def insn_notes(raw):
    """The REG_* notes of an insn: {kind: [text]}."""
    out = defaultdict(list)
    for m in re.finditer(r"\(expr_list:(REG_\w+) \(([^()]*(?:\([^()]*\))?[^()]*)\)", raw):
        out[m.group(1)].append(m.group(2))
    return out


# ---------------------------------------------------------------- dump readers

STAT = re.compile(r"^Register (\d+) used (\d+) times across (\d+) insns(?: in block (\d+))?; set (\d+) times?;"
                  r"(?P<rest>.*)$", re.M)


def reg_stats(text):
    """{pseudo: {refs, length, block, sets, user, calls, class, pointer}} from a dump's
    'Register N used ...' lines."""
    out = {}
    for m in STAT.finditer(text):
        rest = m.group("rest")
        calls = re.search(r"crosses (\d+) call", rest)
        cls = re.search(r"; ([A-Z_0-9]+(?: or [A-Z_0-9]+)*)(?:;|\.)", rest)
        out[int(m.group(1))] = dict(
            refs=int(m.group(2)), length=int(m.group(3)),
            block=int(m.group(4)) if m.group(4) else None, sets=int(m.group(5)),
            user=" user var" in rest, calls=int(calls.group(1)) if calls else 0,
            cls=cls.group(1) if cls else "", pointer=" pointer" in rest)
    return out


def greg_summary(text):
    """order, conflicts, preferences, dispositions, hard regs used from the greg dump."""
    order = []
    m = re.search(r";; \d+ regs? to allocate:((?: \d+)+)", text)
    if m:
        order = [int(t) for t in m.group(1).split()]
    conflicts = {int(a): [int(t) for t in b.split()]
                 for a, b in re.findall(r";; (\d+) conflicts:((?: \d+)*)", text)}
    prefs = {int(a): [int(t) for t in b.split()]
             for a, b in re.findall(r";; (\d+) preferences:((?: \d+)*)", text)}
    disp = {}
    m = re.search(r";; Register dispositions:\n((?:.*\n)*?)\n", text)
    if m:
        for a, b in re.findall(r"(\d+) in (\d+)", m.group(1)):
            disp[int(a)] = int(b)
    used = []
    m = re.search(r";; Hard regs used:((?: +\d+)*)", text)
    if m:
        used = [int(t) for t in m.group(1).split()]
    return order, conflicts, prefs, disp, used


def priority(refs, length, size=1):
    if refs <= 0 or length <= 0:
        return 0
    return int(math.floor(math.log2(refs)) * refs / length * 10000 * size)


# ---------------------------------------------------------------- original side

def align_with_original(addr, obj):
    """Compare the object with the original at addr the way the judge does. Returns
    (n_differ, width, {mine reg: Counter(orig reg)}, lines) where the map comes from differing
    instructions with the same opcode."""
    import match
    text_addr, text = match.load_text()
    target = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
    blob, srelocs, funcs = match.read_object(obj, want_symbols=True)
    if not funcs:
        return None
    fname, foff, fsize = funcs[0]
    fsize = max(fsize, len(blob) - foff)
    import struct
    mine = match.trim_padding(list(struct.unpack_from(f"<{fsize // 4}I", blob, foff)))
    if len(target) > len(mine) and all(w == match.NOP for w in target[len(mine):]):
        target = target[:len(mine)]
    if len(target) > len(mine) >= 2 and (mine[-2] == 0x03E00008 or mine[-2] >> 26 == 2):
        target = target[:len(mine)]
    linked, unresolved = match.link_words(mine, srelocs, foff, addr)
    width = max(len(target), len(mine))
    subst = defaultdict(Counter)
    lines = []
    bad = 0
    for i in range(width):
        t = target[i] if i < len(target) else None
        m = linked[i] if i < len(linked) else None
        rel = srelocs.get(foff + i * 4)
        if t is None or m is None:
            ok = False
        elif rel and (foff + i * 4) in unresolved:
            ok = match.same_ignoring_reloc(t, m, rel[0])
        else:
            ok = t == m
        bad += not ok
        left = match.disasm(t, addr + i * 4) if t is not None else "-"
        right = match.disasm(m, addr + i * 4) if m is not None else "-"
        lines.append(("  " if ok else "! ") + f"{left:<40} | {right}")
        if not ok and t is not None and m is not None:
            lo, ro = left.split()[0], right.split()[0]
            lr, rr = re.findall(r"\$\w+", left), re.findall(r"\$\w+", right)
            if lo == ro and len(lr) == len(rr):
                for a, b in zip(rr, lr):
                    if a != b:
                        subst[a][b] += 1
    return bad, width, subst, lines


# ---------------------------------------------------------------- the table

def pre_alloc_dump(outdir):
    """The last dump before local allocation (the insns still name pseudos)."""
    files = rtl_dumps.dump_files(outdir)
    names = [p for p, _ in files]
    if "lreg" not in names:
        return None
    before = files[:names.index("lreg")]
    for want in ("sched", "regmove", "ce", "combine", "life", "cse2", "loop", "gcse", "jump"):
        for p, path in reversed(before):
            if p == want:
                return path
    return before[-1][1] if before else None


def build(addr, src=None, fresh=False):
    """Everything the table needs, as a dict (see print_table)."""
    src = src or project.source_for(addr)
    if src is None:
        raise SystemExit(f"no source for 0x{addr:08x}")
    outdir = os.path.join(rtl_dumps.RTL, f"{addr:08X}")
    # the dumps are reused only for the same source file, unchanged since
    stamp = f"{os.path.abspath(src)} {os.path.getmtime(src)}"
    stamp_path = os.path.join(outdir, "source.txt")
    old = open(stamp_path, encoding="utf-8").read() if os.path.exists(stamp_path) else None
    if fresh or old != stamp or not os.path.exists(os.path.join(outdir, "out.o")):
        rtl_dumps.dump(src, outdir)
        with open(stamp_path, "w", encoding="utf-8") as f:
            f.write(stamp)
    lreg = open(rtl_dumps.dump_for(outdir, "lreg"), encoding="utf-8", errors="replace").read()
    greg_path = rtl_dumps.dump_for(outdir, "greg")
    greg = open(greg_path, encoding="utf-8", errors="replace").read() if greg_path else ""
    pre_path = pre_alloc_dump(outdir)
    pre = open(pre_path, encoding="utf-8", errors="replace").read() if pre_path else ""
    life_path = rtl_dumps.dump_for(outdir, "life")
    life = open(life_path, encoding="utf-8", errors="replace").read() if life_path else ""

    stats = reg_stats(life)
    stats.update(reg_stats(lreg))  # the numbers global.c used
    order, conflicts, prefs, disp, used = greg_summary(greg)
    pre_insns = insns(pre)
    post_insns = {uid: body for uid, _, body, _ in insns(lreg)}

    pseudos = {}
    seq = 0
    for uid, kind, body, raw in pre_insns:
        seq += 1
        for name, num, hard in regs_in(body):
            if hard:
                continue
            p = pseudos.setdefault(num, dict(num=num, first=seq, last=seq, first_uid=uid, role=None,
                                             local=None, sugg=set(), uids=[]))
            p["last"] = seq
            p["uids"].append(uid)
        # the role: the first insn that sets it; copies to/from hard regs are local-alloc's suggestions
        if isinstance(body, list):
            sets = [body] if _head(body) == "set" else [e for e in (body[1] if _head(body) == "parallel" else []) if _head(e) == "set"]
            for s in sets:
                d = reg_token(s[1]) if isinstance(s[1], list) else None
                if d and not d[2] and pseudos[d[1]]["role"] is None:
                    pseudos[d[1]]["role"] = render(s[2])
                    if kind == "call_insn":
                        pseudos[d[1]]["role"] = "result of " + render(s[2])
                srcr = reg_token(s[2]) if isinstance(s[2], list) else None
                if d and srcr and d[2] != srcr[2]:
                    (pseudos[srcr[1]] if not srcr[2] else pseudos[d[1]])["sugg"].add(hard_name(d[1] if d[2] else srcr[1]))
    for num, st in stats.items():
        pseudos.setdefault(num, dict(num=num, first=0, last=0, first_uid=None, role=None, local=None, sugg=set(), uids=[]))
    for num, p in pseudos.items():
        st = stats.get(num, {})
        p["stats"] = st
        # the dispositions list reg_renumber of every pseudo: global.c's and local-alloc's
        p["rank"] = order.index(num) + 1 if num in order else None
        p["global"] = disp.get(num) if p["rank"] else None
        p["local"] = disp.get(num) if not p["rank"] else None
        p["hard"] = disp.get(num)
        refs, length = st.get("refs", 0), st.get("length", 0)
        if p["rank"] is None and p["local"] is not None and p["first"]:
            # local-alloc.c QTY_CMP_PRI: the quantity's span in half-insn units of the scheduled
            # block (birth 2*set, death 2*last use), not lreg's REG_LIVE_LENGTH (which
            # update_equiv_regs doubles for REG_EQUIV pseudos and which counts other blocks)
            length = max(1, 2 * (p["last"] - p["first"]))
        elif p["rank"] is None and p["local"] is not None and length <= 0:
            length = max(1, p["last"] - p["first"] + 1)
        p["pri"] = priority(refs, length)
        p["conflicts"] = conflicts.get(num, [])
        p["prefs"] = prefs.get(num, [])

    orig = align_with_original(addr, os.path.join(outdir, "out.o")) if os.path.exists(os.path.join(outdir, "out.o")) else None
    return dict(addr=addr, src=src, outdir=outdir, pseudos=pseudos, order=order, used=used,
                orig=orig, pre_path=pre_path, pre_insns=pre_insns)


def print_table(t, insn_listing=False):
    ps = t["pseudos"]
    print(f"0x{t['addr']:08x}  {os.path.relpath(t['src'], ROOT)}  dumps: {os.path.relpath(t['outdir'], ROOT)}")
    if t["orig"]:
        bad, width, subst, _ = t["orig"]
        print(f"judge: {bad} of {width} instructions differ" if bad else f"judge: MATCH ({width} instructions)")
    subst = t["orig"][2] if t["orig"] else {}
    glob = [n for n in t["order"] if n in ps]
    local = sorted(n for n, p in ps.items() if p["rank"] is None and p["local"] is not None)
    rest = sorted(n for n, p in ps.items() if p["rank"] is None and p["local"] is None)
    print(f"{len(glob)} global pseudos (allocation order), {len(local)} local, {len(rest)} not allocated/vanished")
    hdr = f"{'pseudo':<6} {'who':<9} {'got':<5} {'orig':<14} {'refs':>4} {'len':>4} {'sets':>4} {'calls':>5} {'pri':>6}  role"
    print(hdr)
    print("-" * len(hdr))

    def row(n, who):
        p = ps[n]
        st = p["stats"]
        hard = hard_name(p["hard"]) if p["hard"] is not None else "-"
        o = ""
        if p["hard"] is not None and hard in subst:
            o = " ".join(f"{k}x{v}" for k, v in subst[hard].most_common(2))
        role = p["role"] or "?"
        if st.get("user"):
            role += "  (user var)"
        if p["sugg"]:
            role += "  sugg " + ",".join(sorted(p["sugg"]))
        if p["prefs"]:
            role += "  pref " + ",".join(hard_name(x) if x < 76 else f"r{x}" for x in p["prefs"])
        span = f"i{p['first']}-{p['last']}" if p["first"] else ""
        print(f"r{n:<5} {who:<9} {hard:<5} {o:<14} {st.get('refs', 0):>4} {st.get('length', 0):>4} {st.get('sets', 0):>4} "
              f"{st.get('calls', 0):>5} {p['pri']:>6}  {role}  {span}")
    for k, n in enumerate(glob):
        row(n, f"global#{k + 1}")
    for n in local:
        row(n, "local")
    for n in rest:
        row(n, "-")
    if subst:
        print("register substitutions mine->orig at differing instructions (same opcode):")
        for a, c in sorted(subst.items()):
            print(f"  {a}: " + ", ".join(f"{b} x{k}" for b, k in c.most_common()))
    if t["used"]:
        print("hard regs used: " + " ".join(hard_name(x) for x in t["used"]))
    if insn_listing:
        print(f"\npre-allocation insns ({os.path.basename(t['pre_path'])}):")
        for uid, kind, body, raw in t["pre_insns"]:
            notes = insn_notes(raw)
            tag = " ".join(f"{k[4:].lower()} {v}" for k, vs in notes.items() for v in vs
                           if k in ("REG_DEAD", "REG_UNUSED", "REG_EQUAL", "REG_EQUIV"))
            print(f"  {uid:>4} {render(body) if body else kind:<60} {tag}")


def print_sched(outdir, which="sched2"):
    path = rtl_dumps.dump_for(outdir, which)
    if not path:
        print(f"no {which} dump")
        return
    for line in open(path, encoding="utf-8", errors="replace"):
        if line.startswith(";;"):
            print(line.rstrip())


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("addr")
    ap.add_argument("file", nargs="?")
    ap.add_argument("--fresh", action="store_true")
    ap.add_argument("--sched", action="store_true", help="print the sched2 clock tables")
    ap.add_argument("--sched1", action="store_true", help="print the sched (before reload) clock tables")
    ap.add_argument("--dbr", action="store_true", help="print reorg's summary")
    ap.add_argument("--insns", action="store_true", help="print the pre-allocation insns")
    ap.add_argument("--diff", action="store_true", help="print the judge's side-by-side listing")
    a = ap.parse_args()
    addr = int(a.addr, 16)
    t = build(addr, a.file, a.fresh)
    print_table(t, a.insns)
    if a.diff and t["orig"]:
        print()
        print("\n".join(t["orig"][3]))
    if a.sched1:
        print_sched(t["outdir"], "sched")
    if a.sched:
        print_sched(t["outdir"], "sched2")
    if a.dbr:
        print_sched(t["outdir"], "dbr")


if __name__ == "__main__":
    main()
