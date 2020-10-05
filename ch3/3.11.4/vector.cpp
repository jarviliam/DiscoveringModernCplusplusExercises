//This is where Im stopping. I have no clue and Hopefully I can come back to this in the future

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
		std::copy(li.begin(), li.end(), end());

	}
	//Delete daata because its on the Heap?
	~Vector() {
		delete[] data;
	}
	std::iterator begin() {
		return 
	}
	const std::iterator begin() {

	}
	std::iterator end() noexcept {
		return data + size;
	}
	const std::iterator end() const noexcept {

	}
};

int main() {
	Vector<int> vec = Vector<int>{1,2,3};


}