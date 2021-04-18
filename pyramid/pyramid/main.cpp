#include <iostream>
using namespace std;

int main() {
	/*
	int map[5][5] = {
		50,0,0,0,0,
		22,0,0,0,0,
		0,0,10,0,0,
		0,4,0,0,0,
		0,0,0,0,-13
	};

	int ok[5][5] = {
		1,0,0,0,0,
		1,0,0,0,0,
		0,0,1,0,0,
		0,1,0,0,0,
		0,0,0,0,1
	};
	*/
	int map[5][5] = {
		92,0,0,0,0,
		0,20,0,0,0,
		0,0,11,0,0,
		0,-81,0,0,0,
		0,0,0,98,0
	};
	int ok[5][5] = {
		1,0,0,0,0,
		0,1,0,0,0,
		0,0,1,0,0,
		0,1,0,0,0,
		0,0,0,1,0
	};

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x <= y; x++) {
			if (ok[y][x] == 1) continue;
			if (ok[y][x] == 0 && ok[y][x + 1] == 1) {
				map[y][x] = map[y - 1][x] - map[y][x + 1];
				ok[y][x] = 1;
			}
			if (ok[y][x] == 0 && ok[y][x - 1] == 1) {
				map[y][x] = map[y - 1][x - 1] - map[y][x - 1];
				ok[y][x] = 1;
			}
		}
		for (int x = y; x >=0; x--) {
			if (ok[y][x] == 1) continue;
			if (ok[y][x] == 0 && ok[y][x + 1] == 1) {
				map[y][x] = map[y - 1][x] - map[y][x + 1];
				ok[y][x] = 1;
			}
			if (ok[y][x] == 0 && ok[y][x - 1] == 1) {
				map[y][x] = map[y - 1][x - 1] - map[y][x - 1];
				ok[y][x] = 1;
			}
		}
	}

	return 0;
}