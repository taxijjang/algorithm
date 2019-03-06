#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10001];
int arr[10001];
int cost[10001];
int visited[10001];
int c = 0;

void dfs(int here) {
	visited[here] = 1;
	for (auto v : graph[here]) {
		if (visited[v] != 1) {
			if (c > cost[v]) c = cost[v];
			dfs(v);
		}
	}
}



int min_(int a, int b) {
	return a < b ? a : b;
}
int main(void) {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
	}

	for (int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] != 1) {
			c = cost[i];
			dfs(i);
			sum += c;
		}
	}

	printf("%d", sum);
	getchar();
}