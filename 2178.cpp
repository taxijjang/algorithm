#include <iostream>
#include <queue>
#include <string>

using namespace std;

int graph[101][101];
int visited[101][101];

int X[4] = { -1,0,1,0 };
int Y[4] = { 0,1,0,-1 };

queue<pair<int, int>> q;

int bfs(int x, int y,int N, int M) {
	visited[x][y] = 1;
	q.push(pair<int, int>(x, y));
	int xx, yy;
	int cnt = 0;

	while (!q.empty()) {	
		int q_size = q.size();

		for (int size = 1; size <= q_size; size++) {
			xx = q.front().first;
			yy = q.front().second;

			for (int i = 0; i < 4; i++) {
				if (graph[xx + X[i]][yy + Y[i]] != 0) {
					if (visited[xx + X[i]][yy + Y[i]] != 1) {
						visited[xx + X[i]][yy + Y[i]] = 1;
						q.push(pair<int, int>(xx + X[i], yy + Y[i]));
					}
				}
				if (xx + X[i] == N && yy + Y[i] == M) {
					return cnt + 2;
				}
			}
			q.pop();
		}
		cnt++;
	}
}
int main(void) {
	int N, M;
	string s;
	scanf("%d %d ", &N, &M);

	for (int i = 1; i <= N; i++) {
		cin >> s;
		int s_size = s.size();
		for (int j = 1; j <= s_size; j++) {
			graph[i][j] = s[j - 1] - '0';
		}
	}
	printf("%d",bfs(1, 1,N,M));
}