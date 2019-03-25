#include<iostream>

typedef long long int ll;
using namespace std;

int arr[101][101];
ll dp[101][101] = { 0 };

int x_l[2] = { 0,1 };
int y_l[2] = { 1,0 };

ll dfs(int x, int y, int N) {

	if (x == N && y == N) {
		return 1;
	}
	if (arr[x][y] == 0) {
		return 0;
	}

	if (dp[x][y]) {
		return dp[x][y];
	}

	for (int i = 0; i < 2; i++) {
		int X = x + (x_l[i] * arr[x][y]);
		int Y = y + (y_l[i] * arr[x][y]);
		if (X > N || Y > N) continue;
		dp[x][y] += dfs(X, Y, N);
	}

	return dp[x][y];
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%lld", dfs(1, 1, N));
}