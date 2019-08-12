#include<iostream>
#define SIZE 45

bool vip[SIZE];
int dp[SIZE];

int main(void) {
	int N, M; scanf("%d%d", &N, &M);

	for (int m = 1; m <= M; m++) {
		int index; scanf("%d", &index);
		vip[index] = true;
	}
	dp[0] = 1; dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= SIZE; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int res = 1;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (vip[i] == true) {
			res *= dp[cnt];
			cnt = 0;
		}
		else if (vip[i] != true) {
			cnt++;
		}
	}

	printf("%d", res *dp[cnt]);
}