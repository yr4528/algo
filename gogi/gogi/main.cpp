#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};

int map[4][6];
int used[4][6];
int direct[4][2] = { -1,0,1,0,0,1,0, -1 };

Node queue[100];

int bfs() {
	memset(queue, 0, sizeof(Node) * 100);
	//memset(used, 0, 4 * 6 * 4);
	queue[0] = { 0,0 };
	used[0][0] = 1;
	int head = 0;
	int tail = 1;
	int cnt = 0;

	while (head != tail) {
		Node now = queue[head++];

		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];

			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 6) continue;
			if (map[ny][nx] == 1 || map[ny][nx] == 3) continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;
			queue[tail++] = { ny,nx };
			if (map[ny][nx] == 2) {
				map[ny][nx] = 3;
				cnt++;

			}
		}
	}
	return cnt;
}

int main() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 6; x++) {
			cin >> map[y][x];
		}
	}

	int ret = bfs();
	cout << ret;

	return 0;
}