#include <iostream>

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	int result = N - 1 + N*(M - 1);

	printf("%d", result);

	return 0;
}