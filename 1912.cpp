#include<iostream>
#include <algorithm>

using namespace std;

int arr[100002];
int arr2[100002];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	arr2[0] = arr[0];

	for (int i = 0; i < N- 1; i++) {
		if (arr2[i] + arr[i + 1] >= arr[i + 1]) {
			arr2[i + 1] = arr2[i] + arr[i + 1];
		}
		else {
			arr2[i + 1] = arr[i + 1];
		}
	}

	sort(arr2, arr2 + N);
	printf("%d", arr2[N-1]);
	return 0;
}