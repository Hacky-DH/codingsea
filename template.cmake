# Copyright (c) 2018 Hacky DH
#
# This file is distributed under MIT License. See the LICENSE file for details.

file(GLOB sources "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
foreach(src ${sources})
  get_filename_component(name ${src} NAME_WE)
  add_executable(${name} ${src})
  target_compile_options(${name} PRIVATE -std=c++11 -Wall)
endforeach()
