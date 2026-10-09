#!/usr/bin/env python3
"""The attempts diary: what was already tried on a function, so nobody repeats a failed idea.

One JSON record per attempt in knowledge/attempts.jsonl (versioned, append-only; one line per
record so parallel agents can append safely). Read it before working on a function, write to it
after every hypothesis you judged, matched or not.

    attempts.py show ADDR [--no-files]     the diary for ADDR, its family's diary, and what the
                                           automatic tools reached (cpu_solve, region compilers,
                                           fragments, best partial score, draft files under build/)
    attempts.py log ADDR --hypothesis TEXT --result RESULT [--diff N] [--of M] [--file PATH]
                    [--compiler NAME] [--who NAME]
                                           RESULT: match | differs | worse | no-change |
                                           no-compile | open | abandoned (free text allowed);
                                           warns when a similar hypothesis is already recorded
    attempts.py summary [--top N]          most-attempted functions, results, sources
    attempts.py seed                       (re)build the seeded records from knowledge/*.md open
                                           notes, build/auto notes, failed autoloop/agent runs
                                           (build/auto/log.jsonl), near_fix and fragments runs;
                                           records not from `seed` are kept as they are

ADDR may be written 326750, 0x00326750 or func_00326750.
"""
import argparse
import csv
import json
import os
import re
import sys
import textwrap
import time
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DIARY = os.path.join(ROOT, "knowledge", "attempts.jsonl")
BUILD = os.path.join(ROOT, "build")
AUTO = os.path.join(BUILD, "auto")
FUNCTIONS = os.path.join(BUILD, "functions.csv")
FAILED = ("match",)  # every other result counts as a failed attempt


def norm(addr):
    s = str(addr).strip()
    s = re.sub(r"^(func_|0x)", "", s, flags=re.I)
    return f"{int(s, 16):08x}"


def load(path=None):
    path = path or DIARY
    if not os.path.exists(path):
        return []
    out = []
    for line in open(path, encoding="utf-8"):
        line = line.strip()
        if line:
            try:
                out.append(json.loads(line))
            except ValueError:
                pass
    return out


def by_addr(records=None):
    out = defaultdict(list)
    for r in records if records is not None else load():
        out[r["addr"]].append(r)
    return out


def failed_weight(recs):
    """How much the diary says a function resists: 1 per failed hypothesis by an agent or a
    person, 0.3 per failed automatic tool run (those are cheap and broad, not specific ideas)."""
    w = 0.0
    for r in recs:
        if r.get("result") in FAILED:
            continue
        w += 0.3 if r.get("who") == "tool" else 1.0
    return w


def append(rec):
    os.makedirs(os.path.dirname(DIARY), exist_ok=True)
    line = (json.dumps(rec, ensure_ascii=False) + "\n").encode("utf-8")
    fd = os.open(DIARY, os.O_WRONLY | os.O_APPEND | os.O_CREAT | getattr(os, "O_BINARY", 0))
    try:
        os.write(fd, line)
    finally:
        os.close(fd)


def words(text):
    return {w for w in re.findall(r"[a-z0-9_]+", text.lower()) if len(w) > 2}


def similar(a, b):
    wa, wb = words(a), words(b)
    return len(wa & wb) / len(wa | wb) if wa and wb else 0.0


# ---------------------------------------------------------------- function facts (build/)

def function_table():
    out = {}
    if os.path.exists(FUNCTIONS):
        for row in csv.DictReader(open(FUNCTIONS)):
            out[int(row["address"], 16)] = (int(row["max_size"]), int(row["calls"]))
    return out


def jsonl(path):
    if not os.path.exists(path):
        return []
    out = []
    for line in open(path, encoding="utf-8", errors="replace"):
        try:
            out.append(json.loads(line))
        except ValueError:
            pass
    return out


def best_results():
    """{addr: [(differ, of, source, file)]} from every automatic tool's results."""
    out = defaultdict(list)
    for r in jsonl(os.path.join(AUTO, "cpu", "results.jsonl")):
        if r.get("result") == "differs" and r.get("of"):
            out[r["addr"]].append((r["differ"], r["of"], "cpu_solve" + (" ctx" if r.get("ctx") else ""),
                                   f"build/auto/cpu/{r['addr']}.c"))
    region = os.path.join(AUTO, "region")
    if os.path.isdir(region):
        for name in os.listdir(region):
            for r in jsonl(os.path.join(region, name, "results.jsonl")):
                if r.get("result") == "differs" and r.get("of"):
                    out[r["addr"]].append((r["differ"], r["of"], f"region {name}",
                                           f"build/auto/region/{name}/{r['addr']}.c"))
    of = {a: min(x[1] for x in v) for a, v in out.items()}
    for r in jsonl(os.path.join(BUILD, "fragments", "results.jsonl")):
        a = r.get("addr")
        if a and not r.get("matched") and r.get("after") is not None and a in of:
            best = os.path.join(BUILD, "fragments", "work", f"{a}.best.c")
            out[a].append((r["after"], of[a], "fragments",
                           f"build/fragments/work/{a}.best.c" if os.path.exists(best) else ""))
    for r in jsonl(os.path.join(AUTO, "log.jsonl")):
        m = re.search(r"(\d+) of (\d+) instructions differ", r.get("last") or "")
        if m and not r.get("matched"):
            out[r["addr"]].append((int(m.group(1)), int(m.group(2)), f"autoloop {r.get('model') or ''}".strip(), ""))
    return out


def partial_scores():
    path = os.path.join(AUTO, "partial.json")
    return json.load(open(path)) if os.path.exists(path) else {}


def families_index():
    path = os.path.join(BUILD, "families.json")
    fams = json.load(open(path)) if os.path.exists(path) else []
    index = {}
    for i, f in enumerate(fams):
        for m in f["members"]:
            index.setdefault(m, i)
    return fams, index


def groups_index():
    path = os.path.join(BUILD, "groups.json")
    index = {}
    if os.path.exists(path):
        for g in json.load(open(path))["groups"]:
            for a in g:
                index[a] = g
    return index


def done_set():
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import autoloop
    return {f"{a:08x}" for a in autoloop.done_addrs()}


def draft_files(addr):
    """Files under build/ whose name carries the address (drafts, probes, variants)."""
    found = []
    pat = re.compile(addr.lstrip("0")[-6:], re.I)
    for dirpath, dirs, files in os.walk(BUILD):
        dirs[:] = [d for d in dirs if d not in ("obj", "full", "splat", "splat_try", "__pycache__")]
        for name in files:
            if pat.search(name):
                found.append(os.path.relpath(os.path.join(dirpath, name), ROOT).replace(os.sep, "/"))
    return sorted(found)


# ---------------------------------------------------------------- commands

def wrap(text, indent="      "):
    return textwrap.fill(" ".join(text.split()), 100, initial_indent=indent, subsequent_indent=indent)


def fmt(r):
    d = f" {r['diff']}" + (f"/{r['of']}" if r.get("of") else "") if r.get("diff") is not None else ""
    extra = "".join(f" {k}={r[k]}" for k in ("compiler", "file") if r.get(k))
    src = f" [{r['source']}]" if r.get("source") else ""
    return (f"  {r.get('time', '')[:10]} {r.get('who', '?')}: {r.get('result', '?')}{d}{extra}{src}\n"
            + wrap(r.get("hypothesis", "")))


def cmd_show(addr, files=True):
    a = norm(addr)
    records = load()
    mine = [r for r in records if r["addr"] == a]
    table = function_table()
    size, calls = table.get(int(a, 16), (0, 0))
    done = a in done_set()
    fams, findex = families_index()
    groups = groups_index()
    print(f"func_{a.upper()}  {size} B, {calls} callers, {'MATCHED' if done else 'unmatched'}"
          + (f", {len(groups[a])} identical copies" if a in groups else ""))
    if a in findex:
        f = fams[findex[a]]
        print(f"family #{findex[a]}: {f['count']} members ({f['matched']} matched when families.py ran), "
              f"representative {f['representative']}  (families.py show {findex[a]})")
    print(f"\ndiary: {len(mine)} records, failed weight {failed_weight(mine):.1f}")
    for r in mine:
        print(fmt(r))
    if a in findex:
        members = set(fams[findex[a]]["members"]) - {a}
        sib = [r for r in records if r["addr"] in members]
        if sib:
            c = Counter(r["addr"] for r in sib)
            print(f"\nfamily members' diary: {len(sib)} records on {len(c)} members: "
                  + ", ".join(f"{m} ({n})" for m, n in c.most_common(8)))
            for r in sib[-5:]:
                print(f"  [{r['addr']}]" + fmt(r)[1:])
    res = best_results().get(a, [])
    print("\nautomatic tools (differing instructions, closest first):")
    if not res:
        print("  none recorded")
    for d, of, src, path in sorted(set(res))[:8]:
        print(f"  {d:>4} of {of:<5} {src:<40} {path}")
    p = partial_scores().get(a)
    if p is not None:
        print(f"  best partial score (agent_step.py try): {p}%")
    if files:
        found = draft_files(a)
        print(f"\nfiles under build/ named with the address: {len(found)}")
        for path in found[:15]:
            print("  " + path)
        if len(found) > 15:
            print(f"  ... {len(found) - 15} more")


def cmd_log(args):
    a = norm(args.addr)
    rec = {"addr": a, "time": time.strftime("%Y-%m-%d %H:%M"), "who": args.who,
           "hypothesis": args.hypothesis.strip(), "result": args.result.strip()}
    for k in ("diff", "of", "file", "compiler"):
        v = getattr(args, k)
        if v is not None:
            rec[k] = v
    prior = [r for r in load() if r["addr"] == a and similar(r.get("hypothesis", ""), rec["hypothesis"]) >= 0.5]
    append(rec)
    print(f"logged ({a}: {rec['result']})")
    if prior:
        print(f"note: {len(prior)} similar hypotheses were already recorded for {a}:")
        for r in prior[-3:]:
            print(fmt(r))


def cmd_summary(top):
    records = load()
    print(f"{len(records)} records on {len({r['addr'] for r in records})} functions")
    print("results: " + ", ".join(f"{k} {n}" for k, n in Counter(r.get("result") for r in records).most_common(10)))
    print("by: " + ", ".join(f"{k} {n}" for k, n in Counter(r.get("who") for r in records).most_common(10)))
    done = done_set()
    groups = by_addr(records)
    rows = sorted(((failed_weight(v), a, v) for a, v in groups.items() if a not in done), reverse=True)
    print(f"\nmost-attempted unmatched functions (failed weight: 1 per hypothesis, 0.3 per tool run):")
    for w, a, v in rows[:top]:
        diffs = [r["diff"] for r in v if r.get("diff") is not None]
        last = next((r for r in reversed(v) if r.get("who") != "tool"), v[-1])
        print(f"  {a}  {w:5.1f}  {len(v):3} records  best diff {min(diffs) if diffs else '-':>4}  "
              f"last: {' '.join(last.get('hypothesis', '').split())[:70]}")


# ---------------------------------------------------------------- seeding

ADDR_RE = re.compile(r"(?<![0-9A-Fa-f])(?:func_|0x)?(00[1-6][0-9A-Fa-f]{5})(?![0-9A-Fa-f])")
OPEN_RE = re.compile(r"\bOpen\b|[Nn]ot (?:reproduced|found|explained)|no change|did not (?:help|move)|"
                     r"do not move|could not|[Tt]ried|still differ|not matched")


def paragraphs(text):
    """Markdown bullets/paragraphs with their first line number."""
    out, cur, start = [], [], 0
    for i, line in enumerate(text.splitlines(), 1):
        new = line.startswith(("- ", "#", "* ", "|")) or not line.strip()
        if new and cur:
            out.append((start, " ".join(cur)))
            cur = []
        if line.strip() and not line.startswith("#"):
            if not cur:
                start = i
            cur.append(line.strip())
    if cur:
        out.append((start, " ".join(cur)))
    return out


def snippet(text, addr):
    m = re.search(addr, text, re.I)
    pos = m.start() if m else 0
    lo = max(0, text.rfind(". ", 0, max(0, pos - 150)) + 2) if pos > 200 else 0
    s = text[lo:lo + 700]
    return s + (" ..." if lo + 700 < len(text) else "")


def seed_records(table, done):
    recs = []
    funcs = {f"{a:08x}" for a in table}

    def addrs_in(text, keep_done=False):
        seen = []
        for m in ADDR_RE.finditer(text):
            a = m.group(1).lower()
            if a in funcs and (keep_done or a not in done) and a not in seen:
                seen.append(a)
        return seen

    def status(para, a):
        """'open' when the note is about the function (named at the start or after the 'Open'
        keyword), 'mentioned' when it only appears in passing (a callee, a matched example)."""
        o = OPEN_RE.search(para)
        pos = re.search(a, para, re.I).start()
        return "open" if pos < 80 or (o and pos >= o.start()) else "mentioned"

    for name in ("gt4.md", "ee-gcc-2.96.md", "classes.md", "architecture.md"):
        path = os.path.join(ROOT, "knowledge", name)
        if not os.path.exists(path):
            continue
        for line, para in paragraphs(open(path, encoding="utf-8").read()):
            if not OPEN_RE.search(para):
                continue
            for a in addrs_in(para, keep_done=True):
                st = status(para, a)
                if st == "mentioned" and a in done:
                    continue
                recs.append({"addr": a, "who": "knowledge", "result": st,
                             "hypothesis": snippet(para, a), "source": f"seed:knowledge/{name}:{line}"})
    notes = [os.path.join(AUTO, n) for n in os.listdir(AUTO) if n.startswith("notes")] if os.path.isdir(AUTO) else []
    for d in os.listdir(AUTO) if os.path.isdir(AUTO) else []:
        p = os.path.join(AUTO, d)
        if os.path.isdir(p):
            notes += [os.path.join(p, n) for n in os.listdir(p) if n.startswith("notes") and n.endswith(".txt")]
    for path in notes:
        rel = os.path.relpath(path, ROOT).replace(os.sep, "/")
        for line, para in paragraphs(open(path, encoding="utf-8", errors="replace").read()):
            for a in addrs_in(para, keep_done=True):
                m = re.search(r"(\d+) of (\d+) differ", para)
                rec = {"addr": a, "who": "notes", "result": "open", "hypothesis": snippet(para, a),
                       "source": f"seed:{rel}:{line}"}
                if m:
                    rec["diff"], rec["of"] = int(m.group(1)), int(m.group(2))
                recs.append(rec)
    # Failed model runs (autoloop.py, agent_step.py giveup).
    for r in jsonl(os.path.join(AUTO, "log.jsonl")):
        a = r.get("addr")
        if r.get("matched") or not a or a in done or a not in funcs:
            continue
        m = re.search(r"(\d+) of (\d+) instructions differ", r.get("last") or "")
        who = r.get("model") or ("agent" if "agent" in (r.get("levels") or []) else "autoloop")
        rec = {"addr": a, "time": r.get("time", ""), "who": "tool" if who == "autoloop" else who,
               "result": "differs" if m else "abandoned",
               "hypothesis": f"model rewrite from asm + m2c draft ({r.get('effort') or '?'} effort, "
                             f"{r.get('attempts', '?')} attempts): {(r.get('last') or 'gave up')[:200]}",
               "source": "seed:build/auto/log.jsonl"}
        if m:
            rec["diff"], rec["of"] = int(m.group(1)), int(m.group(2))
        recs.append(rec)
    # near_fix.py and fragments.py runs (automatic, one record per function and tool).
    of = {}
    for r in jsonl(os.path.join(AUTO, "cpu", "results.jsonl")):
        if r.get("of"):
            of[r["addr"]] = r["of"]
    nearfix = os.path.join(AUTO, "nearfix")
    tried = set()
    for name in os.listdir(nearfix) if os.path.isdir(nearfix) else []:
        if name.startswith("tried") and name.endswith(".txt"):
            tried |= {l.strip()[:8].lower() for l in open(os.path.join(nearfix, name)) if l.strip()}
    if True:
        for a in sorted(tried):
            if a in funcs and a not in done:
                recs.append({"addr": a, "who": "tool", "result": "no-change",
                             "hypothesis": "near_fix.py diff rules (hex floats, numeric addresses, operand order, derefs)",
                             "source": "seed:build/auto/nearfix/tried*.txt"})
    for r in jsonl(os.path.join(BUILD, "fragments", "results.jsonl")):
        a = r.get("addr")
        if not a or r.get("matched") or a in done or a not in funcs:
            continue
        rec = {"addr": a, "who": "tool",
               "result": "differs" if r.get("after", 0) < r.get("before", 0) else "no-change",
               "hypothesis": f"fragments.py statement edits ({r.get('judges', '?')} judged; kept: "
                             f"{', '.join(r.get('steps') or []) or 'none'}), {r.get('before')} -> {r.get('after')} differ",
               "source": "seed:build/fragments/results.jsonl"}
        if r.get("after") is not None:
            rec["diff"] = r["after"]
            if a in of:
                rec["of"] = of[a]
        recs.append(rec)
    return recs


def cmd_seed():
    table = function_table()
    done = done_set()
    kept = [r for r in load() if not str(r.get("source", "")).startswith("seed:")]
    seeds = seed_records(table, done)
    tmp = DIARY + ".tmp"
    with open(tmp, "w", encoding="utf-8", newline="\n") as f:
        for r in seeds + kept:
            f.write(json.dumps(r, ensure_ascii=False) + "\n")
    os.replace(tmp, DIARY)
    c = Counter(r["source"].split(":")[1].split("/")[0] if r["source"].startswith("seed:knowledge") else r["source"]
                for r in seeds)
    print(f"{len(seeds)} seeded records on {len({r['addr'] for r in seeds})} functions, {len(kept)} other records kept")
    for k, n in c.most_common():
        print(f"  {n:6}  {k}")


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("show")
    s.add_argument("addr")
    s.add_argument("--no-files", action="store_true")
    s = sub.add_parser("log")
    s.add_argument("addr")
    s.add_argument("--hypothesis", "-H", required=True)
    s.add_argument("--result", "-r", required=True)
    s.add_argument("--diff", type=int)
    s.add_argument("--of", type=int)
    s.add_argument("--file")
    s.add_argument("--compiler")
    s.add_argument("--who", default=os.environ.get("GT4_AGENT", "agent"))
    s = sub.add_parser("summary")
    s.add_argument("--top", type=int, default=25)
    sub.add_parser("seed")
    args = ap.parse_args()
    if args.cmd == "show":
        cmd_show(args.addr, files=not args.no_files)
    elif args.cmd == "log":
        cmd_log(args)
    elif args.cmd == "summary":
        cmd_summary(args.top)
    elif args.cmd == "seed":
        cmd_seed()


if __name__ == "__main__":
    main()
