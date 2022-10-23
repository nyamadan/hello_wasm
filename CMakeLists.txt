cmake_minimum_required(VERSION 3.0.0)
project(hello_wasm VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(add add.c)
set_target_properties(add PROPERTIES SUFFIX ".wasm")
target_link_options(add PRIVATE "--no-entry")
