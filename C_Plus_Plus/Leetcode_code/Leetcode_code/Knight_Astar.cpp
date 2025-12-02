#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dir[8][2] = { 2, -1, 2, 1, -2, -1, -2, 1, 1, 2, 1, -2, -1, 2, -1, -2 };
int b1, b2;

struct Knight {
	int x, y;
	int g, h, f;

	// 小顶堆
	bool operator < (const Knight k) const {  // 注意：运算操作符重载，这里修饰成员函数的const必须有
		return f > k.f;  // 降序排序，在队列中弹出的总是最小值
	}
};

int Heuristic(const Knight& kn) {
	return (kn.x - b1)*(kn.x - b1) + (kn.y - b2)* (kn.y - b2);
}

priority_queue<Knight> pq;
int moves[1001][1001]; // 记录从出发点 到 经过的点的最少步数

void astar(const Knight& kn) {
	pq.emplace(kn);
	Knight cur, next;
	while (!pq.empty()) {
		cur = pq.top(); pq.pop();
		if (cur.x == b1 && cur.y == b2) break;
		for (int i = 0; i < 8; i++) {
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if (next.x < 1 || next.x > 1000 || next.y < 1 || next.y >1000) continue;
			// 走过的点，不再重走
			if (!moves[next.x][next.y]) {
				moves[next.x][next.y] = moves[cur.x][cur.y] + 1;
				next.g = cur.g + 5;
				next.h = Heuristic(next);
				next.f = next.g + next.h;
				pq.emplace(next);
			}
		}

	}
}

int main() {
	int n, a1, a2;
	cin >> n;
	while (n--) {
		cin >> a1 >> a2 >> b1 >> b2;
		memset(moves, 0, sizeof(moves));
		Knight start;
		start.x = a1;
		start.y = a2;
		start.g = 0;
		start.h = Heuristic(start);
		start.f = start.g + start.h;
		astar(start);
		while (!pq.empty()) {
			pq.pop();
		}
		cout << moves[b1][b2] << endl;
	}
	return 0;
}