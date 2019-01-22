#include <iostream>
#include <algorithm>

using namespace std;
int city[201][201];
int route[1001];
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	int INF = 999999999;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				city[i][j] = 0;
			}
			else {
				city[i][j] = INF;
			}
		}
	}

	int a;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &a);
			if (i == j) continue;
			else{
				if (a != 0)city[i][j] = a;
			}
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}

	int r;
	for (int i = 1; i <= M; i++) {
		scanf("%d", &r);
		route[i] = r;
	}

	int judge = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (city[i][j] == INF) {
				judge = 1;
				i = N;
				break;
			}
		}
	}
	
	if (judge == 0) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	getchar();
}
