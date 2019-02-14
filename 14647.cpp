#include <iostream>
#include <string>

using namespace std;

int arr[501][501];
int cnt[501][501] = { 0, };

int max_(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			int num = arr[i][j];

			while (num != 0) {
				if (num % 10 == 9) {
					cnt[i][j] ++;
				}
				num /= 10;

			}

		}
	}

	int total = 0;
	int garo = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < M; j++) {
			sum += cnt[i][j];
		}
		total += sum;
		garo = max_(garo, sum);
	}

	int sero = 0;
	for (int i = 0; i < M; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum += cnt[j][i];
		}
		sero = max_(sero, sum);
	}

	total -= max_(garo, sero);

	printf("%d", total);
	getchar();
}

