#include <stdio.h>

int main(void) {

	do {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d", a + b);
		while (a != 0 && b != 0);
	}
	return 0;

}