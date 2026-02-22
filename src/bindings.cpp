#include <pybind11/pybind11.h>
#include "System.hpp"

namespace py = pybind11;

PYBIND11_MODULE(hivsim, m) {
    py::class_<System>(m, "System")
        .def(py::init<>())
        .def("version_string", &System::version_string, py::arg("cpp_version"))
        .def("authors_string", &System::authors_string, py::arg("year"));

    // optional: also expose helper functions
    m.def("print_version", [](const std::string& v){
        System s;
        py::print(s.version_string(v));
    });

    m.def("print_authors", [](int year){
        System s;
        py::print(s.authors_string(year));
    });
}