#include <iostream>
#define mod 10007

typedef long long int ll;

ll dp[1001][10];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k])%mod;
			}
		}
	}

	ll sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[N][i];
	}

	printf("%lld", sum % mod);
	return 0;
}