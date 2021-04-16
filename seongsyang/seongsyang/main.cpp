#include <iostream>
using namespace std;

int k = 11;
int vect[10] = { 6,2,5,5,4,5,6,3,7,6 };
int cnt = 0;
char path[10];

void run(int level, int sum) {
	if (k < 2) return;

	if (sum == k) {
		cnt++;
		cout << path << " ";
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (level == 0 && i == 0) continue;
		if (sum + vect[i] > k) continue;
		path[level] = i + '0';
		run(level + 1, sum + vect[i]);
		path[level] = 0;
	}
}

int main() {

	run(0, 0);
	cout << "\n" << cnt << "°³";

	return 0;
}