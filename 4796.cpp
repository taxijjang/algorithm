#include <iostream>

int main(void) {
	int L, P, V;
	for(int i =1;;i++) {
		scanf("%d %d %d", &L, &P, &V);

		if (L == 0 && P == 0 && V == 0) {
			break;
		}
		int day = 0;

		day += (V / P)*L;

		if (V%P > L) {
			day += L;
		}
		else {
			day += V%P;
		}

		printf("Case %d: %d\n", i, day);
	}
}