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
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	for (auto g : s) {
		if (g == '(' || g=='{' || g=='[') {
			_stack.push(g);
		}

		else {
			if (g == ')') g--;
			else g -= 2;

			if (_stack.top() != g) {
				cout << "False";
				return 0;
			}
			_stack.pop();
		}
	}

	if (_stack.empty())
		cout << "True";
	else
		cout << "False";

	return 0;

}