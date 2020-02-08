#include<iostream>
#include<algorithm>

#define SIZE 1010
using namespace std;

int board[SIZE][SIZE];
int dp[SIZE][SIZE];
int tmp[2][SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}


	for (int j = 1; j <= M; j++) {
		dp[1][j] += dp[1][j - 1] + board[1][j];
	}

	for (int i = 2; i <= N; i++) {
		tmp[0][0] = dp[i - 1][1];
		for (int j = 1; j <= M; j++) {
			tmp[0][j] = max(dp[i - 1][j], tmp[0][j - 1]) + board[i][j];
		}

		tmp[1][M + 1] = dp[i - 1][M];
		for (int j = M; j > 0; j--) {
			tmp[1][j] = max(dp[i - 1][j], tmp[1][j + 1]) + board[i][j];
		}

		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(tmp[0][j], tmp[1][j]);
		}
	}

	cout << dp[N][M];
}