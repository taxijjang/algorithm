#include<iostream>

using namespace std;

int main(void) {
	int n, sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &n);
		if (n < 40) n = 40;
		sum += n;
	}

	printf("%d", sum / 5);
}