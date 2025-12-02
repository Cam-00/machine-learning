# include <iostream>
# include <unordered_map>

using namespace std;

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		unordered_map<int, int> notes = { {5, 0}, {10, 0}, {20, 0} };
		for (int i = 0; i < bills.size(); i++) {
			if (bills[i] == 5) {
				notes[5]++;
			}
			else if (bills[i] == 10) {
				if (notes[5] > 0) {
					notes[5]--;
					notes[10]++;
				}
				else {
					return false;
				}
			}
			else if (bills[i] == 20) {
				if (notes[10] > 0 && notes[5] > 0) {
					notes[10]--;
					notes[5]--;
					notes[20]++;
				}
				else if (notes[5] > 2) {
					for (int j = 0; j < 3; j++) {
						notes[5]--;
					}
					notes[20]++;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}
};

int main(){
	vector<int> bills = { 5,5,5,5,20,20,5,5,20,5 };
	Solution s1;
	bool res;
	res = s1.lemonadeChange(bills);
	cout << "res = " << res << endl;

	return 0;

}