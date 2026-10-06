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
            3. match.py check: compile with the original compiler, compare instruction by
               instruction (relocated fields: opcode and registers only); diff goes back to
               the model
            4. near miss after the last try -> permute.py (decomp-permuter, CPU only)
            5. on a match: src/func_ADDR.cpp, then dedup.py apply copies it to every
               identical function (each copy re-checked)
        autoloop.py report  matches, cost and tokens per function, by size and by model
```

| Tool | Purpose |
|---|---|
| `project.py` | reads `project.toml`; loads the executable through its loader (cached) |
| `match.py` | `asm`/`gnu` views of an original function; `check` compiles and judges a source |
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
