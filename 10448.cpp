#include <iostream>

int arr[51] = { 0, };
int MAX = 50;
int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= MAX; i++) {
		arr[i] = arr[i-1] + i;
	}

	for (int t = 0; t < T; t++) {
		int K;
		scanf("%d", &K);

		bool judge = false;

		for (int i = 1; i <= MAX; i++) {
			for (int j = 1; j <= MAX; j++) {
				for (int k = 1; k <= MAX; k++) {
					if (K == arr[i] + arr[j] + arr[k]) {
						judge = true;
						j = MAX + 1;
						i = MAX + 1;
						break;
					}
				}
			}
		}

		if (judge == false) printf("0\n");
		else printf("1\n");

	}
}