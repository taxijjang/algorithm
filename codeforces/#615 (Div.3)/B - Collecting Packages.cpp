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


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		vector<pair<int, int>> loc;

		int n; cin >> n;

		loc.push_back({ 0,0 });
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			loc.push_back({ x,y });
		}

		sort(loc.begin(), loc.end());

		string res = "";
		bool check = false;
		for (int i = 1; i < loc.size(); i++) {
			check = false;
			if (loc[i - 1].first < loc[i].first && loc[i - 1].second > loc[i].second)
				break;
			check = true;
			for (int r = 0; r < loc[i].first - loc[i - 1].first; r++) {
				res += 'R';
			}

			for (int u = 0; u < loc[i].second - loc[i - 1].second; u++) {
				res += 'U';
			}
		}
		if (check == false)
			cout << "NO\n";
		else
			cout << "YES\n" << res << "\n";
	}
}