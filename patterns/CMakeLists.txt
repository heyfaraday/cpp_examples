cmake_minimum_required (VERSION 3.9 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(patterns)

add_subdirectory(decorator)
add_subdirectory(composite)
add_subdirectory(specification)
add_subdirectory(builder)

add_subdirectory(memento)
add_subdirectory(observer)
add_subdirectory(interpreter)