#include <iostream>
using namespace std;

int main() {

	char map[6][6] = {
		'#','#','#','#','#','#',
		'>','#','*','#','#','#',
		'#','#','#','#','*','#',
		'#','<','#','>','>','#',
		'>','#','*','#','*','<',
		'#','#','#','#','#','#'
	};

	int direct[3][2] = { 0,-1,1,0,0,1 };
	int cnt = 0;

	for (int i = 0; i < 6; i++) {
		int nowY = 0;
		int nowX = i;

		int stop = 0;
		while (1) {
			if (map[nowY][nowX] == '#') {
				nowY++;
			}
			if (map[nowY][nowX] == '*') {
				nowY++;
				stop++;
				if (stop == 2) break;
			}
			if (map[nowY][nowX] == '>') {
				nowX++;
			}
			if (map[nowY][nowX] == '<') {
				nowX--;
			}
			if (nowY == 5) {
				cnt++;
				cout << i << " ";
				break;
			}
		}
	}
	cout << "\n" << cnt;
	return 0;
}