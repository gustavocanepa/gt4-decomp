#!/usr/bin/env bash
# One-time setup of the Linux side (native Linux or WSL): compiler, MIPS binutils, decomp-permuter.
# Usage: bash tools/setup_linux.sh
set -e
base="$HOME/.local/share/gt4"
mkdir -p "$base"

echo "== packages (MIPS binutils, 32-bit libc for the compiler, python modules for the permuter)"
sudo dpkg --add-architecture i386 2>/dev/null || true
sudo apt-get update -qq
sudo apt-get install -y -qq binutils-mips-linux-gnu libc6:i386 python3-toml python3-levenshtein >/dev/null

echo "== ee-gcc 2.96 (decomp.me build)"
if [ ! -x "$base/ee-gcc2.96/bin/ee-gcc" ]; then
    mkdir -p "$base/ee-gcc2.96"
    curl -sL https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.96.tar.xz \
        | tar -xJ -C "$base/ee-gcc2.96"
fi
"$base/ee-gcc2.96/bin/ee-gcc" --version | head -1

echo "== decomp-permuter"
if [ ! -d "$base/decomp-permuter" ]; then
    git clone -q --depth 1 https://github.com/simonlindholm/decomp-permuter "$base/decomp-permuter"
fi
python3 "$base/decomp-permuter/permuter.py" --help >/dev/null && echo "permuter ok"
