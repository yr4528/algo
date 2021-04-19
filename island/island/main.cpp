#include <iostream>
using namespace std;

struct Node {
	int y, x;
};

int main() {

	int map[4][4] = { 0 };
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}

	Node q[100] = { {0,0} };
	int head = 0;
	int tail = 1;
	int cnt = 0;

	int direct[4][2] = { -1,0,1,0,0,1,0,-1 };

	while (head != tail) {
		Node now = q[head++];

		for (int i = 0; i < 4; i++) {
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
			if (map[ny][nx] != 1) continue;

			map[ny][nx] = 0;
			q[tail++] = { ny,nx };
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}