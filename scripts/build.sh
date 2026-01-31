#!/bin/bash

cmake -G Ninja -B build

cmake --build build

cp compile_commands.json ../
