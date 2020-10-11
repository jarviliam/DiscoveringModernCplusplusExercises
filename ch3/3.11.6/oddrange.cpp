/*
Write a class for a range of odd numbers. 
The member or free functions begin and endshould return an odd_iterator as defined in Exercise 3.11.
*/

#include <iostream>
#include "odditr.h"

class odd_range {
private :
	int x, y;
public :
	//Take the Start and End Values
	odd_range(int st, int ed) {
		x = st;
		y = ed;
	}
	//Free Function returns an odditr 
	inline odditr begin() {
		odditr sx(x);
		return sx;
	}
	//Free Function also returns an odd_itr
	inline odditr end() {
		odditr sy(y);
		return sy;
	}
};

int main() {
	//The For loop retrieves the std::begin() from inline begin and the end from inline end;
	for (int i : odd_range(7, 27)) {
		std::cout << i << "\n";
	}
}