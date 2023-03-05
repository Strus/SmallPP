cmake_minimum_required(VERSION 3.25)
project("SmallPP")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(
    sources 
    main.c
    include/smallpp/object.h
)

add_executable(smallpp ${sources})

target_include_directories(smallpp PUBLIC include)
