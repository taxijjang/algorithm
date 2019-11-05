#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 110

using namespace std;

typedef long long int ll;

string dp[SIZE][SIZE];

string string_sum(string a, string b) {
	// a가 더 크게
	if (a.size() < b.size()) swap(a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int a_size = a.size();
	int b_size = b.size();

	string res = "";
	int allim = 0;

	for (int i = 0; i < a_size; i++) {
		int sum;
		if (i >= b_size) {
			sum = a.at(i) - '0' + allim;
			res += to_string(sum % 10);
			allim = sum/10;
			continue;
		}
		sum = a.at(i) - '0' + b.at(i) - '0' + allim;
		allim = sum / 10;
		res += to_string(sum % 10);
	}
	res = allim > 0 ? res + to_string(allim) : res;
	reverse(res.begin(), res.end());
	return res;
	
}
void fill_dp() {
	for (int i = 0; i < SIZE; i++) {
		dp[i][0] = "1";
		dp[i][i] = "1";
		for (int j = 1; j < i; j++) {
			dp[i][j] = string_sum(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill_dp();

	int N, M; cin >> N >> M;

	cout << dp[N][M];
}