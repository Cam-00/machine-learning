#pragma once

#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int findContentChildren(vector<int>& g, vector<int>& s) {
//		sort(g.begin(), g.end());
//		sort(s.begin(), s.end());
//		int index = s.size() - 1; // 饼干数组的下标
//		int result = 0;
//		for (int i = g.size() - 1; i >= 0; i--) { // 遍历胃口
//			if (index >= 0 && s[index] >= g[i]) { // 遍历饼干
//				result++;
//				index--;
//			}
//		}
//		return result;
//	}
//};

class Solution {  // 贪心算法：核心是找到局部最优。本题是：大饼干优先给大胃口，这样才能最优。
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		// 预先将胃口、饼干，按照降序排序，方便接下来的
		sort(g.begin(), g.end(), greater<int>());
		sort(s.begin(), s.end(), greater<int>());
		int start = 0;
		int count = 0;
		for (int i = 0; i < s.size(); i++) { // 大饼干在前
			int tmp = 0;  // 用于标记某个大饼干是否能满足剩下的人中的某一个或某几个
			for (int j = start; j < g.size(); j++) { // 大胃口在前
				if (s[i] >= g[j]) {
					start = ++j;
					++tmp;
					break;
				}
			}
			count += tmp;  // 统计目前胃口满足的人数
			if (tmp == 0) break; // 一旦某个大饼干不能满足剩余的所有人，立即退出最外层循环
		}

		return count;
	}
};