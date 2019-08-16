#include<iostream>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);

	int n; cin >> n;

	int sum = 0;

	while (n >= 5) {
		sum += n / 5;
		n /= 5;
	}

	cout << sum;
}