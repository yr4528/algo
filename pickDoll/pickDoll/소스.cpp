#include <iostream>
#include <vector>
#include <string>
using namespace std;

int board[5][5] = {
	0,0,0,0,0,
	0,0,1,0,3,
	0,2,5,0,1,
	4,2,4,4,2,
	3,5,1,3,1
};

int moves[8] = { 1,5,3,5,1,2,1,4 };

vector<int> basket;

int solution() {
	int answer = 0;
	int msize = 8;
	int bsize = 5;

    for (int i = 0; i < msize; i++) {
        if (board[bsize - 1][moves[i] - 1] == 0) continue;

        for (int j = 0; j < bsize; j++) {
            if (board[j][moves[i] - 1] == 0) continue;
            else {
                basket.push_back(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
                if (basket.size() >= 2) {
                    if (basket[basket.size() - 1] == basket[basket.size() - 2]) {
                        basket.pop_back();
                        basket.pop_back();
                        answer += 2;
                        break;
                    }
                }
                break;
            }
        }
    }
    return answer;
}

int main() {

	int sol = solution();
	cout << sol;

	return 0;
}