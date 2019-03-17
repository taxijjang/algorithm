#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;
ll arr[10001];
int main(void) {
	int N;
	scanf("%d", &N);

	ll judge = 0;
	ll Max = 0;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
		judge += arr[i];
		if (Max < arr[i]) Max = arr[i];
	}

	sort(arr, arr + N);

	ll budget;
	scanf("%lld", &budget);

	if (budget >= judge) {
		printf("%lld", Max);
	}

	else {
		ll mok = budget / N;

		ll cnt = N;
		for (int i = 0; i < N; i++) {
			if (mok >= arr[i]) {
				budget -= arr[i];
			}
			else {
				cnt = N - i;
				mok = budget / cnt;
				if (arr[i] > mok) {
					break;
				}
				i--;
			}
		}

		printf("%lld", budget / cnt);
	}


}