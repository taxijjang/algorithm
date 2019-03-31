#include<iostream>

int arr[1001];
int N, K, ans,sum;

void dfs(int i, int sum) {
	if (i > N || sum >= K) {
		if (sum == K)
			ans++;
		return;
	}

	dfs(i + 1, sum + arr[i]);
	dfs(i + 1, sum);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &N, &K);

		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		ans = 0, sum = 0;
		dfs(0, sum);

		printf("#%d %d\n", t, ans);
	}
}