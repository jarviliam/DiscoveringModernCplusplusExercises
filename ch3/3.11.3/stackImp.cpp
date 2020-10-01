#include <stdlib.h>
#include <cassert>
#include <vector>

template <typename T>
struct Stacker {
private:
	int maxSize = 5;
	std::vector<T> cap;
public:

	stacker() {
	}
	~stacker() {
	}
	T top() {
		return cap.back;
	}
	void pop() {
		if (!empty()) {
			cap.pop_back();
		}
	}
	void push(T val) {
		if (!full()) {
			cap.push_back(val);
		}
	}
	void clear() {
		cap.clear();
	}
	int size() {
		return cap.size;
	}
	bool full() {
		return cap.size == maxSize;
	}
	bool empty() {
		return cap.size == 0;
	}
};

int main() {

	Stacker s = Stacker();
}