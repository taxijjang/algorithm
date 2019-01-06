#include <iostream>
using namespace std;

int main(void) {
	int N;
	int tile[1001];
	cin >> N;
	tile[0] = 1;
	tile[1] = 1;
	for (int i = 2; i <= N; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2])%10007;
	}
	cout <<tile[N] % 10007;

	return 0;
}