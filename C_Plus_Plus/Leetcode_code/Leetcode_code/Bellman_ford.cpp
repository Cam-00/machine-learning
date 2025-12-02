/*
	Bellman_ford 算法
	用于具有负权路径单向图中寻找最短路径
	算法思想：对所有边松弛n-1次，n为节点数量
	松弛 n-1 次所有的边 就可以求得 起点到任何节点的最短路径，
	松弛 n 次以上，minDist数组（记录起到到其他节点的最短距离）中的结果也不会有改变.
	时间复杂度： O(N * E) , N为节点数量，E为图中边的数量
	空间复杂度： O(N) ，即 minDist 数组所开辟的空间
*/

#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

int main() {
	int n, m, p1, p2, val;
	cin >> n >> m;

	vector<vector<int>> grid;

	// 将所有边保存起来
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2 >> val;
		// p1 指向 p2，权值为 val
		grid.push_back({ p1, p2, val });

	}
	int start = 1;  // 起点
	int end = n;    // 终点

	vector<int> minDist(n + 1, INT_MAX);
	minDist[start] = 0;
	for (int i = 1; i < n; i++) { // 对所有边 松弛 n-1 次
		for (vector<int> &side : grid) { // 每一次松弛，都是对所有边进行松弛
			int from = side[0]; // 边的出发点
			int to = side[1]; // 边的到达点
			int price = side[2]; // 边的权值
			// 松弛操作 
			// minDist[from] != INT_MAX 防止从未计算过的节点出发
			if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price) {
				minDist[to] = minDist[from] + price;
			}
		}
	}
	if (minDist[end] == INT_MAX) cout << "unconnected" << endl; // 不能到达终点
	else cout << minDist[end] << endl; // 到达终点最短路径

}