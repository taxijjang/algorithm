#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	int num;
	int max, min;

	cin >> N;

	cin >> num;
	max = num;
	min = num;
	for (int n = 1; n < N; n++) {
		cin >> num;
		if (max < num) max = num;
		if (min > num) min = num;
	}
	cout << min << " " << max;
}