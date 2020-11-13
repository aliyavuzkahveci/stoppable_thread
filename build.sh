#!/bin/bash

# removing previously built binary
rm stoppable_thread

# cleaning old build
rm -rf build/

# creating build folder
mkdir build

cd build/

# preparation of Makefile
cmake ..

# compile & build
make

# copying the binary to the rott project folder
cp stoppable_thread ../

# starting binary
./stoppable_thread
