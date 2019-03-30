#include<iostream>

int arr[200001];

int main(void) {
	int N;
	scanf("%d", &N);

	int z_cnt = 0;
	int o_cnt = 0;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 0) z_cnt++;
		else o_cnt++;
	}

	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			z_cnt--;
		}
		else {
			o_cnt--;
		}

		if (z_cnt == 0 || o_cnt == 0) {
			printf("%d", i);
			break;
		}
	}
}