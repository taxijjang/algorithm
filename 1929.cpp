#include<iostream>
#define MAX 1000001;
#include <algorithm>
#include <cstdarg>

using namespace std;
bool prime[1000001];

int main(void) {
	for (int i = 2; i <= 1000001; i++) {
		for (int j = 2; i*j<= 1000001; j++) {
			if (prime[i*j]== false) {
				prime[i*j] = true;
			}
		}
	}

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = N; i <= M; i++) {
		if (prime[i] != true) {
			printf("%d\n", i);
		}
	}
}