#include <iostream>

using namespace std;

int main(void) {
	int N;
	int TT;
	int T[11];
	T[0] = 1;
	T[1] = 1;
	T[2] = 2;
	cin >> TT;
	for (int tt = 0; tt < TT; tt++) {
		cin >> N;
		for (int n = 3; n <= N; n++) {
			T[n] = T[n - 1] + T[n - 2] + T[n - 3];
		}

		cout << T[N];
	}
	return 0;
}