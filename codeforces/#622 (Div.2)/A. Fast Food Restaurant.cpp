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

	vector<int> arr = { 1,2,3 };


	while (T--) {
		vector<int> food(4, 0);
		int res = 0;
		cin >> food[1] >> food[2] >> food[3];

		vector<string> combi = { "1","2","3","12","13","23","123" };

		do {
			int cnt = 0;
			vector<int> tmp; tmp.assign(food.begin(), food.end());
			for (auto c : combi) {
				int c_size = c.size();

				if (c_size == 1) {
					if (tmp[c[0] - '0']) {
						tmp[c[0] - '0']--;
						cnt++;
					}

				}
				else if (c_size == 2) {
					if (tmp[c[0] - '0'] && tmp[c[1] - '0'] >0) {
						tmp[c[0] - '0']--; tmp[c[1] - '0']--;
						cnt++;
					}
				}
				else if (c_size == 3) {
					if (tmp[c[0] - '0'] && tmp[c[1] - '0'] && tmp[c[2] - '0']) {
						tmp[c[0] - '0']--; tmp[c[1] - '0']--; tmp[c[2] - '0']--;
						cnt++;
					}
				}
			}
			res = max(res, cnt);

		} while (next_permutation(combi.begin(), combi.end()));
		cout << res << "\n";
	}
}