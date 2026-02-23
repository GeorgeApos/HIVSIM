#include <Kokkos_Core.hpp>
#include <string>

enum class CellState : int {
    HEALTHY = 0,
    INFECTED = 1,
    DEAD = 2
};

class Grid {
public:
    Grid(int nx, int ny, int nz);

    void seed_center();
    int count_state(CellState state) const;

    int nx() const { return nx_; }
    int ny() const { return ny_; }
    int nz() const { return nz_; }

private:
    int nx_, ny_, nz_;
    Kokkos::View<CellState***> cells_;
};