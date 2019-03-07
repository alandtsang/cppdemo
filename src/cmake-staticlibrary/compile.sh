#!/bin/bash

base=$(pwd)
basebin=$base/bin
rm -rf $basebin
mkdir -p $basebin

cd src
source=$(pwd)
echo $source

buildpath=$source/build
#rm -rf $source
mkdir $buildpath

cd $buildpath
cmake ..
make -j4
cp test $basebin
