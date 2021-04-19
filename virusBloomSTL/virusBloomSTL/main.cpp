#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int y, x;
};

int main() {
	
	queue<Node> q;

	int n;
	cin >> n;

	vector<vector<int>> map(n, vector<int>(n));

	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;

	q.push({ y1,x1 });
	q.push({ y2,x2 });

	map[y1][x1] = 1;
	map[y2][x2] = 1;

	int direct[4][2] = { -1,0,1,0,0,1,0,-1 };

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (map[ny][nx] != 0) continue;

			map[ny][nx] = map[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cout << map[y][x];
		}
		cout << "\n";
	}

	return 0;
}