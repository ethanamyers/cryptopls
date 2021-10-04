cmake_minimum_required(VERSION 3.20)
project(cryptopls)

set(CMAKE_CXX_STANDARD 14)

add_library(cryptopls string_manipulation.cpp frequency_cmp.cpp frequency_cmp.h)
