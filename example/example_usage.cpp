#include <iostream>
#include "string_pad.h"

int main() {
    // Define the input string
    std::string input = "I have 4 apples and 12 bananas. I need 1.4 months to finish.";
    
    // Define the padding width (e.g., pad numbers to 3 digits)
    int width = 3;
    
    // Use the function to pad whole numbers in the input string
    std::string output = string_utils::pad_whole_numbers_in_string(input, width);
    
    // Output the original and processed strings
    std::cout << "Original: " << input << std::endl;
    std::cout << "Processed: " << output << std::endl;

    return 0;
}

