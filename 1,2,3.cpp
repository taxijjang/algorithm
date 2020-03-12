#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int dp[SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[0] = 1;
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		if (i - 1 >= 0)
			dp[i] += dp[i - 1];
		if (i - 2 >= 0)
			dp[i] += dp[i - 2];
		if (i - 3 >= 0)
			dp[i] += dp[i - 3];
	}

	cout << dp[N];
}