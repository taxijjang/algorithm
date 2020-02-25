#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 510
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int MOD = 20170805;

int dx[4] = { 0,1 };
int dy[4] = { 1,0 };

int dp[2][SIZE][SIZE];

int dfs(int h_x, int h_y, int m, int n , int stop, vector<vector<int>> &city_map) {
	if (h_x == m - 1 && h_y == n - 1)
		return dp[stop][h_x][h_y] = 1;

	if (dp[stop][h_x][h_y] != -1)
		return dp[stop][h_x][h_y] % MOD;

	dp[stop][h_x][h_y] = 0;

	for (int d = 0; d < 2; d++) {
		int n_x = h_x + dx[d];
		int n_y = h_y + dy[d];

		if (n_x < 0 || n_x >= m || n_x < 0 || n_y >= n)
			continue;

		if (city_map[h_x][h_y] == 0) {
			dp[stop][h_x][h_y] = (dp[stop][h_x][h_y] + dfs(n_x, n_y, m, n, d, city_map)) % MOD;
		}
		if (city_map[h_x][h_y] == 1) {
			continue;
		}

		if (city_map[h_x][h_y] == 2) {
			if (stop == d) {
				dp[stop][h_x][h_y] = (dp[stop][h_x][h_y] + dfs(n_x, n_y, m, n, stop, city_map)) %MOD;
			}
		}
	}
	return dp[stop][h_x][h_y] % MOD;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	memset(dp, -1, sizeof(dp));

	int right = dfs(0, 1, m, n, 0, city_map);
	int down = dfs(1, 0, m, n, 1, city_map);

	return (right+ down) % MOD;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, n; cin >> m >> n;

	vector<vector<int>> city_map;

	for (int i = 0; i < m; i++) {
		vector<int> city;
		for (int j = 0; j < n; j++) {
			int road; cin >> road;
			city.push_back(road);
		}
		city_map.push_back(city);
	}

	cout << solution(m, n, city_map);
}