cmake_minimum_required (VERSION 3.5)
project(MyFormat)

SET(CMAKE_CXX_FLAGS "-std=c++20")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


# Add sub directories
add_subdirectory(libs/Formatter)
add_subdirectory(libs/tests)
add_subdirectory(Main)