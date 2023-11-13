cmake_minimum_required(VERSION 3.24)
project(09)

set(CMAKE_CXX_STANDARD 20)

add_executable(09 main.cpp context.h fiber.h fiber.cpp scheduler.h scheduler.cpp context.cpp)
