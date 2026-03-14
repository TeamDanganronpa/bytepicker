cmake_minimum_required(VERSION 3.30)

project(bytepicker
        DESCRIPTION "Simple, easy-to-use library for positional/mmap bytes reading/writing"
        LANGUAGES C
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

add_library(bytepicker)
target_include_directories(bytepicker PUBLIC "src")
target_sources(bytepicker PRIVATE
        "src/bytepicker/positional/reader/positional_reader.c"
        "src/bytepicker/positional/writer/positional_writer.c"
)