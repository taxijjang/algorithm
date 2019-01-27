#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;

long long int dp[MAX];
int main(void) {
	int N;
	scanf("%d", &N);

	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printf("%lld", dp[N]);

	return 0;
}