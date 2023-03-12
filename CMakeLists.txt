cmake_minimum_required(VERSION 3.25)
project("SmallPP")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -O0 -g")

set(
    sources 
    src/object.c
    src/smallpp.c
    src/type.c
)

set(
    single_inheritance_sources
    examples/single_inheritance/main.c
    examples/single_inheritance/my_object.c
    )

add_library(smallpp ${sources})
target_include_directories(smallpp PUBLIC include)

add_executable(single_inheritance ${single_inheritance_sources})
target_include_directories(single_inheritance PUBLIC include)
target_link_libraries(single_inheritance PRIVATE smallpp)

