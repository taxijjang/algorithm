#include <iostream>

int arr[301][301];

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int K;
	scanf("%d", &K);

	int x1, y1, x2, y2;
	int sum;
	for (int k = 1; k <= K; k++) {
		sum = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				sum += arr[i][j];
			}
		}
		printf("%d\n", sum);
	}

	
}