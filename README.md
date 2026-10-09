# Gran Turismo 4 decompilation

[![Code](https://decomp.dev/gustavocanepa/gt4-decomp.svg?mode=shield&measure=code&label=Code)](https://decomp.dev/gustavocanepa/gt4-decomp)
[![Functions](https://decomp.dev/gustavocanepa/gt4-decomp.svg?mode=shield&measure=functions&label=Functions)](https://decomp.dev/gustavocanepa/gt4-decomp)

A work-in-progress matching decompilation of the Gran Turismo 4 engine (PS2, `CORE.GT4`, NTSC-U
SCUS-97328 v1.01): C++ source that compiles, with the original compiler, to the exact same
instructions as the game. The long-term goal is a native port.

Most of GT4's game logic lives in Adhoc scripts, which
[OpenAdhoc](https://github.com/Nenkai/OpenAdhoc) already re-creates; this project covers the
executable that runs them. Format documentation comes from the
[Gran Turismo Modding Hub](https://nenkai.github.io/gt-modding-hub/).

**This repository contains no game data.** You need your own copy of the game.

## Status

- The executable is understood: retail `CORE.GT4` is raw deflate (no encryption), loading at
  `0x00100000` with entry `0x00100008`; 15,068 functions are reached by calls.
- The compiler is identified: Sony's ee-gcc 2.96 build `001003-1`, `-O2 -G0`; game code is C++.
- A first pilot matched 13 of 20 randomly picked functions by hand; see [PILOT.md](PILOT.md).
- 14% of the functions are exact copies of another; one match settles a whole group.
<!-- progress:start -->
- **Progress (October 2026): 16,685 of 31,128 functions match (53.6%), 27.4% of the code bytes.**
  The live numbers are on the `progress` branch (objdiff report format).
- **The full build reproduces the original executable** (both loaded segments, SHA-1 checked):
  16,311 functions are linked from C/C++ source at their original addresses, and the rest is
  assembled from splat's disassembly of your own executable. 155 more match on their own and
  carry their own constants (`.rodata`), placed at their original addresses from source.
<!-- progress:end -->
- Matched functions are in [`src/`](src/), one file per function, organised as
  `src/<subsystem>/<unit or class>/` and named after the script-engine or RTTI name when one is
  known (`func_ADDR` otherwise; `config/symbol_addrs.txt` and `config/adhoc_methods.txt` map names
  to addresses). Most were produced by AI agents (Claude) driving the tools in [`tools/`](tools/),
  each one verified by the compiler and the judge, never by eye.

## Documentation

What the game code does, as far as the project has established it (each page marks what is inferred or unknown):

- [`knowledge/architecture.md`](knowledge/architecture.md): the engine's subsystems (start-up, Adhoc script VM, game data, UI, race and physics, sound, file system, network, libraries), address ranges, match status and how they connect.
- [`knowledge/classes.md`](knowledge/classes.md): the 509 RTTI classes grouped by subsystem, with parents, instance sizes, vtable sizes and script natives.
- [`knowledge/script-engine.md`](knowledge/script-engine.md): how C++ classes are registered with the Adhoc VM and how scripts call into them, mapped to the community's documentation.
- [`knowledge/runtime-types.md`](knowledge/runtime-types.md): the ref-counted string, handles, allocator, STL containers and object layout seen in the matched code.
- [`knowledge/coverage-map.md`](knowledge/coverage-map.md): what is matched and what is missing, by subsystem; [`knowledge/gt4.md`](knowledge/gt4.md) and [`knowledge/ee-gcc-2.96.md`](knowledge/ee-gcc-2.96.md) cover the compiler side.

## Credits

Started and maintained by **Gustavo Canepa** ([@gustavocanepa](https://github.com/gustavocanepa)),
with AI agents (Anthropic's Claude) doing the bulk of the matching. Thanks to Nenkai and the Gran
Turismo modding community, whose research made the file formats and scripts understandable.

If you use these tools or this work elsewhere, please credit this project (MIT, see [LICENSE](LICENSE)).

This license covers the tools, documentation and the source code written for this project.
Gran Turismo 4 is a trademark of Sony Interactive Entertainment; this project is not affiliated
with or endorsed by Sony Interactive Entertainment or Polyphony Digital. It contains no game data,
and you need your own copy of the game to use it.

## Contributing

Help is welcome: matching functions, naming them, reconstructing structs and classes, or improving
the tools. Start with [CONTRIBUTING.md](CONTRIBUTING.md).

## Setup

Requirements: Python 3.11+ with `rabbitizer` (`pip install rabbitizer`), and Linux or WSL (Ubuntu).

1. Dump your disc and place the image as described in [`orig/README.md`](orig/README.md), then
   extract and convert the executable (commands there).
2. Set up the Linux side once: `bash tools/setup_linux.sh` (compiler, MIPS binutils, permuter).
3. Split the executable with splat (assembly for every function, under `build/splat/`):
   `bash tools/splat.sh` (in WSL/Linux).
4. Check that the full build reproduces your executable: `python tools/build.py`.
5. Build the function list and the duplicate groups:
   `python tools/find_functions.py orig/SCUS-97328/files/CORE.GT4 build/functions.csv` and
   `python tools/dedup.py scan`.

The automated loop (`tools/autoloop.py`) and how to reuse these tools for another game are
described in [TOOLS.md](TOOLS.md).

## Working on a function

```sh
python tools/match.py asm 3951d0                    # show the original
python tools/match.py check 3951d0 src/func_003951D0.c   # compile and compare
```

A function is done when `check` prints `MATCH` and `python tools/build.py` still reproduces the
original (it links every function at its real address and compares SHA-1). Notes on idioms found so far are in
[NOTES.md](NOTES.md) and [PILOT.md](PILOT.md).
