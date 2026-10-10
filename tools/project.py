"""Read project.toml: the per-game settings every tool uses."""
import importlib.util
import os
import re
import tomllib

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONFIG = tomllib.load(open(os.path.join(ROOT, "project.toml"), "rb"))

_cache = {}

# Short name of the game: names the build's working directory in WSL and the linked image, so
# several projects (one per game) can share one Linux toolchain without touching each other.
BASENAME = CONFIG["game"].get("basename", "gt4")


def path(rel):
    return os.path.join(ROOT, rel)


def load_image():
    """(entry, [(address, bytes), ...]) of the executable, through the configured loader."""
    if "image" not in _cache:
        name = CONFIG["game"]["loader"]
        spec = importlib.util.spec_from_file_location(name, path(f"tools/loaders/{name}.py"))
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        _cache["image"] = module.load(path(CONFIG["game"]["executable"]))
    return _cache["image"]


COMPILER_MARKER = re.compile(r"^/\* compiler: ([\w.+-]+) \*/\s*$")


def compilers():
    """{name: config} of the alternative compilers ([compilers.NAME] tables); the project's own
    compiler is not among them (it needs no marker)."""
    return CONFIG.get("compilers", {})


def source_compiler(path):
    """The compiler a source asks for on its first line (`/* compiler: NAME */`), or None for the
    project's compiler."""
    try:
        with open(path, encoding="utf-8", errors="replace") as f:
            m = COMPILER_MARKER.match(f.readline())
    except OSError:
        return None
    if m and m.group(1) not in compilers():
        raise SystemExit(f"{path}: unknown compiler {m.group(1)!r} (see [compilers] in project.toml)")
    return m.group(1) if m else None


def compiler_command(name=None):
    """The compile command for Linux/WSL, with $HOME in place of ~: the project's compiler, or the
    alternative called name (see compilers())."""
    c = CONFIG["compiler"] if name is None else compilers()[name]
    directory = c["dir"].replace("~", "$HOME", 1)
    # GT4_COMPILER_COMMAND overrides the project compiler's command (for experiments with flags).
    command = c["command"] if name else os.environ.get("GT4_COMPILER_COMMAND", c["command"])
    # {tools}: this repository's tools/ directory as Linux/WSL sees it (wrappers such as cc_as.sh)
    tools = os.path.dirname(os.path.abspath(__file__))
    if os.name == "nt":
        tools = "/mnt/" + tools[0].lower() + tools[2:].replace("\\", "/")
    return command.replace("{dir}", directory).replace("{tools}", tools)


def knowledge():
    """The knowledge files listed in project.toml, joined."""
    files = CONFIG.get("model", {}).get("knowledge", [])
    if isinstance(files, str):
        files = [files]
    return "\n\n".join(open(path(f), encoding="utf-8").read().strip() for f in files if os.path.exists(path(f)))


# ---------------------------------------------------------------- sources

SRC = os.path.join(ROOT, "src")
SOURCE_EXTS = (".c", ".cpp")
INCLUDE = os.path.join(ROOT, "include")
_sources = {}

_stamp = {}


def include_stamp():
    """A digest of include/ (every file's path, size and mtime), computed once per process: the
    Linux side keeps one copy of include/ per stamp (tools/include_wsl.sh)."""
    if "v" not in _stamp:
        import hashlib
        h = hashlib.sha1()
        for dirpath, dirs, files in os.walk(INCLUDE):
            dirs.sort()
            for f in sorted(files):
                st = os.stat(os.path.join(dirpath, f))
                h.update(f"{os.path.relpath(os.path.join(dirpath, f), INCLUDE)}:{st.st_size}:{st.st_mtime_ns}\n".encode())
        _stamp["v"] = h.hexdigest()[:16]
    return _stamp["v"]


def with_include_stamp(args):
    """A Linux/WSL command line (list) run with INCLUDE_STAMP set (tools/include_wsl.sh)."""
    return ["env", f"INCLUDE_STAMP={include_stamp()}"] + list(args)


_QUOTED_INCLUDE = re.compile(r'^[ \t]*#[ \t]*include[ \t]*"([^"]+)"[^\n]*\n?', re.M)


def inline_includes(text, seen=None):
    """text with every `#include "NAME"` of a header in include/ replaced by the header itself
    (recursively, each header once), for tools that need a self-contained file (the permuter)."""
    seen = set() if seen is None else seen

    def one(m):
        p = os.path.join(INCLUDE, m.group(1).replace("/", os.sep))
        if not os.path.isfile(p):
            return m.group(0)
        if p in seen:
            return ""
        seen.add(p)
        body = open(p, encoding="utf-8").read()
        return inline_includes(body if body.endswith("\n") else body + "\n", seen)
    return _QUOTED_INCLUDE.sub(one, text)


def source_address(path):
    """The address of the function a source file is for (from its file name: func_ADDR or a name
    of tools/symbols.py), or None for a file that is not a function's source."""
    import symbols
    stem, ext = os.path.splitext(os.path.basename(path))
    if ext not in SOURCE_EXTS:
        return None
    m = re.fullmatch(r"func_([0-9A-Fa-f]{8})", stem)
    if m:
        return int(m.group(1), 16)
    # A real name exactly (aliases included: func_ADDR__method is a script function listed under
    # its registration function), or Name_ADDR when two names differ only by case
    # (tools/layout.py); any other func_ADDR__suffix file is a note or a variant, not a source.
    if stem in symbols._load().names:
        addr, kind = symbols._load().names[stem]
        return addr if kind == "func" else None
    if symbols.GENERIC.match(stem):
        return None
    m = re.fullmatch(r"(.+)_([0-9A-Fa-f]{8})", stem)
    if m and symbols.kind_of(m.group(1)) == "func" and symbols.address_of(m.group(1)) == int(m.group(2), 16):
        return int(m.group(2), 16)
    if symbols.kind_of(stem) != "func":
        return None
    return symbols.address_of(stem)


def sources(refresh=False):
    """{address: path} of every function source under src/ (flat or organized, tools/layout.py).
    The scan is cached per process; refresh=True scans again."""
    if refresh or "map" not in _sources:
        out = {}
        for dirpath, _, files in os.walk(SRC):
            for name in files:
                p = os.path.join(dirpath, name)
                addr = source_address(p)
                if addr is not None:
                    out[addr] = p
        _sources["map"] = out
    return _sources["map"]


def source_for(addr):
    """The path of the source of the function at addr, or None. Looks at the places a source can
    be (flat src/func_ADDR.*, then its planned path) before falling back to a scan, so a file
    written by another process a moment ago is found; a scan (cached) covers anything else."""
    import layout
    for ext in SOURCE_EXTS:
        p = os.path.join(SRC, f"func_{addr:08X}{ext}")
        if os.path.exists(p):
            return p
        p = os.path.join(ROOT, layout.path_for(addr, ext).replace("/", os.sep))
        if os.path.exists(p):
            return p
    p = sources().get(addr)
    return p if p and os.path.exists(p) else None


def done_addresses():
    """Addresses that have a source (one scan)."""
    return set(sources(refresh=True))
