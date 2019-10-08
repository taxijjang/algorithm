#include<iostream>
#define SIZE 1000100

typedef long long int ll;
using namespace std;

ll arr[SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	ll left = 1, right = 3e9, mid, cnt = 0, res = 0;

	while (left <= right) {
		cnt = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < N; i++) {
			cnt += arr[i] - mid < 0 ? 0 : arr[i] - mid;
		}

		if (cnt < M)
			right = mid - 1;
		else {
			if (res < mid)
				res = mid;
			left = mid + 1;
		}
	}
	cout << res;
}