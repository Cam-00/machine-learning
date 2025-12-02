# include <iostream>
# include <vector>
# include <algorithm>
# include <string>


using namespace std;

// 动态规划
class Solution {
public:
	int ans = 0;
	int num = 0;

	int maxPalindromes(string s, int k) {
		int n = (int)s.size();
		// dp[i][j] : 区间[i,j]字符串是否为回文
		vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, true));
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (i == j) {
					dp[i][j] = true;
				}
				else {
					dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
				}
			}
		}

		backtrack(dp, 0, n);

		return ans;
	}

	void backtrack(vector<vector<bool>>& dp, int start, int n) {
		if (start + 2 >= n || start == n) {
			ans = max(ans, num);
			return;
		}

		for (int i = start + 2; i < n; i++) {
			if (dp[start][i]) {
				num++;
				backtrack(dp, i + 1, n);
				num--;
			}

			backtrack(dp, start + 1, n);
		}
		backtrack(dp, n, n);
	}
};

int main() {
	string s = "abaccdbbd";
	int k = 3;
	Solution so;
	
	int maxN = so.maxPalindromes(s,k);
	cout << "maxN = " << maxN << endl;

	return 0;
}