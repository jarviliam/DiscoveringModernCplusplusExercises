#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

template <typename T, typename U>
double Trapezoid(T func, U a, U b) {
    int n = 300;

    double h = (b - a) / n;

    double summation = 0;

    for (int i = 0; i <= n - 1; ++i) {
        summation += func(a + (i * h));
    }
    return (h / 2) * func(a) + (h / 2) * func(b) + (h * summation);
}

int main() {
    std::cout << Trapezoid([](double x) { return std::exp(3.0 * x); }, 0.0,
                           4.0);
}
