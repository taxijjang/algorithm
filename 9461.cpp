#include <iostream>

typedef long long int ll;
ll dp[101];
ll arr[101];

int main(void) {
	int N;
	scanf("%d", &N);

	dp[1] = 1;	dp[2] = 1;

	for (int i = 3; i <= 100; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);
		printf("%lld\n", dp[num]);
	}
	
	return 0;
}