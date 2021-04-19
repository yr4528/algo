#include <iostream>
using namespace std;

int main() {

	int n = 19;
	int cnt = n;
	int edge[50][2] = {
		0,1,
		0,2,
		0,3,
		1,4,
		1,5,
		2,6,
		3,7,
		3,8,
		3,9,
		4,10,
		4,11,
		5,12,
		5,13,
		6,14,
		6,15,
		6,16,
		8,17,
		8,18
	};

	int connEdge[50] = { 0 };

	for (int i = 0; i < n; i++) {
		connEdge[i] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		connEdge[edge[i][0]] += connEdge[edge[i][1]];
	}

	int start = 0;
	int maxi = 0;
	int maxIndex = 0;
	int hoo = 0;

	while (1) {
		for (int i = 0; i < n; i++) {
			if (edge[i][0] == start) {
				hoo++;
				for (int j = 0; j < hoo; j++) {
					if (connEdge[edge[j][1]] > maxi) {
						maxi = connEdge[edge[j][1]];
						maxIndex = j;
					}
					cnt -= connEdge[j];
				}
			}
		}


	}

	return 0;
}