
project(u_common)

aux_source_directory(src FILES)
add_library(${PROJECT_NAME} ${FILES})