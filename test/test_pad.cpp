#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include "string_pad.h"
#include <sstream>

using namespace string_utils;

TEST_CASE("Whole numberss are padded", "[pad_whole_numbers_in_string]") {
    REQUIRE(pad_whole_numbers_in_string("ID 7 and 42", 4) == "ID 0007 and 0042");
    REQUIRE(pad_whole_numbers_in_string("Agent 007", 5) == "Agent 00007");
}

TEST_CASE("Numbers after '.' or ':' are not padded", "[pad_whole_numbers_in_string]") {
    REQUIRE(pad_whole_numbers_in_string("Time is 9:45", 2) == "Time is 09:45");
    REQUIRE(pad_whole_numbers_in_string("Decimal 3.14", 2) == "Decimal 03.14");
}

TEST_CASE("Odd Cases", "[pad_whole_numbers_in_string]") {
    REQUIRE(pad_whole_numbers_in_string("Time is 9:45:21", 2) == "Time is 09:45:21");
    REQUIRE(pad_whole_numbers_in_string("Decimal 3.14.2", 2) == "Decimal 03.14.2");
}

TEST_CASE("Uphold Provided Cases", "[pad_whole_numbers_in_string]") {
    REQUIRE(pad_whole_numbers_in_string("James Bond 7", 3) == "James Bond 007");
    REQUIRE(pad_whole_numbers_in_string("PI=3.14", 2) == "PI=03.14");
    REQUIRE(pad_whole_numbers_in_string("It's 3:14PM", 2) == "It's 03:14PM");
    REQUIRE(pad_whole_numbers_in_string("99UR1336", 6) == "000099UR001336");
}


TEST_CASE("Negative Number", "[pad_whole_numbers_in_string]") {
    REQUIRE(pad_whole_numbers_in_string("Negative Number -1.2", 2) == "Negative Number -01.2");
}

TEST_CASE("Edge Cases", "[pad_whole_numbers_in_string]") {
    REQUIRE(pad_whole_numbers_in_string("", 2) == "");
    REQUIRE(pad_whole_numbers_in_string("1", 2) == "01");
    REQUIRE(pad_whole_numbers_in_string("0.1", 2) == "00.1");
}


TEST_CASE("Mixed content", "[pad_whole_numbers_in_string]") {
    std::string input = "Code 8 at 12:34 and level 9.5";
    std::string expected = "Code 0008 at 0012:34 and level 0009.5";
    REQUIRE(pad_whole_numbers_in_string(input, 4) == expected);
}

TEST_CASE("Stream-based processing", "[process_stream]") {
    std::istringstream ss("Time 42 starts at 1:23 and ends at 2.45");
    REQUIRE(pad_whole_numbers_in_stringstream(ss, 3) == "Time 042 starts at 001:23 and ends at 002.45");
}

