#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int T; cin >> T;

	while (T--) {
		int N, K; cin >> N >> K;

		if (N / K < K) {
			cout << "NO\n";
			continue;
		}

		if ((N%2 ==1 && K%2 == 1) || (N%2 == 0 && K%2==0)) {
			cout << "YES\n";
		}
		
		else {
			cout << "NO\n";
		}
	}
}