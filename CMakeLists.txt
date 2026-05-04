cmake_minimum_required(VERSION 3.10)

project(BioSimulator VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

set(SOURCES
    main.c
    engine.c
    biology.c
)

add_executable(simulator ${SOURCES})