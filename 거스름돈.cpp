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
#include<stack>

#define SIZE 101000
const int INF = 2000000000;
const int MOD = 1000000007;
using namespace std;

typedef long long int ll;

int dp[SIZE];
int solution(int n, vector<int> money) {
	dp[0] = 1;

	sort(money.begin(), money.end());
	for (auto m : money) {
		for (int i = 1; i <= n; i++) {
			dp[i] = (dp[i] + dp[i - m])%MOD;
		}
	}

	return dp[n]%MOD;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 5;
	vector<int> money = { 1,2,5 };

	cout << solution(n, money);

}