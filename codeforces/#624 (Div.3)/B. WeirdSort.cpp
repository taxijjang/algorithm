#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define SIZE 110
const int INF = 2e9;
using namespace std;

typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		int n, m; cin >> n >> m;

		int a[SIZE];
		set<int> p;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		for (int i = 1; i <= m; i++) {
			int index; cin >> index;
			p.insert(index);
		}

		bool change = true;

		while (change) {
			change = false;
			for (auto idx : p) {
				if (idx < n && a[idx] > a[idx+1]) {
					int tmp = a[idx];
					a[idx] = a[idx + 1];
					a[idx + 1] = tmp;
					change = true;
				}
			}
		}

		bool impossible = false;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i + 1]) {
				impossible = true;
				break;
			}
		}

		if (impossible)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}