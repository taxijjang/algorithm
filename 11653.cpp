#include <iostream>

int main(void) {
	int N;
	scanf("%d", &N);

	int temp = N;

	for (int i = 2; i <= N; i++) {
		while (1) {
			if (temp%i == 0) {
				printf("%d\n", i);
				temp /= i;
			}
			else break;
		}
	}
}