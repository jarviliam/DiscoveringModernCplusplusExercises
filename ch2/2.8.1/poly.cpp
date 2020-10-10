/*
2.8.1 PolynomialWrite a class for polynomials that should at least contain:
• A constructor giving the degree of the polynomial;
• A dynamic array/vector/list of double to store the coefficients;
• A destructor;
and• A output function for ostream.
Further members like arithmetic operations are optiona

*/
#include <cassert>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <iostream>

class Polynominal {
private:
	int degree{};
	std::vector<double> coef{};

public:
	//Init List
	//Just you know, Assuming Degree = 1 on init lists
	Polynominal(std::initializer_list<double> bah) : coef(bah), degree(1) {};
	//Const With Degree
	Polynominal() = default;
	explicit Polynominal(int degree) : degree(degree){}
	~Polynominal() = default;
	//Output 
	friend std::ostream& operator << (std::ostream& out, const Polynominal& poly)
	{
		for (auto const& value : poly.coef) {
			out << value << ",";
		}
		return out;
	}
	//Arithmetic Addition
	//StackOverflow said to use std::transform
	Polynominal& operator +=(const Polynominal& py) {
		//Assert same size
		assert(coef.size() == py.coef.size());
		//Add These Bad Boys Together
		std::transform(coef.begin(), coef.end(),  py.coef.begin(), coef.begin(), std::plus<double>());
		return *this;
	}
	//Same thign as above
	Polynominal& operator -= (const Polynominal& py) {
		assert(coef.size() == py.coef.size());
		std::transform(coef.begin(), coef.end(), py.coef.begin(), coef.begin(), std::minus<double>());
			return *this;
	}

};

int main() {

	Polynominal p1{ 12,54,64 };
	Polynominal p2{ 1,2,3 };

	p1 += p2;
	std::cout << p1 << std::endl;
	p1 -= p2;
	std::cout << p1;
}