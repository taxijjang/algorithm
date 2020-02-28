#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		int x, y, a, b; cin >> x >> y >> a >> b;

		int sum = a + b;
		int dis = y - x;
		if (dis %sum != 0)
			cout << -1 << "\n";
		else
			cout << dis / sum << "\n";
	}

}