#include <iostream>

int arr[1010];
int dp[1010];

int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	
	for (int i = 0; i <= N; i++) {
		dp[i] = 0;
	}
	int nn = 0;
	int Max = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[j], dp[i]);
			}
		}
		dp[i] += 1;
		if (Max < dp[i]) Max = dp[i];
	}
	printf("%d", Max);
}