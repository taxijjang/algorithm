#include <iostream>

int arr[501][501];
bool visited[501][501];
int cnt = 0;
int dp[501][501];

int x_l[4] = { 1,0,-1,0 };
int y_l[4] = { 0,1,0,-1 };
int N, M;

int dfs(int x, int y) {
	if (x == N && y == M) {
		return 1;
	}
	if (x < 1 || y<1 || x > N || y  > M)
		return 0;
	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		
		if (arr[x + x_l[i]][y + y_l[i]] < arr[x][y]) {
			dp[x][y]+=dfs(x + x_l[i], y + y_l[i]);
		}
	}
	return dp[x][y];
}
int main(void) {
	
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d", dfs(1, 1));

	getchar();
}