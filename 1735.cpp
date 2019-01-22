#include <iostream>


int Eucli(int a, int b) {
	if (b == 0) {
		return a;
	}
	Eucli(b, a % b);
}

int main(void) {
	int b1, a1;
	int b2, a2;

	scanf("%d %d", &b1, &a1);
	scanf("%d %d", &b2, &a2);

	int euc = Eucli(a1*a2, b1*a2 + b2*a1);
	printf("%d %d", (b1*a2 + b2*a1) / euc, (a1*a2) / euc);

	return 0;
}