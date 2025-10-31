#!/bin/bash

echo "Deleting old build/"
rm -rf build/
rm -rf .cache/
echo "--------------"

echo "Create New build/ folder"
mkdir build/
echo "--------------"

echo "Moving into build/ folder"
cd build
echo "--------------"

echo "Generate Project Files"
cmake -GNinja ..
echo "--------------"

echo "Moving compile_commands.json to root directory of the project"
cp compile_commands.json ..
echo "--------------"

echo "Build the project"
ninja
echo "--------------"

echo "Finished!"
