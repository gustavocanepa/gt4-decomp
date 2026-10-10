#!/usr/bin/env python3
"""Full build: link every matched function at its original address into one ELF and compare the
result with the original executable, byte for byte.

    build.py [--jobs 4] [--keep-going] [--limit N] [--compile-only]

Every function source under src/ (project.sources: flat src/func_ADDR.* or organized by
tools/layout.py) is compiled with the game's compiler and linked, with the real addresses of
everything it references (tools/symbols.py: func_/D_ names and the real names alike), into a
single ELF. Code that is not decompiled yet is taken from your own
executable (`.incbin` of the original bytes, never committed), so the image is complete from day
one and shrinks to pure source as functions are matched. The build passes when both loaded segments
hash the same as the original's.

This closes the gap left by match.py, which compares one function at a time and, for words that
carry a relocation, only the opcode and registers: here every relocation is resolved by the linker,
so a function that points at the wrong global fails.

Outputs (all in build/full/): BASENAME.elf (project.toml), report.json (per-function status) and, on the screen, a
summary plus every function that does not survive the link.
"""
import argparse
import csv
import datetime
import glob
import hashlib
import json
import os
import re
import struct
import subprocess
import sys

import match
import project
import symbols

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "full")
WSL_DIR = f"$HOME/.local/share/{project.BASENAME}/full"
ELF = project.path(project.CONFIG["game"]["elf"])
IMAGE = f"{project.BASENAME}.elf"
SYMBOL = symbols.GENERIC  # the generic names; symbols.address_of resolves the real names too
# Sections a compiled function may bring along without changing the image.
HARMLESS = {".text", ".reginfo", ".mdebug", ".mdebug.eabi64", ".comment", ".pdr", ".gnu.attributes",
            ".note.GNU-stack", ".eh_frame", ".gcc_except_table"}


# gcc 2.96 puts a local symbol for .eh_frame after the globals, which modern ld rejects; the image
# carries no debug or unwind data from these objects, so both are dropped after compiling.
STRIP = "-R .eh_frame -R .rel.eh_frame -R .mdebug -R .mdebug.eabi64"


SPLAT_DIR = os.path.join(ROOT, "build", "splat", "asm", "nonmatchings", "core", "text")
SPLAT_SYMBOL = re.compile(r"\b(?:func|D|jtbl)_[0-9A-F]{8}\b")
INSN = re.compile(r"^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/")


def splat_functions():
    """{address: (size, assembly lines)} for every function splat wrote (tools/splat.sh), with
    alignment directives dropped: functions are placed by address, not by alignment."""
    out = {}
    if not os.path.isdir(SPLAT_DIR):
        return out
    for name in os.listdir(SPLAT_DIR):
        m = re.match(r"func_([0-9A-F]{8})\.s$", name)
        if not m:
            continue
        lines = open(os.path.join(SPLAT_DIR, name)).read().splitlines()
        # Size from the instructions themselves: each one carries "/* offset vram word */".
        size = 4 * sum(1 for l in lines if INSN.match(l))
        if size:
            out[int(m.group(1), 16)] = (size, [l for l in lines if not l.startswith(".align")])
    return out


def elf_section(path, name):
    """Bytes of one section of an ELF32 little-endian object."""
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 46)
    secs = [struct.unpack_from("<10I", d, shoff + i * shentsize) for i in range(shnum)]
    base = secs[shstrndx][4]
    for s in secs:
        if d[base + s[0]:d.index(b"\0", base + s[0])].decode() == name:
            return d[s[4]:s[4] + s[5]]
    return b""


def place_rodata(addrs, data_addr, orig_data, orig_text, text_addr):
    """{function address: original address of its object's .rodata} for the objects whose
    references to their own .rodata all agree on one place, holding the same bytes."""
    if not addrs:
        return {}
    local = os.path.join(OUT, "robj")
    os.makedirs(local, exist_ok=True)
    names = " ".join(f"func_{a:08X}.o" for a in addrs)
    wsl(f'cd "{WSL_DIR}/obj" && cp {names} {to_wsl(local)}/\n')
    sext = lambda v: (v & 0xFFFF) - 0x10000 if v & 0x8000 else v & 0xFFFF
    word = lambda a: struct.unpack_from("<I", orig_text, a - text_addr)[0]
    out = {}
    for addr in addrs:
        path = os.path.join(local, f"func_{addr:08X}.o")
        blob, srelocs, _ = match.read_object(path, want_symbols=True)
        rodata = elf_section(path, ".rodata")
        mine = lambda off: struct.unpack_from("<I", blob, off)[0]
        bases = set()
        offs = sorted(srelocs)
        for n, off in enumerate(offs):
            rtype, sym = srelocs[off][0], srelocs[off][1]
            if sym != ".rodata" or rtype != match.R_MIPS_HI16:
                continue
            lo = next((o for o in offs[n + 1:] if srelocs[o][1] == ".rodata" and srelocs[o][0] == match.R_MIPS_LO16), None)
            if lo is None:
                bases.add(None)
                continue
            addend = ((mine(off) & 0xFFFF) << 16) + sext(mine(lo))
            target = ((word(addr + off) & 0xFFFF) << 16) + sext(word(addr + lo))
            bases.add(target - addend)
        if len(bases) != 1 or None in bases:
            continue
        base = bases.pop()
        o = base - data_addr
        if 0 <= o and o + len(rodata) <= len(orig_data) and orig_data[o:o + len(rodata)] == rodata:
            out[addr] = base
    return out


def to_wsl(path):
    """The path as the Linux side sees it (unchanged when already running on Linux)."""
    if os.name != "nt":
        return os.path.abspath(path)
    path = os.path.abspath(path).replace("\\", "/")
    return f"/mnt/{path[0].lower()}{path[2:]}"


def wsl(script, check=True):
    """Run a bash script in WSL (set -e and pipefail: a failing stage fails the step) and return
    its stdout. The script file is named after this process, so two builds never share it."""
    path = os.path.join(OUT, f"step_{os.getpid()}.sh")
    open(path, "w", newline="\n").write("set -eo pipefail\n" + script)
    env = dict(os.environ, MSYS_NO_PATHCONV="1")
    cmd = ["wsl", "-d", "Ubuntu", "--", "bash", to_wsl(path)] if os.name == "nt" else ["bash", path]
    try:
        res = subprocess.run(cmd, capture_output=True, text=True, env=env)
    finally:
        try:
            os.remove(path)
        except OSError:
            pass
    if check and res.returncode:
        sys.exit(f"WSL step failed:\n{res.stdout[-3000:]}\n{res.stderr[-3000:]}")
    return res.stdout


def source_problems():
    """(orphans, duplicates) among the files under src/: sources no address claims (a file named
    after a name the project does not know: config/adhoc_methods.txt or config/symbol_addrs.txt
    out of date, a typo), which the build silently leaves out, and addresses with more than one
    source, of which project.sources keeps only one. Both make the numbers wrong, so the build
    reports them and fails on them (--keep-going still exits 0)."""
    orphans, by_addr = [], {}
    for dirpath, _, files in os.walk(project.SRC):
        for name in files:
            p = os.path.join(dirpath, name)
            if os.path.splitext(name)[1] not in project.SOURCE_EXTS:
                continue
            addr = project.source_address(p)
            if addr is None:
                orphans.append(os.path.relpath(p, ROOT).replace(os.sep, "/"))
            else:
                by_addr.setdefault(addr, []).append(os.path.relpath(p, ROOT).replace(os.sep, "/"))
    duplicates = {f"{a:08x}": sorted(ps) for a, ps in sorted(by_addr.items()) if len(ps) > 1}
    return sorted(orphans), duplicates


def git_state():
    """(commit, dirty): the commit of HEAD and whether the tree the build reads differs from it."""
    try:
        head = subprocess.run(["git", "rev-parse", "HEAD"], cwd=ROOT, capture_output=True, text=True, check=True).stdout.strip()
        status = subprocess.run(["git", "status", "--porcelain", "--", "src", "config", "include", "tools"],
                                cwd=ROOT, capture_output=True, text=True, check=True).stdout
        return head, bool(status.strip())
    except (OSError, subprocess.CalledProcessError):
        return None, True


def segments():
    """The original's loaded segments: [(vaddr, file offset, size)]."""
    import struct
    data = open(ELF, "rb").read()
    phoff, = struct.unpack_from("<I", data, 28)
    phnum, = struct.unpack_from("<H", data, 44)
    out = []
    for i in range(phnum):
        p_type, off, vaddr, _, filesz, _, _, _ = struct.unpack_from("<8I", data, phoff + 32 * i)
        if p_type == 1:
            out.append((vaddr, off, filesz))
    return data, out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--keep-going", action="store_true", help="exit 0 even if the image differs")
    ap.add_argument("--limit", type=int, default=0,
                    help="compile at most N stale sources this run (a mass change in slices)")
    ap.add_argument("--compile-only", action="store_true", help="stop after the compile step")
    ap.add_argument("--incbin", action="store_true",
                    help="fill undecompiled code with raw bytes even if splat's assembly is there")
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)
    # The previous proof goes first: a build that fails on the way leaves no report or image that
    # a later step (tools/report.py, publish_progress.py) could take for this tree's. A
    # --compile-only run writes no new one, so it keeps the last (publish_progress.py still
    # refuses it once any source is newer than it).
    if not a.compile_only:
        for stale in ("report.json", IMAGE, "built_text.bin", "built_data.bin"):
            if os.path.exists(os.path.join(OUT, stale)):
                os.remove(os.path.join(OUT, stale))

    elf, segs = segments()
    (text_addr, text_off, text_size), (data_addr, data_off, data_size) = segs
    open(os.path.join(OUT, "text.bin"), "wb").write(elf[text_off:text_off + text_size])
    open(os.path.join(OUT, "data.bin"), "wb").write(elf[data_off:data_off + data_size])

    sources = project.sources(refresh=True)  # {address: path}
    starts = set(sources)
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            starts.add(int(row["address"], 16))
    starts = sorted(s for s in starts if text_addr <= s < text_addr + text_size)

    # 1. Compile every source on the Linux side, four at a time; a source whose first line names
    # another compiler (project.source_compiler) is compiled with that one. Objects are named by
    # address (obj/func_ADDR.o) whatever the source is called; only the function's own symbols
    # stay global (its file name and its address), so two objects never define the same name.
    orphans, duplicates = source_problems()
    for p in orphans:
        print(f"  orphan source (no address claims it; is config/adhoc_methods.txt current?): {p}")
    for key, ps in duplicates.items():
        print(f"  duplicate sources for {key}: {', '.join(ps)}")
    print(f"compiling {len(sources)} functions...", flush=True)
    by_compiler = {}
    for addr, path in sources.items():
        rel = os.path.relpath(path, project.SRC).replace(os.sep, "/")
        stem = os.path.splitext(os.path.basename(path))[0]
        digest = hashlib.sha1(open(path, "rb").read()).hexdigest()
        by_compiler.setdefault(project.source_compiler(path), []).append(f"{rel} func_{addr:08X} {stem} {digest}")
    # Only objects of sources that exist now take part: an object left by a source since deleted,
    # renamed or re-addressed would otherwise be linked as if it were still proven.
    expected = os.path.join(OUT, "objects_expected.txt")
    open(expected, "w", newline="\n").write("".join(f"func_{addr:08X}.o\n" for addr in sorted(sources)))
    loops = []
    for name, lines in by_compiler.items():
        listing = os.path.join(OUT, f"sources_{name or 'default'}.txt")
        open(listing, "w", newline="\n").write("\n".join(sorted(lines)) + "\n")
        # An object is reused only if obj/func_ADDR.src says it was made from this very source
        # (path, compiler and content hash): objects are named by address, so a file renamed or
        # re-addressed since would otherwise be linked from another function's code (seen on
        # 2026-10-09; mtimes cannot tell). Per source: the old object and record go first, the
        # source is copied afresh, and the new object exists only if the compile and the objcopy
        # both succeeded (a failure removes what either left). Temporary names are per object.
        loops.append(f"""
while read -r f o stem h; do [ "$(cat "../obj/$o.src" 2>/dev/null)" = "$f {name or 'default'} $h" ] || echo "$f $o $stem $h"; done < {to_wsl(listing)} > ../todo_all.txt
head -n {a.limit if a.limit else 1000000} ../todo_all.txt > ../todo.txt; echo "stale: $(wc -l < ../todo_all.txt), compiling: $(wc -l < ../todo.txt)"
cat ../todo.txt | xargs -r -P{a.jobs} -L1 bash -c 'f="$0"; o="../obj/$1"; rm -f "$o.o" "$o.src"; cp -f "{to_wsl(project.SRC)}/$f" "$f" && {project.compiler_command(name)} "$f" -o "$o.raw" 2>"$o.err" && mips-linux-gnu-objcopy {STRIP} --wildcard -G "$2*" -G "$1*" "$o.raw" "$o.o" && echo "$f {name or 'default'} $3" > "$o.src" || rm -f "$o.o" "$o.src"; rm -f "$o.raw"; true'
""")
    print(wsl(f"""
d="{WSL_DIR}"; mkdir -p "$d/src" "$d/obj"
cp -rup {to_wsl(project.SRC)}/. "$d/src/"
cp -rup {to_wsl(os.path.join(ROOT, "include"))} "$d/src/"
cd "$d/obj"
ls | grep -E '^func_[0-9A-F]{{8}}\\.o$' | sort > ../have.txt || true
sort {to_wsl(expected)} | comm -23 ../have.txt - > ../stale_objects.txt
if [ -s ../stale_objects.txt ]; then echo "removing $(wc -l < ../stale_objects.txt) objects without a source"; sed 's/\\.o$//' ../stale_objects.txt | xargs -r -I{{}} rm -f {{}}.o {{}}.src {{}}.err; fi
cd "$d/src"
""" + "".join(loops)).strip(), flush=True)
    if a.compile_only:
        return
    info = wsl(f"""
cd "{WSL_DIR}/obj"
for o in func_*.o; do
  echo "@ $o"; mips-linux-gnu-readelf -SW "$o" | awk '$1 ~ /^\\[/ && $2 ~ /^\\./ {{print "S", $2, $6}} $1 ~ /^\\[/ && $3 ~ /^\\./ {{print "S", $3, $7}}'
  mips-linux-gnu-nm -u "$o" | awk '{{print "U", $2}}'
done
""")

    # 2. Decide, per function, whether its object can go into the image.
    status, objects = {}, {}
    cur = None
    parsed = {}
    for line in info.splitlines():
        if line.startswith("@ "):
            cur = int(line[7:15], 16)
            parsed[cur] = {"sections": {}, "undefined": []}
        elif line.startswith("S ") and cur is not None:
            _, name, size = line.split()
            if name.startswith(".gnu.linkonce.t."):  # a template instantiation (tools/stl.py) is code
                name = ".text"
            parsed[cur]["sections"][name] = parsed[cur]["sections"].get(name, 0) + int(size, 16)
        elif line.startswith("U ") and cur is not None:
            parsed[cur]["undefined"].append(line.split()[1])
    undefined = set()
    rodata_candidates = []
    # An object may cover the functions after its own (a source defining two); it only has to stop
    # before the next function that has a source of its own. The byte comparison settles the rest.
    src_starts = sorted(sources) + [text_addr + text_size]
    covered_until, covering = 0, None
    for i, addr in enumerate(src_starts[:-1]):
        p = parsed.get(addr)
        if addr < covered_until:
            status[addr] = f"linked as part of func_{covering:08X}"
            continue
        nxt = src_starts[i + 1]
        # A source that also defines the functions after it (e.g. a copy glued to its neighbour)
        # takes their place if it ends exactly where a later source starts.
        if p and ".text" in p["sections"] and p["sections"][".text"] > nxt - addr:
            end = addr + p["sections"][".text"]
            later = [s for s in src_starts if addr < s]
            nxt = next(s for s in later if s >= end)
        if p is None or ".text" not in p["sections"]:
            status[addr] = "does not compile"
            continue
        extra = {k: v for k, v in p["sections"].items()
                 if v and k not in HARMLESS and not k.startswith(".rel") and not k.endswith("tab")}
        bad_syms = [s for s in p["undefined"] if symbols.address_of(s) is None]
        if set(extra) == {".rodata"} and not p["sections"].get(".rel.rodata"):
            rodata_candidates.append(addr)
        if extra and addr not in rodata_candidates:
            status[addr] = "brings its own data: " + ", ".join(sorted(extra))
        elif bad_syms:
            status[addr] = "references unnamed-address symbols: " + ", ".join(bad_syms[:3])
        elif p["sections"][".text"] > nxt - addr:
            status[addr] = f"too long ({p['sections']['.text']} bytes, room for {nxt - addr})"
        else:
            objects[addr] = p["sections"][".text"]
            undefined.update(p["undefined"])
            status[addr] = "linked"
            covered_until, covering = addr + p["sections"][".text"], addr

    # 2b. Objects with their own constants (.rodata): the original's instructions say where those
    # constants live, so the object's .rodata goes exactly there, if its bytes are the original's.
    rodata_at = place_rodata([a for a in rodata_candidates if a in objects], data_addr,
                             elf[data_off:data_off + data_size], elf[text_off:text_off + text_size], text_addr)
    for addr in rodata_candidates:
        if addr in objects and addr not in rodata_at:
            del objects[addr]
            status[addr] = "brings its own data: .rodata (its place in the original could not be confirmed)"
    data_plan, end = [], data_addr
    for addr, base in sorted(rodata_at.items(), key=lambda kv: kv[1]):
        if base < end:  # overlaps one already placed
            del objects[addr]
            status[addr] = "brings its own data: .rodata (overlaps another function's)"
            continue
        data_plan.append((addr, base))
        end = base + parsed[addr]["sections"][".rodata"]
    placed_rodata = len(data_plan)

    # 3. Linker script: objects at their addresses, the original's bytes in between.
    gaps, order = [], []
    pos = text_addr
    for addr in sorted(objects):
        if addr > pos:
            gaps.append((pos, addr - pos))
            order.append(("gap", pos))
        order.append(("obj", addr))
        pos = addr + objects[addr]
    if pos < text_addr + text_size:
        gaps.append((pos, text_addr + text_size - pos))
        order.append(("gap", pos))
    splat_funcs = {} if a.incbin else splat_functions()
    incbin = lambda start, size: [f'.incbin "text.bin", 0x{start - text_addr:x}, 0x{size:x}']
    asm = [".set noreorder", ".set noat", f'.include "macro.inc"']
    from_asm = 0
    for start, size in gaps:
        asm += [f'.section .text.g{start:08x}, "ax"', ".balign 4"]
        # Assembly from splat for every whole function inside the gap; raw bytes elsewhere.
        cur, end = start, start + size
        for f in sorted(x for x in splat_funcs if start <= x < end):
            fsize, body = splat_funcs[f]
            if f < cur or f + fsize > end:
                continue
            if f > cur:
                asm += incbin(cur, f - cur)
            asm += body
            from_asm += fsize
            cur = f + fsize
        if cur < end:
            asm += incbin(cur, end - cur)
    # Data: the original's bytes, with each placed .rodata in between at its address.
    data_body, pos = [], data_addr
    for addr, base in data_plan:
        if base > pos:
            asm += [f'.section .data.g{pos:08x}, "aw"',
                    f'.incbin "data.bin", 0x{pos - data_addr:x}, 0x{base - pos:x}']
            data_body.append(f"    gaps.o(.data.g{pos:08x})")
        data_body.append(f"    obj/func_{addr:08X}.o(.rodata)")
        pos = base + parsed[addr]["sections"][".rodata"]
    asm += [f'.section .data.g{pos:08x}, "aw"',
            f'.incbin "data.bin", 0x{pos - data_addr:x}, 0x{data_addr + data_size - pos:x}']
    data_body.append(f"    gaps.o(.data.g{pos:08x})")
    open(os.path.join(OUT, "gaps.s"), "w", newline="\n").write("\n".join(asm) + "\n")

    syms = []
    referenced = set(undefined)
    for _, body in splat_funcs.values():
        for line in body:
            referenced.update(m.group(0) for m in SPLAT_SYMBOL.finditer(line))
    for s in sorted(referenced):  # PROVIDE never overrides a real definition
        addr = symbols.address_of(s)
        if addr is not None:
            quoted = f'"{s}"' if re.search(r"[^\w]", s) else s
            syms.append(f"PROVIDE({quoted} = 0x{addr:08x});")
    for extra in ("undefined_syms_auto.txt", "undefined_funcs_auto.txt"):
        path = os.path.join(ROOT, "build", "splat", extra)
        if splat_funcs and os.path.exists(path):
            for line in open(path):
                m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+);", line)
                if m:
                    syms.append(f"PROVIDE({m.group(1)} = {m.group(2)});")
    body = []
    for kind, addr in order:
        if kind == "gap":
            body.append(f"    gaps.o(.text.g{addr:08x})")
        else:
            body.append(f"    obj/func_{addr:08X}.o(.text .gnu.linkonce.t.*)")
    ld = ("\n".join(syms) + "\nSECTIONS\n{\n"
          f"  .text 0x{text_addr:x} : SUBALIGN(4)\n  {{\n" + "\n".join(body) + "\n  }\n"
          f"  .data 0x{data_addr:x} : SUBALIGN(1)\n  {{\n" + "\n".join(data_body) + "\n  }\n"
          "  /DISCARD/ : { *(.reginfo) *(.mdebug*) *(.comment) *(.pdr) *(.eh_frame) *(.gcc_except_table) *(*) }\n}\n")
    open(os.path.join(OUT, "link.ld"), "w", newline="\n").write(ld)

    # 4. Assemble the gaps. Instructions the modern assembler cannot parse in splat's syntax
    # (VU0 macro mode) are emitted as their raw words; they are still undecompiled assembly.
    print(f"linking {len(objects)} functions...", flush=True)
    for attempt in range(3):
        out = wsl(f"""
d="{WSL_DIR}"
cp {to_wsl(OUT)}/text.bin {to_wsl(OUT)}/data.bin {to_wsl(OUT)}/gaps.s {to_wsl(OUT)}/link.ld {to_wsl(os.path.join(ROOT, 'include', 'macro.inc'))} "$d/"
cd "$d"
mips-linux-gnu-as {project.CONFIG['cpu']['as_flags']} gaps.s -o gaps.o 2>&1 | grep -E '^gaps.s:[0-9]+: Error' | cut -d: -f2 || true
""")
        bad = {int(n) for n in out.split()}
        if not bad:
            break
        lines = asm
        for n in bad:
            m = re.match(r"^(\s*)/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/", lines[n - 1])
            if m:
                # splat prints the instruction's bytes in file order (little endian)
                word = int.from_bytes(bytes.fromhex(m.group(2)), "little")
                lines[n - 1] = f"{m.group(1)}.word 0x{word:08X}  # {lines[n - 1].strip()}"
        open(os.path.join(OUT, "gaps.s"), "w", newline="\n").write("\n".join(lines) + "\n")
        print(f"  {len(bad)} instructions emitted as raw words", flush=True)
    wsl(f"""
d="{WSL_DIR}"
cd "$d"
mips-linux-gnu-ld -EL -e 0x{project.load_image()[0]:x} -T link.ld -o {IMAGE} --no-check-sections
mips-linux-gnu-objcopy -O binary --only-section=.text {IMAGE} built_text.bin
mips-linux-gnu-objcopy -O binary --only-section=.data {IMAGE} built_data.bin
cp {IMAGE} built_text.bin built_data.bin {to_wsl(OUT)}/
""")
    built_text = open(os.path.join(OUT, "built_text.bin"), "rb").read()
    built_data = open(os.path.join(OUT, "built_data.bin"), "rb").read()
    orig_text = elf[text_off:text_off + text_size]
    orig_data = elf[data_off:data_off + data_size]

    failed = []
    for addr, size in objects.items():
        o = addr - text_addr
        if built_text[o:o + size] != orig_text[o:o + size]:
            status[addr] = "differs after linking"
            failed.append(addr)
    text_ok = built_text == orig_text
    data_ok = built_data == orig_data
    sha = lambda b: hashlib.sha1(b).hexdigest()

    linked_bytes = sum(objects[a] for a in objects if status[a] == "linked")
    data_sizes = {f"{a:08x}": parsed[a]["sections"][".rodata"] for a, _ in data_plan if status[a] == "linked"}
    commit, dirty = git_state()
    # Provenance first: when this build was made and the exact tree it proves, so a report built
    # from it (tools/report.py, publish_progress.py) can say what it describes and refuse a stale
    # or partial build.
    report = {"generated": datetime.datetime.now(datetime.timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"),
              "commit": commit, "dirty": dirty, "partial": bool(a.limit),
              "sources": len(sources), "orphan_sources": orphans, "duplicate_sources": duplicates,
              "text_sha1": sha(built_text), "data_sha1": sha(built_data),
              "text_matches": text_ok, "data_matches": data_ok,
              "functions": {f"{a:08x}": s for a, s in sorted(status.items())},
              "linked_functions": sum(s == "linked" for s in status.values()),
              "linked_code_bytes": linked_bytes, "code_bytes": text_size,
              "sizes": {f"{a:08x}": s for a, s in sorted(objects.items())},
              "data_bytes": data_size, "data_from_source": sum(data_sizes.values()),
              "data_sizes": {k: v for k, v in sorted(data_sizes.items())}}
    json.dump(report, open(os.path.join(OUT, "report.json"), "w"), indent=1)

    counts = {}
    for s in status.values():
        key = s.split(":")[0].split(" (")[0]
        counts[key] = counts.get(key, 0) + 1
    print(f".text {'OK' if text_ok else 'DIFFERS'}  sha1 {sha(built_text)} (original {sha(orig_text)})")
    print(f".data {'OK' if data_ok else 'DIFFERS'} ({placed_rodata} functions' constants placed from source, "
          f"{sum(data_sizes.values())} bytes)")
    for k, v in sorted(counts.items(), key=lambda kv: -kv[1]):
        print(f"  {v:5d}  {k}")
    print(f"code from source: {linked_bytes} of {text_size} bytes ({linked_bytes / text_size:.2%}); "
          f"from splat's assembly: {from_asm} bytes ({from_asm / text_size:.2%}); the rest raw bytes")
    for addr, s in sorted(status.items()):
        if s != "linked":
            print(f"  {addr:08x}  {s}")
    if orphans or duplicates:
        print(f"SOURCES: {len(orphans)} orphan, {len(duplicates)} duplicated (listed above): the numbers leave them out")
    print(f"build of {commit or 'no commit'}{' (uncommitted changes)' if dirty else ''} at {report['generated']}")
    sys.exit(0 if (text_ok and data_ok and not orphans and not duplicates) or a.keep_going else 1)


if __name__ == "__main__":
    main()
