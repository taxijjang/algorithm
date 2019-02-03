#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr[100001];
int parent[100001];

void dfs(int here) {
	for (auto next : arr[here]) {
		if (parent[next] == -1) {
			parent[next] = here;
			dfs(next);
		}
	}
}
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	fill(parent, parent + 100001, -1);
	
	dfs(1);
	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}
}