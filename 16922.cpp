#include<iostream>
#define SIZE 1010

using namespace std;

int dp[21][SIZE];
int arr[6];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	arr[0] = 1, arr[1] = 5, arr[2] = 10, arr[3] = 50;
	dp[1][1] = 1;	dp[1][5] = 1;
	dp[1][10] = 1; dp[1][50] = 1;

	for (int cnt = 2; cnt <= N; cnt++) {
		for (int sum = 1; sum <= N * 50; sum++) {
			for (int i = 0; i < 4; i++) {
				if (sum - arr[i] < 0)
					continue;
				dp[cnt][sum] = dp[cnt][sum] + dp[cnt - 1][sum - arr[i]];
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= SIZE; i++) {
		if (dp[N][i] != 0)
			cnt++;
	}

	cout << cnt;
}