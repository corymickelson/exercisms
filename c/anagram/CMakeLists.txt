cmake_minimum_required(VERSION 3.7)
project(anagram)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
        src/anagram.h
        test/vendor/unity.c
        test/vendor/unity.h
        test/vendor/unity_internals.h
        test/test_anagram.c
        src/anagram.c)

add_executable(anagram test/test_anagram.c ${SOURCE_FILES})