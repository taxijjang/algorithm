#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000001];

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int max = 1000000007;
	int nin = 0;
	int sum;
	while (nin + 1 <max) {
		sum = 0;
		int mid = (max + nin) / 2;

		for (int i = 0; i < N; i++) {
			if (arr[i] > mid) sum += arr[i] - mid;
		}

		if (sum >= M) nin = mid;
		else max = mid;
	}

	printf("%d", nin);
}