#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Data {
	int m;
	int n;
}Data;
Data dp[2][3];
int arr[3];
int main(void) {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

		dp[1][0].m = max(dp[0][0].m, dp[0][1].m) + arr[0];
		dp[1][1].m = max(dp[0][0].m, max(dp[0][1].m, dp[0][2].m)) + arr[1];
		dp[1][2].m = max(dp[0][1].m, dp[0][2].m) + arr[2];

		//min
		dp[1][0].n = min(dp[0][0].n, dp[0][1].n) + arr[0];
		dp[1][1].n = min(dp[0][0].n, min(dp[0][1].n, dp[0][2].n)) + arr[1];
		dp[1][2].n = min(dp[0][1].n, dp[0][2].n) + arr[2];

		for (int j = 0; j <= 3; j++) {
			dp[0][j] = dp[1][j];
		}
	}

	int m_num = 0;
	int n_num = 1000000;
	for (int i = 0; i < 3; i++) {
		m_num = max(m_num, dp[0][i].m);
		n_num = min(n_num, dp[0][i].n);
	}
	printf("%d %d", m_num, n_num);
}
