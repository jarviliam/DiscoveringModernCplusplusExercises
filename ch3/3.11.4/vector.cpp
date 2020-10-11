//This is where Im stopping. I have no clue and Hopefully I can come back to this in the future
//Figured it out. I'm not return std::iterator, but a pointer to the beginning and end entries
/*

3.11.4 Iterator of a VectorAdd the methods begin() and end() for returning a begin and end iterator to classvector. Add the types iterator and const_iterator to the class as well. 
Notethat pointers are models of the concept of random-access iterators.Use the STL function sort for ordering vector entries to demonstrate that youriterators work as they should.

*/

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

template <typename T>
class Vector {
private:
	T* data{};
	std::size_t sz{};
public:
	Vector(std::initializer_list<T> li) {
		sz = li.size();
		data = new T[sz];
		std::copy(li.begin(), li.end(), begin());
		std::cout << "Copied" << std::endl;
	}

	~Vector() {
		delete[] data;
	}
	//Pointer to First entry
	 T* begin() {
		 return data;
	}
	const T*begin() const noexcept {
		return data;
	}
	//Returns a Pointer of the end address. (Though you need to -1 for the actual last value)
	T* end() {
		return data + sz;
	}
	//Return Const Pointer of 
	const T* end() const noexcept {
		return data + sz;
	}
	//Ignore
	friend std::ostream& operator << (std::ostream& os, const Vector& vec) {
		//Because *vec.end()-1 is diff from *(vec.end()-1)
		os << *(vec.end()-1) << std::endl;
		return os;
	}
};

int main() {
	Vector<int> vec{2,5,3};
	std::sort(vec.begin(), vec.end());
	assert(*vec.begin() == 2);
	assert(*(vec.end() - 1) == 5);
	std::cout << vec << std::endl;

}