#include <iostream>

int arr[10001];
int dp[10001];
int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - arr[i] >= 0) {
				dp[j] = dp[j] + dp[j - arr[i]];
			}
		}
	}

	printf("%d", dp[K]);
	return 0;
	
}