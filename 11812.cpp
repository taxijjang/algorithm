#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 1010
#define MAX_DEPTH 20
using namespace std;

typedef long long int ll;

int parrent[SIZE][MAX_DEPTH];
int detph[SIZE];
vector<int> tree[SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K, Q; cin >> N >> K >> Q;

	for (int q = 1; q <= Q; q++) {
		ll x, y; cin >> x >> y;

		if (x < y) swap(x, y);
		if (K == 1) {
			cout << x - y << "\n";
		}

		else {
			int cnt = 0;
			while (x != y) {
				cnt++;
				if (x < y) swap(x, y);
				x = (x - 2) / K + 1;
			}
			cout << cnt << "\n";
		}
	}

}