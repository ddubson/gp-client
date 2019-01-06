#!/usr/bin/env bash

# Generate Makefile and respective dependencies for make
cmake -B cmake-build-debug .

# Execute make -- compile
( cd cmake-build-debug ; make )
