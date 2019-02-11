#include <iostream>

int arr[100001];
int psum[100001];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	psum[1] = arr[1];

	for (int i = 2; i <= N; i++) {
		psum[i] = psum[i - 1] + arr[i];
	}

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", psum[b] - psum[a - 1]);
	}
}