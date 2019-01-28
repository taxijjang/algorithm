#include <iostream>

int dp[101][10];

int main(void) {
	int N;
	int m = 1000000000;
	scanf("%d", &N);

	for (int i = 0; i <= 9 ; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1] % m;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8] % m;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%m;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= 9; i++) {
		cnt = (cnt + dp[N][i])%m;
	}

	printf("%d", cnt);
}