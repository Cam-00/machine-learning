#include <iostream>
#include <vector>
using namespace std;



int main() {

	// 长度为 5 的数组
	vector<int> arr = { 1, 2, 3, 4, 5 };
	int i = 0;
	int count = 0;  // 用于循环结束
	// 模拟环形数组，这个循环永远不会结束
	while (i < arr.size() && count < 10) {
		cout << arr[i] << endl;
		i = (i + 1) % arr.size();  //通过取余运算，实现数组的环形循环
		count++;
	}
	return 0;
}