#!/bin/bash

cmake -G Ninja -B build -D CMAKE_BUILD_TYPE=Release

cmake --build build

cp build/compile_commands.json ../ 
