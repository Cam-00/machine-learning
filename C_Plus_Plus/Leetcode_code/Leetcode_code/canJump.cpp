# include <iostream>
# include <vector>

using namespace std;

// dfs--Î´Í¨¹ý
class Solution {
public:
	bool canJump(vector<int>& nums) {
		dfs(nums, 0);
		return flag;
	}

private:
	bool flag = false;

	bool dfs(vector<int>& nums, int cur) {
		if (cur >= nums.size() - 1)  return true;

		for (int i = nums[cur]; i >= 1; i--) {
			if (cur + i >= nums.size() - 1) { flag = true;  return true; }
			dfs(nums, cur + i);
		}

		return false;

	}
};

int main() {
	vector<int> nums = { 2,3,1,1,4 };
	Solution so;
	bool res = so.canJump(nums);
	cout << "res = " << res << endl;

	return 1;
}