#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "string_pad.h"
	
using namespace std;

namespace string_utils{
	
	string pad_whole_numbers_in_string(const string& input, int N) {
	    ostringstream result;
	    size_t i = 0;
	    while (i < input.size()) {
	        // Skip non-digit characters
	        if (!isdigit(input[i])) {
	            result << input[i];
	            ++i;
	            continue;
	        }
	
	        // Check if it's preceded by '.' or ':'
	        if (i > 0 && (input[i - 1] == '.' || input[i - 1] == ':')) {
	            // Copy the number as-is
	            while (i < input.size() && isdigit(input[i])) {
	                result << input[i++];
	            }
	            continue;
	        }
	
	        
	        size_t start = i;
	        while (i < input.size() && isdigit(input[i])) {
	            ++i;
	        }
	        string number = input.substr(start, i - start);
	
	        // Pad with leading zeros
	        ostringstream padded;
	        padded << setw(N) << setfill('0') << number;
	        result << padded.str();
	    }
	
	    return result.str();
	}
	
	
	string pad_whole_numbers_in_stringstream(istream& input, int N) {
	    ostringstream result;
	    bool processing_number = false;
	    bool skip_padding = false;  
	    bool was_punctuation = false; 
	    string current_number;
	    
	    for (char ch; input.get(ch); ) {
	        if (isdigit(ch)) {
	            // Beginning a new number: set skip_padding based on preceding punctuation
	            if (!processing_number) {
	                processing_number = true;
	                skip_padding = was_punctuation;
	                current_number.clear();
	            }
	            current_number.push_back(ch);
	            was_punctuation = false;
	        } else {
	            // If a number was being processed, flush it to the result before handling the character.
	            if (processing_number) {
	                if (!skip_padding) {
	                    ostringstream padded;
	                    padded << setw(N) << setfill('0') << current_number;
	                    result << padded.str();
	                } else {
	                    result << current_number;
	                }
	                processing_number = false;
	                skip_padding = false;
	                current_number.clear();
	            }
	
	            // Set the punctuation flag if the current character is '.' or ':'
	            if (ch == '.' || ch == ':') {
	                was_punctuation = true;
	            } else {
	                was_punctuation = false;
	            }
	            result << ch;
	        }
	    }
	    
	    // Flush any number remaining at the end of the stream.
	    if (processing_number) {
	        if (!skip_padding) {
	            ostringstream padded;
	            padded << setw(N) << setfill('0') << current_number;
	            result << padded.str();
	        } else {
	            result << current_number;
	        }
	    }
	    return result.str();
	}

} //namespace string_utils
