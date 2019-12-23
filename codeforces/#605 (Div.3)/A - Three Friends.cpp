#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int res(int *v) {
	return abs(v[0] - v[1]) + abs(v[0] - v[2]) + abs(v[1] - v[2]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int v[3]; cin >> v[0] >> v[1] >> v[2];
		
		sort(v,v+2);

		int gap = (v[1] - v[0]);
		
		if (gap <= 2) {
			v[0] = gap > 0 ? v[0] + 1: v[0];
			gap--;
			v[1] = gap > 0 ? v[1] - 1 : v[1];
		}

		else {
			v[0]++; v[1]--;
		}

		gap = v[2] - v[1];

		if (gap >= 1)
			v[2]--;

		cout << res(v) << "\n";

	}
}