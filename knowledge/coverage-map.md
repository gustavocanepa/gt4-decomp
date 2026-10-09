# Coverage map (2026-10-08)

What is matched and what is missing, by logic rather than by address. Numbers from
`python tools/coverage.py` (progress/report.json before this session's matches, 15,851 functions /
1.13 MB) and `python tools/families.py`; unit names come from config/units.txt (RTTI class
clusters), unnamed clusters are `unit_<first address>`.

## By subsystem

| subsystem | units | functions done/total | bytes matched/total | missing |
|---|---|---|---|---|
| unnamed clusters (`unit_*`, no RTTI) | 344 | 7,596 / 18,222 | 0.79 / 3.85 MB (20.6%) | 3.06 MB |
| UI faces (`m*`: mSceneViewFace, mListBox, mFlashFace...) | 180 | 2,000 / 3,416 | 102 / 497 KB (20.5%) | 395 KB |
| STL, C++ runtime, libc (0x596fa0 and up) | 49 | 4,607 / 6,365 | 162 / 522 KB (31.1%) | 360 KB |
| race simulation (Race*, Car*, Dynamics*) | 123 | 767 / 1,592 | 27 / 234 KB (11.6%) | 207 KB |
| engine handles (`h*`: hString, hInt...) | 34 | 610 / 982 | 32 / 121 KB (26.7%) | 89 KB |
| other named classes | 44 | 222 / 475 | 13 / 78 KB (16.3%) | 65 KB |
| script-bound model classes (`M*`) | 8 | 49 / 76 | 2 / 7 KB | 6 KB |

Done or nearly done: the compiler-generated families. Static initialisation (244 of 309, the rest
parked: one delay-slot decision, see gt4.md), the script-engine class registrations (131 of 135
after this session, 300 KB -> 43 KB left), two-instruction functions, m2c drafts that compile as
is. Matched functions are mostly small: 50.9% of functions but 21.3% of bytes.

## The big unnamed clusters (where the bytes are)

| unit | range | functions done/total | bytes done/total | what it is (strings, shape) |
|---|---|---|---|---|
| unit_00494578 | 0x494578-0x54db98 | 837 / 3,689 | 39 / 755 KB (5%) | network stack: XML parser (xmlns, CDATA, ENTITY), GameSpy (gsSHA alphabet), SCEA online; C code, 55% of functions <= 128 B; gt4.md's "GameSpy lock guard" 004f47f0 is here |
| unit_0046A050 | 0x46a050-0x4944b0 | 309 / 1,033 | 17 / 173 KB (10%) | image/format code: JFIF, Deflated/Inflator (zlib-style C++), replay "getDate", units |
| unit_004271E8 | 0x4271e8-0x44d3f0 | 677 / 1,452 | 33 / 155 KB (21%) | race front end glue: camera, skinning, snapshot paths, RaceBasic; 79% tiny functions (accessors) |
| unit_00101400 | 0x101400-0x124178 | 262 / 584 | 40 / 142 KB (28%) | game-mode menus (labomode, race-end, option), script callbacks |
| unit_001DC8F0 | 0x1dc8f0-0x1fc448 | 185 / 373 | 20 / 130 KB (15%) | online menus (MNetwork::login, account names), car record lists |
| unit_0017FCB0 | 0x17fcb0-0x19b3a0 | 102 / 306 | 23 / 113 KB (21%) | photo mode (mPhotoMapWindow, MODE_SAVE_PHOTO_FILM), camera |
| unit_0034E9A0 | 0x34e9a0-0x363b10 | 136 / 361 | 4 / 89 KB (5%) | suspension/physics (Bound/Rebound), almost no strings: float math |
| unit_005676B0, unit_005547E8 | 0x5547e8-0x57a058 | 353 / 1,044 | 15 / 153 KB (10%) | stream/socket library (iostream, "corrupted stream", nb_ctl, %u.%u.%u.%u): library C++ |
| unit_0057A128, unit_0059BE80 | 0x57a128-0x5bfb00 | 181 / 1,268 | 6 / 251 KB (2%) | libc/libstdc++ (ostream, istdiostream, (null)); 267 functions have the Sony-SDK prologue (other compiler) |
| unit_00415E90, unit_003F7150, unit_00364818 | 0x364818-0x4074f0, 0x415e90-0x426600 | 239 / 759 | 9 / 188 KB (5%) | no strings at all: vehicle dynamics / VU-side math (0x4a4550 scratchpad base pattern is nearby) |

Library vs game: everything from 0x5547e8 up is library (streams, GameSpy transport, libc,
libstdc++, SDK), about 1.2 MB of .text, of which the SGI STL templates (rb-tree, vector, list
members per element type) are the only part that matches with our compiler flags (gt4.md: the
libraries free stack temporaries per statement, we do not; the Sony SDK parts have another
compiler's prologue). The network stack at 0x494578-0x54db98 is C, compiled with the game's
flags, and should match once drafted as C (m2c already matches short C functions there).

## Where the next tools should aim

1. Families with a matched member (tools/families.py, then tools/siblings.py for the
   immediate-only ones): MListBox/MCarGarage/MCarData getter families (ids 1-5, 13, 19: 300
   functions, 80 KB, 150-500 B each). The siblings differ in registers as well as constants, so
   the next step is a template with the struct layout as the variable, not text substitution.
2. The 10 mSceneViewFace event virtuals (family 9: 6 KB) and similar `m*Face` virtual runs:
   one solved member each, differing in a flag bit and an event-name string.
3. Static-init leftovers (65 functions, 22 KB): only if the delay-slot decision becomes
   predictable (reorg.c in the ee-gcc source would settle it); otherwise leave them.
4. The physics and dynamics clusters (unit_0034E9A0, unit_00415E90, unit_003F7150: 280 KB,
   5% done): float code with no strings, the right target for the model with the float rules in
   ee-gcc-2.96.md, not for templates.
5. The network C code (unit_00494578, 755 KB): C, flat, many tiny functions; m2c drafts plus
   near_fix.py are the cheapest path, then the model for the XML/GameSpy state machines.
