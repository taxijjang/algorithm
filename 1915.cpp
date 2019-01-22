#include <iostream>
#include <algorithm>

using namespace std;

int d[1001][1001] = { 0 };
int DP[1001][1001] = { 0 };

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	int num;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &num);
			d[i][j] = num;
		}
	}

	int area = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (d[i][j] == 1) {
				DP[i][j] = min(min(DP[i - 1][j], DP[i - 1][j - 1]), DP[i][j - 1]) + d[i][j];
			}
			else {
				DP[i][j] = d[i][j];
			}
			if (area < DP[i][j] * DP[i][j]) area = DP[i][j] * DP[i][j];
		}
	}
	printf("%d", area);
}