cmake_minimum_required(VERSION 3.30)

project(bytepicker
        DESCRIPTION "Simple, easy-to-use library for positional/mmap bytes reading/writing"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

add_library(bytepicker)
target_include_directories(bytepicker PUBLIC "src")
target_sources(bytepicker PRIVATE
        "src/bytepicker/positional/reader/open.cpp"
        "src/bytepicker/positional/writer/open.cpp"
)
