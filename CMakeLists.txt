cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)              # Compile as C++17.
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # Require C++17 support.

project(Dature
    VERSION 1.0
    DESCRIPTION "The database system's internal data structure library"
    LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(test)

# add_executable(mytest te.cpp)
# target_link_libraries(mytest PRIVATE dature)
