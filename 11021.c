#include <stdio.h>

int main(void) {
	int cnt;
	int i = 1;
	int a, b;
	scanf("%d", &cnt);
	while (cnt>0) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i++,  a + b);
		cnt--;
	}
	return 0;

}