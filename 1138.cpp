#include<iostream>

int arr[11];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);

		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (cnt == num && arr[j] == 0) {
				arr[j] = i;
				break;
			}
			if (arr[j] == 0) cnt++;
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", arr[i]);
	}
}