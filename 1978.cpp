#include<iostream>
#define MAX 1000001;
#include <algorithm>
#include <cstdarg>

using namespace std;
bool prime[1000001];

int main(void) {
	prime[1] = true;
	for (int i = 2; i <= 1000001; i++) {
		for (int j = 2; i*j<= 1000001; j++) {
			if (prime[i*j]== false) {
				prime[i*j] = true;
			}
		}
	}

	int N;
	scanf("%d", &N);

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if (prime[num] == false) {
			cnt++;
		}
	}
	printf("%d", cnt);
}