# Gran Turismo 4 decompilation

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
- **2,903 of 14,665 functions (19.8%) match byte for byte.** Matched functions are in [`src/`](src/).
  Most were produced by AI agents (Claude) driving the tools in [`tools/`](tools/), each one verified
  by the compiler and the judge, never by eye.

## Credits

Started and maintained by **Gustavo Canepa** ([@gustavocanepa](https://github.com/gustavocanepa)),
with AI agents (Anthropic's Claude) doing the bulk of the matching. Thanks to Nenkai and the Gran
Turismo modding community, whose research made the file formats and scripts understandable.

If you use these tools or this work elsewhere, please credit this project (see [LICENSE](LICENSE)).

## Contributing

Help is welcome: matching functions, naming them, reconstructing structs and classes, or improving
the tools. Start with [CONTRIBUTING.md](CONTRIBUTING.md).

## Setup

Requirements: Python 3.11+ with `rabbitizer` (`pip install rabbitizer`), and Linux or WSL (Ubuntu).

1. Dump your disc and place the image as described in [`orig/README.md`](orig/README.md), then
   extract and convert the executable (commands there).
2. Set up the Linux side once: `bash tools/setup_linux.sh` (compiler, MIPS binutils, permuter).
3. Build the function list and the duplicate groups:
   `python tools/find_functions.py orig/SCUS-97328/files/CORE.GT4 build/functions.csv` and
   `python tools/dedup.py scan`.

The automated loop (`tools/autoloop.py`) and how to reuse these tools for another game are
described in [TOOLS.md](TOOLS.md).

## Working on a function

```sh
python tools/match.py asm 3951d0                    # show the original
python tools/match.py check 3951d0 src/func_003951D0.c   # compile and compare
```

A function is done when `check` prints `MATCH`. Notes on idioms found so far are in
[NOTES.md](NOTES.md) and [PILOT.md](PILOT.md).
