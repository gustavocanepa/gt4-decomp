#!/usr/bin/env bash
# Compile one C/C++ file with Sony's ee-gcc 2.96 (build 001003-1), the compiler GT4 was built with.
# Runs on Linux (or WSL); the compiler binaries are 32-bit i386.
# Usage: tools/eecc.sh input.c output.o [extra flags...]   (EE_FLAGS overrides -O2 -G0)
set -e
# The compiler lives on a Linux filesystem (exec bits survive there, unlike on NTFS under WSL):
# unpack decomp.me's ee-gcc2.96.tar.xz into ~/.local/share/gt4/ee-gcc2.96, or set EE_GCC_DIR.
cc="${EE_GCC_DIR:-$HOME/.local/share/gt4/ee-gcc2.96}"
in="$1"; out="$2"; shift 2
flags="${EE_FLAGS:--O2 -G0}"
# Its 32-bit stat() fails on the 64-bit inode numbers of Windows drives mounted in WSL
# ("Value too large for defined data type"), so it only ever sees files under /tmp.
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
src="$work/$(basename "$in")"
cp "$in" "$src"
for dir in include src; do
    [ -d "$(dirname "$0")/../$dir" ] && cp -r "$(dirname "$0")/../$dir" "$work/$dir"
done
(cd "$work" && "$cc/bin/ee-gcc" -c -B "$cc/bin/ee-" $flags -Iinclude "$@" "$src" -o "$work/out.o")
cp "$work/out.o" "$out"
