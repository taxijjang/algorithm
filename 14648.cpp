#include <iostream>

typedef long long int ll;
ll arr[1001];
int query[4];

int main(void) {
	int N, Q;
	scanf("%d %d", &N, &Q);

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}


	for (int i = 0; i < Q; i++) {
		int n;
		scanf("%d", &n);
		ll sum = 0;
		if (n == 1) {
			int a, b;
			scanf("%d %d", &a, &b);

			for (int j = a; j <= b; j++) {
				sum += arr[j];
			}

			int tmp = arr[a];
			arr[a] = arr[b];
			arr[b] = tmp;
		}
		else if (n == 2) {
			int a, b, c, d ;
			scanf("%d %d %d %d", &a, &b, &c, &d); 
			for (int j = a; j <= b; j++) {
				sum += arr[j];
			}
			for (int j = c; j <= d; j++) {
				sum -= arr[j];
			}
		}
		printf("%lld\n", sum);
	}
}