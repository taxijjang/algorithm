#include <iostream>

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		for (int k =2*( N - i)-1; k >= 0; k--) {
			printf(" ");
		}
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i < N; i++) {
		for (int j = N - i; j > 0; j--) {
			printf("*");
		}
		for (int k = 1; k <= 2 * i; k++) {
			printf(" ");
		}
		for (int j = N - i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
}