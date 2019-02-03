#include <iostream>

int price[11];

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int n = 1; n <= N; n++) {
		scanf("%d", &price[n]);
	}

	int cnt = 0;

	for (int i = N; i > 0; i--) {
		while (K / price[i] != 0) {
			cnt++;
			K = K - price[i];
		}
		if (K == 0) break;
	}

	printf("%d", cnt);

	return 0;
}