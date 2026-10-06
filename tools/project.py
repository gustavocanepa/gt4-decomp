"""Read project.toml: the per-game settings every tool uses."""
import importlib.util
import os
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


def compiler_command():
    """The compile command for Linux/WSL, with $HOME in place of ~."""
    c = CONFIG["compiler"]
    directory = c["dir"].replace("~", "$HOME", 1)
    return c["command"].replace("{dir}", directory)


def knowledge():
    """The knowledge files listed in project.toml, joined."""
    files = CONFIG.get("model", {}).get("knowledge", [])
    if isinstance(files, str):
        files = [files]
    return "\n\n".join(open(path(f), encoding="utf-8").read().strip() for f in files if os.path.exists(path(f)))
