#!/usr/bin/env python3
"""Publish the progress report: regenerate progress/report.json (tools/report.py) and force-push
it, alone, to the `progress` branch, whose workflow uploads it as the artifact decomp.dev reads
(SCUS-97328_report). The branch always holds a single commit, so reports never pile up in history.

    publish_progress.py
"""
import json
import os
import shutil
import subprocess
import tempfile

import match
import report

ROOT = match.ROOT
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
          name: SCUS-97328_report
          path: report.json
"""


def git(*args, cwd):
    subprocess.run(["git", *args], cwd=cwd, check=True, capture_output=True, text=True)


def main():
    report.main()
    data = json.load(open(report.OUT))
    head = subprocess.run(["git", "rev-parse", "--short", "HEAD"], cwd=ROOT, capture_output=True,
                          text=True).stdout.strip()
    with tempfile.TemporaryDirectory() as tmp:
        git("init", "-q", "-b", "progress", cwd=tmp)
        for key in ("user.name", "user.email"):
            value = subprocess.run(["git", "config", key], cwd=ROOT, capture_output=True, text=True).stdout.strip()
            git("config", key, value, cwd=tmp)
        json.dump(data, open(os.path.join(tmp, "report.json"), "w"), separators=(",", ":"))
        os.makedirs(os.path.join(tmp, ".github", "workflows"))
        open(os.path.join(tmp, ".github", "workflows", "progress.yml"), "w", newline="\n").write(WORKFLOW)
        m = data["measures"]
        git("add", "-A", cwd=tmp)
        git("commit", "-q", "-m", f"Progress report for {head}: {m['matched_functions']}/{m['total_functions']} "
            f"functions, {m['matched_code_percent']:.2f}% of code matched, {m['complete_code_percent']:.2f}% linked\n\n"
            "Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>", cwd=tmp)
        url = subprocess.run(["git", "remote", "get-url", "origin"], cwd=ROOT, capture_output=True, text=True).stdout.strip()
        git("push", "-q", "-f", url, "progress", cwd=tmp)
    print("pushed the report to the progress branch")


if __name__ == "__main__":
    main()
