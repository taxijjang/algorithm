#include <iostream>

int S[1000021];
int num[1000021];
int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	int a;
	for (int n = 1; n <= N; n++) {
		scanf("%d", &a);
		num[n] = a;
	}

	S[0] = 0;
	for (int i = 1; i <= N; i++) {
		S[i] = S[i - 1] + num[i];
	}

	int x, y;
	for (int m = 1; m <= M; m++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", S[y] - S[x - 1]);
	}

}