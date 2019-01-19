#include <iostream>
#include <algorithm>
#define MAX 5000001
using namespace std;
typedef long long int ll;

ll arr[MAX];

int main(void) {
	int N, L;
	scanf("%d %d", &N, &L);

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}

	int head = 1, tail = 1;

	ll tmp;
	while (head <= N - L + 1) {
		tmp = 1000000001;
		if (tail < L) {
			for (int i = 1; i < tail + L; i++) {
				if (tmp > arr[i]) {
					tmp = arr[i];

				}
			}
			printf("%d ", tmp);
			tail++;
		}
		else {
			for (int i = head; i <= tail; i++) {
				if (tmp > arr[i]) {
					tmp = arr[i];

				}
			}
			printf("%d ", tmp);
			tail++;
			head++;
		}
	}
	return 0;
}