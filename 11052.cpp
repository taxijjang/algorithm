#include <iostream>

using namespace std;

int arr[10001];
int dp[10001];

int max(int a, int b, int c) {
	if (a > b) {
		if (a > c) return a;
		else return c;
	}
	else if (b > c) {
		if (b > c) return b;
		else return a;
	}
	else if (c > a) {
		if (c > b) return c;
		else return b;
	}
}
int main(void) {
	int N;
	scanf("%d", &N);

	fill(dp + 1, dp + N + 1, -1);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	dp[1] = arr[1];
	if (N > 1) {
		dp[2] = max(arr[2], dp[1] + dp[1],dp[2]);
		for (int i = 3; i <= N; i++) {
			for (int j = 1; j <= i / 2; j++) {
				dp[i] = max(arr[i], dp[j] + dp[i-j],dp[i]);
			}
		}
	}

	printf("%d", dp[N]);	

	return 0;
}