# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		backtrack(nums, 0);
		return res;
	}

private:
	vector<int> track;
	int N = 0;
	vector<vector<int>> res;

	void backtrack(const vector<int>& nums, int start) {
		if (N >= 2) {
			res.emplace_back(track);
		}

		if (start == nums.size()) return;

		for (int i = start; i < nums.size(); i++) {
			if (track.empty() || nums[i] >= track.back()) {
				if (i > start && nums[i] == nums[i - 1]) {
					continue;
				}
				track.emplace_back(nums[i]);
				N++;
			}
			else {
				continue;
			}

			backtrack(nums, i + 1);
			track.pop_back();
			N--;
		}
	}

};

int main() {

	vector<int> nums = { 1,2,3,4,5,6,7,8,9,10,1,1,1,1,1 };
	Solution so;
	vector<vector<int>> ans(so.findSubsequences(nums));

	for (auto v : ans) {
		cout << "[";
		for (auto n : v) {
			cout << n << " ";
		}
		cout << "]" << endl;
	}

	return 0;
}