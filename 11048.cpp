#include <iostream>

int arr[1001][1001];
int dp[1001][1001];

int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= N; i++) {
		dp[i][1] = arr[i][1]+ dp[i-1][1];
	}

	for (int j = 2; j <= M; j++) {
		dp[1][j] = arr[1][j] + dp[1][j-1];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= M; j++) {
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + arr[i][j];
		}
	}

	printf("%d", dp[N][M]);

	return 0;
}