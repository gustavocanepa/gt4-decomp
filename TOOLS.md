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

| Tool | Purpose |
|---|---|
| `project.py` | reads `project.toml`; loads the executable through its loader (cached) |
| `match.py` | `asm`/`gnu` views of an original function; `check` compiles and judges a source |
| `build.py` | full build and SHA-1 comparison with the original; per-function report in `build/full/` |
| `link_diff.py`, `fix_symbols.py` | explain and repair functions that differ after linking |
| `inventory.py` | function inventory from splat (31,164 functions, pointer-only ones included) |
| `dedup_all.py` | propagates every matched function to all its copies |
| `report.py`, `publish_progress.py` | objdiff-format progress report; pushed alone to the `progress` branch, whose workflow uploads it for decomp.dev |
| `rtti.py` | classes from gcc 2.96 RTTI: names, bases, vtables, virtual methods, constructors -> `config/symbol_addrs.txt` |
| `registration.py` | the script engine's class-registration functions: names for the native methods (`config/adhoc_methods.txt`) and the functions themselves from a template; `try ADDR` / `solve -jN`. Handles the parent getter per class, one- and two-callback registrars (null or repeated callbacks included) and global-object registrations (135 functions, 101 of them solved by the tool, 4 left) |
| `families.py` | families of similar functions (identical masked words, or MinHash similarity of 4-gram shingles) ranked by unmatched bytes, with matched members counted -> `build/families.json`; `show ID` lists a family |
| `siblings.py` | unmatched functions that differ from a matched family member only in immediates and addresses: the matched source with those values substituted, kept on MATCH; `scan -jN` / `try MATCHED UNMATCHED` |
| `accessors.py` | the script-bound accessor families (MListBox / MCarGarage / MCarData getters and setters, ~150-500 B each) written from the assembly: a symbolic executor for straight-line code plus templates for the idioms every member shares (handle ctor/dtor, virtual-call argument conversion, result-handle assignment, string build and release), emitted in the original's instruction order so pointer locals, temporaries and call arguments land where the original put them; the struct layout is read from the loads and stores (offset, width, signedness) and written as casts. A few source-level variants are tried in order (constructor returning `this`, store through a temporary, pointer-typed locals). `try ADDR` / `scan -jN [--families 1,2 | --all | --inventory]`; 491 functions (~100 KB) matched, src/ on MATCH |
| `other_compiler.py` | the ~270 functions built by ee-gcc 2.9 (Sony SDK code at 0x3ac140-0x5b9af0, 16-byte save spacing): cpu_solve's draft pipeline and near_fix's fixes run with the `/* compiler: ee-gcc2.9-991111 */` marker on top, so every judge call compiles with that compiler (`list` / `solve -jN` / `stats`). 10 matched; the 208 near misses in build/auto/other/ are ordinary draft problems (flags and the four 2.9 releases give identical code) |
| `stl.py` | the SGI STL instantiations of the library region (gcc 2.96's own headers, copied to include/stl): deduces a `map<basic_string, T>`'s element types from its `_M_insert` (node size, type_info getter, key compare, how the value is copied), writes the same template instantiation for those types with the game's allocator and string, judges it, and looks for the tree's other members by code (insert_unique, hinted insert, _M_erase, _M_copy, erase, operator=...); a member's calls to other instantiations resolve through their gcc 2.96 mangled names, recorded in config/stl_symbols.txt on MATCH. Sources carry `/* compiler: ee-gcc2.96-stl */` (project.toml: include path, -fno-strict-aliasing as the library was built, -fno-implicit-templates so an object holds one member; gcc puts it in `.gnu.linkonce.t.NAME`, which match.py and build.py read as code). `try ADDR [-m MEMBER] [--verify]` / `scan` / `types` / `members` |
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
| `agent_step.py` | the queue driven by AI agents or people: `fill`, `claim`, `prompt`, `try`, `giveup` |
| `cc_wsl.sh` | runs the project's compiler on Linux/WSL from a temporary directory |
| `find_functions.py` | function inventory from call targets |
| `dedup.py` | finds identical functions and propagates matches to them |
| `autoloop.py` | the automated loop above |
| `permute.py` | decomp-permuter bridge for near misses |
| `setup_linux.sh` | one-time Linux/WSL setup: compiler, MIPS binutils, permuter |
| `core2elf.py`, `iso_extract.py`, `find_tags.py`, `scan_text.py` | GT4-specific extraction and inspection |

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
