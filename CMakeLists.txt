cmake_minimum_required(VERSION 3.24)
project(eightpuzzle)

set(CMAKE_CXX_STANDARD 17)

add_executable(eightpuzzle main.cpp header/display.h header/problem.h header/node.h src/node.cpp header/searchalgos.h src/searchalgos.cpp)
