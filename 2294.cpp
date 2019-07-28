#include<iostream>
#include<algorithm>
#define SIZE 10001

using namespace std;

int dp[SIZE];
int cost[101];
int main(void) {
	int n, k; scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &cost[i]);
	}

	sort(cost, cost + n);

	fill(dp, dp + SIZE, 10001);
	dp[0] = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (cost[i] > j) continue;
			dp[j] = min(dp[j - cost[i]] + 1, dp[j]);
		}
	}
	if (dp[k] == 10001)
		printf("-1");
	else
		printf("%d", dp[k]);
}
