#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

vector<int> tree;
map<int, int> _map;
queue<int> q;
vector<int > res;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int loc; cin >> loc;
		tree.push_back(loc);
		_map[loc] = 0;
		q.push(loc);
	}

	ll ans = 0;
	while (!q.empty()) {
		if (res.size() == m) break;

		int here = q.front();
		q.pop();
		if (_map[here] != 0) {
			ans += _map[here];
			res.push_back(here);
		}
		if (_map.count(here - 1) == 0) {
			_map[here - 1] = _map[here] + 1;
			q.push(here - 1);
		}
		if (_map.count(here + 1) == 0) {
			_map[here + 1] = _map[here] + 1;
			q.push(here + 1);
		}
	}
	cout << ans << "\n";
	for (auto r : res)
		cout << r << " ";

}