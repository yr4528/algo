#include <iostream>
#include <string>
using namespace std;

int main(){
//	string m = "kkaxbycyz";
	string m = "acbbcdc";
	string k = "abc";
	string result = "";

	int len = m.length() - k.length();

	int index = 0;
	for (int i = 0; i < len; i++) {
		if (m[i] == k[index]) {
			for (int j = i; j < m.length(); j++) {
				m[j] = m[j + 1];
			}
			m[m.length()] = NULL;
			index++;
		}
	}

	for (int i = 0; i < len; i++) cout << m[i];
	return 0;
}