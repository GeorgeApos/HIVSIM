#include <pybind11/pybind11.h>
#include "System.hpp"
#include "kokkos_info.hpp"
#include <Kokkos_Core.hpp>
#include "Grid.hpp"


namespace py = pybind11;

PYBIND11_MODULE(hivsim_engine, m) {
    m.attr("__BINDINGS_FINGERPRINT__") = "BINDINGS_WITH_KOKKOS_2026_02_22";
    py::class_<System>(m, "System")
        .def(py::init<>())
        .def("version_string", &System::version_string, py::arg("cpp_version"))
        .def("authors_string", &System::authors_string, py::arg("year"));

    // optional: also expose helper functions
    m.def("print_version", [](const std::string& v){
        System s;
        py::print(s.version_string(v));
    });
    m.def("bindings_fingerprint", [](){ return std::string("WITH_KOKKOS"); });
    m.def("print_authors", [](int year){
        System s;
        py::print(s.authors_string(year));
    });

    m.def("kokkos_info", [](){
        return kokkos_info_string();
    });

    m.def("kokkos_init", [](){
        if (!Kokkos::is_initialized()) Kokkos::initialize();
    });

    m.def("kokkos_finalize", [](){
      if (Kokkos::is_initialized() && !Kokkos::is_finalized()) Kokkos::finalize();
    });

    m.def("make_view_sum", [](int n){
      if (!Kokkos::is_initialized()) Kokkos::initialize();

      Kokkos::View<double*> a("a", n);

      Kokkos::parallel_for("fill", n, KOKKOS_LAMBDA(int i){
        a(i) = 1.0 * i;
      });

      // copy to host
      auto h = Kokkos::create_mirror_view_and_copy(Kokkos::HostSpace(), a);

      double sum = 0.0;
      for (int i=0; i<n; ++i) sum += h(i);
      return sum;
    });

    py::class_<Grid>(m, "Grid")
    .def(py::init<int,int,int>())
    .def("seed_center", &Grid::seed_center)
    .def("count_healthy", [](const Grid& g){
        return g.count_state(CellState::HEALTHY);
    })
    .def("count_infected", [](const Grid& g){
        return g.count_state(CellState::INFECTED);
    })
    .def("count_dead", [](const Grid& g){
        return g.count_state(CellState::DEAD);
    });
}

