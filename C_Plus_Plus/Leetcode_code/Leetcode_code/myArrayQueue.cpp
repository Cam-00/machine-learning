#include <iostream>
#include "CycleArray.h"

using namespace std;

template<typename T>
class myArrayQueue {
private:
	CycleArray<T> vec;

public:
	// define constructors and deconstructor
	myArrayQueue(){
		vec = CycleArray<T>();
	}
	myArrayQueue(const myArrayQueue& arr):vec(arr){}
	~myArrayQueue(){}

	// define push member func
	void push(const T& value) {
		vec.addLast(value);
	}

	// define pop member func
	void pop() {
		vec.removeFirst();
	}

	// define front member func
	T front() const {
		return vec.getFirst();
	}

	// define back member func
	T back() const {
		return vec.getLast();
	}

	// define size member func
	size_t size() const {
		return vec.getSize();
	}

};

int main() {

	myArrayQueue<int> q;
	for (int i = 0; i < 5; i++) {
		q.push(i);
	}
	cout << "size = " << q.size() << endl;

	q.pop();
	cout << "q.front = " << q.front() << endl;
	cout << "q.back = " << q.back() << endl;
	cout << "size = " << q.size() << endl;



	return 0;
}