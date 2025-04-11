#include <iostream>
#include <fstream>
#include <string>
#include "string_pad.h"

int main() {
    // Define the padding width (e.g., pad numbers to 3 digits)
    int width = 3;

    // Open an input file
    std::ifstream input_file("input.txt");

    if (!input_file) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }

    // Process the stream from the file
    std::string output = string_utils::pad_whole_numbers_in_stringstream(input_file, width);

    // Output the processed text
    std::cout << "Processed text: " << output << std::endl;

    return 0;
}

