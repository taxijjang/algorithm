#include<iostream>
#include<map>

using namespace std;

int arr[1 << 22];
map<int, bool> _map;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[1 << i];
	}

	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 0; (1 << j) <= i; j++) {
			if (i & (1 << j)) {
				sum += arr[1 << j];
			}
		}
		cout << sum << "\n";
		_map[sum] = true;
	}


	for (int i = 1; i <= 2000000; i++) {
		if (_map[i] != true) {
			cout << i;
			break;
		}
	}
	return 0;
}