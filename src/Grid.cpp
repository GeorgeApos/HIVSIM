#include "Grid.hpp"

Grid::Grid(int nx, int ny, int nz)
    : nx_(nx), ny_(ny), nz_(nz),
      cells_("cells", nx, ny, nz)
{
    // Initialize all to HEALTHY
    Kokkos::parallel_for("init_grid",
        Kokkos::MDRangePolicy<Kokkos::Rank<3>>({0,0,0},{nx_,ny_,nz_}),
        KOKKOS_LAMBDA(int i, int j, int k) {
            cells_(i,j,k) = CellState::HEALTHY;
        });
}

void Grid::seed_center() {
    int cx = nx_ / 2;
    int cy = ny_ / 2;
    int cz = nz_ / 2;

    auto h = Kokkos::create_mirror_view(cells_);
    Kokkos::deep_copy(h, cells_);

    h(cx,cy,cz) = CellState::INFECTED;

    Kokkos::deep_copy(cells_, h);
}

int Grid::count_state(CellState state) const {
    int count = 0;

    auto h = Kokkos::create_mirror_view_and_copy(Kokkos::HostSpace(), cells_);

    for (int i=0;i<nx_;++i)
        for (int j=0;j<ny_;++j)
            for (int k=0;k<nz_;++k)
                if (h(i,j,k) == state)
                    count++;

    return count;
}