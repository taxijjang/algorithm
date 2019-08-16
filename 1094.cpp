#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);

	int n; cin >> n;
	int line = 64;
	int cnt = 0;
	while (1) {
		if (n == line) {
			cnt++;
			break;
		}
		else if (line > n) {
			line /= 2;
		}
		else if (line < n) {
			n -= line;
			cnt++;
		}

	}

	cout << cnt;

}