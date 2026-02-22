# Author: George Apostolidis 2026

import os
import sys
from pathlib import Path

# Paths
ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"

# Ensure Python can find hivsim.pyd in build/
sys.path.insert(0, str(BUILD))

import hivsim


def main():
    cpp_version = "C++23"
    year = 2026

    print("Initializing HIVSIM Engine...\n")
    hivsim.print_version(cpp_version)
    hivsim.print_authors(year)


if __name__ == "__main__":
    main()
