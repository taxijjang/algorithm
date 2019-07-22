#include<iostream>

typedef long long int ll;
ll arr[81];

int main(void) {
	int N; scanf("%d", &N);

	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%lld", arr[N] * 4 + arr[N - 1] * 2);
}