#include <iostream>
using namespace std;

struct Node {
	int y, x;
	int level;
};

int map[4][4] = {
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	1,0,1,0
};

int direct[4][2] = { -1,0,1,0,0,1,0,-1 };

int used[4][5];

Node queue[100];
int head = 0;
int tail = 1;

int tarY, tarX;

int bfs() {
	while (head != tail) {
		Node now = queue[head++];
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
			if (map[ny][nx] == 1) continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;

			queue[tail++] = { ny, nx, now.level + 1 };
			if (ny == tarY && nx == tarX) return now.level + 1;
		}
	}
	return -1;
}

int main() {
	int stY, stX;
	cin >> stY >> stX >> tarY >> tarX;
	queue[0] = { stY,stX,0 };
	used[stY][stX] = 1;

	int ret = bfs();
	cout << ret << "ȸ";

	return 0;
}