#include <iostream>
#include <string>
using namespace std;

int main() {
	string dom[3] = {
		".com", ".net",".org"
	};

	string input[8] = {
		"d@co@m.com",
		"a@abc.com",
		"b@def.com",
		"c@ghi.net",
		"abc.def@x.com",
		"abc",
		"abc@defx",
		"abc@defx.xyz"
	};

	for (int i = 0; i < 8; i++) {
		int gol = 0, dot = 0;
		int flag = 0;
		if (input[i].length() < 7) break;
		for (int j = 0; j < input[i].length(); j++) {
			if (input[i][0] == '@') break;
			if (input[i][j] == '@' && gol == 1) {
				flag = 1;
				break;
			}
			if (input[i][j] == '@' && gol == 0) {
				gol = 1;
			}
			if (dot == 0) {
				for (int k = 0; k < 3; k++) {
					if (input[i].find(dom[k]) > 3) {
						dot = 1;
					}
				}
			}
		}
		if (gol == 1 && dot == 1 && flag == 0) cout << input[i] << "\n";
	}

	return 0;
}