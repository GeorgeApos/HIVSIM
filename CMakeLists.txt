cmake_minimum_required(VERSION 3.16)
project(HIVSIM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Force modern Python finder (avoid PythonInterp/PythonLibs picking WindowsApps Python 3.10)
set(PYBIND11_FINDPYTHON ON)
set(Python3_FIND_STRATEGY LOCATION)
set(Python3_FIND_REGISTRY NEVER)
set(Python3_FIND_VIRTUALENV ONLY)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)

include(FetchContent)
FetchContent_Declare(
        pybind11
        GIT_REPOSITORY https://github.com/pybind/pybind11.git
        GIT_TAG v2.12.0
)
FetchContent_MakeAvailable(pybind11)

# Build Python module: hivsim(.pyd)
pybind11_add_module(hivsim
        src/bindings.cpp
        src/System.cpp
)

target_include_directories(hivsim PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ---- Make the produced .pyd land in a stable place ----
# Put the extension module next to the build directory root, not buried in Debug/Release.
# This avoids "sys.path points to the wrong folder" problems.
set_target_properties(hivsim PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# Multi-config generators (MSVC): also set per-config output directories
foreach(cfg DEBUG RELEASE RELWITHDEBINFO MINSIZEREL)
    string(TOUPPER "${cfg}" cfg_u)
    set_target_properties(hivsim PROPERTIES
            LIBRARY_OUTPUT_DIRECTORY_${cfg_u} "${CMAKE_BINARY_DIR}"
            RUNTIME_OUTPUT_DIRECTORY_${cfg_u} "${CMAKE_BINARY_DIR}"
    )
endforeach()