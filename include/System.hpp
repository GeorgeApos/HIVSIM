#pragma once

#include <string>

class System {
public:
    System() = default;

    // Return strings (Python can print them)
    std::string version_string(const std::string& cpp_version) const;
    std::string authors_string(int year) const;
};