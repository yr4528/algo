#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};

Node q[100];
int map[5][8];

void bfs(int dy, int dx) {
	memset(q, 0, sizeof(Node) * 100);
	int head = 0;
	int tail = 1;
	q[0] = { dy,dx };
	map[dy][dx] = 0;

	int direct[4][2] = { -1,0,1,0,0,1,0,-1 };
	while (head != tail) {
		Node now = q[head++];
		for (int i = 0; i < 4; i++) {
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];

			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 8) continue;
			if (map[ny][nx] == 0) continue;
			map[ny][nx] = 0;
			q[tail++] = { ny,nx };
		}
	}
}

int main() {

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 8; x++) {
			cin >> map[y][x];
		}
	}
	
	int cnt = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 8; x++) {
			if (map[y][x] == 1) {
				bfs(y, x);
				cnt++;
			}
		}
	}

	cout << cnt;
	
	return 0;
}