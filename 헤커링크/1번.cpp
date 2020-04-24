#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
int getMin(string s) {
	int left, right;
	left = right = 0;

	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			left++;
		}
		else if(s[i] == ')'){
			right++;
		}

		if (right > left) {
			cnt++;
			left = left - right + 1;
			right = 0;
		}
	}

	cnt += left;

	return cnt;

}

int main() {
	string s = ")(";
	cout << getMin(s);
}