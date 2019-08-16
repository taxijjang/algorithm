#include<iostream>

using namespace std;

bool odd_even(int n) {
	if (n % 2 == 0)
		return true;
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);

	int n, a, b; cin >> n >> a >> b;

	int round = 0;

	int tmp;
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	while (1) { 
		round++;
		// true Â¦¼ö // false È¦¼ö
		if (!odd_even(a)) {
			a++;
		}
		if (!odd_even(b)) {
			b++;
		}
		if (a == b) {
			cout << round;
			return 0;
		}
		a /= 2; b /= 2;
	}
	return 0;
}