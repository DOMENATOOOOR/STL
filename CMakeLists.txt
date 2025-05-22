cmake_minimum_required(VERSION 3.29)
project(stl)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party/googletest)

add_executable(stl main.cpp
        WaveAlgorithm.cpp
        WaveAlgorithm.h
        ReadWriteFile.cpp
        ReadWriteFile.h
)

add_executable(tests
        WaveAlgorithm.cpp
        tests/test.cpp
        WaveAlgorithm.h
        ReadWriteFile.cpp
        ReadWriteFile.h
)

target_link_libraries(tests gtest)
