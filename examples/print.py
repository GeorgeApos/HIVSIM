import hivsim


def main():
    cpp_version = "C++23"
    year = 2026

    hivsim.print_version(cpp_version)
    hivsim.print_authors(year)

    hivsim.kokkos_init()

    # print(hivsim.kokkos_info())
    # print("sum:", hivsim.make_view_sum(10))

    g = hivsim.Grid(21,21,21)
    g.seed_center()

    print("Healthy:", g.count_healthy())
    print("Infected:", g.count_infected())
    print("Dead:", g.count_dead())

    del g

    hivsim.kokkos_finalize()

if __name__ == "__main__":
    main()
