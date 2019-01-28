#include <iostream>

int dp[12];

int main(void) {
	int N;
	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		printf("%d\n", dp[num]);
	}

	return 0;
}