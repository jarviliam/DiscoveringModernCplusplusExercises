#include <cassert>
#include <iostream>
#include <vector>



template <typename T, typename U>
double Trapezoid(T func,U a, U b) {
	int n = 500;
	//Calculate H
	double h = (b - a) / n;

	//Calculate the Summation
	double summation = 0;
	for (int i = 0; i <= n - 1; ++i) {
		summation += func(a + (i * h));
	}
	return (h / 2) * func(a) + (h / 2) * func(b) + (h * summation);
}

double exp3f(double x) { return std::exp(3.0 * x); }
struct exp3t { double operator() (double x) const { return std::exp(3.0 * x); } };

//Functor
struct func {
	double operator()(double val){ return val < 1 ? std::sin(val) : std::cos(val); }
};
int main() {

	//Test these two function abovve
	std::cout << Trapezoid(exp3f, 0.0, 4.0) << std::endl;

	exp3t exp;
	std::cout << Trapezoid(exp, 0.0, 4.0) << std::endl;

	func f;
	std::cout << Trapezoid(f, 0.0, 4.0) << std::endl;

	//std::cout << Trapezoid(std::sin, 0.0, 2.0)<< std::endl;
}