cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(/workspaces/File_Compressor_/include)

# Add executable
add_executable(File_Compressor_
                /workspaces/File_Compressor_/src/main.cpp 
                /workspaces/File_Compressor_/src/compressor.cpp
                /workspaces/File_Compressor_/src/huffman.cpp)

# If there are additional libraries in the libs directory
# add_subdirectory(libs)