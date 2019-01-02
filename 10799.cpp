#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

int main(void) {
	int k;
	char w[100000];
	string word;
	stack <int> s;
	int cnt;
	cnt = 0;
	cin >> word;

	strcpy(w, word.c_str());

	int len = word.length();
	for (int i = 0; i < len; i++) {
		if (w[i] == '(') {
			s.push(i);
		}
		else if (w[i] == ')') {
			//레이저 임
			if (i - s.top() == 1) {
				s.pop();
				cnt += s.size();
			}
			else {
				s.pop();
				cnt += 1;
			}
		}
	}
	cout << cnt;
}