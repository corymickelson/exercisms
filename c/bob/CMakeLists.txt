cmake_minimum_required(VERSION 3.7)
project(bob)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        test/vendor/unity.c
        test/vendor/unity.h
        test/vendor/unity_internals.h
        test/test_bob.c
        src/bob.c
        src/bob.h)

add_executable(bob test/test_bob.c ${SOURCE_FILES})