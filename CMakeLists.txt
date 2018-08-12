# Copyright (c) 2018 Hacky DH
#
# This file is distributed under MIT License. See the LICENSE file for details.

cmake_minimum_required(VERSION 2.8)
project(codingsea CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")

# include all source.cmake in sub directory
file(GLOB files "${CMAKE_CURRENT_LIST_DIR}/*/source.cmake")
foreach(file ${files})
  include(${file})
endforeach()
