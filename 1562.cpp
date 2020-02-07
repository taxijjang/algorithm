#include<bits/stdc++.h>

#define SIZE 110

using namespace std;

typedef long long int ll;

const int INF = 2000000000;
const int MOD = 1000000000;

int dp[SIZE][10][1<<10];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	for (int i = 1; i < 10; i++) {
		dp[1][i][1 << i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < 1 << 10; k++) {			
				int use = k | (1 << j);
				if (j == 0) {
					dp[i][j][use] += dp[i - 1][1][k] % MOD;
				}
				else if (j == 9) {			
					dp[i][j][use] += dp[i - 1][8][k] % MOD;
				}
				else {
					dp[i][j][use] += (dp[i - 1][j - 1][k] % MOD + dp[i - 1][j + 1][k] % MOD);
				}
			}
		}
	}

	int res = 0;

	for (int i = 0; i < 10; i++) {
		res += (dp[N][i][(1 << 10) - 1]) % MOD;
	}

	cout << res %MOD;
}