#include <iostream>

int arr[101][101];
int result[101][101];
int INF = 9999;

int min(int a, int b) {
	return a < b ? a : b;
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0) arr[i][j] = INF;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(arr[i][j] != INF)
				printf("%d ", 1);
			else {
				printf("%d ", 0);
			}
		}
		printf("\n");
	}
}