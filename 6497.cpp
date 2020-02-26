#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 200010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int parrent[SIZE];

priority_queue<tuple<int, int, int>> pq;

void init() {
	for (int i = 0; i < SIZE; i++) {
		parrent[i] = i;
	}
}

int _find(int a) {
	if (parrent[a] == a)
		return a;

	return parrent[a] = _find(parrent[a]);
}

void _union(int a, int b) {
	int aRoot = _find(a);
	int bRoot = _find(b);

	if (aRoot == bRoot)
		return;

	parrent[bRoot] = aRoot;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int m, n; cin >> m >> n;

		if (m == 0 && n == 0)
			break;

		int sum = 0;
		for (int i = 0; i < n; i++) {
			int a, b, w; cin >> a >> b >> w;

			sum += w;
			pq.push(make_tuple(-w, a, b));
		}

		init();
		getchar();

		int connect = 0;
		while (!pq.empty()) {
			int w, a, b;
			tie(w, a, b) = pq.top();
			pq.pop();


			if (_find(a) == _find(b)) {
				continue;
			}

			else {
				_union(a, b);
				connect += -w;
			}
		}
		
		cout << sum - connect << "\n";
	}
}