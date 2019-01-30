#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001][3];
int arr[10001];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0][0] = 0;
	dp[0][1] = arr[0];
	dp[0][2] = arr[0];

	for (int i = 1; i < N; i++) {
		dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}

	printf("%d", max(max(dp[N-1][0], dp[N-1][1]), dp[N-1][2]));
}