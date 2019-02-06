#include <stdio.h>

int main(void) {
	int cnt;
	int a, b;

	scanf("%d", &cnt);
	while (cnt>= 0) {
		scanf("%d %d", &a, &b);
		printf("%d", a + b);
		cnt--;
	}
	return 0;

}