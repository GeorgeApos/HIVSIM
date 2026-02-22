#include "System.hpp"

std::string System::version_string(const std::string& cpp_version) const {
    return "HIVSIM Engine (" + cpp_version + ")";
}

std::string System::authors_string(int year) const {
    return "Author: George Apostolidis " + std::to_string(year);
}