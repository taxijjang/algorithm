#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
int visited[1001];

int cnt = 0;
void dfs(int here) {
	visited[here] = 1;
	for (auto v : graph[here]) {
		if (visited[v] == 1) {
			cnt++;
		}
		if (visited[v] != 1) {
			dfs(v);
		}
	}
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);

		for (int i = 0; i<= N; i++) {
			graph[i].assign(0, 0);
		}
		for (int i = 1; i <= N; i++) {
			int v;
			scanf("%d", &v);
			graph[i].push_back(v);
		}

		cnt = 0;

		fill(visited, visited + N + 1, 0);
		for (int i = 1; i <= N; i++) {
			if(visited[i] != 1)
				dfs(i);
		}

		printf("%d\n", cnt);
	}
}