#include<iostream>
#define SIZE 35
using namespace std;

typedef long long int ll;

typedef struct Data {
	ll w, h;
}Data;
int main(void) {
	ios::sync_with_stdio(false);

	while(1) {
		int n; cin >> n;
		if (n == 0)break;
		ll dp[SIZE][SIZE];
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				dp[i][j] = 0;
			}
		}
		Data d; d.w = n - 1, d.h = 1;
		dp[d.h][d.w] = 1;
		for (int j = d.w; j >= 0; j--) {
			for (int i = d.h; i >= 0; i--) {
				if (j - 1 >= 0)
					dp[i + 1][j - 1] += dp[i][j];
				if (i - 1 >= 0)
					dp[i - 1][j] += dp[i][j];
			}
			d.w--;
			d.h++;
		}

		cout << dp[0][0] << "\n";
	}
}