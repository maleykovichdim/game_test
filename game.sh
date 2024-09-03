#!/bin/bash

# Create a build directory if it doesn't exist
mkdir -p build && cd build

# Run CMake to configure the project
cmake ..

# Compile the project
make

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Please check for errors."
    exit 1
fi

# Run the threaded version of the program
echo "Running in threaded mode:"
./PlayerComm thread

# Run the process version of the program
echo "Running in process mode:"
./PlayerComm process

# Go back to the original directory
cd ..
