#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];

bool cmp(int a, int b) {
	return a > b;
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr + 1, arr + N + 1,cmp);

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] >= 1) {
			if (arr[i + 1] >= 1) {
				if (arr[i] + arr[i + 1] > arr[i] * arr[i + 1]) {
					sum += arr[i] + arr[i + 1];
				}
				else {
					sum += arr[i] * arr[i + 1];
				}
				i++;
			}
			else {
				sum += arr[i];
			}
		}
		else if (arr[i] == 0) {
			if ((N - i)%2 != 0) {
				sum += arr[i] * arr[i + 1];
				i++;
			}
		}
		else {
			if ((N - i) % 2 == 0) {
				sum += arr[i];
			}
			else {
				sum += arr[i] * arr[i + 1];
				i++;
			}
		}
	}

	printf("%d", sum);
}