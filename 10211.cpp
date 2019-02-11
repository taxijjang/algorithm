#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int psum[1001];

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}

		
		psum[1] = arr[1];
		int max = psum[1];

		for (int i = 2; i <= N; i++) {
			if (psum[i - 1] + arr[i] < arr[i]) {
				psum[i] = arr[i];
			}
			else {
				psum[i] = psum[i - 1] + arr[i];
			}
			if (psum[i] > max) max = psum[i];
		}

		printf("%d\n", max);

		fill(arr, arr + N + 1, 0);
		fill(psum, psum + N + 1, 0);
	}

	return 0;
}