# include <iostream>
# include <vector>
# include <string>
# include <unordered_map>
# include <queue>
# include <algorithm>

using namespace std;

class Solution {
public:
	unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

	vector<string> stk;

	void dfs(const string& curr) {
		while (vec.count(curr) && vec[curr].size() > 0) {
			string tmp = vec[curr].top();
			vec[curr].pop();
			dfs(move(tmp));
		}
		stk.emplace_back(curr);
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		for (auto& it : tickets) {
			vec[it[0]].emplace(it[1]);
		}
		dfs("JFK");

		reverse(stk.begin(), stk.end());
		return stk;
	}
};

int main() {
	vector<vector<string>> tickets = { {"EZE","TIA"},{"EZE","HBA"},{"AXA","TIA"},{"JFK","AXA"},
		{"ANU","JFK"},{"ADL","ANU"},{"TIA","AUA"},{"ANU","AUA"},{"ADL","EZE"},{"ADL","EZE"},
		{"EZE","ADL"},{"AXA","EZE"},{"AUA","AXA"},{"JFK","AXA"},{"AXA","AUA"},{"AUA","ADL"},
		{"ANU","EZE"},{"TIA","ADL"},{"EZE","ANU"},{"AUA","ANU"} };

	Solution so;

	vector<string> res(so.findItinerary(tickets));

	cout << "[";
	for (auto s : res) {
		cout << s << " ";
	}
	cout << "]" << endl;

	return 0;
}