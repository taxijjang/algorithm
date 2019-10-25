#include<iostream>
#define MAX 100000
using namespace std;
int arr[30];
int main(void) {
	int D, K; cin >> D >> K;

	for (int one = 1; one <= MAX; one++) {
		arr[1] = one;
		for (int two = 1; two <= MAX; two++) {
			arr[2] = two;
			for (int day = 3; day <= D; day++) {
				arr[day] = arr[day - 1] + arr[day - 2];

				if (day == D && arr[day] == K) {
					cout << arr[1] << "\n" << arr[2];
					return 0;
				}
				else if (day > D || arr[day] > K) {
					break;
				}
			}
		}
	}
	return 0;
}