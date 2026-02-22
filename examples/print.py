# Author: George Apostolidis 2026

import hivsim

def main():
    cpp_version = "C++23"
    year = 2026

    engine = hivsim.System()

    print("Initializing HIVSIM Engine...\n")

    engine.print_version(cpp_version)
    engine.print_authors(year)

if __name__ == "__main__":
    main()