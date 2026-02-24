cmake_minimum_required(VERSION 3.16)
project(HIVSIM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

add_compile_options(-fPIC)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Kokkos_ENABLE_PIC ON CACHE BOOL "" FORCE)
set(Kokkos_ENABLE_SERIAL ON CACHE BOOL "" FORCE)

FetchContent_Declare(
        kokkos
        GIT_REPOSITORY https://github.com/kokkos/kokkos.git
        GIT_TAG 4.5.01
)
FetchContent_MakeAvailable(kokkos)

FetchContent_Declare(
        pybind11
        GIT_REPOSITORY https://github.com/pybind/pybind11.git
        GIT_TAG v2.12.0
)
FetchContent_MakeAvailable(pybind11)

pybind11_add_module(hivsim
        src/bindings.cpp
        src/System.cpp
)

target_include_directories(hivsim PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(hivsim PRIVATE Kokkos::kokkos)
