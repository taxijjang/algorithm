#include<iostream>

void print(int num) {
	while (num != 0) {
		printf("%d", num % 10);
		num /= 10;
	}
}
int main(void) {
	int a, b; scanf("%d %d", &a, &b);
	for (int i = 0; i < 3; i++) {
		if (a % 10 > b % 10) {
			print(a);
			i = 3;
		}
		else if (a % 10 < b % 10) {
			print(b);
			i = 3;
		}
		else {
			printf("%d", a % 10);
		}
		a /= 10; b /= 10;
	}
	return 0;
}