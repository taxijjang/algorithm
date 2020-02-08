#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 101000

using namespace std;

typedef long long int ll;
const int MAX = 200000;
int dp[SIZE];

void dfs(int here, int cnt, vector<int> nums) {
	if (dp[here] <= cnt)
		return;

	dp[here] = min(dp[here], cnt);

	int left = here - nums[here];
	int right = here + nums[here];

	if (left >= 0) {
		dfs(left, cnt + 1, nums);
	}

	if (right < nums.size()) {
		dfs(right, cnt + 1, nums);
	}
}
int solution(vector<int> nums) {
	fill(dp, dp + SIZE, MAX); 
	dfs(0, 0, nums);
	return (dp[nums.size()-1] == MAX ? -1 : dp[nums.size()-1]);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> v;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	cout << solution(v);
}