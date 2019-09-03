#include<iostream>
#define SIZE 10010
using namespace std;

bool arr[SIZE] = { true, };

void eratos() {
	for (int i = 2; i < SIZE; i++) {
		for (int j = 2; j *i < SIZE; j++){
			if (arr[j* i] != true) {
				arr[j * i] = true;
			}
		}
	}
}

void print(int sum, int num) {
	if (sum == 0) {
		cout << -1;
		return;
	}
	cout << sum << "\n" << num;
}
int main(void) {
	eratos();

	int a, b; cin >> a >> b;
	int min_num = 2e9;
	int sum = 0;
	for (int i = a; i <= b; i++) {
		if (arr[i] != true) {
			min_num = min_num > i ? i : min_num;
			sum += i;
		}
	}

	print(sum, min_num);
}