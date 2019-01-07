cmake_minimum_required(VERSION 3.13)
project(gp_client)

set(CMAKE_CXX_STANDARD 14)

# Link libpqxx and libpq
set(CMAKE_EXE_LINKER_FLAGS "-lpqxx -lpq")

file(GLOB SOURCES "src/*.cpp" "src/.h")
add_executable(gp_client ${SOURCES})