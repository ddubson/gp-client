#!/usr/bin/env bash

# Generate Makefile and respective dependencies for make
cmake -DCMAKE_BUILD_TYPE=Release -B release .

# Execute make -- compile
( cd release ; make )

