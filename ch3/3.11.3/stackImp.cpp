/*
Write a stack implementation for a generic value type. The maximal size of the stack is
defined in the class (hard-wired).
*/


#include <stdexcept>
#include <cassert>
#include <iostream>
#include <vector>

template <typename T>
struct Stacker {
private:
	int maxSize = 5;
	std::vector<T> cap;
public:
	Stacker() {
		cap.reserve(maxSize);
	}
	~Stacker() {
	}
	T top() {
		if (!empty()) {
			return cap.back();
		}
	}
	void pop() {
		if (!empty()) {
			cap.pop_back();
		}
		else {
			throw std::underflow_error("No Entries BRO!");
		}
	}
	void push(T val) {
		if (!full()) {
			cap.push_back(val);
		}
		else {
			throw std::overflow_error("MAN YOU PUT TOO MUCH IN HERE");
		}
	}
	void clear() {
		cap.clear();
	}
	std::size_t size() {
		return cap.size();
	}
	bool full() {
		return cap.size() == maxSize;
	}
	bool empty() {
		return cap.size() == 0;
	}
};

int main() {
	Stacker<int> s;
	assert(s.size() == 0);
	assert(s.full() == false);
	for (int i = 0; i < 5; ++i) {
		s.push(i);
		assert(s.top() == i);
	}
	assert(s.full() == true);

	for (int i = 0; i < 5; ++i) {
		s.pop();
	}
	assert(s.empty() == true);
}