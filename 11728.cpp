#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;
ll arr[2000001];
ll a[1000001];
ll b[1000001];

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%lld", &b[i]);
	}

	sort(a, a + N);
	sort(b, b + M);

	int i = 0, j = 0, index = 0;
	while (i < N && j < M) {
		if (a[i] < b[j]) {
			arr[index++] = a[i++];
		}
		else {
			arr[index++] = b[j++];
		}
	}

	if (i != N) {
		for (; i < N; i++) {
			arr[index++] = a[i];
		}
	}
	if (j != M) {
		for (; j < M; j++) {
			arr[index++] = b[j];
		}
	}

	for (int i = 0; i < N+M; i++) {
		printf("%d ", arr[i]);
	}
}