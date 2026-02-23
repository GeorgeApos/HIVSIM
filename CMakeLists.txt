cmake_minimum_required(VERSION 3.16)
project(HIVSIM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Python: prefer venv
set(PYBIND11_FINDPYTHON ON)
set(Python3_FIND_STRATEGY LOCATION)
set(Python3_FIND_REGISTRY NEVER)
set(Python3_FIND_VIRTUALENV ONLY)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)

include(FetchContent)

# --- Kokkos ---
FetchContent_Declare(
        kokkos
        GIT_REPOSITORY https://github.com/kokkos/kokkos.git
        GIT_TAG 4.5.01
)
FetchContent_MakeAvailable(kokkos)

# --- pybind11 ---
FetchContent_Declare(
        pybind11
        GIT_REPOSITORY https://github.com/pybind/pybind11.git
        GIT_TAG v2.12.0
)
FetchContent_MakeAvailable(pybind11)

# ---- Extension module (ONLY ONCE) ----
pybind11_add_module(hivsim_engine
        src/bindings.cpp
        src/System.cpp
        src/kokkos_info.cpp
        src/Grid.cpp
)

target_include_directories(hivsim_engine PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(hivsim_engine PRIVATE Kokkos::kokkos)

set_target_properties(hivsim_engine PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)