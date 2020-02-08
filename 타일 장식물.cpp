#include <string>
#include <vector>
#include<iostream>

using namespace std;

long long dp[2000];

long long solution(int N) {
	dp[1] = dp[2] = 1;

	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	long long answer = (dp[N] + 2* dp[N-1] + dp[N-2]) * 2;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	cout << solution(N);
}