cmake_minimum_required(VERSION 3.0.0)
project(hello_wasm VERSION 0.1.0)

add_executable(side side.c)
set_target_properties(side PROPERTIES SUFFIX ".wasm")
target_link_options(side PRIVATE
    "--no-entry"
    "-sSIDE_MODULE"
)
target_link_options(side PRIVATE
    "--no-entry"
    "-sSIDE_MODULE=2"
)

add_executable(main main.c)
target_compile_options(main PRIVATE "-fPIC")
target_link_options(main PRIVATE
    "-sEXPORT_ES6"
    "-sMODULARIZE"
    "-sMAIN_MODULE=2"
)
set_target_properties(main PROPERTIES SUFFIX ".js")
