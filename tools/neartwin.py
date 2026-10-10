#!/usr/bin/env python3
"""Near twins across the sister games (GT4 and Tourist Trophy share one code base): an unmatched
function of this game whose code is *almost* the same as a matched function of the other game
gets that function's source adapted and judged. tools/crossgame.py covers the identical twins
(same masked words); this tool covers the rest: a struct that grew a field (every offset after
it moved), a global or a callee at another address, a constant that changed, a call added or
removed. Every match counts twice for the two projects, so these come first.

    neartwin.py scan --from ../GT4 [--min-sim 0.8]     the twin of every open function (similarity
                                                        of the masked words), -> build/neartwin/pairs.txt
    neartwin.py apply --from ../GT4 [--jobs 2] [--limit N] [--min-sim 0.8] [--list FILE] [--retry]
                                                        port, adapt, judge; src/ on MATCH
    neartwin.py try ADDR OTHER_ADDR --from ../GT4       one pair, every step shown
    neartwin.py residuals                               what still differs after the rules, counted

How a twin is adapted (build/neartwin/work/func_ADDR.*): the other game's source with generic
names (func_/D_ADDR), the calls renamed by position (aligned on the masked words when the call
counts differ), the globals moved by the judge's relocation deltas (match.suggest_renames), then
rules read from the judge's diff until nothing changes: literals and offsets shifted (a struct
field inserted: `0x54(a0)` -> `0x58(a0)`), 32-bit constants built by lui/ori, zero <-> constant,
offsets above 0x7FFF, a literal written several times (each occurrence tried, the closest kept).
A match is saved only when no source exists for the address (other agents add sources in
parallel), copied to its identical copies (dedup.py apply) and logged in the attempts diary.

pairs.txt has the format of the agents' work lists (build/near_twins.txt): `MINE OTHER BYTES SIM
OTHER_SOURCE`, so `--list` accepts those too.
"""
import argparse
import difflib
import json
import os
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

HERE = os.path.dirname(os.path.abspath(__file__))


# ----------------------------------------------------------------------------------------------
# the other project: read-only exports, run in a child process with its own tools on the path

def export(mode, in_path, out_path):
    import csv
    import match
    import project
    import symbols
    import families
    text_addr, text = match.load_text()
    done = project.sources()
    if mode == "index":
        out = {}
        with open(match.FUNCTIONS) as f:
            for row in csv.DictReader(f):
                addr = int(row["address"], 16)
                if addr not in done:
                    continue
                words = match.trim_padding(match.words_at(text_addr, text, addr, int(row["max_size"])))
                if len(words) >= 3:
                    out[f"{addr:08x}"] = [families.mask_word(w) for w in words]
        json.dump(out, open(out_path, "w"))
        return
    wanted = json.load(open(in_path))
    out = {}
    for a in wanted:
        addr = int(a, 16)
        path = done.get(addr)
        if not path:
            continue
        words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
        out[a] = {"addr": addr, "ext": path.rsplit(".", 1)[1], "path": os.path.relpath(path, match.ROOT).replace(os.sep, "/"),
                  "calls": call_sites(addr, words), "masked": [families.mask_word(w) for w in words],
                  "text": symbols.generic_text(open(path, encoding="utf-8").read())}
    json.dump(out, open(out_path, "w"))


def call_sites(addr, words):
    """[(index, target)] of the function's jal/j instructions that leave it, in code order."""
    end = addr + 4 * len(words)
    out = []
    for i, w in enumerate(words):
        if w >> 26 in (2, 3):
            t = ((w & 0x3FFFFFF) << 2) | ((addr + 4 * i) & 0xF0000000)
            if not addr <= t < end:
                out.append((i, t))
    return out


def run_export(other, mode, in_path, out_path):
    other = os.path.abspath(other)
    subprocess.run([sys.executable, os.path.abspath(__file__), "export", mode, in_path, out_path],
                   check=True, cwd=other, env=dict(os.environ, CROSSGAME_TOOLS=os.path.join(other, "tools")))


# ----------------------------------------------------------------------------------------------
# this project

def setup():
    sys.path.insert(0, HERE)
    import match
    global ROOT, OUT, WORK, PAIRS, RESULTS, TRIED
    ROOT = match.ROOT
    OUT = os.path.join(ROOT, "build", "neartwin")
    WORK = os.path.join(OUT, "work")
    PAIRS = os.path.join(OUT, "pairs.txt")
    RESULTS = os.path.join(OUT, "results.jsonl")
    TRIED = os.path.join(OUT, "tried.txt")
    os.makedirs(WORK, exist_ok=True)


def my_functions():
    """[(addr, words, masked)] of this game's unmatched functions of at least 3 words."""
    import csv
    import match
    import project
    import families
    text_addr, text = match.load_text()
    done = project.sources()
    out = []
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            addr = int(row["address"], 16)
            if addr in done:
                continue
            words = match.trim_padding(match.words_at(text_addr, text, addr, int(row["max_size"])))
            if len(words) >= 3:
                out.append((addr, words, [families.mask_word(w) for w in words]))
    return out


def similarity(a, b):
    return difflib.SequenceMatcher(None, a, b, autojunk=False).ratio()


def scan(other, min_sim):
    """Best matched twin of the other game for every open function, by masked-word similarity."""
    index_path = os.path.join(OUT, "other_index.json")
    run_export(other, "index", "", index_path)
    theirs = {a: m for a, m in json.load(open(index_path)).items()}
    keys = sorted(theirs)
    # exact masked skeletons (the tiny functions) and 3-gram shingles for the rest
    exact = {}
    postings = {}
    for k in keys:
        m = theirs[k]
        exact.setdefault(tuple(m), []).append(k)
        for i in range(len(m) - 2):
            postings.setdefault((m[i], m[i + 1], m[i + 2]), []).append(k)
    cap = 3000  # a shingle this common (prologues) says nothing
    mine = my_functions()
    pairs = []
    t0 = time.time()
    for n, (addr, words, masked) in enumerate(mine, 1):
        cands = {}
        for k in exact.get(tuple(masked), []):
            cands[k] = 1 << 20
        if len(masked) >= 6:
            for i in range(len(masked) - 2):
                lst = postings.get((masked[i], masked[i + 1], masked[i + 2]))
                if lst and len(lst) <= cap:
                    for k in lst:
                        cands[k] = cands.get(k, 0) + 1
        if not cands:
            continue
        best = None
        for k, _ in sorted(cands.items(), key=lambda kv: -kv[1])[:12]:
            m = theirs[k]
            if not 0.6 <= len(m) / len(masked) <= 1.6:
                continue
            s = similarity(masked, m)
            if s >= min_sim and (best is None or s > best[0] or (s == best[0] and len(m) == len(masked) and len(best[1]) != len(masked))):
                best = (s, m, k)
        if best:
            pairs.append((addr, int(best[2], 16), 4 * len(words), best[0]))
        if n % 2000 == 0:
            print(f"{n}/{len(mine)} scanned, {len(pairs)} twins ({time.time() - t0:.0f} s)", flush=True)
    pairs.sort(key=lambda p: (-p[3], p[2], p[0]))
    with open(PAIRS, "w") as f:
        f.write("# MINE OTHER BYTES SIMILARITY OTHER_SOURCE: open function of this game with a matched near twin in the other\n")
        for addr, o, size, s in pairs:
            f.write(f"{addr:08x} {o:08x} {size} {s:.2f} -\n")
    print(f"{len(pairs)} of {len(mine)} open functions have a twin with similarity >= {min_sim} in {other}: {PAIRS}")
    hist = {}
    for *_, s in pairs:
        hist[round(s, 1)] = hist.get(round(s, 1), 0) + 1
    print("by similarity:", " ".join(f"{k:.1f}:{v}" for k, v in sorted(hist.items(), reverse=True)))


def read_list(path):
    out = []
    for line in open(path):
        p = line.split()
        if not p or p[0].startswith("#"):
            continue
        out.append((int(p[0], 16), int(p[1], 16), int(p[2]) if len(p) > 2 else 0, float(p[3]) if len(p) > 3 else 1.0))
    return out


# ----------------------------------------------------------------------------------------------
# the diff and the rules

IMMEDIATE = re.compile(r"^(-?)(0x[0-9A-Fa-f]+|\d+)(\(\$\w+\))?$")


def diff_rows(verdict):
    """[(differs, left tokens, right tokens, relocation symbol or None)] per instruction line."""
    out = []
    for line in verdict.splitlines():
        if "|" not in line or line[:1] not in "! ":
            continue
        left, right = line[1:].split("|", 1)
        rel = re.search(r"<([^>]*)>", right)
        right = re.sub(r"<[^>]*>", "", right)
        tok = lambda s: s.replace(",", " ").split()
        out.append((line[0] == "!", tok(left), tok(right), rel.group(1) if rel else None))
    return out


def differ(verdict):
    m = re.search(r"(\d+) of (\d+) instructions differ", verdict)
    return (int(m.group(1)), int(m.group(2))) if m else (0 if "MATCH" in verdict.split("\n", 1)[0] else 1 << 30, 0)


def _int(s):
    try:
        return int(s, 0)
    except ValueError:
        return None


def literal_forms(v):
    return list(dict.fromkeys([f"0x{v:X}", f"0x{v:x}", f"0x{v:08X}", f"0x{v:08x}", str(v)]))


def occurrences(text, v):
    """[(form, [match spans])] of the literal v in the source, any spelling."""
    out = []
    for form in literal_forms(v):
        spans = [m.span() for m in re.finditer(rf"(?<![\w.]){re.escape(form)}(?![\w.])", text)]
        if spans:
            out.append((form, spans))
    return out


def replace_once(text, have, want):
    """The literal `have` changed to `want` when the source writes it exactly once."""
    occ = occurrences(text, have)
    if len(occ) == 1 and len(occ[0][1]) == 1:
        form, ((a, b),) = occ[0]
        new = f"0x{want:X}" if form.startswith("0x") else str(want)
        return text[:a] + new + text[b:]
    return text


def wanted_literals(rows):
    """{have: want} for every differing line that is the same instruction with another constant
    (offset, immediate, lui/ori pair, lui/addiu pair), signs kept."""
    out = {}
    hi = {}
    for bad, l, r, rel in rows:
        if rel or not l or not r:
            continue
        if len(l) >= 3 and len(r) >= 3 and l[0] == r[0] == "lui" and l[1] == r[1]:
            a, b = _int(l[2]), _int(r[2])
            if a is not None and b is not None:
                hi[l[1]] = (a, b)
                if a != b:
                    out[b << 16] = a << 16  # a lone lui constant (float bit pattern)
            continue
        if len(l) == 4 and len(r) == 4 and l[0] == r[0] and l[0] in ("ori", "addiu") and l[1:3] == r[1:3] and l[2] in hi:
            a, b = _int(l[3]), _int(r[3])
            ha, hb = hi.pop(l[2])
            if a is not None and b is not None:
                if l[0] == "ori":
                    want, have = (ha << 16) | a, (hb << 16) | b
                else:
                    want, have = ((ha << 16) + a) & 0xFFFFFFFF, ((hb << 16) + b) & 0xFFFFFFFF
                if want != have:
                    out[have] = want
                    out.pop(hb << 16, None)
            continue
        if not bad or len(l) != len(r) or l[:-1] != r[:-1]:
            continue
        lm, rm = IMMEDIATE.match(l[-1]), IMMEDIATE.match(r[-1])
        if not lm or not rm or lm.group(3) != rm.group(3):
            continue
        want = int(lm.group(1) + lm.group(2), 0)
        have = int(rm.group(1) + rm.group(2), 0)
        if want != have and (want < 0) == (have < 0):
            out[have] = want
    return out


def zero_literals(rows):
    """{have: want} for a constant that is 0 in one game (daddu r, zero, zero) and K in the other."""
    out = {}
    for bad, l, r, rel in rows:
        if not bad or rel or len(l) != 4 or len(r) != 4 or l[1] != r[1]:
            continue
        if l[0] == "addiu" and l[2] == "$zero" and r[0] == "daddu" and r[2:] == ["$zero", "$zero"]:
            k = _int(l[3])
            if k:
                out[0] = k
        elif r[0] == "addiu" and r[2] == "$zero" and l[0] == "daddu" and l[2:] == ["$zero", "$zero"]:
            k = _int(r[3])
            if k:
                out[k] = 0
    return out


def big_offsets(rows):
    """{have: want}: `lui r, H; addu r, r, x; op off(r)`: a struct offset above 0x7FFF that moved."""
    out, hi = {}, {}
    mem = re.compile(r"^(-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)$")
    for bad, l, r, rel in rows:
        if rel or len(l) != 3 or len(r) != 3:
            continue
        if l[0] == r[0] == "lui" and l[1] == r[1]:
            a, b = _int(l[2]), _int(r[2])
            if a is not None and b is not None:
                hi[l[1]] = (a, b)
            continue
        if l[0] == r[0] and l[1] == r[1]:
            ml, mr = mem.match(l[2]), mem.match(r[2])
            if ml and mr and ml.group(2) == mr.group(2) and ml.group(2) in hi:
                ha, hb = hi[ml.group(2)]
                want, have = (ha << 16) + _int(ml.group(1)), (hb << 16) + _int(mr.group(1))
                if want != have and want > 0 and have > 0:
                    out[have] = want
    return out


def moved_symbols(rows):
    """{D_x: D_y} for a global whose lui/lo pair the original builds at another address and
    which match.suggest_renames could not move (a class named after its vtable)."""
    hi, moved = {}, {}
    for bad, l, r, rel in rows:
        if not rel or not re.match(r"D_[0-9A-F]{8}$", rel) or len(l) < 2:
            continue
        if l[0] == "lui":
            hi[rel] = _int(l[-1])
        elif rel in hi and hi[rel] is not None:
            lo = IMMEDIATE.match(l[-1])
            if lo:
                v = int(lo.group(1) + lo.group(2), 0)
                moved[rel] = f"D_{((hi[rel] << 16) + v) & 0xFFFFFFFF:08X}"
    return {k: v for k, v in moved.items() if k != v}


def align_calls(other_calls, other_masked, my_calls, my_masked):
    """{other target: my target} by position; when the call counts differ, by the alignment of the
    masked words (a call inside a matching block maps to the call at the same place)."""
    if len(other_calls) == len(my_calls):
        return {a: b for (_, a), (_, b) in zip(other_calls, my_calls) if a != b}
    mine_at = dict(my_calls)
    out = {}
    for a, b, n in difflib.SequenceMatcher(None, other_masked, my_masked, autojunk=False).get_matching_blocks():
        for i, t in other_calls:
            if a <= i < a + n and (i - a + b) in mine_at and mine_at[i - a + b] != t:
                out[t] = mine_at[i - a + b]
    return out


STORES = {"sw", "sh", "sb", "sd", "sq", "swc1", "sdc1"}


def wanted_calls(rows):
    """{my symbol: original target} for `jal X | jal Y <sym>` lines (the calls were aligned by
    position and the order differs, or a call has a near twin at another address); a symbol the
    original wants at two different targets is left alone (see calls_by_site)."""
    out, conflict = {}, set()
    for bad, l, r, rel in rows:
        if rel and len(l) == 2 and len(r) == 2 and l[0] == r[0] == "jal" and re.match(r"func_[0-9A-F]{8}$", rel):
            m = re.match(r"func_([0-9A-Fa-f]+)$", l[1])
            if m:
                target = f"func_{int(m.group(1), 16):08X}"
                if out.get(rel, target) != target:
                    conflict.add(rel)
                out[rel] = target
    return {k: v for k, v in out.items() if k != v and k not in conflict}


CALL_SITE = re.compile(r"\b(func_[0-9A-F]{8})\(")


def calls_by_site(text, rows):
    """The source with the k-th call statement renamed to the original's k-th jal target, when the
    source's calls (in text order, declarations aside) are mine's jal sequence: one callee of the
    other game stands for two of this one (two handle constructors in one function), which no
    rename by symbol can express. The new callee takes the old one's declaration."""
    asm_mine, asm_orig = [], []
    for bad, l, r, rel in rows:
        if r[:1] == ["jal"] and rel and re.match(r"func_[0-9A-F]{8}$", rel) and l[:1] == ["jal"]:
            m = re.match(r"func_([0-9A-Fa-f]+)$", l[1])
            if not m:
                return None
            asm_mine.append(rel)
            asm_orig.append(f"func_{int(m.group(1), 16):08X}")
    head, brace, body = text.partition("{")
    sites = [m for m in CALL_SITE.finditer(body)]
    if [m.group(1) for m in sites] != asm_mine or asm_mine == asm_orig:
        return None
    out, last = [], 0
    for m, target in zip(sites, asm_orig):
        out.append(body[last:m.start(1)] + target)
        last = m.end(1)
    body = "".join(out) + body[last:]
    decls = ""
    for old, new in dict.fromkeys(zip(asm_mine, asm_orig)):
        if old != new and not re.search(r"\b" + new + r"\b", head):
            d = re.search(r"^.*\b" + old + r"\(.*;\s*$", head, re.M)
            if d:
                decls += d.group(0).replace(old, new) + "\n"
    cut = head.rfind("\n", 0, len(head.rstrip())) + 1  # before the signature's line
    return head[:cut] + decls + head[cut:] + brace + body


def known_renames(renames):
    """suggest_renames' proposals restricted to real addresses: a function start for func_, the
    image for D_ (a twin whose code differs at a call gives a nonsense delta otherwise)."""
    import match
    import project
    _, sections = project.load_image()
    out = {}
    for k, v in renames.items():
        addr = int(v[v.index("_") + 1:], 16)
        if v.startswith("func_"):
            try:
                match.function_span(addr)
            except SystemExit:
                continue
        elif not any(a <= addr < a + len(b) for a, b in sections):
            continue
        out[k] = v
    return out


def store_order(text, rows):
    """The source with its store statements reordered so the compiled order is the original's,
    when the diff only permutes stores (the same lines on both sides) and every store of the diff
    names exactly one statement: the output position of a statement depends on its source
    position, so the statements are permuted by the inverse (build/scratch/opus3/perm_fix.py)."""
    import near_fix
    bad = [(l, r) for b, l, r, rel in rows if b]
    if not bad or not all(l and r and l[0] in STORES and r[0] in STORES for l, r in bad):
        return None
    if sorted(map(tuple, (l for l, _ in bad))) != sorted(map(tuple, (r for _, r in bad))):
        return None
    lines = text.split("\n")
    idx = [i for i, l in enumerate(lines) if near_fix.STORE_LINE.match(l)]

    def statement(tok):
        m = re.match(r"(-?0x[0-9A-Fa-f]+|-?\d+)\(", tok[-1])
        if not m:
            return None
        off = int(m.group(1), 0)
        hits = [i for i in idx if near_fix._names_offset(lines[i], off)]
        return hits[0] if len(hits) == 1 else None
    orig = [statement(l) for l, _ in bad]
    mine = [statement(r) for _, r in bad]
    if None in orig or None in mine or len(set(orig)) != len(orig) or set(orig) != set(mine):
        return None
    # the statement at source position j lands at output position mine.index(stmt): give that
    # source position the statement the original emits there
    src_pos = sorted(set(mine))
    out = list(lines)
    for stmt in src_pos:
        out[stmt] = lines[orig[mine.index(stmt)]]
    return "\n".join(out) if out != lines else None


BLOCK = re.compile(r"^(struct|class|union)\b[^;{]*\{", re.M)


def flat_head(text):
    """(text with every struct/class body before the function replaced by a placeholder, restore)
    so tools/near_fix.py's rules, which split a draft at its first brace, see the declarations and
    the function only."""
    blocks = []
    out, last = [], 0
    for m in BLOCK.finditer(text):
        if m.start() < last:
            continue
        depth, i = 0, m.end() - 1
        while i < len(text):
            depth += (text[i] == "{") - (text[i] == "}")
            i += 1
            if depth == 0:
                break
        end = text.find(";", i)
        end = end + 1 if end >= 0 else i
        if re.search(r"\bfunc_[0-9A-F]{8}\s*\([^)]*\)\s*$", text[last:m.start()]):
            break  # the function itself
        out.append(text[last:m.start()] + f"/*@BLOCK{len(blocks)}@*/")
        blocks.append(text[m.start():end])
        last = end
    out.append(text[last:])
    flat = "".join(out)

    def restore(t):
        for i, b in enumerate(blocks):
            t = t.replace(f"/*@BLOCK{i}@*/", b)
        return t
    return flat, restore


class Port:
    """One twin adapted step by step; `steps` tells what each judge call tried and gave."""

    def __init__(self, addr, other, verbose=False):
        import match
        self.addr, self.other, self.verbose = addr, other, verbose
        self.path = os.path.join(WORK, f"func_{addr:08X}.{other['ext']}")
        self.steps = []
        text_addr, text = match.load_text()
        self.words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
        self.best = (1 << 30, None, "")
        self.budget = 60

    def judge(self, text, what):
        open(self.path, "w", encoding="utf-8", newline="\n").write(text)
        res = subprocess.run([sys.executable, os.path.join(HERE, "match.py"), "check", f"{self.addr:x}", self.path],
                             capture_output=True, text=True, cwd=ROOT)
        n, of = differ(res.stdout)
        ok = res.returncode == 0 and "MATCH" in res.stdout.split("\n", 1)[0]
        if ok:
            n = 0
        self.steps.append((what, n, of))
        self.budget -= 1
        if self.verbose:
            print(f"  {what}: {'MATCH' if ok else f'{n} of {of} differ'}", flush=True)
        if n < self.best[0]:
            self.best = (n, text, res.stdout)
        return ok, n, res.stdout

    def step(self, text, candidate, what, state):
        """Judge a candidate; keep it when it is not worse than the current text. state = (n, verdict)."""
        ok, n, verdict = self.judge(candidate, what)
        if ok or n <= state[0]:
            return ok, candidate, (n, verdict)
        return False, text, state

    def run(self):
        import families
        import match
        other = self.other
        text = other["text"].replace(f"func_{other['addr']:08X}", f"func_{self.addr:08X}")
        text = text.replace(f"0x{other['addr']:08x}", f"0x{self.addr:08x}")
        my_masked = [families.mask_word(w) for w in self.words]
        renames = align_calls([tuple(c) for c in other["calls"]], other["masked"], call_sites(self.addr, self.words), my_masked)
        text = match.apply_renames(text, {f"func_{a:08X}": f"func_{b:08X}" for a, b in renames.items()})
        ok, n, verdict = self.judge(text, "ported")
        state = (n, verdict)
        for _ in range(3):  # globals: each round moves the symbols whose delta the judge can see
            if ok:
                break
            try:
                moved = known_renames(match.suggest_renames(self.addr, self.path))
            except SystemExit:
                moved = {}
            if not moved:
                break
            candidate = match.apply_renames(text, moved)
            ok, text, state = self.step(text, candidate, "globals moved " + ",".join(f"{k}>{v}" for k, v in moved.items()), state)
            if text is not candidate:
                break
        for _ in range(8):  # literals, offsets, calls, store order: until nothing changes
            if ok or self.budget <= 0:
                break
            before = state[0]
            rows = diff_rows(state[1])
            fixed = text
            moved = {**moved_symbols(rows), **wanted_calls(rows)}
            if moved:
                fixed = match.apply_renames(fixed, moved)
            for have, want in {**big_offsets(rows), **wanted_literals(rows), **zero_literals(rows)}.items():
                fixed = replace_once(fixed, have, want)
            if fixed != text:
                ok, text, state = self.step(text, fixed, "literals moved", state)
                if ok or state[0] < before:
                    continue
                rows = diff_rows(state[1])
            reordered = store_order(text, rows)
            if reordered:
                ok, text, state = self.step(text, reordered, "stores reordered", state)
                if ok or state[0] < before:
                    continue
                rows = diff_rows(state[1])
            by_site = calls_by_site(text, rows)
            if by_site:
                ok, text, state = self.step(text, by_site, "calls by site", state)
                if ok or state[0] < before:
                    continue
            ok, text, state = self.ambiguous_literals(text, state)
            if ok or state[0] >= before:
                break
        if not ok and self.budget > 0:
            ok, text, state = self.near_fix_rules(text, state)
        if not ok and self.budget > 0:
            ok, text, state = self.profiles(text, state)
        return ok, text

    def profiles(self, text, state):
        """The closest text under another compiler profile the diff points at (near_fix.profiles_for:
        no sibling calls for a `jal` + epilogue tail, no strict aliasing for reordered loads and
        stores, ee-gcc 2.9 in the SDK range): the TT wrappers of GT4's func_001010E0 family keep
        `jal` where GT4 has `j`."""
        import near_fix
        import project
        bad = [(l, r) for b, l, r, _ in diff_rows(state[1]) if b]
        body = re.sub(r"^/\* compiler: [\w.+-]+ \*/\s*\n", "", text)
        for marker in near_fix.profiles_for(self.addr, bad):
            if self.budget <= 0:
                break
            candidate = f"/* compiler: {marker} */\n" + body
            ok, n, verdict = self.judge(candidate, f"profile {marker}")
            if ok:
                return True, candidate, (0, verdict)
        return False, text, state

    def ambiguous_literals(self, text, state):
        """A literal written several times of which the diff wants some changed: each occurrence
        alone and all of them tried, the closest kept."""
        rows = diff_rows(state[1])
        wants = {**big_offsets(rows), **wanted_literals(rows), **zero_literals(rows)}
        candidates = []
        for have, want in wants.items():
            for form, spans in occurrences(text, have):
                if 1 < len(spans) <= 12:
                    new = f"0x{want:X}" if form.startswith("0x") else str(want)
                    for a, b in spans:
                        candidates.append(text[:a] + new + text[b:])
                    candidates.append(re.sub(rf"(?<![\w.]){re.escape(form)}(?![\w.])", new, text))
        best = None
        for cand in candidates[:24]:
            if self.budget <= 0:
                break
            ok, n, v = self.judge(cand, "one occurrence")
            if ok:
                return True, cand, (0, v)
            if best is None or n < best[0]:
                best = (n, cand, v)
        if best and best[0] < state[0]:
            return False, best[1], (best[0], best[2])
        return False, text, state

    def near_fix_rules(self, text, state):
        """tools/near_fix.py's structural rules on what is left: an argument the caller passes
        through (m2c-style `arg0`), a callee's void return, a float argument's place, two stores
        exchanged. Only sources shaped like drafts (one function, `arg0` parameters) can take them."""
        import near_fix
        rows = diff_rows(state[1])
        bad = [(l, r) for b, l, r, _ in rows if b]
        variants = []
        original = text
        text, restore = flat_head(text)
        try:
            shifted = any(len(l) > 1 and len(r) > 1 and l[0] == r[0] and l[1] != r[1] and r[1] in ("$a0", "$a1", "$a2")
                          and l[1] == f"$a{int(r[1][2]) + 1}" for l, r in bad if l and r)
            if shifted or any(r[:2] == ["daddu", "$a0"] and l[:2] != ["daddu", "$a0"] for l, r in bad if r):
                variants += [("this passed through", v) for v in near_fix.this_passthrough(text)]
            if bad and all(len(l) == len(r) and l[0] == r[0] and {"$v0", "$v1"} & set(l + r) for l, r in bad if l and r):
                variants += [("void return", v) for v in near_fix.void_returns(text)]
            if any("$f12" in l + r for l, r in bad):
                variants += [("float place", v) for v in near_fix.float_places(text)]
            offs = near_fix.store_permutation(bad)
            if offs is not None:
                variants += [("two stores", v) for v in list(near_fix.store_orders(text, offs))[:12]]
        except Exception:
            pass
        ok = False
        for what, v in variants[:30]:
            if self.budget <= 0:
                break
            v = restore(v)
            ok, n, verdict = self.judge(v, what)
            if ok:
                return True, v, (0, verdict)
            if n <= state[0]:  # the structural edit may have exposed a literal to move
                rows = diff_rows(verdict)
                fixed = v
                for have, want in {**big_offsets(rows), **wanted_literals(rows), **zero_literals(rows)}.items():
                    fixed = replace_once(fixed, have, want)
                if fixed != v:
                    ok, n2, verdict2 = self.judge(fixed, what + " + literals")
                    if ok:
                        return True, fixed, (0, verdict2)
                    if n2 < state[0]:
                        return False, fixed, (n2, verdict2)
        return ok, original, state


def save_match(addr, text, ext, hypothesis, who):
    """src/ (only when no source exists), identical copies, the diary, the auto log."""
    import asm_policy
    import project
    import symbols
    bad = asm_policy.violations(text)
    if bad:
        return "asm policy: " + "; ".join(bad)
    project.sources(refresh=True)
    if project.source_for(addr):
        return "a source appeared meanwhile; not saved"
    dest = os.path.join(ROOT, "src", f"func_{addr:08X}.{ext}")
    open(dest, "w", encoding="utf-8", newline="\n").write(symbols.rename_text(text))
    log_attempt(addr, hypothesis, "match", 0, None, dest, who)
    with open(os.path.join(ROOT, "build", "auto", "log.jsonl"), "a") as f:
        f.write(json.dumps({"addr": f"{addr:08x}", "matched": True, "effort": "neartwin",
                            "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
    d = subprocess.run([sys.executable, os.path.join(HERE, "dedup.py"), "apply", f"{addr:08x}"],
                       cwd=ROOT, capture_output=True, text=True)
    copies = sum("MATCH" in l for l in d.stdout.splitlines())
    return f"saved{f', +{copies} copies' if copies else ''}"


def log_attempt(addr, hypothesis, result, n, of, path, who):
    import attempts
    rec = {"addr": attempts.norm(f"{addr:x}"), "time": time.strftime("%Y-%m-%d %H:%M"), "who": who,
           "hypothesis": hypothesis, "result": result}
    if n is not None:
        rec["diff"] = n
    if of:
        rec["of"] = of
    if path:
        rec["file"] = os.path.relpath(path, ROOT).replace(os.sep, "/")
    attempts.append(rec)


def apply(other, pairs, jobs, who, verbose=False, log=True):
    import project
    done = project.sources(refresh=True)
    pairs = [p for p in pairs if p[0] not in done]
    wanted = sorted({f"{o:08x}" for _, o, *_ in pairs})
    in_path, out_path = os.path.join(OUT, "wanted.json"), os.path.join(OUT, "exported.json")
    json.dump(wanted, open(in_path, "w"))
    run_export(other, "texts", in_path, out_path)
    theirs = json.load(open(out_path))
    todo = [(a, theirs[f"{o:08x}"], s) for a, o, _, s in pairs if f"{o:08x}" in theirs]
    print(f"{len(todo)} pairs to adapt", flush=True)
    hits, t0 = 0, time.time()

    def work(item):
        addr, oth, sim = item
        try:
            port = Port(addr, oth, verbose)
            ok, text = port.run()
            return addr, oth, sim, ok, text, port
        except Exception as e:  # one bad pair must not stop the run
            return addr, oth, sim, False, f"error: {e}", None

    with ThreadPoolExecutor(jobs) as pool, open(RESULTS, "a") as results, open(TRIED, "a") as tried:
        for i, (addr, oth, sim, ok, text, port) in enumerate(pool.map(work, todo), 1):
            hyp = (f"neartwin.py: twin 0x{oth['addr']:08x} of the other game ({oth['path']}, similarity {sim:.2f}) "
                   "adapted: calls by position, globals by suggest_renames, shifted literals/offsets/constants from the diff")
            tried.write(f"{addr:08x} {oth['addr']:08x}\n")
            if port is None:
                print(f"0x{addr:08x} <- 0x{oth['addr']:08x}: {text}", flush=True)
                continue
            n, of = port.best[0], (port.steps[-1][2] if port.steps else 0)
            rec = {"addr": f"{addr:08x}", "other": f"{oth['addr']:08x}", "sim": round(sim, 3),
                   "result": "match" if ok else "differs", "differ": 0 if ok else n, "of": of,
                   "steps": [s[0].split(" ")[0] + f":{s[1]}" for s in port.steps]}
            if ok:
                hits += 1
                why = save_match(addr, text, oth["ext"], hyp, who)
            else:
                best_text = port.best[1]
                if best_text:
                    open(port.path, "w", encoding="utf-8", newline="\n").write(best_text)
                rec["diff"] = [l for l in port.best[2].splitlines() if l.startswith("!")][:8]
                why = f"differs {n} of {of}: " + "; ".join(f"{a}:{b}" for a, b, _ in port.steps)
                if log:
                    log_attempt(addr, hyp, "differs", n, of, port.path, who)
            results.write(json.dumps(rec) + "\n")
            results.flush()
            print(f"0x{addr:08x} <- 0x{oth['addr']:08x} ({sim:.2f}): {'MATCH ' + why if ok else why}", flush=True)
            if i % 50 == 0:
                print(f"-- {i}/{len(todo)}, {hits} matched ({(time.time() - t0) / 60:.0f} min)", flush=True)
    print(f"done: {hits} of {len(todo)} matched", flush=True)


def residuals():
    """The first differing lines of the failures, counted by opcode pair, closest first."""
    latest = {}
    for line in open(RESULTS):
        if line.strip():
            r = json.loads(line)
            latest[r["addr"]] = r
    import project
    done = project.sources()
    fails = [r for r in latest.values() if r["result"] != "match" and int(r["addr"], 16) not in done]
    by_n = {}
    for r in fails:
        by_n[min(r["differ"], 10)] = by_n.get(min(r["differ"], 10), 0) + 1
    print(f"{len(fails)} open failures; by differing instructions: " + " ".join(f"{k}:{v}" for k, v in sorted(by_n.items())))
    sigs = {}
    for r in fails:
        for l in r.get("diff", [])[:1]:
            left, right = l[1:].split("|", 1)
            lt, rt = left.split(), re.sub(r"<[^>]*>", "", right).split()
            key = f"{lt[0] if lt else '-'} > {rt[0] if rt else '-'}"
            if lt and rt and lt[0] == rt[0]:
                d = [(a, b) for a, b in zip(lt, rt) if a != b]
                key += " " + ("regs" if all(a.startswith("$") for a, _ in d) else "imm" if d else "len")
            sigs.setdefault(key, []).append(r["addr"])
    for k, v in sorted(sigs.items(), key=lambda kv: -len(kv[1]))[:30]:
        print(f"{len(v):5}  {k:28} e.g. {' '.join(v[:4])}")


def main():
    if len(sys.argv) >= 2 and sys.argv[1] == "export":
        if HERE in sys.path:
            sys.path.remove(HERE)
        sys.path.insert(0, os.environ["CROSSGAME_TOOLS"])
        export(sys.argv[2], sys.argv[3], sys.argv[4])
        return
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", choices=["scan", "apply", "try", "residuals"])
    ap.add_argument("args", nargs="*")
    ap.add_argument("--from", dest="other", help="the other project's root")
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--limit", type=int)
    ap.add_argument("--min-sim", type=float, default=0.8)
    ap.add_argument("--list", help="pairs file (default build/neartwin/pairs.txt; build/near_twins.txt works too)")
    ap.add_argument("--retry", action="store_true", help="pairs already tried too")
    ap.add_argument("--who", default="neartwin")
    ap.add_argument("--no-log", action="store_true", help="do not log failures in the attempts diary")
    a = ap.parse_args()
    setup()
    if a.command == "residuals":
        residuals()
        return
    if not a.other:
        sys.exit("--from OTHER_PROJECT is required")
    if a.command == "scan":
        scan(a.other, a.min_sim)
        return
    if a.command == "try":
        addr, oth = int(a.args[0], 16), int(a.args[1], 16)
        in_path, out_path = os.path.join(OUT, "wanted_try.json"), os.path.join(OUT, "exported_try.json")
        json.dump([f"{oth:08x}"], open(in_path, "w"))
        run_export(a.other, "texts", in_path, out_path)
        theirs = json.load(open(out_path))
        if f"{oth:08x}" not in theirs:
            sys.exit(f"0x{oth:08x} has no source in {a.other}")
        port = Port(addr, theirs[f"{oth:08x}"], verbose=True)
        ok, text = port.run()
        print("MATCH" if ok else f"best {port.best[0]} differ; {port.path}")
        if not ok and port.best[2]:
            print("\n".join(l for l in port.best[2].splitlines() if l.startswith("!"))[:4000])
        return
    pairs = read_list(a.list or PAIRS)
    pairs = [p for p in pairs if p[3] >= a.min_sim]
    if not a.retry and os.path.exists(TRIED):
        tried = set(open(TRIED).read().splitlines())
        pairs = [p for p in pairs if f"{p[0]:08x} {p[1]:08x}" not in tried]
    if a.limit:
        pairs = pairs[:a.limit]
    apply(a.other, pairs, a.jobs, a.who, log=not a.no_log)


if __name__ == "__main__":
    main()
