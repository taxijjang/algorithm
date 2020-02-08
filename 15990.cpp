#include<iostream>
#include<algorithm>
#include<vector>

#define SIZE 101000
using namespace std;

typedef long long ll;

const int MOD = 1000000009;
vector<int> coins;

ll dp[SIZE][4];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int  T; cin >> T;

	for (int i = 1; i < 4; i++) {
		coins.push_back(i);
	}
	dp[0][0] = dp[1][1] = dp[2][2] = dp[3][3] = 1;
	for (int i = 1; i < SIZE; i++) {
		if (i - 1 >= 0) {
			dp[i][1] += (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		}

		if (i - 2 >= 0) {
			dp[i][2] += (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		}
		if (i - 3 >= 0) {
			dp[i][3] += (dp[i - 3][1] + dp[i - 3][2]) % MOD;
		}

	}
	for (int t = 1; t <= T; t++ ) {
		int n; cin >> n;

		ll sum = 0;
		for (int i = 1; i <= 3; i++) {
			sum = (sum + dp[n][i]) % MOD;
		}

		cout << sum;
	}
}