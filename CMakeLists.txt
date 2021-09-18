
cmake_minimum_required(VERSION 3.10)
project(main VERSION 1.0)

option(PRINT_VERSION "version" ON)
option(PRINT_BUILD_TYPE "build_type" OFF)

configure_file(cmake/u_config.h.in config.h)


if(PRINT_VERSION)
message(STATUS ${PROJECT_BINARY_DIR} ${VERSION})
endif()

add_subdirectory(src/u_common)
add_subdirectory(src/u_unit)