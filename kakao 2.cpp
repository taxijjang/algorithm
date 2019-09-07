#include <string>
#include <vector>
#include<iostream>
#include<stack>

using namespace std;

stack<char> stk;
string res = "";
bool allbarn(string p) {
	int p_size = p.size();

	if (p_size == 0)
		return false;
	int cnt = 0;
	bool check = true;
	for (int i = 0; i < p_size; i++) {
		stk.push(p[i]);
		if (p[i] == '(')
			cnt++;
		else if (p[i] == ')')
			cnt--;
		if (cnt < 0) {
			check = false;
			break;
		}
	}
	return check;
}

void recur(string s, string u, string v) {
	if (s == "")
		return;
	int s_size = s.size();
	int cnt = 0;
	int left = 0, right = 0;
	bool toggle = true;
	for (int i = 0; i < s_size; i++) {
		if ((i != 0) && (left == right)) {
			u = s.substr(0, i);
			v = s.substr(i, s_size - i);
			toggle = false;
			break;
		}
		if (s[i] == '(')
			left++;
		else
			right++;
	}

	if (toggle) {
		u = s;
		v = "";
	}
	if (allbarn(u)) {
		res += u;
		if (v == "")
			return;
		recur(v, "", "");
	}
	else {
		res += '(';
		recur(v, "", "");
		res += ')';
		int u_size = u.size();

		for (int i = 1; i < u_size - 1; i++) {
			if (u[i] == '(')
				res += ')';
			else
				res += '(';
		}
	}
}
string solution(string p) {
	int p_size = p.size();
	bool check = false;

	if (allbarn(p)) {
		return p;
	}
	else {
		recur(p, "", "");
	}


	string answer = res;
	return answer;
}


int main(void) {
	string s;
	//s = "))((";
	//s = "()))((()";
	s = "(()())()";
	cout << solution(s);
}