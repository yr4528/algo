#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};

int main() {
	int garo, sero;
	cin >> garo >> sero;

	vector<vector<int>> map(garo, vector<int>(sero));

	for (int y = 0; y < sero; y++) {
		for (int x = 0; x < garo; x++) {
			cin >> map[y][x];
		}
	}

	int sty, stx;
	cin >> sty >> stx;

	queue<Node> q;
	q.push({ sty,stx });

	int direct[4][2] = { -1,0,1,0,0,1,0, -1 };
	int maxi = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];
			if (ny < 0 || nx < 0 || ny >= sero || nx >= garo) continue;
			if (map[ny][nx] != 0) continue;

			map[ny][nx] = map[now.y][now.x] + 1;
			if (maxi < map[ny][nx]) maxi = map[ny][nx];
			q.push({ ny,nx });
		}
	}
	cout << maxi << "\n";
	/*
	for (int y = 0; y < sero; y++) {
		for (int x = 0; x < garo; x++) {
			cout << map[y][x];
		}
		cout << "\n";
	}
	*/
	return 0;
}