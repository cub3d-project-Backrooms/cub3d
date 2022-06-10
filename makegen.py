#!/usr/bin/env python3

import re
import textwrap
from pathlib import Path
from typing import List

SRC = Path("src")
PKG = Path("config") / "packages.mk"


def get_subdirs(path: Path):
    yield from (p for p in path.glob("[!.]*") if p.is_dir())


def get_src_files(subdir: Path):
    yield from (p for p in subdir.glob("*.c"))


def make_var(name: str, values: List[str]) -> str:
    name_len = len(name)
    wrapped = textwrap.wrap(" ".join(values), 70 - name_len)
    wrapped_len = len(wrapped)
    if wrapped_len == 0:
        return ""
    pad = "\t" * ((name_len + 3) // 4)
    res = f"{name} = {wrapped[0]}"
    if wrapped_len > 1:
        res += "\\"
    for w in wrapped[1:-1]:
        res += f"\n{pad}{w}\\"
    if wrapped_len > 1:
        res += f"\n{pad}{wrapped[-1]}"
    res += "\n"
    return res


def create_values(subdir: Path) -> str:
    values = [s.stem for s in get_src_files(subdir)]
    return make_var(f"{subdir.name}V", values)


def create_template(subdir: Path) -> str:
    subdirs = [s for s in get_subdirs(SRC)]
    packages = [s.name for s in subdirs]
    res = make_var("PKGS", packages) + "\n"
    for subdir in subdirs:
        res += create_values(subdir)
    return res


def regex_index(lst: 'list[str]', pattern: str, flags=0):
    for i, line in enumerate(lst):
        if re.match(pattern, line, flags):
            return i
    raise ValueError(f"{pattern} not found in {lst}")


def main():
    template = create_template(SRC)
    sections = PKG.read_text().splitlines()
    begin = 1 + regex_index(sections, r"#\s*@packages", re.IGNORECASE)
    end = begin + regex_index(sections[begin:], "#")
    # replace section
    sections[begin:end] = [template]
    PKG.write_text("\n".join(sections))


if __name__ == "__main__":
    main()
