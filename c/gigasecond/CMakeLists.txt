cmake_minimum_required(VERSION 3.7)
project(gigasecond)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        test/vendor/unity.c
        test/vendor/unity.h
        test/vendor/unity_internals.h
        test/test_gigasecond.c src/gigasecond.c src/gigasecond.h)

add_executable(gigasecond test/test_gigasecond.c ${SOURCE_FILES})