#include <iostream>
#include <algorithm>
#define MAX 100001;
using namespace std;

typedef long long int ll;

struct time {
	ll start;
	ll end;

	bool operator < (const time & t) {
		if (end == t.end) {
			return start < t.start;
		}
		return end < t.end;
	}
};

time arr[100001];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%lld %lld", &arr[i].start, &arr[i].end);
	}

	sort(arr + 1, arr + N + 1);

	ll cnt = 1;
	ll s = arr[1].start;
	ll e = arr[1].end;

	for (int i = 2; i <= N; i++) {
		if (arr[i].start >= e) {
			cnt++;
			e = arr[i].end;
		}
	}
	printf("%lld",cnt);

	return 0;
}