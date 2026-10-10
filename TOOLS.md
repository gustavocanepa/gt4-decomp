# Tools

A pipeline for matching decompilation with a language model, written for GT4 but kept game-agnostic:
everything specific to a game lives in `project.toml`, a loader in `tools/loaders/`, and the
knowledge files in `knowledge/`.

## Pipeline

```
executable ──loader──> code + data sections
     │
     ├─ find_functions.py   function list (targets of jal)            -> build/functions.csv
     ├─ dedup.py scan       groups of identical functions (masked)   -> build/groups.json
     │
     └─ autoloop.py pick    batch: one function per duplicate group, biggest impact first
        autoloop.py run     per function, with --jobs N in parallel:
            1. prompt: assembly (match.py gnu), m2c draft, strings it uses,
               the 2 most similar solved functions, knowledge files
            2. model writes the function (Claude Code CLI, no tools, fresh session)
               Haiku first for small functions, then Sonnet low effort,
               Sonnet medium effort only while the result is close; budget per function
            3. match.py check: compile with the original compiler, resolve every relocation
               to a func_/D_ADDR symbol at its real address, compare word by word; the diff
               (and any "wrong address" symbol) goes back to the model
            4. near miss after the last try -> permute.py (decomp-permuter, CPU only)
            5. on a match: src/func_ADDR.cpp, then dedup.py apply copies it to every
               identical function (each copy re-checked)
        autoloop.py report  matches, cost and tokens per function, by size and by model

splat.sh               splat (config/gt4.yaml) splits your executable: one .s per function
build.py               full build: every matched function linked at its original address into one
                       ELF, the not-yet-decompiled code assembled from splat's output (raw bytes
                       only where splat has no function); passes when both loaded segments hash
                       the same as the original
  ├─ link_diff.py      what differs after linking, per function, disassembled side by side
  └─ fix_symbols.py    repairs functions that reference the wrong address (renames the symbol)
```

A source may name another compiler on its first line (`/* compiler: NAME */`, NAME from the
`[compilers]` tables of project.toml): `project.source_compiler()` reads it, and `match.py check`,
`build.py` (one compile loop per compiler) and the CI (which installs the named compilers from
decomp.me's archive) compile that source with it. Sources without a marker use the game's compiler.

`match.py check` proves one function in isolation; `build.py` proves them all together, with
real addresses. Run the build before every commit: a function only counts once it links.

## Numbers: one source of truth

Every number the project shows comes from the last full build, in this order, and never by hand:

```
build.py  ->  build/full/report.json   per-function status, linked bytes, data placed; and the
                                        provenance: `generated`, `commit`, `dirty`, `partial`,
                                        `orphan_sources`, `duplicate_sources`, the .text/.data SHA-1s
report.py ->  progress/report.json      objdiff format (what decomp.dev reads)
              progress/report.meta.json generation date, the build's commit and hashes, the counts
                                        the README quotes (linked functions, data functions...)
update_readme.py -> README.md           the Status bullets between <!-- progress:start/end -->
publish_progress.py                     runs the two above, then pushes report.json + report.meta.json
                                        to the `progress` branch (date and commit in the message)
```

`publish_progress.py` refuses (and `--check` only tells) unless the build is complete (not
`--limit`), reproduces the original (.text and .data), was made from the commit HEAD points at
with nothing uncommitted under src/, config/, include/ or tools/ then and now, and found no orphan
or duplicated source. So: commit, `build.py`, `publish_progress.py`, commit the README it rewrote.

Two things the build counts as wrong and fails on (`--keep-going` still exits 0): an **orphan
source**, a file under src/ whose name no address claims (a name missing from
config/adhoc_methods.txt or config/symbol_addrs.txt), which the build silently leaves out; and
**two sources for one address**, of which `project.sources` keeps only one (the judge says
"another source stands for ADDR too"). Both happened on 2026-10-09: config/adhoc_methods.txt was
reverted to its pre-rush 1,062 rows while 672 sources and the 143 class-registration functions
(300 KB of code) used the regenerated names, so the registration functions failed to link
("references unnamed-address symbols") and the linked code fell from 30.5% to 27.1% although the
build still hashed like the original. `registration.py names` now merges with the existing file
(a name never disappears; an old spelling stays as an alias), and the build and the publish
report both problems.

Isolation and failure rules of every compile step: each `cc_wsl.sh`, `cc_rf.sh` and
`lines_wsl.sh` call works in its own `mktemp -d`, removes a stale output first and writes the
output through a temporary name only when every stage succeeded (`set -eo pipefail`);
`build.py` reuses `obj/func_ADDR.o` only if `obj/func_ADDR.src` says it was made from the same
source path, compiler and content hash (objects are named by address, so a renamed or
re-addressed file would otherwise link another function's code, as 0x5C3A78 did on 2026-10-09;
mtimes cannot tell), names temporaries per object (`.raw`, `.err`), removes the old object and
record before recompiling and whatever a failed compile or objcopy left, prunes objects whose
source no longer exists before every link, removes the previous report and image before it
starts, and names its WSL step scripts per process; `match.py` names its
objects per call (`build/obj/match_PID_UUID.o`); `permute.py` works in `build/perm/ADDR/run_PID_x/`
and a Linux-side twin removed at exit, and never writes a second source for an address;
`libmatch.py` compiles into `build/libmatch/NAME/obj_PID/` (removed at exit) and replaces the
stable objects `diff` reads only after every file compiled.

| Tool | Purpose |
|---|---|
| `project.py` | reads `project.toml`; loads the executable through its loader (cached) |
| `match.py` | `asm`/`gnu` views of an original function; `check` compiles and judges a source |
| `build.py` | full build and SHA-1 comparison with the original; per-function report in `build/full/` |
| `link_diff.py`, `fix_symbols.py` | explain and repair functions that differ after linking |
| `inventory.py` | function inventory from splat (31,164 functions, pointer-only ones included) |
| `dedup_all.py` | propagates every matched function to all its copies |
| `report.py`, `update_readme.py`, `publish_progress.py` | objdiff-format progress report plus `report.meta.json` (date, commit, hashes, counts) from the last full build; the README's Status bullets written from them; the publish, refused unless the build is complete, reproduces the original and describes HEAD (see "Numbers: one source of truth") |
| `rtti.py` | classes from gcc 2.96 RTTI: names, bases, vtables, virtual methods, constructors -> `config/symbol_addrs.txt` |
| `registration.py` | the script engine's class-registration functions: names for the native methods (`config/adhoc_methods.txt`) and the functions themselves from a template; `try ADDR` / `solve -jN`. Handles the parent getter per class, one- and two-callback registrars (null or repeated callbacks included) and global-object registrations (135 functions, 101 of them solved by the tool, 4 left) |
| `families.py` | families of similar functions (identical masked words, or MinHash similarity of 4-gram shingles) ranked by unmatched bytes, with matched members counted -> `build/families.json`; `show ID` lists a family |
| `siblings.py` | unmatched functions that differ from a matched family member only in immediates and addresses: the matched source with those values substituted, kept on MATCH; `scan -jN` / `try MATCHED UNMATCHED` |
| `accessors.py` | the script-bound accessor families (MListBox / MCarGarage / MCarData getters and setters, ~150-500 B each) written from the assembly: a symbolic executor for straight-line code and structured `if (cond) { ... } [else { ... }]` (nested; arms are regions, the join keeps only registers both paths agree on, a returning arm is dead; plain branches run their delay slot before the `if`, branch-likely delay slots are a copy of the target's first instruction or the else arm's first; a `b` delay slot copied from the join starts the join) plus templates for the idioms every member shares (handle ctor/dtor, virtual-call argument conversion, result-handle assignment, string build and release), emitted in the original's instruction order so pointer locals, temporaries and call arguments land where the original put them; the struct layout is read from the loads and stores (offset, width, signedness) and written as casts. A few source-level variants are tried in order (constructor returning `this`, store through a temporary, pointer-typed locals). `try ADDR` / `scan -jN [--families 1,2 | --all | --inventory]`; 491 functions (~100 KB) matched, +84 with the `if` support (2026-10-09), src/ on MATCH |
| `dtors.py` | destructors and constructors (`X__structor_N`) written from the assembly: a symbolic executor (this/args/float args/constants/this+off/loads/call results/ALU ops; stores and calls emitted in the original's order; forward branches as nested `if`/`if-else` (branch-likely slots = copy of the join's first insn); `while` loops with an entry test, loop-invariant pre-header and `bnel` copy slot; `do-while` (a `for (i = 0; i < n; i++)` variant for gcc's reversed counters); `j` as a tail call; `jalr` through an old-ABI vtable entry `{s16 delta; s16 index; fn}` as an inline vcall helper; locals for loads kept across calls/stores; prototypes from the use; float literals a quarter ulp off, since gcc 2.96 misrounds decimals) plus idioms: inlined basic_string release (`str_release`, interleaved instructions allowed), member helpers chosen by knobs (`member`: string + flag-2 call; `node`: a 16-byte member ending in its release, e.g. STL tree clear+put_node; `block`: an inline clear(); `reset`: `if (p) delete p; p = 0;`; `array`: `if (&arr) { destroy elements }` plus the rest of the member), `retcall`/`vret` return variants, then a search over the order of independent store runs (<= 40 orders, only when <= 12 instructions differ), and the library compiler for 0x5547e8+. `try ADDR [--show]` / `scan [--names]` (deleting dtors: vtable slot 0 of config/classes.json) / `scan --structors [--range=LO-HI] [--part=K/N]`; 2026-10-09: 68 of 72 deleting dtors + 73 other structors matched, src/ on MATCH; scratch build/auto/dtors/. Open: the hObject-ctor family (mCalendar, mFloatConst, DirectivityMicrophone, ~30 at 2-6 off) whose original leaves the epilogue unscheduled (`ld s0; ld s1; ld ra` in save order after the stores) - no source form found (real C++ ctor, inline helpers, store orders, types, volatile, throw()) reproduces it; mDomNode/mActor/mGTShirtPS2 (1-4 off: reg choice, schedule, bgez vs bgezl); big ctors keeping `this+0xF140`-style member pointers; stack temporaries (string builds) give up |
| `other_compiler.py` | the ~270 functions built by ee-gcc 2.9 (Sony SDK code at 0x3ac140-0x5b9af0, 16-byte save spacing): cpu_solve's draft pipeline and near_fix's fixes run with the `/* compiler: ee-gcc2.9-991111 */` marker on top, so every judge call compiles with that compiler (`list` / `solve -jN` / `stats`). 10 matched; the 208 near misses in build/auto/other/ are ordinary draft problems (flags and the four 2.9 releases give identical code) |
| `blockcopy.py` | m2c failures with unaligned `ldl/ldr`, `sdl/sdr` (`lwl/lwr`, `swl/swr`) pairs: each pair is rewritten as one aligned access for m2c, runs of 64-bit loads/stores become `*(BlockN *)dst = *(BlockN *)src`, judged per library profile. Functions whose pairs are right half first (`ldr; ldl`, `right_first`: same access kind and register) are tried only with `ee-gcc2.96-nsa-nosib-rf`, the rest only with the left-first profiles. `queue` / `solve -jN [--list FILE] [--compilers a,b]` / `one ADDR` / `stats`; results in build/auto/blockcopy/. 2026-10-09: 0 matches on the 284 right-first (all PMF-by-value thunks, differ 7 of 7: m2c drops the struct argument) and on 100 of the 130 left-first ones the old filter skipped |
| `cc_rf.sh`, `rf_as.py` | the `ee-gcc2.96-nsa-nosib-rf` compile command: `gcc -S`, rf_as.py expands gcc's `uld/usd/ulw/usw` macros right half first, then `as` (the assembler Sony's library code went through; GNU ee-as expands left first). func_005C2B60 matches with it |
| `stl.py` | the SGI STL instantiations of the library region (gcc 2.96's own headers, copied to include/stl): deduces a `map<basic_string, T>`'s element types from its `_M_insert` (node size, type_info getter, key compare, how the value is copied), writes the same template instantiation for those types with the game's allocator and string, judges it, and looks for the tree's other members by code (insert_unique, hinted insert, _M_erase, _M_copy, erase, operator=...); a member's calls to other instantiations resolve through their gcc 2.96 mangled names, recorded in config/stl_symbols.txt on MATCH. Sources carry `/* compiler: ee-gcc2.96-stl */` (project.toml: include path, -fno-strict-aliasing as the library was built, -fno-implicit-templates so an object holds one member; gcc puts it in `.gnu.linkonce.t.NAME`, which match.py and build.py read as code). Trees with a non-string key whose `_M_insert` cannot be deduced are entered by hand in `KNOWN_TREES` (one member's address -> Spec, e.g. map<HSymID, HValue> from its `_M_copy` 005eeb70) and solved with `try` from that address; `POD_KEYS` names one-word key classes. `try ADDR [-m MEMBER] [--verify]` / `scan` / `types` / `members` |
| `stl_vector.py` | sibling of stl.py for `vector<T>` and the algorithms it calls out of line (fill, fill_n, copy, uninitialized_*): compiles every member once per element shape (scalars, pointer, n-word POD) and allocator (GameAlloc, simple_alloc heap 0x10/0x40) with the type_info getter as a placeholder, searches the image for that code, re-instantiates each hit with the getter it calls and judges it; callees are placed by mangled name as in stl.py. `-c list` does the same for `list<T>` (`_List_base::clear`, insert, erase, operator=, remove/unique/merge/sort...; the allocator tags `_List_node<T>`). `scan [-c vector|list] [-m MEMBER] [-s SHAPE]` / `members` / `shapes` |
| `coverage.py` | matched bytes by subsystem and by translation unit (from `progress/report.json`): the table behind `knowledge/coverage-map.md` |
| `cpu_solve.py` | CPU only: m2c's draft (`--valid-syntax`) compiled and judged as is for every unmatched function; near misses kept for the permuter. `--context types` (or `protos`) adds drafts made with the type database's context (below), the closest draft of all is kept; `--retry --context types --context-only` re-judges the kept draft and adds only the context drafts (resumable: results carry `ctx`), `--shard K/N` splits the queue |
| `types_db.py` | type database rendered as an m2c `--context` file: `build` reads every matched source (the definition's prototype; the majority of the callers' extern declarations for not-yet-matched callees; the types of `D_` globals), the RTTI classes (`config/classes.json`: which class a method belongs to, extended to callees only ever called with a `this`) and the instructions (loads/stores at constant offsets from `this`: a field only when 75% of the accesses agree on one width, `f32` vs int, signedness) -> `build/types_db.json`, `build/types_context.c` (19.6 K prototypes, 16.4 K from definitions; 22.2 K globals; 489 classes with 5.9 K fields). cpu_solve writes a per-function context (its callees, globals, their structs, its own prototype with `this` typed) and prepends the same declarations to the compiled draft. `measure` re-drafts a fixed sample of 400 failures with no context / prototypes only / everything (`build/auto/types_bench/`): prototypes carry nearly all of the gain (48 of 400 closer, 0 farther, 5 newly compiling, 2 matches, all under 128 B; the struct layouts change almost nothing beyond them); over the whole queue (13,553 failed functions up to 2 KB, `--context-only`, ~2.5 h on 2 jobs) 91 matched from the context draft alone (80 under 128 B, 11 of 128-512 B, none over 512 B; 7.7 KB) and 1,274 near misses got closer. `show CLASS` prints a layout with its evidence |
| `patches/m2c-unused-params.patch` | fix for m2c (GPL-3.0, apply to tools/ext/m2c): in `--valid-syntax`, unused leading argument registers become placeholder parameters (m2c's own 431 tests pass) |
| `near_fix.py` | CPU only: near misses fixed by rules read from the judge's diff (exact hex float literals, global addresses written as numbers, commutative operand order) |
| `fragments.py` | CPU only: learns from the matched functions at the level of statements and applies it to m2c's near misses. `lines` compiles every matched source with `-g` (`tools/lines_wsl.sh`; the code is identical with and without it) and maps gcc's stabs line markers to instructions: (normalised instruction pattern -> C statement templates with counts), `build/fragments/dict.json`. `edits` compares m2c's draft of each function matched later with the matched source (return and parameter types, callee prototypes, tail calls, temporaries, casts, structure, literals) and counts (judge-diff signature -> edit kind), `edits.json`. `apply` rewrites each near miss (`build/auto/cpu/`) by the mutations those counts rank first for its diff, judges every candidate and hill-climbs on the number of differing instructions; `src/func_ADDR.c` only on MATCH, `work/ADDR.best.c` when it only got closer. Resumable (`tried.txt`, `results.jsonl`; the kept edits of earlier runs feed back into the ranking), `--sample N --seed S` for a fixed sample (kept in `sample_S_N.txt`), `try ADDR` shows every step, `stats` prints the tables. Dictionary: 3.3 K patterns from 80.8 K statements of 16.5 K sources; edits: 739 near-miss pairs; applied to the 3.7 K near misses of <= 12 instructions: 253 matches (18.3 KB), 1.1 K closer, see knowledge/ee-gcc-2.96.md |
| `local_llm.py` | Local GPU (Ollama): a local coding model rewrites near misses from the assembly, the draft and the diff; `--bench` compares models on a fixed set |
| `permute_cpu.py` | CPU only: decomp-permuter on those near misses, closest first |
| `trivial.py` | solves two-instruction functions from templates, no model |
| `libmatch.py` | third-party libraries from their public source (THIRD_PARTY.md): `scan NAME` compiles the files of `config/libs/NAME.toml` with the game's compiler, finds every function in the image (every 8-byte position of the range, so functions only reached through pointers are found too), learns the address of each symbol they reference and places whole data sections by their layout; `emit NAME` writes one self-contained `src/func_ADDR.c` per function (the file flattened, other functions reduced to declarations, tables to externs at their addresses), kept on MATCH; a source that only matches with the library's own compiler entry (`compiler` in the config, a `[compilers]` table of project.toml) gets the `/* compiler: NAME */` first line; one that needs nothrow stubs for the functions defined earlier waits in `build/libmatch/pending/`; `diff NAME FUNCTION` shows a miss against the original. Expat 1.95.7: 321 of 323 functions match from source, 236 sources in src/ |
| `static_init.py` | static-initialization functions (gcc's `__static_initialization_and_destruction_0`): `try ADDR` / `solve` write one `if (prio == 0xFFFF && init == 1) ctor(&D_x, n);` per store and call read from the assembly, kept only when the judge accepts it (244 functions, 416 KB, no model); the 65 left differ only in one delay-slot decision of the original compiler (see knowledge/gt4.md) |
| `units.py` | proposes translation units from each class's cluster of functions -> `config/units.txt` |
| `asm_policy.py` | rejects assembly posing as C (file-scope asm, `.word`, multi-instruction blocks) |
| `agent_step.py` | the queue driven by AI agents or people: `fill`, `claim`, `prompt` (includes the function's attempts diary), `try`, `giveup` |
| `attempts.py` | the attempts diary, `knowledge/attempts.jsonl` (versioned, one JSON record per attempt: addr, time, who, hypothesis, result, diff/of, file, compiler, source), so agents stop repeating failed ideas. `show ADDR` prints the function's records, its family's records, the closest automatic drafts (cpu_solve, region compilers, fragments, failed model runs, partial score) and the draft files under build/ named with the address; `log ADDR --hypothesis TEXT --result RESULT [--diff N --of M --file F --compiler C --who W]` appends one record and points out similar hypotheses already recorded; `summary` lists the most-attempted unmatched functions; `seed` rebuilds the seeded records (source `seed:...`; everything else is kept) from the open notes of knowledge/*.md, build/auto notes files, failed autoloop/agent runs (build/auto/log.jsonl), near_fix's tried lists and fragments' results. Failed weight: 1 per failed hypothesis by an agent or person, 0.3 per failed automatic tool run |
| `work_queue.py` | the work queue ranked by expected return (`build/queue.json`, top N printed): items are single unmatched functions (one per group of identical copies) and families with >= 3 unmatched members (build/families.json). value = unmatched bytes settled (copies included) x (1 + callers/200, capped); p = chance of a match from the closest draft's differing/total instructions (cpu_solve, region compilers, fragments, model runs) or a size prior, x 0.7 per failed attempt in the diary; cost = size-proportional, cheaper for close drafts, dearer per failed attempt, for library code without a working profile (0x5547e8+), SDK code (ee-gcc 2.9) and VU/MMI/COP code; score = value x p / cost. Each item names an approach: family generator / template from a matched member, rule (near_fix, fragments, permuter) for drafts <= 3 instructions off, sibling template, library source, other compiler, agent or hand work from the best draft. `--top N --kind function|family --min-bytes/--max-bytes --grep TEXT`. (Not `queue.py`: that name would shadow Python's `queue` module for every tool in tools/.) |
| `cc_wsl.sh` | runs the project's compiler on Linux/WSL from a temporary directory |
| `find_functions.py` | function inventory from call targets |
| `dedup.py` | finds identical functions and propagates matches to them |
| `crossgame.py` | takes the matched sources of a sister game (same code base, e.g. GT4 and Tourist Trophy) for functions identical in both: calls and globals moved to this game's addresses, kept on MATCH (`apply --from ../OTHER`) |
| `cpu_cycle.sh` | one CPU-only cycle (m2c drafts, fragments, near_fix, copies, permuter, full build); log in build/auto/cpu_cycle.out |
| `autoloop.py` | the automated loop above |
| `permute.py` | decomp-permuter bridge for near misses |
| `setup_linux.sh` | one-time Linux/WSL setup: compiler, MIPS binutils, permuter |
| `core2elf.py`, `iso_extract.py`, `find_tags.py`, `scan_text.py` | Polyphony CORE extraction (GT4, Tourist Trophy: decryption, inflate, ELF) and inspection |

## Porting to another game

1. **Loader**: add `tools/loaders/<name>.py` with `load(path) -> (entry, [(address, bytes), ...])`
   returning the executable's sections as the game's memory sees them (unpack, decrypt, relocate
   as needed). The section holding the entry point is treated as code.
2. **Compiler**: find the exact compiler build (version strings in the binary help: GT4 carries
   `Libgcc_2_96_ee_001003_1`); decomp.me's compiler archive has most console compilers. Put its
   command line in `project.toml` and calibrate the flags on two or three small functions with
   `match.py check`.
3. **CPU**: set the rabbitizer category, assembler flags, objdump architecture and m2c target.
   The judge currently understands MIPS relocations (PS1, PS2, N64, PSP); other CPUs need their
   relocation types added to `match.py`.
4. **Knowledge**: reuse the compiler's knowledge file if another game used the same compiler, and
   start a new file for the game's own idioms. Every rule found while matching (tail calls,
   argument registers...) goes there, so the model stops repeating the same mistake.
5. Run `find_functions.py`, `dedup.py scan`, then `autoloop.py pick` and `run`.
