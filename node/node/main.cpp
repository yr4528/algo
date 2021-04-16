#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n = 9;

	int nod[9][2] = {
		0,2,
		2,1,
		2,4,
		3,5,
		5,4,
		5,7,
		7,6,
		6,8
	};

	vector<int> answer;
	int dat[10] = { 0 };

	for (int y = 0; y < n - 1; y++) {
		for (int x = 0; x < 2; x++) {
			dat[nod[y][x]]++;
			if (dat[nod[y][x]] == 3)
				answer.push_back(nod[y][x]);
		}
	}

	for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";

	return 0;
}