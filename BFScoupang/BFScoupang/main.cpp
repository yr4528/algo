#include <iostream>
#include <cstring>
using namespace std; 

struct Node {
	int y, x;
	int lev;
};

Node queue[100];
char map[3][5];
int used[3][5];
int head;
int tail;
int direct[4][2] = { -1,0,1,0,0,1,0,-1 };
int ty = 0, tx = 0;

int bfs(int sy, int sx, int tarNum) {
	memset(queue, 0, sizeof(Node) * 100);
	memset(used, 0, 3 * 5 * 4);
	queue[0] = { sy,sx,0 };
	used[sy][sx] = 1;
	head = 0;
	tail = 1;

	while (head != tail) {
		Node now = queue[head++];

		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny < 0 || nx < 0 || ny >= 3 || nx >= 5) continue;
			if (map[ny][nx] == '#') continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;

			queue[tail++] = { ny,nx,now.lev + 1 };

			if (map[ny][nx] - '0' == tarNum) {
				ty = ny;
				tx = nx;
				return now.lev + 1;
			}
		}
	}
	return -1;
}

int main() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x];
		}
	}

	int sy = 0, sx = 0;
	int tarNum = 1;
	int sum = 0;

	while (1) {
		int ret = bfs(sy, sx, tarNum);
		if (ret == -1) break;
		sum += ret;
		sy = ty;
		sx = tx;
		tarNum++;
	}

	cout << sum << "ȸ";

	return 0;
}