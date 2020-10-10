/*
2.8.3 Initializer ListExpand the program from Exercise 2.8.1 with a constructor and an assignment operatorfor a initializer list.
The degree of the polynomial should be the length of the initializer listminus one afterward

I basically did it in the first example
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
	Polynominal(std::initializer_list<double> bah) : coef(bah), degree(bah.size()-1) {};
	//Const With Degree
	Polynominal() = default;
	explicit Polynominal(int degree) : degree(degree){}
	~Polynominal() = default;

	Polynominal& operator =(std::initializer_list<double> list) {

		assert(list.size() > 1);
		coef.assign(list.begin(), list.end());
		degree = list.size() - 1;
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
	Polynominal p1{ 1,2,3,4 };
	Polynominal p2;
	p2 = { 1,2,3 };
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
}