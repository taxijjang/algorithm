#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int a,b;
	scanf("%d", &a);
	
	for (int i = 1; i <= a; i++) {
		for (int k = i; k < a;k++) {
			printf(" ");
		}
		for (int j = 0; j < i*2-1  ; j++) {
			printf("*");
		}
		printf("\n");
	}
}