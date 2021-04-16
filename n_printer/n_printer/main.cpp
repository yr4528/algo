#include <iostream>
using namespace std;

int main() {

	int data[5][3] = {
		1,0,2,
		2,3,2,
		3,2,4,
		4,2,2,
		5,5,2
	};

	int end[5][2] = { 0 };

	for (int i = 0; i < 5; i++) {
		end[i][0] = data[i][0];
		end[i][1] = data[i][1] + data[i][2];
	}
	
	int mini = 21e8;
	
	for (int y = 0; y < 4; y++) {
		for (int x = y; x >= 0; x--) {
			if (end[x][1] > end[x + 1][1]) {
				swap(end[x][0], end[x + 1][0]);
				swap(end[x][1], end[x + 1][1]);
			}
		}
	}

	for (int i = 0; i < 5; i++) cout << end[i][0] << " ";


	return 0;
}