#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

struct Point {
	ll x;
	ll y;

	bool operator <(Point &a) {
		if (x == a.x)
			return y < a.y;
		return x < a.x;
	}

	Point operator - (Point &a) {
		return{ x - a.x, y - a.y };
	}
};

ll ccw(Point A, Point B) {
	return A.x * B.y - B.x * A.y;
}
ll ccw(Point A, Point B, Point C) {
	ll j = ccw(B - A, C - A);
	if (j < 0) return -1;
	else if (j > 0) return 1;
	else return 0;
}

Point up_chain[100001], down_chain[100001];
Point convex_hull[100001];
Point p[100001];
int main(void) {
	int N;
	ll last_up = 0;
	ll last_down = 0;
	scanf("%d", &N);


	ll x, y;
	for (int i = 1; i <= N; i++) {
		scanf("%lld %lld", &x, &y);
		p[i].x = x; p[i].y = y;
	}

	sort(p + 1, p + N + 1);

	for (int i = 1; i <= N; i++) {
		while (last_up >= 2 && ccw(up_chain[last_up - 1], up_chain[last_up], p[i]) >= 0) last_up--;
		up_chain[++last_up] = p[i];
	}

	for (int i = N; i > 0; i--) {
		while (last_down >= 2 && ccw(down_chain[last_down - 1], down_chain[last_down], p[i]) >= 0) last_down--;
		down_chain[++last_down] = p[i];
	}

	int con = 0;
	for (int i = 1; i <= last_down; i++) {
		convex_hull[con++] = down_chain[i];
	}

	for (int i = 2; i < last_up; i++) {
		convex_hull[con++] = up_chain[i];
	}

	printf("%lld", last_down + last_up - 2);

	return 0;
}