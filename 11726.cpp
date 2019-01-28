#include <iostream>
#define mod 10007
int dp[1001];

int main(void) {
	int N;
	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}

	printf("%d", (dp[N]) % mod);

	return 0;
}