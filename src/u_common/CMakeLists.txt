
project(u_common)


set(_msg_cxx_files)
if(EXISTS ${CMAKE_SOURCE_DIR}/thirt_part/local)
set(GEN_COMMAND ${CMAKE_SOURCE_DIR}/thirt_part/src/fastddsgen/scripts/fastddsgen)

file(GLOB _msg_files msg/*.idl)
foreach(name ${_msg_files})
get_filename_component(name ${name} NAME_WE)
list(APPEND _msg_cxx_files ${name}.cxx ${name}PubSubTypes.cxx ${name}Publisher.cxx ${name}Subscriber.cxx)
endforeach()

add_custom_command(OUTPUT ${_msg_cxx_files}
COMMAND  ${GEN_COMMAND} -example  CMake -d ${CMAKE_CURRENT_BINARY_DIR}/ ${_msg_files}
DEPENDS  ${_msg_files})

# add thirt_part
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/thirt_part/local)
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)
endif()

include_directories(
    ${fastcdr_INCLUDE_DIR}
)


aux_source_directory(src _cxx_files)
add_library(${PROJECT_NAME} SHARED ${_cxx_files} ${_msg_cxx_files})
target_link_libraries(${PROJECT_NAME} fastcdr fastrtps)

include(CMakePackageConfigHelpers)
set(INCLUDE_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR} ${fastcdr_INCLUDE_DIR})
set(LIB_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR})
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

