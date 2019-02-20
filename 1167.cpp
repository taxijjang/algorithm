#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int>> tree[100001];
bool visited[100001];
int dist[100001];
int sum = 0;
queue<int> q;

int max_(int a, int b) {
	return a > b ? a : b;
}
int bfs(int here) {
	fill(dist, dist + 100001, 0);
	fill(visited, visited + 100001, false);
	visited[here] = true;
	q.push(here);
	int max = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto a : tree[v]) {
			if (visited[a.first] != true) {
				dist[a.first] += dist[v] + a.second;
				max = max_(max, dist[a.first]);
				visited[a.first] = true;
				q.push(a.first);
			}

		}
	}
	return max;
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		int V;
		scanf("%d", &V);
		while (1) {
			int V2;
			scanf("%d", &V2);
			if (V2 == -1) break;
			int W;
			scanf("%d", &W);

			tree[V].push_back(pair<int, int>(V2, W));
		}
	}

	int max = 0;
	int start = 1;
	bfs(start);

	for (int i = 2; i <= N; i++) {
		if (dist[i] > dist[start]) start = i;
	}
	
	bfs(start);

	printf("%d", *max_element(dist,dist+100001));
}