/*
3.11.1
Write a generic function to_string that takes an argument of an arbitrary type (as
const&) and generates a string by piping it to a std::stringstream and returning
the resulting string.
*/

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cassert>


template <typename T>
std::string to_string(const T& param) {
	std::stringstream s;
	s << param;
	return s.str();
};

int main() {
	assert("123456780" == to_string(123456780));
	assert("testing1234" == to_string("testing1234"));
}