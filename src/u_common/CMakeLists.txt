
project(u_common)

aux_source_directory(src FILES)
add_library(${PROJECT_NAME} SHARED ${FILES})
target_link_libraries(${PROJECT_NAME} tinyxml2)

set(INCLUDE_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIB_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR})

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${PROJECT_NAME}Config.cmake.in
    ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_BINARY_DIR}
    PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR
)

install(TARGETS u_common
RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/install
LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/install/lib
ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/install
)

