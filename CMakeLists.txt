# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(StringPadExample)

# Set the C++ standard to C++17 (you can adjust this if necessary)
set(CMAKE_CXX_STANDARD 17)

# Specify the include directory for header files
include_directories(include)

# Add the source files
add_library(string_pad src/string_pad.cpp)

# Add the executable target for the example program
add_executable(example_program example/example_usage.cpp)

# Add the executable target for the stream example
add_executable(example_stream example/example_stream.cpp)

# Link the string_pad library with the example programs
target_link_libraries(example_program string_pad)
target_link_libraries(example_stream string_pad)

# Copy the input.txt file from the examples directory to the build directory
configure_file(${CMAKE_SOURCE_DIR}/example/input.txt ${CMAKE_BINARY_DIR}/input.txt COPYONLY)

# Add test executable
add_executable(test_pad test/test_pad.cpp test/catch_amalgamated.cpp)

# Link your library
target_link_libraries(test_pad string_pad)

# Include test directory for catch_amalgamated.hpp
target_include_directories(test_pad PRIVATE ${CMAKE_SOURCE_DIR}/test)

# Enable testing and define the test
enable_testing()
add_test(NAME pad_tests COMMAND test_pad)

