#include "kokkos_info.hpp"
#include <Kokkos_Core.hpp>
#include <sstream>

std::string kokkos_info_string() {
    std::ostringstream oss;
    oss << "Kokkos enabled\n";
    oss << "Execution space: " << Kokkos::DefaultExecutionSpace::name() << "\n";
    oss << "Memory space: " << Kokkos::DefaultExecutionSpace::memory_space::name() << "\n";
    return oss.str();
}