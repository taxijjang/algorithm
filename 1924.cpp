#include <iostream>

using namespace std;

int main(void) {
	int dal[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	while (1) {
		int m, n;
		int sum = 0;
		cin >> m >> n;

		for (int i = 0; i < m-1; i++) {
			sum += dal[i];
		}
		sum += n;


		switch (sum % 7) {
		case 1:
			cout << "MON";
			break;
		case 2:
			cout << "TUE";
			break;
		case 3:
			cout << "WED";
			break;
		case 4:
			cout << "THU";
			break;
		case 5:
			cout << "FRI";
			break;
		case 6:
			cout << "SAT";
			break;
		case 0:
			cout << "SUN";
			break;
		}
	}
}