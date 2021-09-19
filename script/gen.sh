#!/bin/bash

if [ ! -z "$1" ];then
echo "#define MY_TEST 1" >$1
fi