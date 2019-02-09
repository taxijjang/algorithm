#include <iostream>

void hanoi(int n, int a, int b) {
	int c;
	if (n <= 1) {
		printf("%d %d\n", a, b);
	}
	
	else {
		c = 6 - a - b;

		hanoi(n - 1, a, c);
		printf("%d %d\n", a, b);
		hanoi(n - 1, c, b);
	}
}
int main(void) {
	int N;
	scanf("%d", &N);

	printf("%d\n", (1 << N) - 1);
	hanoi(N, 1, 3);

	return 0;
}