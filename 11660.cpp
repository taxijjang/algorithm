#include <iostream>

using namespace std;

int arr[1026][1026] = { 0 };
int D[1025][1025] = { 0 };
int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	int start;

	int num;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num);
			arr[i][j] = num;
		}

	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + arr[i][j];
		}
	}

	int x1, x2, y1, y2;

	for (int m = 1; m <= M; m++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", D[x2][y2] - D[x2][y1 - 1] - D[x1 - 1][y2] + D[x1 - 1][y1 - 1]);
	}
}