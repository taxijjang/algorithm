#include<iostream>

using namespace std;

int graph[51][51];
int visited[51][51];
int X[8] = { -1,-1,0,1,1,1,0,-1 };
int Y[8] = { 0,1,1,1,0,-1,-1,-1 };

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		if (graph[x + X[i]][y + Y[i]] == 1) {
			if(visited[x + X[i]][y + Y[i]] != 1)
			dfs(x + X[i], y + Y[i]);
		}
	}
}
int main(void) {
	while (1) {
		int W, H;
		scanf("%d %d", &W, &H);

		if (W == 0 && H == 0) {
			break;
		}

		for (int x = 1; x <= H; x++) {
			for (int y = 1; y <= W; y++) {
				scanf("%d", &graph[x][y]);
			}
		}

		int cnt = 0;

		for (int x = 1; x <= H; x++) {
			for (int y = 1; y <= W; y++) {
				if (visited[x][y] != 1 && graph[x][y] == 1) {
					dfs(x, y);
					cnt++;
				}
			}
		}

		for (int i = 0; i <= H; i++) {
			for (int j = 0; j <= W; j++) {
				visited[i][j] = 0;
				graph[i][j] = 0;
			}
		}
		printf("\n\n%d\n\n", cnt);
	}
}