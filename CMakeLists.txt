cmake_minimum_required(VERSION 3.12)

project(
    Sandpile
    VERSION 1.0
    DESCRIPTION "C++ Sandpile Model"
    LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 17)


add_executable(
        labwork3
        main.cpp
        lib/parser/parser.cpp
        lib/parser/parser.h
        lib/sandpile/sandpile.cpp
        lib/parser/readTSV.cpp
        lib/sandpile/sandpile.h
        lib/sandpile/utilities.cpp
        lib/setupBMP/setupBMP.cpp
        lib/setupBMP/setupBMP.h
)

