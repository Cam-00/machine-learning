# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.size() == 0 || s.size() == 0) return false;

		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < wordDict.size(); j++) {
				if (s[i] == wordDict[j][0]) {
					int k = 0;
					int temp = i;
					while (i < s.size() && k < wordDict[j].size() && s[i] == wordDict[j][k]) {
						i++; k++;
					}
					if (i <= s.size() && k == wordDict[j].size()) {
						// Æ¥Åä³É¹¦
						i--;
						break;
					}
					else {
						i = temp;
					}
				}
				if (i == s.size() - 1 && j == wordDict.size() - 1) {
					return false;
				}
			}
		}

		return true;
	}
};

int main() {

	Solution so;
	string s = "leetcode";
	vector<string> wordDict = { "leet", "code" };
	bool ans = so.wordBreak(s, wordDict);

	cout << "ans = " << ans << endl;

	return 0;
}