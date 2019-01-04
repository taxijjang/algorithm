#include <iostream>

using namespace std;


int main(void) {
	int N;
	int D[31];
	D[0] = 1;
	D[1] = 0;
	D[2] = 3;
	cin >> N;

	for (int n = 4; n <= N; n++) {
		if (n % 2 != 0) {
			D[n] = 0;
			continue;
		}

		D[n] = 3 * D[n - 2];

		for (int j = 4; j <= n; j += 2) {
			D[n] += D[n - j] * 2;
		}

	}

	cout << D[N];
	return 0;
}
