

project(u_unit)

# 引入第三方库
## 方法 1
# 
#
#

#target_include_directories(
#
#)
#set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
find_package(u_common)

include_directories(
    ${u_common_INCLUDE_DIR}
)
link_directories(
    ${u_common_LIBS}
)

message(STATUS "include=${u_common_INCLUDE_DIR}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

aux_source_directory(src FILES)
add_executable(${PROJECT_NAME}_node ${FILES})
target_link_libraries(${PROJECT_NAME}_node u_common)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_node
DESTINATION ${CMAKE_SOURCE_DIR}/install/bin
)

