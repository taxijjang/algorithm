#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	int max = 0;

	for (int i = 0; i < N; i++) {
		if (arr[i] * (N - i) > max) {
			max = arr[i] * (N - i);
		}
	}

	printf("%d", max);
}