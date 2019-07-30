#include<iostream>
#include<algorithm>
#define SIZE 4010
using namespace std;

typedef long long int ll;
ll a[SIZE];
ll b[SIZE];
ll c[SIZE];
ll d[SIZE];

ll a_b[16000010];
ll c_d[16000010];

int main(void) {
	int N; scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld %lld %lld %lld", &a[i], &b[i], &c[i], &d[i]);
	}

	int index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a_b[index] = a[i] + b[j];
			c_d[index++] = c[i] + d[j];
		}
	}

	sort(c_d, c_d + index);

	ll cnt = 0;
	for (int i = 0; i < index; i++) {
		auto left = lower_bound(c_d, c_d + index, -a_b[i]) - c_d;
		auto right = upper_bound(c_d, c_d + index, -a_b[i]) - c_d;

		if (a_b[i] + c_d[left] == 0) {
			cnt += right - left;
		}
	}
	printf("%lld", cnt);

}