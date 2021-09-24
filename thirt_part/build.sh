#!/bin/bash


BUILD_PREFIX=$PWD
build_init() {
    if [ -d ${BUILD_PREFIX}/build ];then
      rm -rf ${BUILD_PREFIX}/build/*
    else
      mkdir ${BUILD_PREFIX}/build
    fi

    if [ "$PWD" != "${BUILD_PREFIX}/build" ];then
      cd ${BUILD_PREFIX}/build
    fi
    cmake -DCMAKE_INSTALL_PREFIX=$BUILD_PREFIX/local $2  $1 &&\
    cmake --build . --target install
}

# 需要下载
# tinyxml2 asio
# 下载 fastdds发布源码

build_init ../src/fastcdr 
build_init ../src/tinyxml2/ 
build_init ../src/foonathan_memory_vendor
build_init ../src/fastrtps "-DAsio_INCLUDE_DIR=../src//asio/asio/include"




