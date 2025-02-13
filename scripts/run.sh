#!/bin/bash

if [ ! -d "build" ]; then
    echo "Build directory does not exist. Please build the project first using build.sh."
    exit 1
fi

cd build
cd bin
./obang
