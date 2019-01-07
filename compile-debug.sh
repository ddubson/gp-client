#!/usr/bin/env bash

# Generate Makefile and respective dependencies for make
cmake -DCMAKE_BUILD_TYPE=Debug -B cmake-build-debug .

# Execute make -- compile
( cd cmake-build-debug ; make )
