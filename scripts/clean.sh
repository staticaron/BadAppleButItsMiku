#!/bin/bash

echo "Deleting old build/"
rm -rf build/
rm -rf .cache/
echo "--------------"

echo "Generate Project Files"
cmake -G Ninja -B build -D CMAKE_BUILD_TYPE=Release -D OpenCV_DIR="C:/open-clang-install"
echo "--------------"

echo "Moving compile_commands.json to root directory of the project"
cp build/compile_commands.json .
echo "--------------"

echo "Build the project"
cmake --build build
echo "--------------"

echo "Finished!"
