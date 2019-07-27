#include<iostream>
#define SIZE 51

int arr[SIZE][SIZE];

int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };
int N, M, K;
void dfs(int h_x, int h_y) {
	arr[h_x][h_y] = false;

	for (int i = 0; i < 4; i++) {
		int n_x = h_x + x[i];
		int n_y = h_y + y[i];

		if (n_x < 0 || n_y < 0 || n_x >= N || n_y >= M)
			continue;
		if (arr[n_x][n_y] == false)
			continue;
		dfs(n_x, n_y);
	}
}
int main(void) {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &N, &M, &K);
		int cnt = 0;

		for (int i = 0; i < K; i++) {
			int n, m; scanf("%d %d", &n, &m);
			arr[n][m] = true;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == true) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
}
