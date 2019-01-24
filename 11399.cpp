#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr + 1, arr + N + 1);

	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i] + arr[i - 1];
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += arr[i];
	}
	printf("%d", sum);
}