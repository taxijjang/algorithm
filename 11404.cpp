#include <iostream>

using namespace std;

int INF = 100001;
int city[102][102];
int min(int x, int y) {
	if (x > y) return y;
	return x;
}
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				city[i][j] = 0;
				continue;
			}
			city[i][j] = INF;
		}
	}

	int x, y, cost;
	for (int m = 1; m <= M; m++) {
		scanf("%d %d %d", &x, &y, &cost);
		if (city[x][y] >= cost) city[x][y] = cost;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (city[i][j])
					city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (city[i][j] > 100000) printf("%d ", 0);
			else { printf("%d ", city[i][j]); }
		}
		printf("\n");
	}


	return 0;
}