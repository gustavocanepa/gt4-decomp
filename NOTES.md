# Gran Turismo 4 decompilation: working notes

Goal: a matching decompilation of the GT4 engine (`CORE.GT4`), leading to a native PC port.
Game logic lives mostly in Adhoc scripts, which [OpenAdhoc](https://github.com/Nenkai/OpenAdhoc)
already re-creates; this project covers the executable. No game files are ever committed.

## Step 1: the executable (2026-10-06)

- Disc: SCUS-97328 v1.01 (`SYSTEM.CNF`: `VER = 1.01`, `VMODE = NTSC`). Root: `SCUS_973.28` (273 KB
  bootstrap), `CORE.GT4` (2.0 MB), `IOPRP300.IMG`, `IRX/`, `NET/`, `EPSON/`, `GT4.VOL` (2.46 GB of data).
- `CORE.GT4` (retail, no encryption layer): `u16 flags = 0x0101`, `u32 size = 6119116`, raw deflate.
  Decompressed: two 128-byte hashes, entry `0x00100008`, three sections:
  - `0x00100000..0x00617a14` (5.34 MB, code and data)
  - `0x00617a80..0x006d5dfc` (779 KB)
  - `0x006179fc..0x00617a14` (24 bytes, an identical copy of the first section's tail; dropped)
- Compiler: the binary carries `Libgcc_2_96_ee_001003_1`, i.e. Sony's **ee-gcc 2.96** (build
  001003) from the PS2 SDK, the compiler other PS2 decompilations already reproduce. A matching
  (byte-identical) decompilation should therefore be possible.
- 41 CVS `$Header$` tags, all from Sony's Medius/DME network middleware (`dme_client`, `rt_crypt`,
  `rt_udp`, `rt_upnp`, `rt_util`, ...), dated 2003-2004: they mark third-party units, not
  Polyphony's own code. (`tools/find_tags.py` lists them.)

## Step 2: compiler and pilot (2026-10-06)

- `tools/find_functions.py`: 15,068 functions reached by `jal` in the code section.
- `tools/eecc.sh`: ee-gcc 2.96 under WSL (unpacked on the Linux filesystem; sources are copied to
  /tmp because the 32-bit compiler cannot stat files on mounted Windows drives).
- `tools/match.py`: instruction-by-instruction judge. Flags `-O2 -G0`; game code is C++.
- Pilot: 13 of 20 random functions matched within two rounds; see PILOT.md. Sources in `src/`.

## Next
- Second inventory pass: functions only reached through pointers (vtables, tables in data).
- Reconstruct the shared code that gets inlined everywhere: gcc 2.96 STL, the string class.
- Automate the loop (m2c draft, compile, compare, retry) and measure cost per function.
- Map names from the GT HD prototype symbols onto GT4 functions.
