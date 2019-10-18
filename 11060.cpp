#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#define SIZE 1500
#define INF 2e9
using namespace std;

int arr[SIZE];
int dp[SIZE];

void fill_dp() {
	for (int i = 0; i < SIZE; i++)
		dp[i] = INF;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	fill_dp();
	dp[0] = 0;
	for (int num= 0; num < N; num++) {
		for (int jump = 1; jump <= arr[num]; jump++) {
			dp[num + jump] = min(dp[num] + 1, dp[num + jump]);
		}
	}

	if (dp[N - 1] == INF)
		cout << "-1";
	else
		cout << dp[N - 1];
}