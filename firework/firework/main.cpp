#include <iostream>
using namespace std;

struct Node {
	int y, x;
	int level;
};

int main() {
	Node q[100];
	int head = 0, tail = 0;

	int map[5][5];
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) q[tail++] = { y,x };
		}
	}

	int direct[8][2] = { -1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1 };

	while (head != tail) {
		Node now = q[head++];

		for (int i = 0; i < 8; i++) {
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];

			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 5) continue;
			if (map[ny][nx] != 0) continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			q[tail++] = { ny,nx,now.level + 1 };
		}
	}

	cout << q[tail - 1].level;

	return 0;
}