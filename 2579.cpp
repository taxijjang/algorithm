#include <iostream>

int arr[301];
int dp[301];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}
int main(void) {
	int N;
	scanf("%d", &N);

	int a;
	for (int n = 1, a; n <= N; n++) {
		scanf("%d", &a);
		arr[n] = a;
	}
	dp[0] = 0;
	dp[1] = max(arr[0] + arr[1], arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	for (int d = 3; d <= N; d++) {
		dp[d] += max(dp[d - 2] + arr[d], dp[d - 3] + arr[d - 1] + arr[d]);
	}
	printf("%d", dp[N]);
}