#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#define SIZE 300000
using namespace std;

int prime[SIZE];
int dp[SIZE];

void eratos() {
	for (int i = 2; i < SIZE; i++) {
		for (int j = 2; i * j < SIZE; j++) {
			if (prime[i*j] == false)
				prime[i*j] = true;
		}
	}

	for (int i = 2; i < SIZE; i++) {
		int add = 0;
		if (prime[i] == false) {
			add = 1;
		}
		dp[i] = dp[i - 1] + add;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	eratos();

	do {
		int n; cin >> n;
		if (n == 0)
			break;

		cout << dp[n * 2] - dp[n] << "\n";
		
	} while (true);
}