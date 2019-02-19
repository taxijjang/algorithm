#include <iostream>

int arr[13] = { 0, };
int main(void) {
	int N;
	scanf("%d", &N);

	int result = 1;

	arr[0] = 1;

	for (int i = 1; i <= N; i++) {
		arr[i] = arr[i-1] * i;
	}

	printf("%d", arr[N]);
}