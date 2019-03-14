#include<iostream>
typedef long long int ll;
using namespace std;

ll lan[10001];

int main(void) {
	int K, N;
	scanf("%d %d", &K, &N);

	ll max = 0;
	for (int i = 0; i < K; i++) {
		scanf("%lld", &lan[i]);
		if (max < lan[i]) max = lan[i];
	}

	ll start = 1, end = max, mid,Max=0;
	while (start <= end) {
		mid = (start + end) / 2;
		ll sum = 0;

		for (int i = 0; i < K; i++) {
			sum += lan[i]/mid;
		}
		if (sum < N) {
			end = mid - 1;
		}
		else {
			if (Max < mid) {
				Max = mid;
			}

			start = mid + 1;
		}
	}
	printf("%lld", Max);
}