# Setup walkthrough

A tested, step-by-step version of **Setup** in [README.md](README.md), with every place a first
build got stuck and what fixed it. The proof is the same as for any change: `python tools/build.py`
prints `.text OK` and `.data OK`.

| Path | Status |
|---|---|
| Ubuntu 24.04 in Distrobox on Arch Linux (Omarchy 4.0.6) | tested 2026-10-25 at `b1e5cc1f6efc`, full build OK |
| Windows + WSL (Ubuntu) | **not tested yet**, see [the end of this file](#windows--wsl-not-tested-yet) |

Measured times below are from that run (one machine, x86_64, `--jobs 2`); expect different numbers
on other hardware.

## 1. Ubuntu container (Arch-based hosts only)

`tools/setup_linux.sh` uses `apt` and `dpkg`, so on a distribution without them run the project
inside an Ubuntu container. Distrobox shares your home directory with the container, so the clone
and the disc image can stay where they are.

```sh
sudo pacman -S --needed distrobox podman
distrobox create -n gt4 -i docker.io/library/ubuntu:24.04
distrobox enter gt4
```

The first `distrobox enter` installs Ubuntu's base packages (77 s). It may print that it cannot
turn `/etc/resolv.conf` into a symlink (`Device or resource busy`): the container mounts that file
from the host, and the warning is harmless. Every following step runs inside the container.

On Ubuntu or Debian itself, skip this section.

## 2. Packages, clone and Python

```sh
sudo apt update && sudo apt install -y git curl xz-utils python3 python3-venv python3-pip
git clone https://github.com/gustavocanepa/gt4-decomp && cd gt4-decomp
python3 -m venv .venv && . .venv/bin/activate
pip install rabbitizer
pip install toml Levenshtein pynacl
```

Ubuntu 24.04 marks its system Python as externally managed, so the walkthrough uses a virtual
environment. Keep it active for every step below (`. .venv/bin/activate` in each new shell).

**Permuter modules.** `tools/setup_linux.sh` installs them (`toml Levenshtein pynacl`, the
[decomp-permuter README](https://github.com/simonlindholm/decomp-permuter)'s prerequisite list) into its own
venv at `~/.local/share/gt4/venv` and runs the permuter check with that venv's Python, so the check
passes or the script stops with `permuter check failed`; it no longer exits 0 after a
`ModuleNotFoundError`.

## 3. Disc image and executable

Place your own dump as described in [`orig/README.md`](orig/README.md); a symlink works and leaves
the image where it is:

```sh
mkdir -p orig/SCUS-97328
ln -s "/path/to/Gran Turismo 4 (USA).iso" "orig/SCUS-97328/Gran Turismo 4 (USA) (v1.01).iso"
python tools/iso_extract.py "orig/SCUS-97328/Gran Turismo 4 (USA) (v1.01).iso" CORE.GT4 SYSTEM.CNF SCUS_973.28 -o orig/SCUS-97328/files
python tools/core2elf.py orig/SCUS-97328/files/CORE.GT4 orig/SCUS-97328/CORE.GT4.elf
sha1sum orig/SCUS-97328/files/CORE.GT4 orig/SCUS-97328/files/SCUS_973.28 orig/SCUS-97328/CORE.GT4.elf
```

Compare the three hashes with the table in [`orig/README.md`](orig/README.md) (under a second).

## 4. Compilers, binutils, permuter and splat

```sh
bash tools/setup_linux.sh
```

This installs the MIPS binutils, the 32-bit libc, ee-gcc 2.96 under `~/.local/share/gt4/ee-gcc2.96`,
every compiler profile, decomp-permuter and splat. Check that its output has both `permuter ok` and `splat 0.50.1`
(or later).

`setup_linux.sh` also installs every compiler profile of `project.toml` (`tools/install_compilers.py`,
the same script `.github/workflows/check.yml` runs with `--used src`): the ee-gcc 2.9 and 2.96 copies
under `~/.local/share/gt4/compilers/` and the ee-gcc 3.2 assembler some profiles need. Sources whose
first line is `/* compiler: NAME */` use the profile `NAME`, and cannot be compiled without it. Run
`python3 tools/install_compilers.py` again at any time; directories already installed are left alone.

## 5. Split, function list and full build

```sh
bash tools/splat.sh
python tools/find_functions.py orig/SCUS-97328/files/CORE.GT4 build/functions.csv
python tools/build.py --jobs 2
bash tools/run_tests.sh
```

- `splat.sh` (43 s) writes one `.s` per function under `build/splat/`. splat 0.50.1 prints
  `Error: Unable to determine a segment for the following user-declared symbols.` for
  `D_006D6050`, `D_0083F5C8`, `D_0083F5E8` and `D_00846468`; it still exits 0 and the build is
  unaffected.
- **Stuck point: `build/functions.csv`.** `build.py` reads it at start-up and fails with
  `FileNotFoundError: ... build/functions.csv` on a fresh checkout, so `find_functions.py` comes
  before the build (under a second, 15,068 functions).
- `build.py` compiled 30,157 sources and linked 29,995 functions in 867 s, with `--jobs 2` (the
  limit in `.claude/skills/gt4-decomp/SKILL.md`). It ends with
  `.text OK  sha1 28422e7e20a6298224294255355487b9a22cef31` and `.data OK`; `build/full/report.json`
  records the commit, `partial: false`, and the SHA-1 of both segments.
- `run_tests.sh`: 108 tests, all passing.

From installing the host packages to the build proof: 19 minutes, most of it the build.

## Windows + WSL (not tested yet)

Nobody has run this walkthrough on WSL yet. Steps 2 to 5 are expected to apply as they are inside
an Ubuntu 24.04 WSL distribution (`wsl --install -d Ubuntu-24.04`), without step 1. If you run it,
replace this section with what you did, how long each step took and where you got stuck.
