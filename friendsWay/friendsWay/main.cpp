#include <iostream>
#include <cstring>
using namespace std;

int map[3][5] = {
	0,0,0,0,1,
	1,0,1,0,0,
	0,0,0,0,1
};

int used[3][5];
int direct[4][2] = { -1,0,1,0,0,1,0,-1 };

struct Node {
	int y, x;
	int lev;
};

Node queue[100];
int head;
int tail;

int bfs(int sy, int sx, int ey, int ex) {
	head = 0;
	tail = 1;
	memset(queue, 0, sizeof(Node) * 100);
	memset(used, 0, 4 * 5 * 4);
	queue[0] = { sy,sx,0 };
	used[sy][sx] = 1;

	while (head != tail) {
		Node now = queue[head++];
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny < 0 || nx < 0 || ny >= 3 || nx >= 5) continue;
			if (map[ny][nx] == 1) continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;
			queue[tail++] = { ny,nx,now.lev + 1 };

			if (ny == ey && nx == ex) return now.lev + 1;
		}
	}

	return -1;
}

int main() {
	int sum = 0;
	int chy, chx, fy, fx;
	cin >> chy >> chx >> fy >> fx;
	sum += bfs(0, 0, chy, chx);
	sum += bfs(chy, chx, fy, fx);
	cout << sum;

	return 0;
}