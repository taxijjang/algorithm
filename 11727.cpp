#include <iostream>

using namespace std;

int main(void) {
	int N;
	int tile[1001];
	tile[0] = 1;
	tile[1] = 1;
	cin >> N;

	for (int n = 2; n <= N; n++) {
		tile[n] = (tile[n - 1] + (2 * tile[n - 2])) % 10007;
	}

	cout << tile[N] % 10007;

	return 0;
}