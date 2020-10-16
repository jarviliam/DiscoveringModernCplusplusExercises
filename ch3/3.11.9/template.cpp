#include <cassert>
#include <vector>


template <typename T, std::size_t sz>
//Const Array of Typename T References. 
std::size_t array_size(const T (&array)[sz]) {
	return sz;
}

int main() {
	double doub[32];
	assert(32 == array_size(doub));

	unsigned int test[123];
	assert(123 == array_size(test));
}