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

	while (T--) {
		deque<int> x, y;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			x.push_back(num);
		}

		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			y.push_back(num);
		}

		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		for (auto xx : x)
			cout << xx << " ";
		cout << "\n";
		for (auto yy : y)
			cout << yy << " ";
		cout << "\n";
	}

}