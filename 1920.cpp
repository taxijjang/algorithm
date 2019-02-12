#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int num[100001];

bool binary(int start, int end, int n) {
	int mid = (start + end) / 2;
	bool result;
	if (start > end) {
		return false;
	}
	else {
		if (arr[mid] > n) {
			result = binary(start, mid - 1, n);
		}
		else if (arr[mid] < n) {
			result = binary(mid + 1, end, n);
		}
		else {
			return true;
		}

		return result;
	}
}

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr + 1, arr + N + 1);

	int M;
	scanf("%d", &M);

	for (int i = 1; i <= M; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 1; i <= N; i++) {
		bool result;
		result = binary(1, N, num[i]);

		if (result == true) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}

}