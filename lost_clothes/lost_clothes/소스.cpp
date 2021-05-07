#include <iostream>
#include <vector>
using namespace std;

int n = 3;
vector<int> lost = { 3 };
vector<int> reserve = { 1 };

int solution() {
	int answer = 0;
	vector<int> stu(n,1);
	for (int i = 0; i < reserve.size(); i++) {
		stu[reserve[i] - 1]++;
	}
	for (int i = 0; i < lost.size(); i++) {
		stu[lost[i] - 1]--;
	}

	for (int i = 0; i < n; i++) {
		if (stu[i] > 1) {
			if (i >= 1 && stu[i - 1] == 0) {
				stu[i]--;
				stu[i - 1]++;
			}
			if (i < n - 1 && stu[i + 1] == 0) {
				stu[i]--;
				stu[i + 1]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (stu[i] != 0) answer++;
	}

	return answer;
}

int main() {

	int sol = solution();

	cout << sol;

	return 0;
}