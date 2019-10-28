#include<iostream>
#include<string>
#include<set>
using namespace std;

set<string> _set;

int main(void) {
	string s; cin >> s;
	string res = "";

	for (int i = s.size() - 1; i >= 0; i--) {
		res = s[i] + res;
		_set.insert(res);
	}

	for (auto it = _set.begin(); it != _set.end(); it++) {
		cout << *it << "\n";
	}
}