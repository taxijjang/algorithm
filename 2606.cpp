#include <iostream>
#include <vector>

using namespace std;

bool visited[101];
vector<int> arr[101];
int cnt = 0;
void dfs(int here) {
	visited[here] = true;

	for (auto a : arr[here]) {
		if (visited[a] != true) {
			cnt++;
			dfs(a);
		}
	}
}
int main(void) {
	int N;
	scanf("%d", &N);
	int M;
	scanf("%d", &M);

	for (int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(1);

	printf("%d", cnt);
}