#include <iostream>

typedef long long int ll;
ll dp[91];

int main(void) {
	int N;
	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printf("%lld", dp[N]);

	return 0;
}