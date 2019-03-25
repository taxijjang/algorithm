#include <iostream>
#include<algorithm>
using namespace std;

int arr[2001];
int dp[2001][2001];

int go(int i, int j) {
	if (dp[i][j] >= 0)
		return dp[i][j];
	if (i >= j)
		return dp[i][j] = 1;
	if (i + 1 == j) {
		if (arr[i] == arr[j])
			return dp[i][j] = 1;
		else
			return dp[i][j] = 0;
	}
	if (arr[i] == arr[j]) {
		dp[i][j] = go(i + 1, j - 1);
	}
	else {
		return dp[i][j] = 0;
	}
}
int main(void) {
	int N;
	scanf("%d", &N);


	fill(&dp[0][0], &dp[2001][2001], -1);


	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			dp[i][j] = go(i, j);
		}
	}

	int M;

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d", dp[a][b]);
	}
	getchar();
}