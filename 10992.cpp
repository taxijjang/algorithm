#include <iostream>

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j++) {
			printf(" ");
		}
		for (int j = 1; j <= 2 * i - 1; j++) {
			if (j == 1 || j == 2*i-1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	for (int i = 1; i <= 2*N-1; i++) {
		printf("*");
	}

	return 0;
}