#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);

	int N; cin >> N;

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}

	int v_size = v.size();

	for (int i = 0; i < v_size; i++) {
		int cnt = 1;
		for (int j = 0; j < v_size; j++) {
			if (i == j)
				continue;
			if (v[j].first > v[i].first && v[j].second > v[i].second) {
				cnt++;
			}
		}
		cout << cnt << " ";
	}
}