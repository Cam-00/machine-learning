#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 动态规划---迭代版--滚动数组优化-降低空间复杂度
class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = (int)matrix.size();
		if (n == 1) return *min_element(matrix[0].begin(), matrix[0].end());

		int mins = INT_MAX;
		vector<int> dp(n, INT_MAX);

		for (int i = 0; i < n; i++) {
			dp[i] = matrix[0][i];
		}

		for (int i = 1; i < n; i++) {
			mins = min(dp[0], dp[1]);
			int temp = mins;

			for (int j = 1; j < n - 1; j++) {
				mins = min(dp[j - 1], min(dp[j], dp[j + 1]));
				dp[j - 1] = matrix[i][j - 1] + temp;
				temp = mins;
			}

			mins = min(dp[n - 2], dp[n - 1]);
			dp[n - 2] = matrix[i][n - 2] + temp;
			dp[n - 1] = matrix[i][n - 1] + mins;
		}

		return *min_element(dp.begin(), dp.end());
	}
};

int main() {
	Solution so;
	vector<vector<int>> matrix = { {2,1,3}, {6,5,4}, {7,8,9} };

	int ans = so.minFallingPathSum(matrix);

	cout << "ans = " << ans << endl;


	return 0;
}
