#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

#define SIZE 110
const int INF = 2e9;
using namespace std;

typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		vector<int> arr;
		int n, m; cin >> n >> m;

		int sum = 0;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			arr.push_back(num);
			sum += num;
		}
		if (sum <= m) {
			cout << sum << "\n";
		}
		else if (sum >= m) {
			cout << m << "\n";
		}

	}
	return 0;
}