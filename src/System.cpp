#include "System.hpp"

std::string System::version_string(const std::string& cpp_version) const {
    return "HIVSIM Engine 0.1.0 (" + cpp_version + ")";
}

std::string System::authors_string(int year) const {
    return "Authors: Apostolidis George, Chalis Apostolos | " + std::to_string(year);
}