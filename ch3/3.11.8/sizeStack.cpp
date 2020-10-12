/*
 
 3.11.8 Stack with Custom Size
 Revise your stack implementation from Exercise 3.11.3 
 (and optionally that of Exercise3.11.7) with a user-defined size.
 The size is passed as the second template argument. Thedefault should be 4096.
 
 */
#include <vector>
#include <cassert>

template <typename T, std::size_t S = 4096>
struct Stacker {
private:
	std::vector<T> cap;
public:
	Stacker() {
		cap.reserve(S);
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

	Stacker<int, 15> stack;

}