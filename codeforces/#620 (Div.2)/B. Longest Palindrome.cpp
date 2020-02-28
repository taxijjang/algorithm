#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 110
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

map<string, bool> _map;
bool pal[SIZE];

bool check_pal(string s) {
	int s_size = s.size();

	string r_s = s;
	reverse(r_s.begin(), r_s.end());

	if (s == r_s)
		return true;
	else
		return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;

	string res = "";
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		string t_s = s;
		reverse(t_s.begin(), t_s.end());

		if (_map.find(s) == _map.end() && _map.find(t_s) == _map.end()) {
			_map[s] = false;
		}
		else
			_map[t_s] = true;
	}

	for (auto word : _map) {
		if (word.second == false && check_pal(word.first)) {
			res = word.first;
			break;
		}
	}

	for (auto word : _map) {
		if (word.second == true) {
			res = word.first + res;
			string tmp = word.first;
			reverse(tmp.begin(), tmp.end());
			res = res + tmp;
		}
	}
	cout << res.size() << "\n";
	cout << res;
}