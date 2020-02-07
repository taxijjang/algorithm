#include<bits/stdc++.h>

using namespace std;

int cnt[1000];
vector<int> coins;

int main(void) {
	int x; cin >> x;

	for (int i = 0; i < 3; i++) {
		int c; cin >> c;
		coins.push_back(c);
	}

	cnt[0] = 1;
	for (int i = 1; i <= x; i++) {
		for (auto c : coins) {
			if (i - c >= 0)
				cnt[i] += cnt[i - c];
		}
	}
}