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
typedef pair<int, int> pii;

stack<char> _stack;
int solution(string inputString) {
	string in = inputString;
	int in_size = in.size();
	int res = 0;
	for (int i = 0; i < in_size; i++) {
		if (in[i] == '(' || in[i] == '{' || in[i] == '[' || in[i] == '<')
			_stack.push(in[i]);
		else if(in[i] == ')' || in[i] == '}' || in[i] == ']' || in[i] == '>'){
			if (_stack.size() == 0)
				return -1;
			else {
				_stack.pop();
				res++;
			}
		}
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s = "line[plus]><";
	cout << solution(s);
}