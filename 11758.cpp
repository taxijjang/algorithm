#include <iostream>

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int cost = (x1*y2 + x2*y3 + x3*y1);
	cost = cost - (y1*x2 + y2 * x3 + y3*x1);
	if (cost > 0)
		return 1;
	else if (cost < 0)
		return -1;
	else
		return 0;

}
int main(void) {
	int x1, x2, x3, y1, y2, y3;

	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);

	printf("%d", ccw(x1, y1, x2, y2, x3, y3));
}
