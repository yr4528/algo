#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	int y, x, lev;
};

Node queue[20];
int map[4][9];
int used[4][9];
int cnt[4][9];
int direct[4][2] = { -1,0,1,0,0,1,0,-1 };

int bfs() {
	memset(queue, 0, sizeof(Node) * 20);
	int head = 0, tail = 1;

	while (head != tail) {
		Node now = queue[head++];
		int flag;
		for (int t = 0; t < 4; t++) {
			flag = 0;
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 9) continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;
			if (map[ny][nx] == map[now.y][now.x]) {
				queue[tail++] = { ny,nx,now.lev + 1 };
				flag = 1;
			}
		}
		if (flag == 0) return now.lev + 1;
	}
	return 1;
}

int main() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> map[y][x];
		}
	}

	queue[0] = { 0,0,0 };
	
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 9; x++) {
			if (used[y][x] == 0)
				cnt[y][x] = bfs();
		}
	}


	return 0;
}