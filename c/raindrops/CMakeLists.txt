cmake_minimum_required(VERSION 3.7)
project(raindrops)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES
        test/vendor/unity.c
        test/vendor/unity.h
        test/vendor/unity_internals.h
        test/test_raindrops.c src/raindrops.c src/raindrops.h)

add_executable(raindrops test/test_raindrops.c ${SOURCE_FILES})