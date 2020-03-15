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
#include<stack>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

stack<char> _stack;
int solution(string s)
{
	int s_size = s.size();

	for (int i = 0; i < s_size; i++) {
		if (_stack.empty())
			_stack.push(s.at(i));
		else if (_stack.top() == s.at(i)) {
			_stack.pop();
		}
		else {
			_stack.push(s.at(i));
		}
	}

	return (_stack.size() ? 0 : 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	cout << solution(s);
}