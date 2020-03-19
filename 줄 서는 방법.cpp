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

#define SIZE 22
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

ll dp[SIZE];
vector<int> num;
vector<int> solution(int n, long long k) {
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i < SIZE; i++) {
		dp[i] = dp[i - 1] * i;
	}

	for (int i = 1; i <= n; i++) {
		num.push_back(i);
	}
	vector<int> answer;
	k--;
	while (!num.empty()) {
		if (k == 0) {
			answer.push_back(num[k]);
			num.erase(num.begin());
			continue;
		}
		ll mok = k / dp[n-1];
		ll na = k % dp[n-1];

		answer.push_back(num[mok]);
		num.erase(num.begin() + mok);
		k = na; n--;

	}
	return answer;

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; ll k; cin >> n >> k;
	
	vector<int> res = solution(n, k);

	getchar();
}
