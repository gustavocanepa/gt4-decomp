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
| `coverage.py` | matched bytes by subsystem and by translation unit (from `progress/report.json`): the table behind `knowledge/coverage-map.md` |
| `cpu_solve.py` | CPU only: m2c's draft (`--valid-syntax`) compiled and judged as is for every unmatched function; near misses kept for the permuter |
| `patches/m2c-unused-params.patch` | fix for m2c (GPL-3.0, apply to tools/ext/m2c): in `--valid-syntax`, unused leading argument registers become placeholder parameters (m2c's own 431 tests pass) |
| `near_fix.py` | CPU only: near misses fixed by rules read from the judge's diff (exact hex float literals, global addresses written as numbers, commutative operand order) |
| `local_llm.py` | Local GPU (Ollama): a local coding model rewrites near misses from the assembly, the draft and the diff; `--bench` compares models on a fixed set |
| `permute_cpu.py` | CPU only: decomp-permuter on those near misses, closest first |
| `trivial.py` | solves two-instruction functions from templates, no model |
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
