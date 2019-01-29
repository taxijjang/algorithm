#include <iostream>


bool load[101][101];
bool visited[101][101];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int dfs(int x, int y) {
	visited[x][y] = true;
	int cnt = 1;
	//╩С
	if (visited[x][y - 1] != true && load[x][y - 1] == true) {
		cnt += dfs(x, y - 1);
	}
	//го
	if (visited[x][y + 1] != true && load[x][y + 1] == true) {
		cnt += dfs(x, y + 1);
	}
	//аб
	if (visited[x-1][y ] != true && load[x-1][y ] == true) {
		cnt += dfs(x-1, y);
	}
	//©Л
	if (visited[x+1][y] != true && load[x+1][y] == true) {
		cnt += dfs(x+1, y);
	}
	return cnt;
}
int main(void) {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	int x, y;
	for (int i = 1; i <= K; i++) {
		scanf("%d %d", &x, &y);
		load[x][y] = true;
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visited[i][j] != true && load[i][j] == true) {
				cnt = max(dfs(i, j),cnt);
			}
		}
	}
	printf("%d", cnt);
}