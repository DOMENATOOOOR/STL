cmake_minimum_required(VERSION 3.29)
project(stl)

set(CMAKE_CXX_STANDARD 20)

add_executable(stl main.cpp
        WaveAlgorithm.cpp
        WaveAlgorithm.h)
