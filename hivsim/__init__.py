import os
import sys
from pathlib import Path

# 1) Ensure MinGW runtime DLLs are discoverable (dev path)
# If you want, make this configurable via env var.
msys_bin = r"C:\msys64\mingw64\bin"
if os.path.isdir(msys_bin):
    os.add_dll_directory(msys_bin)

# 2) If running from source tree, prefer local build output
root = Path(__file__).resolve().parents[1]
build_dir = root / "build"
if build_dir.exists():
    os.add_dll_directory(str(build_dir))
    sys.path.insert(0, str(build_dir))

# 3) Import the compiled extension
from hivsim_engine import *  # noqa