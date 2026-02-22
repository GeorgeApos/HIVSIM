#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "System.hpp"

namespace py = pybind11;

PYBIND11_MODULE(hivsim, m) {
    m.doc() = "HIVSIM Simulation Engine";

    py::class_<System>(m, "System")
        .def(py::init<>())

        .def("version_string", &System::version_string, py::arg("cpp_version"))
        .def("authors_string", &System::authors_string, py::arg("year"))

        .def("__repr__", [](const System &) { return "<hivsim.System>"; });
}