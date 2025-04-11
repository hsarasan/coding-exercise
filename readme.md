Overview

There are two functions implemented 
  a. pad_whole_numbers_in_string => This left pads every whole number of the input string with 0s
  b. pad_whole_numbers_in_stringstream => This pads a characters from a stream (cin, stringstream, fstream etc) and left pads whole numbers with 0s

  Numbers following . and : are not padded in both cases

Source Code Structure

  root
      ---- src
            -------- string_pad.cpp # implementation of the above functions
      ---- include
            -------- string_pad.h  # header file for the above functions
      ----- example
            -------- example_usage.cpp # example usage of pad_whole_numbers_in_string()
            -------- example_stream.cpp # exmaple usage of pad_whole_numbers_in_stringstream()
            -------- input.txt # example file used as input for filestream to use 
      ----- test
            -------- test_pad.cpp # unit test cases to be run with catch
            -------- catch_amalgamated.hpp # testing framework source code downloaded from https://github.com/catchorg/Catch2/releases (latest version 3.8.1)
            -------- catch_amalgamated.cpp # testing framework source code 
      CMakeLists.txt 
      readme.md

How to Build & use
      The source code was compiled with C++17 on Ubuntu 22.04. 
      Steps to build

      mkdir build
      cd build
      cmake ./..
      make

This should create the following executables
  example_program #to test the usage of pad_whole_number_in_string() 
  example_stream  # to test usage of pad_whole_numbers_in_stringstream()
  test_pad # run the unit tests using catch 

  All executables are to be run like ./<executable>
    

Time complexity & Space Complexity

  Function 1 => pad_whole_numbers_in_string()
  
  Time Complexity [ n- length of string, N- pad width]

  we loop over the string once leading to O(n)
  we also for every number detected, do a setw and setfill. So if there are m numbers this would lead to O(m*N)
  So the total time complexity is O(n+n*N) => O(N*n)

  Space complexity is O(n) as we create a new string but the space could be increased by O(N*n) because we pad extra 0s

  Hence Space Complexity is also O(N*m+n)


  Function 2 => pad_whole_numbers_in_stringstream()

  Time Complexity

  We iterate over n characters of the stream processing it at O(1)
  for every number encountered, there could O(N) processing
  So the total complexity is O (n+ m*N) m - no of occurences of Numbers

  Space Complexity

  The space complexity is copy of original string (O(n) ) + padded numbers (O(m*N) 
  So the total Space Complexity is O(n+m*N)


  
           

Testing

  I have used catch for testing as the source code be downloaded and is easier to share than google test.

  I have added the following set of unit test cases

  1. Whole Numbers
  2. Numbers with . and :
  3. Odd Cases (multiple : , multiple .)
  4. Time format (9:34) and decimal format (3.14)
  5. Negative Number
  6. Edge cases - empty string, only numbers in the string
  7. Cases provided in the uphold document
  8. Stream based processing using stringstream



  


  


