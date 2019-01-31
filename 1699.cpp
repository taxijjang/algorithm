#include <iostream>
#include <cmath>

using namespace std;
int dp[100001];

int min(int a, int b) {
	return a < b ? a : b;
}
int main(void) {
	int N;
	scanf("%d", &N);

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j*j] + 1);
		}
	}

	printf("%d", dp[N]);
}