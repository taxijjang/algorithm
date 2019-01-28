#include <iostream>

int dp[1000001];

int main(void) {
	int N;
	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1])%15746;
	}

	printf("%d", dp[N]);

	return 0;
}