#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int color = 1;

vector<int> graph[20001];
int visited[20001];
int Color[20001];
int judge;
int one = 999999;

void dfs(int here,int color) {
	visited[here] = 1;
	if (graph[here].size() == 0) {
		Color[here] = one--;
	}
	else { Color[here] = color; }

	for (auto v : graph[here]) {
		if (v == here) { Color[here] = one--; }
		if (visited[v] != 1) {
			dfs(v,color* -1);
		}
	}
}

bool binay(int V) {
	for (int i = 0; i <= V; i++) {
		int size = graph[i].size();
		for (auto v : graph[i]) {
			if (Color[i] == Color[v] && i!=v)
				return false;
		}
	}
	return true;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int V, E;
		scanf("%d %d", &V, &E);

		for (int i = 0; i <= V; i++) {
			graph[i].assign(0, 0);
		}

		for (int i = 1; i <= E; i++) {
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}


		fill(visited, visited + V + 1, 0);
		judge = 0;

		fill(Color, Color + V + 1, 0);

		for (int i = 1; i <= V; i++) {
			if (judge == 1) break;
			if (visited[i] != 1) {
				dfs(i, color);
			}
		}

		if (!binay(V)) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}

	return 0;
}