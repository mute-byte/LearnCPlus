# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.0)
#project name  
project(HELLOWORLD)
#add compile options
add_compile_options("--std=c++11")
#set CMAKE_BUILD_TYPE
set( CMAKE_BUILD_TYPE Debug )
# set output binary path  
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
############################################################
# Create a library
############################################################
#Generate the static library from the library sources
add_library( solution_lib STATIC src/solution.cpp )
target_include_directories( solution_lib PUBLIC ${PROJECT_SOURCE_DIR}/include )
############################################################
# Create an executable
############################################################
# Add an executable with the above sources
add_executable( helloworld helloworld.cpp )
# link the new swap_01 target with the swap_lib target
target_link_libraries( helloworld solution_lib )
