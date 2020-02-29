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
		int x, y; cin >> x >> y;

		int res;
		if (x == y)
			res = 0;

		else if (x > y) {
			if (abs(x - y) % 2 == 0)
				res = 1;
			else
				res = 2;
		}
		else {
			if (abs(x - y) % 2 == 1)
				res = 1;
			else
				res = 2;
		}
		cout << res << "\n";
	}
	return 0;
}