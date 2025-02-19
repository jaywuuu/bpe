cmake_minimum_required(VERSION 3.10)

project(bpe)
set (CMAKE_CXX_STANDARD 20)

add_executable(bpe
    main.cpp
    bpe.cpp
)

target_include_directories(bpe PUBLIC
    include/
)
