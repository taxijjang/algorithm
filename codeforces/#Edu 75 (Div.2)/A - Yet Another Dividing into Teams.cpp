#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
 
set<char> _set;
int main(void) {
	int T; cin >> T;
 
	for (int t = 1; t <= T; t++) {
		string s; cin >> s;
		int s_size = s.size();
		if (s_size == 1) {
			cout << s;
		}
		else {
			for (int i = 1; i < s_size; i++) {
				if (s[i - 1] == s[i]) {
					s[i - 1] = '0';
					s[i] = '0';
					i++;				
				}
				else {
					_set.insert(s[i - 1]);
				}
			}
			if (s[s_size - 1] != s[s_size - 2])
				_set.insert(s[s_size - 1]);
 
			for (auto it = _set.begin(); it != _set.end(); it++) {
				cout << *it;
			}
		}
		
		set<char> empty;
		swap(_set,empty);
		cout << "\n";
	}
}