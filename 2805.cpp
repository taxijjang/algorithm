#include <iostream>
typedef long long int ll;

using namespace std;

ll tree[1000001];

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	ll max = 1;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &tree[i]);
		if (max < tree[i]) max = tree[i];
	}

	ll start = 1, end = max, mid, cut = 0;


	while (start <= end) {
		ll sum = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < N; i++) {
			if ((tree[i] - mid) >= 0) {
				sum += tree[i] - mid;
			}
		}

		if (sum >= M) {
			if (cut < mid) cut = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	printf("%d", cut);


}