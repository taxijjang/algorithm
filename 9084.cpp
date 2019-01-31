#include <iostream>

int dp[10011];
int arr[30];

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}

		int M;
		scanf("%d", &M);

		dp[0] = 1;

		for (int i = 1; i <= M; i++) {
			dp[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = arr[i]; j <= M; j++) {
				dp[j] = dp[j] + dp[j - arr[i]];
			}
		}

		printf("%d\n", dp[M]);
	}
}