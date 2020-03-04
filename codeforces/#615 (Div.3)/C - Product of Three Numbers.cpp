#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		ll num; cin >> num;

		vector<int> factor;
		for (int i = 2; i <= sqrt(num); i++) {
			if (num %i == 0) {
				factor.push_back(i);
			}
		}

		if (factor.size() <= 0) {
			cout << "NO\n";
			continue;
		}

		vector<int> idx(factor.size(), 0);
		for (int i = factor.size() - 2; i < factor.size(); i++) {
			idx[i] = 1;
		}

		bool check = true;
		do {
			set<int> _set;
			ll res = 1;
			for (int i = 0; i < idx.size(); i++) {
				if (idx[i] == 1) {
					res *= factor[i];
					_set.insert(factor[i]);
				}
			}

			if (num%res == 0) {
				_set.insert(num / res);
				if (_set.size() <= 2)
					continue;

				cout << "YES\n";
				for (int i = 0; i < factor.size(); i++) {
					if (idx[i] == 1)
						cout << factor[i] << " ";
				}
				cout << num / res << "\n";
				check = false;
				break;
			}
		} while (next_permutation(idx.begin(), idx.end()));

		if (check)
			cout << "NO\n";
	}

}