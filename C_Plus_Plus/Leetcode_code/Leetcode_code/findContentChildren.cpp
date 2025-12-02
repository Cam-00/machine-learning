#include"findContentChildren_455.h"
#include<vector>
#include<iostream>
using namespace std;

int main() {
	vector<int> g = {1, 2, 3};
	vector<int> s = {1, 1};
	Solution vec;
	int result = vec.findContentChildren(g, s);
	cout<< "result = " << result << endl;

	return 1;
}
