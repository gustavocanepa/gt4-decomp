---
name: gt4-decomp
description: Compact orientation for working on the Gran Turismo 4 matching decompilation in ../GT4 — the judge, compilers, source layout, tools by purpose, the rules, and which knowledge file answers which question. Load this first in any GT4 decomp task instead of reading all of TOOLS.md and knowledge/.
---

# GT4 decomp in five minutes

**Goal:** C/C++ in `src/` that compiles, with the original compiler, to byte-identical code. A
function counts only when the judge says MATCH and the full build still hashes like the original.

## The judge and the build
- `python tools/match.py check ADDR FILE` → `MATCH` or a side-by-side diff (`!` = differing
  instruction; left original, right yours). `python tools/match.py asm ADDR` shows the original.
- Never weaken the judge (it rejects references to the object's own .bss/.data and inline asm).
- Full proof: `python tools/build.py --keep-going --jobs 2` must print `.text OK` and `.data OK`.
  Never run two builds at once (check `Get-CimInstance Win32_Process` and
  `wsl -e sh -c "ps aux | grep build.py"` first).

## Compilers (first-line marker `/* compiler: NAME */`, entries in project.toml)
- default: ee-gcc 2.96 `-O2 -G0 -fno-exceptions` — the game's own code (mostly C++).
- `ee-gcc2.96-no-strict-aliasing` — Sony's libraries (libstdc++ basic_string, expat, most of the
  library region 0x5547e8+). Try it first on any library near miss.
- `ee-gcc2.96-stl` — SGI STL template instantiations (`include/stl`, tools/stl.py).
- `ee-gcc2.9-991111` — ~270 SDK functions saving registers 16 bytes apart (tools/other_compiler.py).
- Hand-written assembly (MMI strlen, kernel stubs) is listed in config/asm_functions.txt: not a target.

## Where things are
- Sources: `src/<subsystem>/<unit or class>/NAME.c|cpp` (tools/layout.py; new files may sit flat
  in src/ — `python tools/organize.py` moves them). Names ↔ addresses: config/symbol_addrs.txt.
- Drafts and results of the CPU tools: build/auto/cpu/ (results.jsonl), build/auto/*.
- Never touch orig/ (the user's game files); never commit game data.

## Before and after every function: the attempts diary
- Choose work with `python tools/work_queue.py --top 30` (expected bytes recovered / expected cost,
  with a suggested approach per item; families first when a generator pays more than one function).
- Before touching a function: `python tools/attempts.py show ADDR` (every hypothesis already tried,
  the family's diary, the closest automatic drafts and the draft files under build/). Do not repeat
  a recorded failed idea; if you have nothing new, pick another item.
- After each judged hypothesis, matched or not: `python tools/attempts.py log ADDR --hypothesis
  "what you changed and why" --result match|differs|worse|no-change|no-compile|abandoned --diff N
  --of M [--file PATH] [--compiler NAME] --who YOUR_NAME`. One line per idea, specific enough that the
  next agent can tell whether its idea is the same. knowledge/attempts.jsonl is versioned.

## Tools by purpose (details in TOOLS.md)
- Drafts: `cpu_solve.py` (m2c with EE register names, compile_fix, variants, `--context types`),
  `types_db.py` (prototypes/globals/layouts context), `fragments.py` (learned statement edits),
  `near_fix.py` (diff rules), `permute_cpu.py` (decomp-permuter), `region_compiler.py` (a range
  with another compiler).
- Families/generators: `families.py`, `static_init.py`, `registration.py`, `accessors.py`,
  `siblings.py`, `stl.py`, `libmatch.py` (third-party code from public source, THIRD_PARTY.md).
- Sister game (../TT, same tools): `crossgame.py apply --from ../TT` copies the sources
  of identical functions; `neartwin.py scan|apply --from ../TT` adapts the sources of near twins
  (offsets, constants, callees, globals, call order, store order, profile; `try ADDR OTHER` shows
  the steps). Every shared match counts for both games: run these before hand work.
- Planning: `work_queue.py` (ranked work items), `attempts.py` (show/log/summary of the diary).
- Diagnosis: `census.py` (why functions fail, ranked), `compiler_probe.py`, `coverage.py`.

## Recipes that worked (read the knowledge section before re-deriving)
- Repeated code → understand one member, write a generator (static_init, registration, accessors).
- Library code → find the exact public source of the era (GCC 2000-10-03 tree at
  the gcc 2000-10-03 snapshot (../gcc-20001003, outside the repository): libstdc++/std/bastring.*, libstdc++/stl/), keep the library's own
  inline helpers nested as in its headers (each inline level shows in the register choice), and
  compile with -fno-strict-aliasing.
- Near misses → group failures by diff kind (census.py), turn the biggest group into a rule.
- m2c: always feed match.m2c_asm (EE names: $8-$11 are arguments 5-8); write float literals in hex.

## Knowledge map (read only the part you need)
- knowledge/ee-gcc-2.96.md — compiler rules (how C shapes compile).
- knowledge/gt4.md — project rules: C++/STL/string/handles/registration, open problems.
- knowledge/architecture.md, classes.md, script-engine.md, runtime-types.md — what the game code is.
- knowledge/gthd.md — real method names/prototypes from Gran Turismo HD (tools/gthd_names.py),
  its source files as GT4 translation units and its global names (tools/gthd_units.py).
- knowledge/coverage-map.md — what is matched and missing, by unit.
- knowledge/attempts.jsonl — every attempt per function (read it with tools/attempts.py show ADDR).

## Rules for agents
- English for all code and docs, in the existing style. Byte-exact only; new sources only on MATCH.
- `attempts.py show ADDR` before working on a function, `attempts.py log ADDR ...` after every judged
  hypothesis (also the failed ones: they are the point). Stop on a function after ~10 failed
  hypotheses of your own and log `abandoned` with what is left to try.
- Foreground commands only: never background/detached processes or anything that opens console
  windows (it froze the user's PC once). At most 2 parallel jobs; keep > 4 GB RAM free.
- Do not commit or push (the main session reviews, builds and commits).
- Third-party code goes in only with a redistributable licence and a THIRD_PARTY.md entry.
