#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

typedef long long int ll;
int dp[100001][4];
int arr[3][100001];
int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int n;
		scanf("%d", &n);

		int tmp;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		dp[1][0] = 0;
		dp[1][1] = arr[1][1];
		dp[1][2] = arr[2][1];

		for (int i = 2; i <= n; i++) {
			dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[1][i];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[2][i];
		}

		int sum = 0;
		
		sum = max(max(dp[n][0], dp[n][1]), dp[n][2]);

		printf("%d\n", sum);
		
	}

}