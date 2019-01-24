#include <iostream>
#include <algorithm>

using namespace std;

int r[100001];
int p[100001];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
	}

	
	r[0] = 0;
	for (int i = 1; i <= N; i++) {
		int q = -1000000;
		for (int j = 1; j <= i; j++) {
			q = max(q, p[j] + r[i - j]);
		}
		r[i] = q;
	}

	printf("%d", r[N]);
	return 0;
}