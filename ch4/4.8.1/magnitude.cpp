/*

Create a vector of double and initialize it with the values -9.3, -7.4, -3.8, -0.4, 1.3, 3.9,5.4, 8.2. 
You can use an initializer list. Sort the values by magnitude.
Write• A functor and• A lambda expression for the comparison.
Try both solutions.

*/
#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>


struct functor {
	bool operator()(double x, double y) {
		return abs(x) < abs(y);
	}
};

template <typename BIG>
void printThisBadBoy(const BIG& vect, std::ostream& output) {

	output << "POW POW POW " << std::endl;

	//Man Autos are so cool
	//Even cooler that I understand how Iterators work now
	//This book is actually prettyy decent
	for (auto &e: vect) {
		output << e << " ";
	}
	output << std::endl;
	output << "POW POW POW" << std::endl;
}

int main() {

	std::vector<double> vect = { -9.3, -7.4, -3.8, -0.4, 1.3, 3.9,5.4, 8.2 };

	printThisBadBoy(vect, std::cout);
	//Lmao this is right out of the textbook
	std::sort(vect.begin(), vect.end(), [](double x, double y) {return abs(x) < abs(y); });

	assert(vect[0] == -0.4);
	printThisBadBoy(vect, std::cout);

	//Time for my Functor, Its the same tho
	vect = { -9.3, -7.4, -3.8, -0.4, 1.3, 3.9,5.4, 8.2 };
	functor fx = functor();
	std::sort(vect.begin(), vect.end(), fx);
	assert(vect[0] == -0.4);
	printThisBadBoy(vect, std::cout);
}