#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 path_to_cpp_file"
    exit 1
fi

FILE_NAME=$(basename -- "$1")
BASE_NAME="${FILE_NAME%.*}"

g++ "$1" -o "a.out" -std=c++14 -Wall

# If compilation is successful, run the program
if [ $? -eq 0 ]; then
    ./"a.out"
else
    echo "Compilation failed!"
    exit 2
fi
