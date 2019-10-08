#include<iostream>
#define SIZE 10010
using namespace std;
typedef long long int ll;
ll arr[SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	int K, N; cin >> K >> N;

	for (int k = 0; k < K; k++) {
		cin >> arr[k];
	}

	ll left = 1, right = 3e9, mid;
	ll res = 0, cnt = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 0;
		for (int k = 0; k < K; k++) {
			cnt += arr[k] / mid;
		}
		if (cnt < N) {

			right = mid - 1;
		}
		else {
			if (res < mid)
				res = mid;
			left = mid + 1;
		}
	}
	cout << res;
}