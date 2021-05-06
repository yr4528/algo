#include <iostream>
#include <string>
#include <vector>
using namespace std;

string hand = "right";
vector<int> numbers = { 1,3,4,5,8,2,1,4,5,9,5 };

int dist(int tar, int from) {
	if (tar == from) return 0;
	else if (tar == 2) {
		if (from == 1 || from == 3 || from == 5) return 1;
		else if (from == 4 || from == 6 || from == 8) return 2;
		else if (from == 7 || from == 9 || from == 0) return 3;	
		else if (from == '*' || from == '#') return 4;	
	}
	else if (tar == 5) {
		if (from == 2 || from == 4 || from == 6 || from == 8) return 1;
		else if (from == 1 || from == 3 || from == 7 || from == 9 || from == 0) return 2;
		else if (from == '*' || from == '#') return 3;
	}
	else if (tar == 8) {
		if (from == 5 || from == 7 || from == 9 || from == 0) return 1;
		else if (from == 4 || from == 6 || from == 2 || from == '*' || from == '#') return 2;
		else if (from == 1 || from == 3) return 3;		
	}
	else if (tar == 0) {
		if (from == '*' || from == '#' || from == 8) return 1;
		else if (from == 5 || from == 7 || from == 9) return 2;
		else if (from == 2 || from == 4 || from == 6) return 3;
		else if (from == 1 || from == 3) return 4;
	}
}

string solution() {
	string answer = "";
	int nl = '*';
	int nr = '#';

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7 || numbers[i] == '*') {
			answer += "L";
			nl = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9 || numbers[i] == '#') {
			answer += "R";
			nr = numbers[i];
		}
		else {
			if (dist(numbers[i], nl) > dist(numbers[i], nr)) {
				answer += "R";
				nr = numbers[i];
			}
			else if (dist(numbers[i], nl) < dist(numbers[i], nr)) {
				answer += "L";
				nl = numbers[i];
			}
			else {
				if (hand == "right") {
					answer += "R";
					nr = numbers[i];
				}
				else {
					answer += "L";
					nl = numbers[i];
				}
			}
		}
	}
	return answer;
}

int main() {

	string sol = solution();

	cout << sol;

	return 0;
}