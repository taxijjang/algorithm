#include <iostream>

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = i; j < N; j++) {
			printf(" ");
		}
		for (int j = 1; j <= 2 * i - 1; j++) {
			if (j % 2 == 0) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}