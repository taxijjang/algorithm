#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 110
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

typedef struct Data{
	int time=0, low, high;
}Data ;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		bool impossible = false;
		Data temp_range[SIZE];
		int n;
		cin >> n >> temp_range[0].low;
		temp_range[0].high = temp_range[0].low;

		for (int i = 1; i <= n; i++) {
			cin >> temp_range[i].time >> temp_range[i].low >> temp_range[i].high;
		}
		for (int i = 1; i <= n; i++) {
			int time_gap = temp_range[i].time - temp_range[i - 1].time;
			int lowest = temp_range[i - 1].low - time_gap;
			int highest = temp_range[i - 1].high + time_gap;

			if (highest < temp_range[i].low || lowest > temp_range[i].high) {
				impossible = true;
				break;
			}
			else {
				temp_range[i].low = max(temp_range[i].low, lowest);
				temp_range[i].high = min(temp_range[i].high, highest);
			}
		}


		if (impossible)
			cout << "NO\n";
		else
			cout << "YES\n";

	}
}