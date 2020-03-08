#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

bool correct(string u) {
	int left, right; left = right = 0;

	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(')
			left++;
		else
			right++;

		if (right > left)
			return false;
	}
	
	return true;
}
string dfs(string s) {
	if (s == "")
		return "";
	int left, right; left = right = 0;
	int s_size = s.size();
	string u, v; u = v = "";
	for (int i = 0; s_size; i++) {
		if (s[i] == '(')
			left++;
		else
			right++;

		if (left == right) {
			u = s.substr(0, i + 1);
			v = s.substr(i + 1, s_size);
			break;
		}
	}

	if (correct(u)) {
		u += dfs(v);
	}
	else {
		string tmp = "(";
		tmp += dfs(v) + ")";
		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == '(')
				tmp += ')';
			else
				tmp += '(';
		}

		return tmp;
	}
	return u;
}
string solution(string p) {
	string answer = "";
	answer +=dfs(p);

	
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	cout << solution(s);
}