#include <vector>
#include <iostream>

using namespace std;

// implement stack container adapter based on vector container
template<typename T>
class myArrayStack {
private:
	vector<T> vec;

public:
	// push element into stack
	void push(const T& val) {
		vec.emplace_back(val);
	}

	// pop element from stack
	void pop() {
		vec.pop_back();
	}

	// get element from stack
	T get() const {
		return vec.back();
	}

	// return the size of stack
	int size() const {
		return vec.size();
	}
};

int main() {
	myArrayStack<int> stk;
	stk.push(5);
	cout << stk.get() << endl;
	stk.push(4);
	cout << stk.get() << endl;
	stk.push(3);
	cout << stk.get() << endl;
	cout << "size = " << stk.size() << endl;
	stk.pop();
	cout << stk.get() << endl;

	return 0;
}