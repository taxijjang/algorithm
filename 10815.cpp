#include <iostream>
#include <algorithm>

using namespace std;

int arr[500001];
int ass[500001];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &ass[i]);
	}

	for (int i = 0; i < M; i++) {
		int start=0, end=N-1, mid;
		bool correct = false;

		while (start <= end) {
			mid = (start + end) / 2;
			if (arr[mid] < ass[i]) {
				start = mid + 1;
			}
			else if (arr[mid] > ass[i]) {
				end = mid - 1;
			}
			else {
				correct = true;
				break;
			}
		}
		if (correct) {
			printf("%d ", 1);
		}
		else {
			printf("%d ", 0);
		}
	}

}