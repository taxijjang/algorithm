#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> name;
stack<char> cnt;
stack<char> w;
int main(void) {
	string s;
	cin >> s;

	int size = s.size();

	int n_cnt = 0;
	int c_cnt = 0;
	for (int i = 0; i < size; i++) {
		if ('A' <= s[i] && s[i] <= 'Z' || s[i] >= 'a' && s[i] <='z') {
			name.push(s[i]);
			if ('A' <= s[i] && s[i] <= 'Z') {
				n_cnt++;
			}
		}
		else {
			cnt.push(s[i]);
			c_cnt++;
		}
	}
	if (n_cnt != c_cnt) {
		printf("error\n");
	}
	else {
		int stack_size = cnt.size();

		string word;
		for (int i = 0; i < stack_size; i++) {
			int num = cnt.top();
			if (num == '1') {
				if ('a' <= name.top() && name.top() <= 'z') {
					w.push(name.top());
					name.pop();
					w.push(name.top());
					name.pop();
				}
				else {
					w.push(name.top());
					name.pop();
				}
			}
			else {
				w.push(cnt.top());
				if ('a' <= name.top() && name.top() <= 'z') {
					w.push(name.top());
					name.pop();
					w.push(name.top());
					name.pop();
				}
				else {
					w.push(name.top());
					name.pop();
				}
			}

			cnt.pop();

		}

		int w_size = w.size();

		for (int i = 0; i < w_size; i++) {
			printf("%c", w.top());
			w.pop();
		}
	}
	
}