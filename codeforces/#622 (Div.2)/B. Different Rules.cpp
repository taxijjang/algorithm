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
		int n, x, y; cin >> n >> x >> y;

		int sum = x + y;

		cout << min(n, max(1, x + y - n + 1)) << " " << min(n, x + y - 1) << "\n";
	}

}