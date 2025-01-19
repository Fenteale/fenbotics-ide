cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

project(fenbotics_ide)

include(scripts/imgui.cmake)
add_subdirectory(src)
add_subdirectory(json)

