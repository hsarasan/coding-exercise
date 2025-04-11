#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

namespace string_utils{

	string pad_whole_numbers_in_string(const std::string& input, int N);
	string pad_whole_numbers_in_stringstream(istream& input, int N);

}
