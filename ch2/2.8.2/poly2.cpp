/*
2.8.2 Move AssignmentWrite a move assignment operator for the polynomial in Exercise 2.8.1.
Define the copyconstructor as default. To test whether your assignment is used write a functionpolynomial f(double c2, double c1, double c0) that takes 
threecoefficients and returns a polynomial.
Print out a message in your move assignment or usea debugger to make sure your assignment is used

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

	Polynominal(double c2, double c1, double c0) {
		coef.push_back(c2);
		coef.push_back(c1);
		coef.push_back(c0);

	}

	//Normal Copy Assignment -> Default
	Polynominal& operator=(const Polynominal &py) = default;

	//Move Operator for R-Value Refs
	Polynominal& operator=(const Polynominal&& py) {
		coef = std::move(py.coef);
		std::cout << "Holla At a Player we Moved that" << std::endl;
		return *this;
	}
	

	//Output 
	friend std::ostream& operator << (std::ostream& out, const Polynominal& poly)
	{
		for (auto const& value : poly.coef) {
			out << value << ",";
		}
		return out;
	}
};

	//This should return a poly because theres a constructor for it.
Polynominal f(double c2, double c1, double c0) { return { c2,c1,c0 }; };
int main() {
	Polynominal poly;
	poly = f(1.0, 2, 3);
		std::cout << poly << std::endl;
		Polynominal poly2 = { 10,11,12 };
		Polynominal poly3 = { 22, 33, 44 };
		poly2 = poly3;
		std::cout << "There Should be no move here" << std::endl;
		std::cout << poly2;
}