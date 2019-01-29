#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
int visited[1001];

void dfs(int start) {
	visited[start] = 1;
	for (auto a : graph[start]) {
		if (visited[a] != 1)
			dfs(a);
	}

}
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	int a, b;
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	int cnt = 0; 
	
	for (int i = 1; i <= N; i++) {
		if (visited[i] != 1) {
			dfs(i);
			cnt++;
		}
	}

	printf("%d", cnt);
}