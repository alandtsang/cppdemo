#!/bin/bash

basepath=$(dirname $(pwd))
buildpath=$basepath/build
binpath=$basepath/bin
echo $basepath

if [ ! -d $buildpath ]; then
    mkdir $buildpath
fi

if [ ! -d $binpath ]; then
    mkdir $binpath
fi

if [ ! -f $buildpath/bin/client ]; then
    cd $buildpath
    cmake ..
    make
    cp bin/client $binpath
    echo "Create client OK"
fi

if [ ! -f $binpath/server ]; then
    go build -o $binpath/server $basepath/src/server.go
    echo "Create server OK"
fi
