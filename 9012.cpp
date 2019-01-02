#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	int T;
	char w[50];
	cin >> T;
	int k;
	string word;
	for (int t = 0; t < T; t++) {
		stack <char> s;
		k = 0;
		cin >> word;

		strcpy(w, word.c_str());

		int size = word.length();
		for (int i = 0; i < size; i++) {
			if (w[i] == '(') {
				s.push(w[i]);
			}

			else if (w[i] == ')') {
				if (s.empty()) {
					i = size;
					k = 1;
					break;
				}
				else {
					s.pop();
				}
			}
		}
		if (k == 0 && s.empty()) {
			cout << "YES" << endl;
		}
		else if (!s.empty() || k == 1) {
			cout << "NO" << endl;
		}
	}
}