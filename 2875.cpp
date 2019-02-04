#include <iostream>

int arr[10000];

int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	 
	int team = 0;
	for (int i = 0; i <= K; i++) {
		if (N - K + i <= 0 || M - i <= 0) {
			continue;
		}
		else {
			team = max(team, min((N - K + i) / 2, (M - i)));
		}
	}

	printf("%d", team);
	return 0;
}