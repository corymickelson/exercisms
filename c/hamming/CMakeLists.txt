cmake_minimum_required(VERSION 3.7)
project(hamming)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        test/vendor/unity.c
        test/vendor/unity.h
        test/vendor/unity_internals.h
        test/test_hamming.c
        src/hamming.c
        src/hamming.h)

add_executable(hamming test/test_hamming.c ${SOURCE_FILES})