cmake_minimum_required(VERSION 3.16)
project(HIVSIM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

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

target_include_directories(hivsim PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)