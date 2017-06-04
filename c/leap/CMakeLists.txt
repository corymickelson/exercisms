cmake_minimum_required(VERSION 3.7)
project(leap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        test/vendor/unity.c
        test/vendor/unity.h
        test/vendor/unity_internals.h
        test/test_leap.c src/leap.c src/leap.h)

add_executable(leap test/test_leap.c ${SOURCE_FILES})