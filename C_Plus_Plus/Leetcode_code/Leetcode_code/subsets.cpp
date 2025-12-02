# include <iostream>
# include <vector>
# include <unordered_set>

using namespace std;

class Solution {
public:

	vector<vector<int>> ans;

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> tmp;
		
		// unordered_set<vector<int>> track; // C++ 没有为vector提供hash构造函数
		
		backtrack(nums, 0, tmp);
		return ans;
	}

	void backtrack(vector<int>& nums, int start, vector<int>& v) {
		
		ans.emplace_back(v);

		for (int i = start; i < nums.size(); i++) {
			v.emplace_back(nums[i]);
			backtrack(nums, i + 1, v);
			v.pop_back();
		}
	}
};

int main() {

	Solution so;
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> ans = so.subsets(nums);

	cout << "[";
	for (auto vec : ans) {
		cout << "[";
		for (auto v : vec) {
			cout << v << " ";
		}
		cout << "],";
	}
	cout << "]" << endl;

	return 0;
}