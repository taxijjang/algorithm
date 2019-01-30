#include <iostream>

int arr[1011];
int dp[1011];

int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}


	int m = 0;
	for (int i = 1; i <= N; i++) {
		int n = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (n < dp[j])
					n = dp[j];
			}
		}
		dp[i] = n + 1;
		if (m < dp[i]) m = dp[i];
	}

	printf("%d", m);

	return 0;
}