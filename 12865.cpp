#include<iostream>
#include<algorithm>
#include<vector>
#define SIZE 110

using namespace std;

typedef struct Data {
	int w, v;

	bool operator < (Data d) {
		return w < d.w;
	}
}Data;

Data arr[SIZE];
int dp[SIZE][100010];

int main(void) {
	int N, K; scanf("%d%d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &arr[i].w, &arr[i].v);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - arr[i].w >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].w] + arr[i].v);
			else
				dp[i][j] = dp[i - 1][j];
		}		
	}

	printf("%d", dp[N][K]);
}