#include<iostream>
#include<vector>

using namespace std;

vector<int> graph[11];
bool visited[11];
int cnt;

void dfs(int here,int dis) {
	visited[here] = true;
	if (cnt < dis) {
		cnt = dis;
	}
	for (auto v : graph[here]) {
		if (visited[v] != true) {
			dfs(v,dis+1);
			visited[v] = false;
		}
	}
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N, M;
		scanf("%d %d", &N, &M);

		for (int m = 0; m < M; m++) {
			int v1, v2;
			scanf("%d %d", &v1, &v2);

			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}

		fill(visited, visited + 11, false);

		cnt = 1;

		for (int i = 1; i <= N; i++) {
			dfs(i, 1);
		}

		printf("#%d %d\n", t, cnt);

		for (int i = 0; i <= N; i++) {
			graph[i].clear();
		}

	}
}