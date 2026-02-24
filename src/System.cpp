#include "System.hpp"
#include <Kokkos_Core.hpp>
#include <sstream>

std::string System::version_string(const std::string& cpp_version) const 
{
    return "HIVSIM Engine (" + cpp_version + ")";
}

std::string System::authors_string(int year) const 
{
    return "Author: George Apostolidis, Chalis Apostolos | " + std::to_string(year);
}

std::string System::kokkos_info_string() {
    std::ostringstream oss;
    oss << "Kokkos enabled\n";
    oss << "Execution space: " << Kokkos::DefaultExecutionSpace::name() << "\n";
    oss << "Memory space: " << Kokkos::DefaultExecutionSpace::memory_space::name() << "\n";
    return oss.str();
}
