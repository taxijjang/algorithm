#include<iostream>
#include<algorithm>
using namespace std;

int arr[501][501];
int dp[501][501];

int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };

int N;
int dfs(int here_x, int here_y) {
	if (dp[here_x][here_y]) {
		return dp[here_x][here_y];
	}
	for (int i = 0; i < 4; i++) {
		int n_x = here_x + x[i];
		int n_y = here_y + y[i];

		if (arr[here_x][here_y] >= arr[n_x][n_y])
			continue;
		dp[here_x][here_y] = max(dp[here_x][here_y], dfs(n_x, n_y) + 1);
	}

	return dp[here_x][here_y];
}
int main(void) {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int res=1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			res = max(dfs(i,j),res);
		}
	}

	printf("%d", res);


}