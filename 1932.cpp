#include <vector>
#include <algorithm>

using namespace std;

int dp[501][501] = { 0 };
int d[501][501] = { 0 };

int max(int a, int b) {
	if (a > b) return a;
	return b;
}
int main(void) {
	int N;
	scanf("%d", &N);

	int n;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &n);
			dp[i][j] = n;
		}
	}

	d[1][1] = dp[1][1];
	int sum = 0;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) d[i][j] = d[i - 1][j] + dp[i][j];
			else if (j == i) d[i][j] = d[i - 1][j - 1] + dp[i][j];
			else {
				if (d[i - 1][j - 1] > d[i - 1][j]) {
					d[i][j] = d[i - 1][j - 1] + dp[i][j];
				}
				else {
					d[i][j] = d[i - 1][j] + dp[i][j];
				}
			}
			if (sum < d[i][j]) sum = d[i][j];
		}
	}
	printf("%d", sum);
}