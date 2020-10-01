/*
Write a variadic template function that represents an arbitrary number of arguments as a
tuple in a string. That is, the function call to_tuple_string(x, y, z) returns a
string of the form (x, y, z) by printing each element to a string stream.
*/
#include <iostream>
#include<sstream>
#include <cassert>


template <typename... T>
std::string to_tuple_string(const T &... params) {
	std::stringstream s;
	(s << ... << params);
	return s.str();
}

int main() {
	assert(to_tuple_string(1234, "Hey", 1, "TupleThis") == "1234Hey1TupleThis");
};