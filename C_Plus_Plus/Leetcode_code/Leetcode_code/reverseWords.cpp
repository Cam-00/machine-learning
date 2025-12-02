#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
	string reverseWords(string s) {
		string t;
		int left = 0, pos = (int)s.size() - 1;
		int right = -1;
		while (pos >= 0) {
			char ch = s[pos];
			if (ch == ' ' && right - left < 0) {
				pos--;
				continue;
			}
			if (ch == ' ' && right - left >= 0 || pos == 0 && ch != ' ') {
				if (pos == 0 && ch != ' ') {
					t.push_back(ch);
					right++;
				}
				t.push_back(' ');
				Reverse(t, left, right);
				left = right + 2;
				right++;
				pos--;
				continue;
			}
			t.push_back(ch);
			right++;
			pos--;
		}

		t.erase(t.end() - 1);
		return t;
	}

	void Reverse(string& s, int left, int right) {
		while (left < right) {
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
	}
};

int main() {

	string s = " asdasd df f";

	Solution so;

	
	string ans = so.reverseWords(s);

	for (char ch : ans) {
		cout << ch;
	}

	cout << endl;

	return 0;
}