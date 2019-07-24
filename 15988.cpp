#include<iostream>
#define SIZE 1000001

typedef long long int ll;
ll arr[SIZE];
const ll mod = 1000000009;

int main(void) {
	arr[1] = 1, arr[2] = 2, arr[3] = 4;
	for (int i = 4; i < SIZE; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3])%mod;
	}
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N; scanf("%d", &N);
		printf("%d\n", arr[N]);
	}
}