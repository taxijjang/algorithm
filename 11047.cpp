#include <iostream>
#include <deque>

using namespace std;

int arr[11];
int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int index = N - 1;
	int cnt = 0;
	while (1) {
		if (arr[index] <= K) {
			K = K - arr[index];
			cnt++;
		}
		if (arr[index] > K) index--;
		if (K <= 0) break;
	}

	printf("%d", cnt);

}