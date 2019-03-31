#include<iostream>

using namespace std;

int N;

int arr[50][50];


int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &arr[i][j]);
			}
		}

		int sum = 0;
		int K = 1;
		for (int i = 0; i < N; i++) {

			if (i <= N / 2) {
				for (int j = (N / 2) - i; j <= (N / 2) + i; j++) {
					sum += arr[i][j];
				}
			}
			else {
				for (int j = K; j < N - K; j++) {
					sum += arr[i][j];
				}
				K++;
			}
		}

		printf("#%d %d\n", t, sum);
	}
}