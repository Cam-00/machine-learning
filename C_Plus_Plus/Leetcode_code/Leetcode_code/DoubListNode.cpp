#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template<typename T>
class DoubListNode {
	//define a node
	struct Node {
		T val;
		Node* pre;
		Node* next;
		Node(T value) :val(value), pre(nullptr), next(nullptr) {};
	};

	//define head node , tail node, list's size
	Node* head;
	Node* tail;
	int size;

public:
	//define constructor
	DoubListNode() {
		head = new Node(T());
		tail = new Node(T());
		head->next = tail;
		tail->pre = head;
		size = 0;
	}

	//define deconstructor
	~DoubListNode() {
		while (size > 0) {
			removeFirst();
		}
		head->next = nullptr;
		tail->pre = nullptr;
		delete head;
		delete tail;
	}

	//define add member func
	void addLast(T var) {
		Node* newNode = new Node(var);
		Node* temp = tail->pre;
		temp->next = newNode;
		newNode->pre = temp;
		newNode->next = tail;
		tail->pre = newNode;
		size++;
	}

	void addFirst(T var) {
		Node* newNode = new Node(var);
		Node* temp = head->next;
		head->next = newNode;
		newNode->pre = head;
		newNode->next = temp;
		temp->pre = newNode;
		size++;
	}

	void add(int index, T var) {  //index: start from 0, 1, ...
		checkBoundary(index);  // check whether index is over the boundary

		Node* pos = getNode(index);  // find the postion to index and return the corresponding node
		Node* newNode = new Node(var);
		Node* temp = pos->pre;
		temp->next = newNode;
		newNode->pre = temp;
		newNode->next = pos;
		pos->pre = newNode;
		size++;
	}

	//define remove member func
	void removeLast() {
		if (size < 1) {
			throw std::out_of_range("No element to remove");
		}
		Node* x = tail->pre;
		Node* temp = x->pre;
		temp->next = tail;
		tail->pre = temp;
		
		x->next = nullptr;
		x->pre = nullptr;
		delete x;
		size--;
	}

	void removeFirst() {
		if (size < 1) {
			throw std::out_of_range("No element to remove");
		}
		Node* x = head->next;
		Node* temp = x->next;
		head->next = temp;
		temp->pre = head;

		x->pre = nullptr;
		x->next = nullptr;
		delete x;
		size--;
	}

	void removeAny(int index) {
		checkBoundary(index);
		if (index + 1 == size) {
			removeLast();
			return;
		}
		if (index == 0) {
			removeFirst();
			return;
		}
		Node* x = getNode(index);
		Node* temp = x->pre;
		temp->next = x->next;
		x->next->pre = temp;

		x->pre = nullptr;
		x->next = nullptr;
		delete x;
		size--;
	}

	//define search member func
	T get(int index) {
		checkBoundary(index);
		// Node* node = getNode(index);
		// return node->val;
		return getNode(index)->val;
	}

	//define modify member func
	void set(int index, T newval) {
		checkBoundary(index);
		// Node* node = getNode(index);
		// node->val = newval;
		getNode(index)->val = newval;
	}

	//define display func
	void display() const {
		cout << "size = " << size << endl;
		for (Node* n = head->next; n != tail; n = n->next) {
			cout << n->val << "<->";
		}
		cout << "null" << endl;
	}

private:
	//define checkBoundary func
	void checkBoundary(int index) const {
		if (index + 1 > size || index < 0) {
			throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
		}
	}

	//define getNode func
	Node* getNode(int index) const {
		checkBoundary(index);
		Node* node = head;
		for (int i = 0; i <= index; i++) {
			node = node->next;
		}
		return node;
	}

};

int main() {

	DoubListNode<int> list;
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addFirst(0);
	list.add(2, 100);

	list.display();
	// size = 5
	// 0 <-> 1 <-> 100 <-> 2 <-> 3 <-> null

	list.removeAny(2);
	list.display();
	// size = 4
	// 0 < ->1 < ->2 < ->3 < ->null

	int val = list.get(2);
	cout << "list[2]->val = " << val << endl;
	// list[2]->val = 2

	list.set(2, 99);
	cout << "list[2]->val = " << list.get(2) << endl;
	// list[2]->val = 99




	return 0;
}