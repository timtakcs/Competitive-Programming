#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 path_to_cpp_file"
    exit 1
fi

# Extract the base filename without extension
FILE_NAME=$(basename -- "$1")
BASE_NAME="${FILE_NAME%.*}"

# Compile the program using g++
g++ "$1" -o "$BASE_NAME.out" -std=c++14 -Wall

# If compilation is successful, run the program
if [ $? -eq 0 ]; then
    ./"$BASE_NAME.out"
else
    echo "Compilation failed!"
    exit 2
fi
