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
	
	while (1) {
		int N;
		scanf("%d", &N);
		
		if (N == 0) {
			break;
		}

		bool judge = false;
		for (int i = 2; i <= N; i++) {
			if (prime[N - i] == false && prime[i] == false) {
				printf("%d = %d + %d\n", N, i, N - i);
				judge = true;
				break;
			}
		}
		if (judge == false) {
			printf("%s\n", "Goldbach's conjecture is wrong.");
		}
	}
}