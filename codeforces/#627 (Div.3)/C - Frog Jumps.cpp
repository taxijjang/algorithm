#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

#define SIZE 110
const int INF = 2e9;
using namespace std;

typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		string s; cin >> s;
		int res = 0;

		int left=s.size(), right=s.size();
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == 'R') {
				left = i;
				res = max(res, right - left);
				right = i;
			}
		}

		
		cout << max(res, left + 1) << "\n";

	}
	return 0;
}