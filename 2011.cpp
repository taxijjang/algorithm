#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define MOD 1000000
#define SIZE 5050

using namespace std;

typedef long long int ll;

int dp[SIZE];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	dp[0] = 1;

	int s_size = s.size();
	for (int i = 1; i <=s_size; i++) {
		if (s[i - 1] > '0')
			dp[i] = (dp[i] + dp[i - 1]) % MOD;

		if (i == 1) continue;

		int sib = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
		if (sib >= 10 && sib <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
	}
	cout << dp[s_size];

	return 0;
}