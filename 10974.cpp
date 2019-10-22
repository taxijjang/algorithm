#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;

	vector<int> v;
	for (int i = 1; i <= N; i++)
		v.push_back(i);

	do {
		for (int i = 0; i < N; i++) {
			cout << v[i] << ' ';
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}