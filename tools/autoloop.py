#!/usr/bin/env python3
"""Decompile a batch of functions automatically: m2c draft -> model writes C++ -> compile -> compare -> retry.

Each function gets a fresh, tool-less model session (Claude Code CLI in print mode) seeded with the
original assembly, the m2c draft and any strings the code points at; the session is resumed with
the judge's diff after each failed attempt. Everything is logged to build/auto/log.jsonl, including
tokens and cost, so the price per function can be measured.

    autoloop.py pick NAME COUNT [--max-bytes 160] [--order impact|random] [--seed N]   choose a batch
    autoloop.py run NAME [--attempts 4] [--model claude-sonnet-5] [--effort auto] [--jobs N]
    autoloop.py report [NAME]
"""
import argparse
import csv
import json
import os
import random
import re
import shutil
import struct
import subprocess
import sys
import threading
import time
from concurrent.futures import ThreadPoolExecutor

import rabbitizer

import match
import project

ROOT = match.ROOT
AUTO = os.path.join(ROOT, "build", "auto")
LOG = os.path.join(AUTO, "log.jsonl")
M2C = os.path.join(ROOT, "tools", "ext", "m2c", "m2c.py")
CLI_CONFIG = os.environ.get("DECOMP_CLAUDE_CONFIG", os.path.expanduser("~/.claude-decomp"))

SYSTEM = f"""You write C++ that {project.CONFIG["compiler"]["name"]} ({project.compiler_command().split(" -c ", 1)[-1]})
compiles to exactly the instructions of a given function from {project.CONFIG["game"]["name"]}. Output ONE
fenced ```cpp block holding a complete, self-contained translation unit: declare every struct, global
and callee you use (extern), then define the function with the exact name given. No headers, no
explanations outside the block. Matching is judged instruction by instruction; addresses filled by the
linker (call targets, %hi/%lo of globals) only need the right opcode and registers.

Conventions:
- Name globals D_XXXXXXXX (char arrays or typed externs) and callees func_XXXXXXXX.
- Model offsets with explicit char padding fields in structs.
- Write C that is also valid C++ (always the `struct` keyword, no classes, references, templates or
  default arguments): it is compiled as C++, but tools also parse it as C.
- Never use goto unless nothing else works.

{project.knowledge()}"""


def text_and_data():
    return project.load_image()


def plain(words):
    for x in words:
        op = x >> 26
        if op in (0x10, 0x12, 0x1C, 0x2F, 0x36, 0x3E, 0x1E, 0x1F):
            return False  # COP0, COP2/VU, MMI, cache, lqc2/sqc2, lq/sq
        if op == 0 and (x & 0x3F) in (0x0C, 0x0F):
            return False  # syscall, sync
    return not other_compiler(words)


def other_compiler(words):
    """True for code built by another compiler (the Sony SDK libraries): its prologue saves the
    callee-saved registers 16 bytes apart, where the game's ee-gcc 2.96 packs them 8 apart."""
    offsets = []
    for x in words[:16]:
        if x >> 26 == 0x3F and (x >> 21) & 31 == 29:  # sd $rt, off($sp)
            rt = (x >> 16) & 31
            if 16 <= rt <= 23 or rt in (30, 31):
                offsets.append(x & 0xFFFF)
    offsets.sort()
    gaps = {b - a for a, b in zip(offsets, offsets[1:])}
    return len(offsets) >= 3 and gaps == {16}


def done_addrs():
    out = set()
    for name in os.listdir(os.path.join(ROOT, "src")):
        m = re.match(r"func_([0-9A-F]{8})\.", name)
        if m:
            out.add(int(m.group(1), 16))
    # Functions written in assembly in the original are not decompilation targets.
    asm_list = os.path.join(ROOT, "config", "asm_functions.txt")
    if os.path.exists(asm_list):
        for line in open(asm_list):
            if line.strip() and not line.startswith("#"):
                out.add(int(line.split()[0], 16))
    return out


def impact():
    """How many functions a match at each address would settle: itself plus its identical copies,
    weighted up a little by how often it is called."""
    groups = {}
    path = os.path.join(ROOT, "build", "groups.json")
    if os.path.exists(path):
        for g in json.load(open(path))["groups"]:
            for a in g:
                groups[int(a, 16)] = len(g)
    calls = {}
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            calls[int(row["address"], 16)] = int(row["calls"])
    return lambda a: groups.get(a, 1) + min(calls.get(a, 0), 50) / 100


def cmd_pick(name, count, max_bytes, seed, order="random", min_bytes=8):
    text_addr, text = match.load_text()
    done = done_addrs()
    # One representative per group of identical functions: the others follow via dedup.
    seen_groups = set()
    group_of = {}
    path = os.path.join(ROOT, "build", "groups.json")
    if os.path.exists(path):
        for i, g in enumerate(json.load(open(path))["groups"]):
            for a in g:
                group_of[int(a, 16)] = i
            if any(int(a, 16) in done for a in g):
                seen_groups.add(i)
    # Functions already tried and given up on wait for a later pass (autoloop.py run --retry-deferred).
    if os.path.exists(LOG):
        for line in open(LOG):
            if line.strip():
                r = json.loads(line)
                if r.get("effort") == "auto" and r.get("matched") is False:
                    done.add(int(r["addr"], 16))
    pool = []
    sizes = {}
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            addr, span = int(row["address"], 16), int(row["max_size"])
            if addr in done or span > max_bytes + 64:
                continue
            g = group_of.get(addr)
            if g is not None:
                if g in seen_groups:
                    continue
                seen_groups.add(g)
            words = match.trim_padding(match.words_at(text_addr, text, addr, span))
            if min_bytes <= len(words) * 4 <= max_bytes and plain(words):
                pool.append(addr)
                sizes[addr] = len(words) * 4
    if order == "small":
        # Smallest first, duplicates' representatives before the rest at equal size.
        score = impact()
        batch = sorted(pool, key=lambda a: (sizes[a], -score(a)))[:count]
    elif order == "impact":
        score = impact()
        batch = sorted(pool, key=lambda a: -score(a))[:count]
    else:
        random.seed(seed)
        batch = sorted(random.sample(pool, min(count, len(pool))))
    os.makedirs(AUTO, exist_ok=True)
    with open(os.path.join(AUTO, f"{name}.txt"), "w") as f:
        f.write("".join(f"{a:08x}\n" for a in batch))
    print(f"{len(batch)} functions picked from {len(pool)} candidates -> build/auto/{name}.txt")


def strings_used(addr, sections):
    """Printable strings at addresses the function builds with lui + addiu/ori/load."""
    asm = match.gnu_asm(addr)
    hi = {}
    found = {}
    for line in asm.splitlines():
        m = re.search(r"\*/\s+(\w+)\s+\$(\w+),\s*(.*)", line)
        if not m:
            continue
        op, reg, rest = m.groups()
        if op == "lui":
            hi[reg] = int(rest, 16) << 16
            continue
        m2 = re.match(r"\$(\w+),\s*(-?0x[0-9A-Fa-f]+)$", rest) or re.match(r"(-?0x[0-9A-Fa-f]+)\(\$(\w+)\)$", rest)
        if not m2:
            continue
        if op in ("addiu", "ori") and m2.re.pattern.startswith(r"\$"):
            base, imm = m2.group(1), int(m2.group(2), 16)
        elif m2.re.pattern.startswith("(-"):
            imm, base = int(m2.group(1), 16), m2.group(2)
        else:
            continue
        if base not in hi:
            continue
        target = hi[base] + imm
        for a, blob in sections:
            if a <= target < a + len(blob):
                end = blob.find(b"\0", target - a, target - a + 200)
                s = blob[target - a:end] if end > 0 else b""
                if len(s) >= 2 and all(32 <= c < 127 or c in (9, 10) for c in s):
                    found[target] = s.decode("ascii")
    return found


def m2c_draft(addr):
    os.makedirs(AUTO, exist_ok=True)
    path = os.path.join(AUTO, f"{addr:08x}.s")
    with open(path, "w") as f:
        f.write(match.gnu_asm(addr))
    res = subprocess.run([sys.executable, M2C, "-t", project.CONFIG["cpu"]["m2c_target"], path], capture_output=True, text=True)
    return (res.stdout or res.stderr).strip()[:6000]


def ask(prompt, model, effort, session=None):
    cmd = ["claude", "-p", "--model", model, "--effort", effort, "--output-format", "json", "--tools", "",
           "--strict-mcp-config", "--system-prompt", SYSTEM]
    if session:
        cmd += ["--resume", session]
    # When launched from inside a Claude Code session, its CLAUDE_*/ANTHROPIC_* variables would
    # point the child CLI at the parent's credentials; use the user's own CLI login instead.
    env = {k: v for k, v in os.environ.items() if not k.upper().startswith(("CLAUDE", "ANTHROPIC"))}
    # A login of its own: sharing ~/.claude with the Claude app makes each one's token refresh
    # invalidate the other's. Log in once with CLAUDE_CONFIG_DIR set to this directory.
    env["CLAUDE_CONFIG_DIR"] = CLI_CONFIG
    t0 = time.time()
    res = subprocess.run(cmd, input=prompt, capture_output=True, text=True, encoding="utf-8", timeout=900, env=env)
    try:
        data = json.loads(res.stdout)
    except json.JSONDecodeError:
        raise RuntimeError(f"claude CLI failed: {res.stdout[:300]} {res.stderr[:300]}")
    if data.get("is_error"):
        raise RuntimeError(f"claude CLI error: {data.get('result')}")
    usage = data.get("usage") or {}
    return {
        "text": data.get("result", ""),
        "session": data.get("session_id"),
        "cost": data.get("total_cost_usd", 0.0),
        "input": usage.get("input_tokens", 0),
        "output": usage.get("output_tokens", 0),
        "cache_read": usage.get("cache_read_input_tokens", 0),
        "cache_write": usage.get("cache_creation_input_tokens", 0),
        "seconds": round(time.time() - t0, 1),
    }


def check(addr, path):
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    out = (res.stdout + res.stderr).strip()
    return res.returncode == 0, out


def mnemonics(addr):
    out = []
    for line in match.gnu_asm(addr).splitlines():
        m = re.search(r"\*/\s+(\S+)", line)
        if m:
            out.append(m.group(1))
    return out


def similar_examples(addr, count=4):
    """The solved functions whose instruction sequences look most like this one."""
    target = mnemonics(addr)
    grams = set(zip(target, target[1:]))
    scored = []
    for name in os.listdir(os.path.join(ROOT, "src")):
        m = re.match(r"func_([0-9A-F]{8})\.(c|cpp)$", name)
        if not m or int(m.group(1), 16) == addr:
            continue
        other = mnemonics(int(m.group(1), 16))
        og = set(zip(other, other[1:]))
        if not og:
            continue
        score = len(grams & og) / len(grams | og) - abs(len(other) - len(target)) / (4 * max(len(target), 1))
        scored.append((score, int(m.group(1), 16), name))
    scored.sort(reverse=True)
    picked, seen = [], set()
    for score, a, name in scored:
        source = open(os.path.join(ROOT, "src", name), encoding="utf-8").read()
        body = re.sub(r"func_[0-9A-F]{8}|D_[0-9A-F]{8}", "", source)
        if body in seen:  # copies of one function teach nothing new
            continue
        seen.add(body)
        picked.append((a, source))
        if len(picked) == count:
            break
    return picked


_names = {}


def rtti_name(addr):
    """Name tools/rtti.py gave the function (class and vtable slot), if any."""
    if not _names:
        path = os.path.join(ROOT, "config", "symbol_addrs.txt")
        if os.path.exists(path):
            for line in open(path):
                parts = line.split("=")
                if len(parts) == 2 and "type:func" in line:
                    _names[int(parts[1].split(";")[0].strip(), 16)] = parts[0].strip()
        _names.setdefault(-1, "")
    return _names.get(addr)


def callee_context(addr):
    """For each function this one calls: its RTTI name and, if solved, its declaration."""
    out = []
    targets = sorted(set(int(t[5:], 16) for t in re.findall(r"func_[0-9A-F]{8}", match.gnu_asm(addr))))
    for target in targets:
        if target == addr:
            continue
        line = f"func_{target:08X}"
        name = rtti_name(target)
        if name:
            line += f" ({name})"
        src = next((n for n in os.listdir(os.path.join(ROOT, "src")) if n.startswith(f"func_{target:08X}.")), None)
        if src:
            text = open(os.path.join(ROOT, "src", src), encoding="utf-8").read()
            m = re.search(r"^[^;{}\n]*\bfunc_%08X\b[^;{]*\)" % target, text, re.M)
            if m:
                line += f": solved, defined as `{m.group(0).strip()}`"
        out.append(line)
    return out


def hints(addr):
    """Facts read straight off the assembly, stated per function (models skip general rules)."""
    text_addr, text = match.load_text()
    words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
    out = []
    if len(words) >= 2:
        tail = [w for w in words if w != 0][-2:]
        if tail and tail[0] >> 26 == 2:  # j target, then the delay slot: a tail call
            target = ((addr & 0xF0000000) | ((tail[0] & 0x03FFFFFF) << 2))
            out.append(f"It ends with a tail call (`j func_{target:08X}`): write "
                       f"`return func_{target:08X}(...);` and give both functions a non-void return type.")
    if any(w >> 26 == 0x11 and ((w >> 21) & 31) in (0x10, 0x11) for w in words):
        out.append("It does floating-point arithmetic: float parameters arrive in $f12, $f13, ... "
                   "and a float result is returned in $f0.")
    return out


def first_prompt(addr, sections):
    strings = strings_used(addr, sections)
    parts = []
    for a, source in similar_examples(addr):
        parts.append(f"Solved example (func_{a:08X}, matches exactly):\n```\n" + match.gnu_asm(a) +
                     "```\n```cpp\n" + source.strip() + "\n```\n")
    facts = hints(addr)
    name = rtti_name(addr)
    if name:
        facts.insert(0, f"RTTI names this function {name} (class and vtable slot from the game's own type info)")
    callees = callee_context(addr)
    if callees:
        facts.append("Functions it calls: " + "; ".join(callees))
    parts += [f"Now the function to write: func_{addr:08X}\n" + "".join(f"- {h}\n" for h in facts),
              "Original assembly:\n```\n" + match.gnu_asm(addr) + "```\n",
              "m2c draft (types and names are guesses):\n```c\n" + m2c_draft(addr) + "\n```\n"]
    if strings:
        parts.append("Strings at addresses the code builds (use them as literals if they fit):\n" +
                     "\n".join(f"  0x{a:08X}: {json.dumps(s)}" for a, s in sorted(strings.items())) + "\n")
    parts.append(f"Write func_{addr:08X} so that it matches.")
    return "\n".join(parts)


def feedback(result):
    lines = result.splitlines()
    head, body = lines[0], [l for l in lines[1:] if l.strip()]
    shown = body[:70]
    more = f"\n... {len(body) - 70} more lines" if len(body) > 70 else ""
    return ("Not yet. Judge output (left: original, right: yours; '!' marks a difference, rN marks a "
            f"relocation):\n{head}\n```\n" + "\n".join(shown) + more + "\n```\nFix it; reply with the full translation unit again.")


def diff_ratio(judge_output):
    m = re.search(r"(\d+) of (\d+) instructions differ", judge_output)
    return int(m.group(1)) / int(m.group(2)) if m else 1.0


def close_enough(judge_output):
    """Worth a pricier try: same length as the original (usually only registers or order differ),
    or at most half of the instructions differ."""
    m = re.search(r"original (\d+), mine (\d+)", judge_output)
    same_length = bool(m) and m.group(1) == m.group(2)
    return same_length or diff_ratio(judge_output) <= 0.5


HAIKU = "claude-haiku-4-5-20251001"
LOCK = threading.Lock()


def schedule(nbytes, model, effort, attempts):
    """The (model, effort) of each attempt. "auto": small functions get one Haiku try first;
    then the main model at low effort; medium effort only while the result is close."""
    if effort != "auto":
        return [(model, effort, False)] * attempts
    plan = [(HAIKU, "low", False)] if nbytes <= 96 else []
    plan += [(model, "low", False), (model, "low", False), (model, "medium", True), (model, "medium", True)]
    return plan[:max(attempts, 1) + (1 if nbytes <= 96 else 0)]


def run_one(addr, sections, attempts, model, effort, log, max_cost=0.40):
    work = os.path.join(AUTO, f"{addr:08x}")
    os.makedirs(work, exist_ok=True)
    nbytes = len(match.trim_padding(match.words_at(*match.load_text(), addr, match.function_span(addr)))) * 4
    session = None
    totals = {"cost": 0.0, "input": 0, "output": 0, "cache_read": 0, "cache_write": 0, "seconds": 0.0}
    prompt = first_prompt(addr, sections)
    matched, last = False, ""
    used = []
    last_cost = 0.0
    for tries, (mdl, level, needs_close) in enumerate(schedule(nbytes, model, effort, attempts), 1):
        if needs_close and not close_enough(last):
            break
        # Stop before an attempt that would likely push the function over its budget.
        estimate = max(last_cost, 0.02) * (3 if used and level != used[-1][1] else 1)  # medium ~3x low
        if used and totals["cost"] + estimate > max_cost:
            break
        if mdl != (used[-1][0] if used else mdl):
            session = None  # a session cannot change model; start over with the full prompt
            prompt = first_prompt(addr, sections) + ("\n\nA previous try was judged:\n" + feedback(last) if last else "")
        used.append((mdl, level))
        reply = ask(prompt, mdl, level, session)
        session = reply["session"]
        last_cost = reply["cost"]
        for k in totals:
            totals[k] += reply[k]
        m = re.search(r"```(?:cpp|c\+\+|c)?\s*\n(.*?)```", reply["text"], re.S)
        source = m.group(1) if m else reply["text"]
        path = os.path.join(work, f"attempt{tries}.cpp")
        with open(path, "w", encoding="utf-8") as f:
            f.write(source)
        matched, last = check(addr, path)
        if matched:
            shutil.copy(path, os.path.join(ROOT, "src", f"func_{addr:08X}.cpp"))
            break
        prompt = feedback(last)
    permuted = False
    if not matched and last and close_enough(last) and used:
        # Near miss: let the permuter search variations on CPU only, no model calls.
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "permute.py"), f"{addr:x}",
                              path, "--seconds", "180", "--jobs", "1"], capture_output=True, text=True)
        if res.returncode == 0:
            matched = permuted = True
    copies = 0
    if matched:
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "dedup.py"), "apply", f"{addr:x}"],
                             capture_output=True, text=True)
        copies = res.stdout.count(": MATCH")
    entry = {"addr": f"{addr:08x}", "bytes": nbytes, "matched": matched, "attempts": len(used),
             "model": model, "effort": effort, "levels": used, "copies": copies, "permuted": permuted,
             **{k: round(v, 4) if isinstance(v, float) else v for k, v in totals.items()},
             "last": last.splitlines()[0] if last else "", "time": time.strftime("%Y-%m-%d %H:%M:%S")}
    with LOCK:
        log.write(json.dumps(entry) + "\n")
        log.flush()
    return entry


def cmd_run(name, attempts, model, effort, retry_deferred=False, jobs=1):
    _, sections = text_and_data()
    batch = [int(l, 16) for l in open(os.path.join(AUTO, f"{name}.txt")) if l.strip()]
    done = done_addrs()
    # Functions the "auto" policy already gave up on are left for a later, richer pass.
    if os.path.exists(LOG) and not retry_deferred:
        for line in open(LOG):
            if line.strip():
                r = json.loads(line)
                if r.get("effort") == "auto" and not r.get("matched", True):
                    done.add(int(r["addr"], 16))
    todo = [(i, a) for i, a in enumerate(batch, 1) if a not in done]
    stop = threading.Event()

    def work(item):
        i, addr = item
        if stop.is_set() or addr in done_addrs():  # a copy may have been matched meanwhile
            return
        try:
            e = run_one(addr, sections, attempts, model, effort, log)
            with LOCK:
                print(f"[{i}/{len(batch)}] {e['addr']} {e['bytes']}B {'MATCH' if e['matched'] else 'no'} "
                      f"in {e['attempts']} ${e['cost']:.3f} {e['seconds']:.0f}s"
                      + (" (permuter)" if e.get("permuted") else "")
                      + (f" +{e['copies']} copies" if e['copies'] else ""), flush=True)
        except Exception as ex:  # keep the batch going; the error is logged
            with LOCK:
                log.write(json.dumps({"addr": f"{addr:08x}", "error": str(ex)[:500],
                                      "time": time.strftime("%Y-%m-%d %H:%M:%S")}) + "\n")
                log.flush()
                print(f"[{i}/{len(batch)}] {addr:08x} ERROR {str(ex)[:200]}", flush=True)
            if "authenticate" in str(ex) or "OAuth" in str(ex):
                stop.set()

    with open(LOG, "a") as log:
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            list(pool.map(work, todo))
    if stop.is_set():
        sys.exit("stopping: the claude CLI is not logged in")


def cmd_report(name=None):
    rows = [json.loads(l) for l in open(LOG) if l.strip()]
    if name:
        wanted = {l.strip() for l in open(os.path.join(AUTO, f"{name}.txt")) if l.strip()}
        rows = [r for r in rows if r["addr"] in wanted]
    ok = [r for r in rows if r.get("matched")]
    tried = [r for r in rows if "matched" in r]
    errors = [r for r in rows if "error" in r]
    cost = sum(r.get("cost", 0) for r in tried)
    tokens = sum(r.get("input", 0) + r.get("output", 0) + r.get("cache_read", 0) + r.get("cache_write", 0) for r in tried)
    print(f"functions tried {len(tried)}, matched {len(ok)}, errors {len(errors)}")
    if tried:
        print(f"cost ${cost:.2f} total, ${cost / len(tried):.3f} per function tried, "
              f"${cost / max(len(ok), 1):.3f} per match")
        print(f"tokens {tokens:,} total, {tokens // len(tried):,} per function tried")
        print(f"attempts per match: {sum(r['attempts'] for r in ok) / max(len(ok), 1):.2f}")
        for key in sorted({(r.get("model"), r.get("effort", "default")) for r in tried}):
            b = [r for r in tried if (r.get("model"), r.get("effort", "default")) == key]
            c = sum(r.get("cost", 0) for r in b)
            print(f"  {key[0]} effort={key[1]}: {sum(r['matched'] for r in b)}/{len(b)} matched, "
                  f"${c / len(b):.3f} per function")
        for lo, hi in ((0, 64), (65, 160), (161, 320), (321, 10000)):
            b = [r for r in tried if lo <= r["bytes"] <= hi]
            if b:
                print(f"  {lo}-{hi} bytes: {sum(r['matched'] for r in b)}/{len(b)}")


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("pick"); p.add_argument("name"); p.add_argument("count", type=int)
    p.add_argument("--max-bytes", type=int, default=160); p.add_argument("--seed", type=int, default=1)
    p.add_argument("--order", choices=["random", "impact", "small"], default="impact")
    r = sub.add_parser("run"); r.add_argument("name"); r.add_argument("--attempts", type=int, default=4)
    r.add_argument("--model", default="claude-sonnet-5")
    r.add_argument("--effort", default="auto", choices=["auto", "low", "medium", "high", "xhigh", "max"])
    r.add_argument("--retry-deferred", action="store_true", help="also retry functions the auto policy gave up on")
    r.add_argument("--jobs", type=int, default=1, help="functions worked on at the same time")
    q = sub.add_parser("report"); q.add_argument("name", nargs="?")
    a = ap.parse_args()
    if a.cmd == "pick":
        cmd_pick(a.name, a.count, a.max_bytes, a.seed, a.order)
    elif a.cmd == "run":
        cmd_run(a.name, a.attempts, a.model, a.effort, a.retry_deferred, a.jobs)
    else:
        cmd_report(a.name)


if __name__ == "__main__":
    main()
