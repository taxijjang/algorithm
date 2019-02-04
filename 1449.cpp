#include <iostream>
#include <algorithm>

using namespace std;

int arr[2000];

int main(void) {
	int N, L;
	scanf("%d %d", &N, &L);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr+1, arr + N+1);

	int cnt = 1;

	int end = arr[1]+L;
	for (int i = 2; i <= N; i++) {
		if (arr[i] < end) {
		}
		else {
			end = arr[i] + L;
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}