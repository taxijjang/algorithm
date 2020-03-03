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
		int n, k; cin >> n >> k;

		int res = 0;

		int mok = n / k;
		int na = n%k;
		if (k / 2 > na) {
			res = n;
		}
		else {
			res = k*mok + k / 2;
		}

		cout << res << "\n";
	}
}