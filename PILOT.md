# Matching pilot (2026-10-06)

Question: can GT4's engine be decompiled to byte-identical C/C++, and at what cost per function?

## Setup

- Compiler: Sony ee-gcc 2.96, build `001003-1`, the exact build named in the executable
  (`Libgcc_2_96_ee_001003_1`). Flags `-O2 -G0`.
- Game code is **C++** (`cc1plus`): two functions matched only once compiled as C++ (tail calls are
  not turned into jumps there). Plain C still matches leaf code.
- Judge: `tools/match.py` compiles one function and compares it instruction by instruction with the
  original; words carrying a relocation are compared on opcode and registers only.
- Sample: 20 functions drawn at random (seed 4) from four size buckets, five each, among functions
  using only ordinary instructions (no COP0/COP2/VU, MMI, `syscall`, `cache`, `lq`/`sq`).
- Budget: at most two rounds (write, compile, compare) per function, as a first pass.

## Results

| Bucket | Function | Bytes | Result | Rounds | Note |
|---|---|---:|---|---:|---|
| 32-64 | 0x003951D0 | 48 | match | 1 | |
| | 0x003F4080 | 40 | match | 1 | `cell[row][col]` |
| | 0x0025BA68 | 56 | match | 1 | addresses of float arguments |
| | 0x00445AB8 | 48 | match | 1 | |
| | 0x00485CA8 | 44 | match | 2 | needed an inline helper |
| 65-160 | 0x00345450 | 88 | match | 1 | |
| | 0x00265C80 | 128 | match | 3 | virtual call; matched with the real strings: `printf("status %s\n", ...)` |
| | 0x00208F70 | 72 | match | 1 | |
| | 0x00146528 | 112 | match | 2 | C++ |
| | 0x0051B968 | 80 | pending | 2 | register allocation |
| 161-320 | 0x001F6300 | 168 | match | 2 | C++; length-prefixed strings |
| | 0x00377BE0 | 184 | match | 2 | 64-byte struct copy |
| | 0x0053E990 | 192 | pending | 2 | 5 instructions off (store order) |
| | 0x00563A60 | 312 | match | 1 | |
| | 0x003ECE90 | 232 | match | 2 | virtual call on a 0x12000-byte object |
| 321-640 | 0x004C5BF8 | 336 | pending | 2 | same length, scheduling differs |
| | 0x003F40F8 | 472 | pending | 2 | same length; needs `sqrt.s` inline asm, branch layout differs |
| | 0x005ECE38 | 456 | deferred | 0 | STL template code: needs gcc 2.96's STL first |
| | 0x0030D390 | 384 | deferred | 0 | inlined ref-counted string class: needs that class first |
| | 0x0039A908 | 608 | not tried | 0 | |

- **13 of 20 matched** in the first pass; **13 of 15** up to 320 bytes.
- Large functions: none within two rounds, but the two attempted reached the original length, which
  usually means a few more rounds of statement-order changes.
- Two of the five large ones depend on shared library code (STL, the string class). Reconstructing
  those once unlocks every function that inlines them.

## What the pilot taught

- Function sizes from `jal` targets glue functions only called through pointers onto the previous
  one (seen three times). The judge now notices when my code returns early, but the inventory needs
  a second pass (pointers in data, vtables) to list those functions.
- Reading the strings an address points to is worth doing first: it gave the exact source of one
  function and names what the code is about.
- Recurring idioms: length stored 16 bytes before string text; old g++ vtables
  (`{short delta; short index; fn}` entries); `sqrt.s` inline asm; full-width EUC digits.

## Scale

15,068 functions are reached by `jal`; 10,602 of them are 256 bytes or less (median 128).
Each matched small or medium function took one to three rounds. Before estimating cost for the whole
executable, the next steps are the ones that change that cost the most: the STL and string class
headers, a function list that includes pointer-only functions, and an automated loop
(m2c draft, compile, compare, retry) instead of hand-driven rounds.
