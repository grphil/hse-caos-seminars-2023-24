cmake_minimum_required(VERSION 3.28)

project(main)

add_executable(main main.cpp a.cpp)

enable_testing()
add_subdirectory(tests)
