/*
3.11.5 Odd IteratorWrite an iterator class for odd numbers named odd_iterator. The class must model(realize) the
ForwardIterator concept(http://www.sgi.com/tech/stl/ForwardIterator.html). 
That means itmust provide the following members:• Default and copy constructor;
• operator++ to the next odd element, as pre-increment and post-increment;
• operator* as dereference which returns an (odd) int;• operator== and operator!=; and
• operator=.with the obvious semantics.
In addition, the class should contain a constructor that acceptsan int value.
This value will be returned in the dereference operator (as long as theiterator is not incremented).
This constructor should throw an exception if the value iseven.
Likewise the default constructor should initialize the internal value with 1 to providea legal state.


*/




#include <iostream>
#include <cassert>

class odditr {
public:
	//Default set to 1
	odditr() {
		location = 1;
	}
	//Location Constructor
	explicit odditr(int value) {
		if (value % 2 == 0) {
			throw "Even Number";
		}
		else {
			location = value;
		}
	}
	//Nothing on Heap;
	~odditr() = default;

	//Increment Operator. It's Odd so add 2;
	odditr &operator ++() {
		location += 2;
		return *this;
	}

	//Post-Increment Operator.
	//Refer to 3.3.2 in the textbook.
	odditr operator ++(int x) {
		odditr tmp = *this;
		++(*this);
		return tmp;
	}
	
	//Indirection Operator. Return Location;
	//Assumed to return ODD because of init and Addition Operators checking that
	int operator*() {
		return location;
	}
	//Set This Location equal to the comp one;
	odditr operator=(const odditr& comp) {
		location = comp.location;
		return *this;
	}
	//Equality Operator. I.e., If Both Locations are the same its Equal;
	bool operator==(const odditr& comp) {
		return location == comp.location;
	}
	//Inequality Operator
	bool operator!=(const odditr& comp) {
		return location != comp.location;
	}
private:
	int location;
};


int main() {
	odditr it{};
	assert(*it == 1);
	try {
		odditr it2{ 2 };
	}
	catch (char* str) {
		std::cout << "Threw an Error" << std::endl;
	}
	odditr it3{ 3 };
	assert(*it3 == 3);
	it3++;
	assert(*it3 == 5);

	it = it3;
	assert(*it == 5);
}