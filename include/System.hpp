#pragma once
#include <string>

class System {
public:
    std::string version_string(const std::string& cpp_version) const;
    std::string authors_string(int year) const;

    // Parallelization info 
    std::string kokkos_info_string();

};
