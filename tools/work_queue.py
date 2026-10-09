#!/usr/bin/env python3
"""The work queue ranked by expected return: bytes a piece of work is expected to recover, divided
by what it is expected to cost. Run it to choose the next thing to work on.

Work items are single unmatched functions (one per group of identical copies) and families of
similar functions with >= 3 unmatched members (build/families.json; the members are then not
listed alone). For each item:

  value  = unmatched bytes it settles (the function times its unmatched identical copies, or the
           family's unmatched bytes), weighted up a little by the number of callers
  p      = chance of a match: the closest automatic draft (build/auto/cpu/results.jsonl, region
           compilers, fragments, failed model runs: differing / total instructions) or, without
           one, a prior by size; times 0.7 per failed attempt in the diary (tools/attempts.py,
           0.3 per failed automatic tool run)
  cost   = size-proportional effort, cheaper when the draft is close, dearer per failed attempt,
           when the code needs a library source/profile (library region 0x5547e8+), another
           compiler (Sony SDK, 16-byte save spacing) or has VU/MMI/COP instructions
  score  = value * p / cost

Each item comes with a suggested approach: generator/family, rule (near_fix, fragments, permuter),
sibling template, library source, other compiler, or hand work from the best draft.

    work_queue.py [--top N] [--kind function|family] [--min-bytes N] [--max-bytes N] [--grep TEXT]
             [--json FILE]          (default JSON output: build/queue.json, all items)
"""
import argparse
import json
import os
import statistics
import sys

import attempts
import autoloop
import match

ROOT = match.ROOT
LIB_START = 0x5547E8   # Sony's libraries (libstdc++, expat, SGI STL, C++ runtime)
STL_START = 0x596FA0


def prior(size):
    if size <= 32:
        return 0.7
    if size <= 128:
        return 0.5
    if size <= 512:
        return 0.35
    if size <= 2048:
        return 0.2
    return 0.1


def load():
    text_addr, text = match.load_text()
    table = attempts.function_table()
    done = autoloop.done_addrs()
    funcs = {}
    for a, (max_size, calls) in table.items():
        if a in done:
            continue
        words = match.trim_padding(match.words_at(text_addr, text, a, max_size))
        if not words:
            continue
        funcs[f"{a:08x}"] = {
            "addr": a, "size": 4 * len(words), "calls": calls,
            "sdk": len(words) >= 8 and autoloop.other_compiler(words),
            "special": not autoloop.plain(words) and not autoloop.other_compiler(words),
        }
    return funcs


def best_of(results):
    """(ratio, differ, of, source, file) of the closest draft, or None."""
    best = None
    for d, of, src, path in results:
        if of:
            key = (d / of, d, of, src, path)
            if best is None or key[:2] < best[:2]:
                best = key
    return best


def function_item(a, f, copies, best, fw, sibling):
    size, calls = f["size"], f["calls"]
    value = size * copies * (1 + min(calls, 100) / 200)
    p = prior(size)
    cost = 0.5 + size / 128
    lib = f["addr"] >= LIB_START
    if best:
        r = best[0]
        p = max(p, 0.95 * (1 - r) ** 3)
        cost *= 0.4 + 0.6 * min(1.0, 2 * r)
    if lib and not (best and best[3].startswith("region") and best[0] < 0.3):
        cost *= 1.5
    if f["sdk"]:
        cost *= 1.3
    if f["special"]:
        cost *= 2
        p *= 0.5
    p *= 0.7 ** fw
    cost *= 1 + 0.3 * fw
    # Suggested approach.
    if f["special"]:
        how = "hand work: VU/MMI/COP instructions (single-instruction intrinsics only, asm_policy.py)"
    elif f["sdk"]:
        how = "other compiler: other_compiler.py solve (ee-gcc2.9-991111 marker)"
    elif best and best[1] <= 3:
        how = f"rule: near_fix.py / fragments.py try / permute_cpu.py on the {best[1]}-of-{best[2]} draft ({best[3]})"
    elif sibling:
        how = f"sibling template: siblings.py try {sibling} {a}"
    elif lib:
        how = ("library source: the era's public source (gcc-20001003 libstdc++/stl, libmatch.py, stl.py)"
               " with -fno-strict-aliasing")
    elif best and best[0] <= 0.35:
        how = f"hand work from the best draft ({best[1]} of {best[2]} differ, {best[3]})"
    elif size <= 128:
        how = "agent: agent_step.py prompt + cpu_solve --context types draft"
    elif size <= 512:
        how = "hand work: cpu_solve --context types draft, types_db.py for the structs"
    else:
        how = "hand work (large): cpu_solve --context types draft, then block by block"
    if fw >= 1:
        how += f"; diary: {fw:.1f} failed - read attempts.py show first"
    return {"kind": "function", "addr": a, "size": size, "copies": copies, "calls": calls,
            "value": round(value), "p": round(p, 3), "cost": round(cost, 2),
            "score": round(value * p / cost, 2), "failed": round(fw, 1),
            "best": f"{best[1]}/{best[2]} {best[3]}" if best else "", "draft": best[4] if best else "",
            "approach": how}


def family_item(i, fam, members, funcs, copies, diary, n_matched, results):
    sizes = [funcs[m]["size"] for m in members]
    value = sum(funcs[m]["size"] * copies.get(m, 1) for m in members)
    value *= 1 + min(sum(funcs[m]["calls"] for m in members), 100) / 200
    fw = statistics.mean(attempts.failed_weight(diary.get(m, [])) for m in members)
    p = (0.45 if n_matched else 0.35) * 0.7 ** fw
    lib = min(funcs[m]["addr"] for m in members) >= LIB_START
    cost = 2 + statistics.median(sizes) / 128 + 0.05 * len(members)
    if n_matched:
        cost *= 0.6
    if lib:
        cost *= 1.3
    cost *= 1 + 0.3 * fw
    near = sorted((b for b in (best_of(results.get(m, [])) for m in members) if b), key=lambda b: b[0])
    rep = fam["representative"] if fam["representative"] in members else min(members, key=lambda m: funcs[m]["size"])
    matched_member = next((m for m in fam["members"] if m not in funcs), None)
    if n_matched:
        how = (f"family generator: template from matched member {matched_member} (siblings.py, then a "
               f"generator like static_init/registration/accessors); families.py show {i}")
    else:
        how = f"family: understand representative {rep} by hand, then write a generator; families.py show {i}"
    if lib:
        how += "; library region: find the public source first"
    if fw >= 1:
        how += f"; diary: {fw:.1f} failed per member"
    return {"kind": "family", "addr": rep, "family": i, "members": len(members), "matched": n_matched,
            "size": int(statistics.median(sizes)), "value": round(value), "p": round(p, 3),
            "cost": round(cost, 2), "score": round(value * p / cost, 2), "failed": round(fw, 1),
            "best": f"{near[0][1]}/{near[0][2]} {near[0][3]}" if near else "",
            "draft": near[0][4] if near else "", "approach": how}


def build_queue():
    funcs = load()
    diary = attempts.by_addr()
    results = attempts.best_results()
    groups = attempts.groups_index()
    fams, _ = attempts.families_index()
    # Identical copies: one representative per group (lowest unmatched address).
    copies, skip = {}, set()
    for a in funcs:
        g = [m for m in groups.get(a, [a]) if m in funcs]
        if a == min(g):
            copies[a] = len(g)
        else:
            skip.add(a)
    items, in_family, sibling = [], set(), {}
    for i, fam in enumerate(fams):
        members = [m for m in fam["members"] if m in funcs and m not in skip]
        n_matched = sum(1 for m in fam["members"] if m not in funcs)
        if len(members) >= 3:
            items.append(family_item(i, fam, members, funcs, copies, diary, n_matched, results))
            in_family.update(members)
        elif n_matched:
            done_member = next(m for m in fam["members"] if m not in funcs)
            for m in members:
                sibling[m] = done_member
    for a, f in funcs.items():
        if a in skip or a in in_family:
            continue
        items.append(function_item(a, f, copies.get(a, 1), best_of(results.get(a, [])),
                                   attempts.failed_weight(diary.get(a, [])), sibling.get(a)))
    items.sort(key=lambda it: -it["score"])
    return items


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--top", type=int, default=30)
    ap.add_argument("--kind", choices=("function", "family"))
    ap.add_argument("--min-bytes", type=int, default=0)
    ap.add_argument("--max-bytes", type=int, default=1 << 30)
    ap.add_argument("--grep", help="keep items whose approach contains this text")
    ap.add_argument("--json", default=os.path.join(ROOT, "build", "queue.json"))
    args = ap.parse_args()
    items = build_queue()
    with open(args.json, "w") as f:
        json.dump(items, f, indent=0)
    shown = [it for it in items if (not args.kind or it["kind"] == args.kind)
             and args.min_bytes <= it["size"] <= args.max_bytes
             and (not args.grep or args.grep.lower() in it["approach"].lower())]
    total = sum(it["value"] for it in items)
    print(f"{len(items)} work items ({sum(1 for it in items if it['kind'] == 'family')} families), "
          f"{total} weighted bytes; all in {os.path.relpath(args.json, ROOT)}")
    print(f"{'#':>3} {'score':>7} {'kind':<8} {'addr':<8} {'size':>5} {'value':>6} {'p':>5} {'cost':>5} "
          f"{'fail':>4}  {'best draft':<28} approach")
    for n, it in enumerate(shown[:args.top], 1):
        kind = f"fam{it['family']}x{it['members']}" if it["kind"] == "family" else "func"
        print(f"{n:>3} {it['score']:>7.1f} {kind:<8} {it['addr']:<8} {it['size']:>5} {it['value']:>6} "
              f"{it['p']:>5.2f} {it['cost']:>5.1f} {it['failed']:>4}  {it['best'][:28]:<28} {it['approach']}")


if __name__ == "__main__":
    main()
