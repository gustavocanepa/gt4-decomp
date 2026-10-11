#!/usr/bin/env python3
"""Search source shapes that move register allocation, for drafts whose logic is already right.

The remaining near misses mostly differ in which register a value gets or in the order of
independent instructions (knowledge/gcc296-codegen-map.md): gcc 2.96 allocates by priority
(refs, lifetime, declaration order, first set) and schedules by dependence and source order. The
byte-neutral source shapes that move those decisions are mechanical (the "recipes" another
all-AI decomp used to close whole classes): local declaration order, operand order of commutative
operators, a statement wrapped in its own block, a mirrored if/else. This hill-climbs over them:
each round generates every single-step variant of the best source so far, judges them all in one
batch (match.judge_many) and keeps the one with the fewest differing instructions; a MATCH is
saved to src/ like any other match (never over an existing source) and logged in the diary.

    regsearch.py [--max-differ 12] [--rounds 4] [--limit N] [--jobs 2] [--addrs FILE]
                 [--from-diary]   also take the best drafts the attempts diary names (abandoned
                                  functions whose notes say only registers/order differ)
Work list by default: unmatched functions whose best m2c draft (build/auto/cpu/ADDR.c) differs by
at most --max-differ instructions with the same length.
"""
import argparse
import itertools
import json
import os
import random
import re
import subprocess
import sys

import match
import project

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "regsearch")
DIFF = re.compile(r"(\d+) of (\d+) instructions differ")
TYPE_WORDS = r"(?:const\s+|volatile\s+|unsigned\s+|signed\s+|struct\s+\w+\s*|\w+)"
DECL = re.compile(r"^(\s+)(?!return\b|if\b|for\b|while\b|do\b|switch\b|case\b|goto\b|else\b)" + TYPE_WORDS +
                  r"(?:\s+" + TYPE_WORDS + r")*[\s\*]+\w+(?:\s*\[[^\]]*\])?(?:\s*,\s*\**\s*\w+(?:\s*\[[^\]]*\])?)*\s*;\s*$")
OPERAND = r"(?:[A-Za-z_][\w]*(?:(?:\.|->)[A-Za-z_]\w*|\[[^\[\]]*\])*|0x[0-9A-Fa-f]+|\d+(?:\.\d*)?f?)"
COMMUTE = re.compile(r"(?<![\w\)\]\.>])(" + OPERAND + r")\s*([+*&|^]|==|!=)\s*(" + OPERAND + r")(?![\w\(\[\.])")
SIMPLE_STMT = re.compile(r"^(\s+)([^\s{}#][^{};]*;)\s*$")


def score(report):
    if report.startswith(("compile failed", "REFUSED")) or "no function" in report:
        return None
    m = DIFF.search(report)
    return int(m.group(1)) if m else (0 if "MATCH" in report else None)


def body_span(text):
    """(start, end) of the function body: the last top-level `{ ... }` of the file."""
    depth, start, last = 0, None, None
    for i, ch in enumerate(text):
        if ch == "{":
            if depth == 0:
                start = i
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0 and start is not None:
                last = (start, i + 1)
    return last


def variants(text, rng, cap=250):
    span = body_span(text)
    if not span:
        return []
    head, body, tail = text[:span[0]], text[span[0]:span[1]], text[span[1]:]
    lines = body.split("\n")
    out = set()
    # 1. order of the local declarations at the top of the body
    decl = []
    for i, l in enumerate(lines[1:], 1):
        if DECL.match(l):
            decl.append(i)
        elif l.strip() and not l.strip().startswith("//"):
            break
    if len(decl) >= 2:
        block = [lines[i] for i in decl]
        perms = itertools.permutations(block) if len(block) <= 5 else (rng.sample(block, len(block)) for _ in range(60))
        for p in perms:
            if list(p) != block:
                new = lines[:]
                for i, l in zip(decl, p):
                    new[i] = l
                out.add("\n".join(new))
    # 2. operand order of one commutative operator
    for m in COMMUTE.finditer(body):
        a, op, b = m.group(1), m.group(2), m.group(3)
        if a == b or op == "*" and body[max(0, m.start() - 1)] in "(=,":
            continue
        out.add(body[:m.start()] + f"{b} {op} {a}" + body[m.end():])
    # 3. one simple statement wrapped in its own block
    for i, l in enumerate(lines):
        m = SIMPLE_STMT.match(l)
        if m and not DECL.match(l) and not l.strip().startswith(("return", "break", "continue", "case", "default")):
            new = lines[:]
            new[i] = f"{m.group(1)}do {{ {m.group(2)} }} while (0);"
            out.add("\n".join(new))
    # 4. two adjacent simple statements swapped (independent ones only compile to the same logic;
    #    the judge rejects the others)
    for i in range(len(lines) - 1):
        a, b = SIMPLE_STMT.match(lines[i]), SIMPLE_STMT.match(lines[i + 1])
        if a and b and not DECL.match(lines[i]) and not DECL.match(lines[i + 1]) \
                and not lines[i].strip().startswith("return") and not lines[i + 1].strip().startswith("return"):
            new = lines[:]
            new[i], new[i + 1] = new[i + 1], new[i]
            out.add("\n".join(new))
    out.discard(body)
    out = list(out)
    rng.shuffle(out)
    return [head + v + tail for v in out[:cap]]


def work_list(a):
    done = set(project.sources(refresh=True))
    items = {}
    if a.addrs:
        for l in open(a.addrs):
            if l.strip():
                addr = int(l.split()[0], 16)
                path = os.path.join(ROOT, "build", "auto", "cpu", f"{addr:08x}.c")
                if addr not in done and os.path.exists(path):
                    items[addr] = path
        return items
    best = {}
    for l in (open(os.path.join(ROOT, "build", "auto", "cpu", "results.jsonl")) if not a.only_diary else []):
        try:
            r = json.loads(l)
        except ValueError:
            continue
        if r.get("result") == "differs" and r.get("same_length") and r.get("differ", 99) <= a.max_differ:
            addr = int(r["addr"], 16)
            best[addr] = min(best.get(addr, 99), r["differ"])
    for addr in sorted(best, key=best.get):
        path = os.path.join(ROOT, "build", "auto", "cpu", f"{addr:08x}.c")
        if addr not in done and os.path.exists(path):
            items[addr] = path
    if a.from_diary:
        words = re.compile(r"register|regalloc|v0/v1|s0/s1|\$s\d|\$v\d|\$f\d|swap|order|schedul", re.I)
        for l in open(os.path.join(ROOT, "knowledge", "attempts.jsonl"), encoding="utf-8"):
            try:
                r = json.loads(l)
            except ValueError:
                continue
            f, addr = r.get("file"), int(r.get("addr", "0"), 16)
            if r.get("result") in ("abandoned", "differs") and f and words.search(r.get("hypothesis", "")) \
                    and addr not in done and (r.get("diff") or 99) <= a.max_differ:
                p = f if os.path.isabs(f) else os.path.join(ROOT, f)
                if os.path.exists(p):
                    items[addr] = p
    return items


def save(addr, text, ext):
    if project.source_for(addr):
        return None
    path = os.path.join(ROOT, "src", f"func_{addr:08X}{ext}")
    open(path, "w", encoding="utf-8", newline="\n").write(text)
    ok, _ = match.judge(addr, path)
    if not ok:
        os.remove(path)
        return None
    subprocess.run([sys.executable, os.path.join(ROOT, "tools", "dedup.py"), "apply", f"{addr:x}"], capture_output=True, cwd=ROOT)
    subprocess.run([sys.executable, os.path.join(ROOT, "tools", "attempts.py"), "log", f"{addr:x}", "--hypothesis",
                    "regsearch: register/order recipes (declaration order, commutative operands, block wraps, swaps)",
                    "--result", "match", "--file", os.path.relpath(path, ROOT), "--who", "regsearch"], capture_output=True, cwd=ROOT)
    return path


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--max-differ", type=int, default=12)
    ap.add_argument("--rounds", type=int, default=4)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--addrs")
    ap.add_argument("--from-diary", action="store_true")
    ap.add_argument("--only-diary", action="store_true", help="only the diary's best drafts (implies --from-diary)")
    a = ap.parse_args()
    a.from_diary = a.from_diary or a.only_diary
    rng = random.Random(1)
    os.makedirs(OUT, exist_ok=True)
    items = list(work_list(a).items())
    if a.limit:
        items = items[:a.limit]
    print(f"{len(items)} functions to search", flush=True)
    matched = 0
    for n, (addr, path) in enumerate(items, 1):
        ext = os.path.splitext(path)[1] or ".c"
        text = open(path, encoding="utf-8", errors="replace").read()
        span = body_span(text)
        if not span or len(re.sub(r"\s", "", text[span[0]:span[1]])) < 40:
            continue  # an empty or stub body (m2c gave up): nothing for the recipes to move
        base = os.path.join(OUT, f"{addr:08x}_0{ext}")
        open(base, "w", encoding="utf-8", newline="\n").write(text)
        ((_, _, ok, report),) = list(match.judge_many([(addr, base)], a.jobs))
        best = score(report)
        if best is None:
            continue
        start = best
        for rnd in range(a.rounds):
            if best == 0:
                break
            cands = variants(text, rng)
            pairs = []
            for k, v in enumerate(cands):
                p = os.path.join(OUT, f"{addr:08x}_{rnd + 1}_{k}{ext}")
                open(p, "w", encoding="utf-8", newline="\n").write(v)
                pairs.append((addr, p))
            improved = None
            for _, p, ok, report in match.judge_many(pairs, a.jobs):
                s = score(report)
                if s is not None and s < best:
                    best, improved = s, p
            for _, p in pairs:
                if p != improved:
                    os.remove(p)
            if not improved:
                break
            text = open(improved, encoding="utf-8").read()
        if best == 0 and save(addr, text, ext):
            matched += 1
            print(f"{addr:08x}: MATCH ({start} -> 0)", flush=True)
        elif best < start:
            open(os.path.join(OUT, f"{addr:08x}_best{ext}"), "w", encoding="utf-8", newline="\n").write(text)
            print(f"{addr:08x}: {start} -> {best}", flush=True)
        if n % 25 == 0:
            print(f"[{n}/{len(items)}] {matched} matched", flush=True)
    print(f"done: {matched} of {len(items)} matched")


if __name__ == "__main__":
    main()
