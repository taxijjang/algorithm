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
		int n; cin >> n;
		int even, odd; even = odd = 0;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			if (num % 2 == 0) even++;
			else odd++;
		}

		if (even == n || odd == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}