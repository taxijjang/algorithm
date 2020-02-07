#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define SIZE 50

using namespace std;

typedef long long int ll;

const int INF = 2000000000;
int dp[2][SIZE];
void dfs(int a_cnt, int b_cnt, int cnt) {
	if (cnt >= SIZE)
		return;

	dp[0][cnt] = b_cnt;
	dp[1][cnt] = a_cnt + b_cnt;

	dfs(dp[0][cnt], dp[1][cnt], cnt + 1);
}
int main(void) {
	int K; cin >> K;

	dp[0][0] = 1;

	dfs(dp[0][0], dp[1][0], 1);

	cout << dp[0][K] << " " << dp[1][K];
}