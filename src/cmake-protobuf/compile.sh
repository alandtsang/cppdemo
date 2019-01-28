#!/bin/bash

basepath=$(pwd)
echo $basepath

buildpath=$basepath/build
rm -rf $buildpath
mkdir $buildpath

cd $buildpath
cmake ..
make
