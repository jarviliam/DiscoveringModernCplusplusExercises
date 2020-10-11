#pragma once
#ifndef odditr
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
#endif // !odditr

