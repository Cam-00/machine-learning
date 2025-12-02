# include <iostream>
# include <vector>
# include <string>
using namespace std;

// 回溯
class Solution {
public:
	string track;
	int num = 0;
	vector<string> res;
	vector<string> restoreIpAddresses(string s) {
		backtrack(s, 0);
		return res;
	}

	void backtrack(const string& s, int start) {

		if (num == 4) {
			if (start == s.size()) {
				track.pop_back(); // 去掉末尾的 .
				res.emplace_back(track);
			}
			else {
				track.pop_back();
			}

			return;
		}

		for (int i = start; i < s.size(); i++) {
			if (num == 3) {
				i = s.size() - 1;
			}
			string sub = s.substr(start, i - start + 1);
			int sz = sub.size();
			if (!isValid(sub)) break;
			int nt = track.size();
			sub += ".";
			track += sub;
			num++;
			

			backtrack(s, i + 1);

			track.erase(nt); // 删除最后加入的sub
			num--;
		}
	}

	bool isValid(const string& s) {
		int n = s.size();
		int num_str = stoi(s);
		if (n > 3 || n > 1 && s[0] == '0' || num_str > 255) {
			return false;
		}
		return true;
	}
};

int main() {
	string s = "101023";
	Solution so;
	vector<string> ans(so.restoreIpAddresses(s));

	for (auto v : ans) {
		cout << v << endl;
	}


	return 0;
}