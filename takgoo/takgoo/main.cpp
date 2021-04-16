#include <iostream>
using namespace std;

int main() {

	int n = 6;
	int p[6] = { 5,4,7,2,0,6 };
	int c[6] = { 4,6,4,9,2,3 };
	float answer = 0.0;

	int jae[7] = { 5 };
	int price = 100;

	for (int i = 0; i < n; i++) {
		if (jae[i] >= c[i]) {
			answer += price * c[i];
			jae[i + 1] = jae[i] - c[i] + p[i + 1];
			price = 100;
		}
		else {
			jae[i + 1] = jae[i] + p[i + 1];
			if (price == 100) price = 50;
			else if (price == 50) price = 25;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << (float)(answer / n);

	return 0;
}