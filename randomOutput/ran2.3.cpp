#include<cassert>
#include <algorithm>
#include <initializer_list>
#include <iterator>
class vector
{
public:
	//Copy Constructor
	//Initalized Values -> Assign to Private Members -> Create a Double Array on the Heap.
	vector(std::initializer_list<double> vals): my_size(vals.size()), data(new double[my_size]){
		//Copy the Actual Values of the Initalized Members into the Heap Array
		//For whatever reason it wont take the argument
		std::copy(std::begin(vals), std::end(vals), std::begin(&data));
	}

	self& operator=(std::initializer_list<double> values) {
		assert(my_size == values.size());
		std::copy(std::begin(values), std::end(values),std::begin(data));
		return *this;
	}

private:
	unsigned my_size;
	double* data;
	//std::unique_ptr<double[]> data;
};


int main() {

	vector x = vector{ 1.0,2.0,3.0 };
}