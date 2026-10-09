"""Read project.toml: the per-game settings every tool uses."""
import importlib.util
import os
import re
import tomllib

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONFIG = tomllib.load(open(os.path.join(ROOT, "project.toml"), "rb"))

_cache = {}


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
    return command.replace("{dir}", directory)


def knowledge():
    """The knowledge files listed in project.toml, joined."""
    files = CONFIG.get("model", {}).get("knowledge", [])
    if isinstance(files, str):
        files = [files]
    return "\n\n".join(open(path(f), encoding="utf-8").read().strip() for f in files if os.path.exists(path(f)))
