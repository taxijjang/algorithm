#include <iostream>
#include <math.h>

typedef long long int ll;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll cost = (x1*y2 + x2*y3 + x3*y1);
	cost = cost - (y1*x2 + y2 * x3 + y3*x1);
	return cost;
}

ll x_l[10001];
ll y_l[10001];

int main(void) {
	int N;
	scanf("%d", &N);

	ll x, y;
	ll sum = 0;

	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &x, &y);
		x_l[i] = x; y_l[i] = y;
	}

	for (int i = 0; i < N - 1; i++) {
		sum += ccw(0, 0, x_l[i], y_l[i], x_l[i + 1], y_l[i + 1]);
	}

	sum += ccw(0, 0, x_l[N - 1], y_l[N - 1], x_l[0], y_l[0]);

	double result = (double)(abs(sum));

	printf("%.1lf", result / 2.0);
}
