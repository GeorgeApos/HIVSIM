import hivsim


def main():
    cpp_version = "C++23"
    year = 2026

    print("Initializing HIVSIM Engine...\n")

    hivsim.print_version(cpp_version)
    hivsim.print_authors(year)

    hivsim.kokkos_init()

    print(hivsim.kokkos_info())
    print("sum:", hivsim.make_view_sum(10))

    hivsim.kokkos_finalize()


if __name__ == "__main__":
    main()
