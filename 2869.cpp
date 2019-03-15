#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);

	double ans = double((double)(V - A) / (double)(A - B) + 1);

	printf("%.0lf", ceil(ans));
}