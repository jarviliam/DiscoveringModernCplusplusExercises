#include<cassert>
#include <iostream>
#include <vector>


struct sloppy {
	double r, i;
};

class vector {
	//Stan Const
public:
	vector(unsigned n) : my_size{ n }, data{ new double[my_size] } {}
	vector(vector&& v): my_size(v.my_size), data(v.data) {
		//0 in C++03
		v.data = nullptr;
		v.my_size = 0;
	}

	//Swaps pointers to the data
	vector& operator=(vector&& src) {
		assert(my_size == 0 || my_size == src.my_size);
		//std::swap(data, src.data);
		delete[] data;
		data = src.data;
		src.data = nullptr;
		src.my_size = 0;
		return *this;
	}

	double& operator[](int i)
	{
		assert(i >= 0 && i < my_size);
		return data[i];
	}

	inline vector twos(int n) {
		vector v(n);
		for(unsigned i = 0; i < n; ++i)
			//Need to make a [] op
			v[i] = 2.0;
		return v;
	}

	friend std::ostream& operator<< (std::ostream& out, const vector& vect) {
		out << vect.my_size;
		return out;
	}
private:
	unsigned my_size;
	double* data;
};

int main() {
	sloppy z1{ 3.5,2.1 }, z2 = { 0,4 };

	vector y = vector(12);
	vector x = vector(vector(5));
	std::cout << "Vector X: Size = " << x << std::endl;
	vector z = vector(std::move(x));
	
	std::cout << "Vector X: Size = " << x << std::endl;
}