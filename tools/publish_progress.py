#!/usr/bin/env python3
"""Publish the progress report: regenerate progress/report.json (tools/report.py) and the README's
numbers (tools/update_readme.py), then force-push the report, alone, to the `progress` branch,
whose workflow uploads it as the artifact decomp.dev reads (SERIAL_report, [game] serial in project.toml). The branch always
holds a single commit, so reports never pile up in history.

    publish_progress.py [--check]      --check: only say whether a publish would be allowed

Nothing is published unless the last full build (build/full/report.json, tools/build.py) is a
complete one that reproduces the original (.text and .data hash alike), was made from the commit
HEAD points at with no uncommitted change to src/, config/, include/ or tools/ (then and now),
and found no orphan or duplicated source. The report pushed carries, in report.meta.json and in
the commit message, the generation date and the exact commit it describes. So the order is:
commit, build, publish; then commit the README the publish updated.
"""
import datetime
import json
import os
import subprocess
import sys
import tempfile

import match
import project
import report
import update_readme

ROOT = match.ROOT
BUILD_REPORT = os.path.join(ROOT, "build", "full", "report.json")
WORKFLOW = """name: progress

# Uploads the objdiff report generated locally by tools/report.py (names, sizes and percentages
# only) as the artifact decomp.dev reads.
on:
  push:
    branches: [progress]

jobs:
  upload:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - uses: actions/upload-artifact@v4
        with:
          name: {serial}_report
          path: report.json
"""


def git(*args, cwd=ROOT):
    return subprocess.run(["git", *args], cwd=cwd, check=True, capture_output=True, text=True).stdout.strip()


def refusals():
    """Why the last full build cannot be published, as a list of reasons (empty when it can)."""
    out = []
    if not os.path.exists(BUILD_REPORT):
        return [f"no full build: {BUILD_REPORT} is missing (python tools/build.py)"]
    build = json.load(open(BUILD_REPORT))
    if "commit" not in build:
        return ["the last build predates provenance tracking: run python tools/build.py again"]
    if not build.get("text_matches"):
        out.append("the built .text differs from the original")
    if not build.get("data_matches"):
        out.append("the built .data differs from the original")
    if build.get("partial"):
        out.append("the last build compiled only a slice (--limit): run a complete one")
    if build.get("orphan_sources"):
        out.append(f"{len(build['orphan_sources'])} orphan sources (no address claims them): "
                   + ", ".join(build["orphan_sources"][:3]))
    if build.get("duplicate_sources"):
        out.append(f"{len(build['duplicate_sources'])} addresses with two sources: "
                   + ", ".join(list(build["duplicate_sources"])[:3]))
    head = git("rev-parse", "HEAD")
    if build.get("commit") != head:
        out.append(f"the build describes {(build.get('commit') or 'no commit')[:12]}, HEAD is {head[:12]}: "
                   "build again after committing")
    if build.get("dirty"):
        out.append("the build read uncommitted changes (src/, config/, include/ or tools/): commit, then build again")
    if git("status", "--porcelain", "--", "src", "config", "include", "tools"):
        out.append("src/, config/, include/ or tools/ have uncommitted changes now: the build would not describe HEAD")
    # Anything the build reads that changed after it was written makes it stale even if committed.
    made = os.path.getmtime(BUILD_REPORT)
    newer = []
    for top in ("src", "config", "include"):
        for dirpath, _, files in os.walk(os.path.join(ROOT, top)):
            for name in files:
                p = os.path.join(dirpath, name)
                if os.path.getmtime(p) > made:
                    newer.append(os.path.relpath(p, ROOT))
    if newer:
        out.append(f"{len(newer)} files changed after the build ({newer[0]}...): build again")
    return out


def main():
    check = "--check" in sys.argv
    why = refusals()
    if why:
        print("not publishing:")
        for w in why:
            print(f"  - {w}")
        sys.exit(1)
    if check:
        print("the last full build can be published")
        return
    report.main()
    update_readme.main()
    data = json.load(open(report.OUT))
    meta = json.load(open(report.META))
    head = git("rev-parse", "HEAD")
    meta["published"] = datetime.datetime.now(datetime.timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ")
    with tempfile.TemporaryDirectory() as tmp:
        git("init", "-q", "-b", "progress", cwd=tmp)
        for key in ("user.name", "user.email"):
            git("config", key, git("config", key), cwd=tmp)
        json.dump(data, open(os.path.join(tmp, "report.json"), "w"), separators=(",", ":"))
        json.dump(meta, open(os.path.join(tmp, "report.meta.json"), "w"), indent=1)
        os.makedirs(os.path.join(tmp, ".github", "workflows"))
        open(os.path.join(tmp, ".github", "workflows", "progress.yml"), "w", newline="\n").write(WORKFLOW.replace("{serial}", project.CONFIG["game"]["serial"]))
        m = data["measures"]
        git("add", "-A", cwd=tmp)
        git("commit", "-q", "-m",
            f"Progress report for {head[:12]} ({meta['generated'][:10]}): {m['matched_functions']}/{m['total_functions']} "
            f"functions, {m['matched_code_percent']:.2f}% of code matched, {m['complete_code_percent']:.2f}% linked, "
            f"{m['matched_data_percent']:.2f}% of data\n\n"
            f"Describes commit {head}, built {meta['build']['generated']}, report generated {meta['generated']}; "
            f"the full build hashes .text {meta['build']['text_sha1']} and .data {meta['build']['data_sha1']} "
            "like the original.\n\n"
            "Co-Authored-By: Claude Fable 5.1 <noreply@anthropic.com>", cwd=tmp)
        url = git("remote", "get-url", "origin")
        git("push", "-q", "-f", url, "progress", cwd=tmp)
    print(f"pushed the report for {head[:12]} to the progress branch; README.md updated (commit it)")


if __name__ == "__main__":
    main()
