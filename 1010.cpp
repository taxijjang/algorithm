#include <iostream>

long long int arr[1001][1001] = { 0 };

int main(void) {
	int T;
	scanf("%d", &T);

	int N, M;

	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;

	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);


		for (int n = 2; n <= M; n++) {
			for (int j = 0; j <= M; j++) {
				arr[n][j] = arr[n - 1][j - 1] + arr[n - 1][j];
				arr[n][j];
			}
		}

		printf("%lld\n", arr[M][N]);
	}
}