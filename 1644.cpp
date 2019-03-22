#include<iostream>

using namespace std;

bool arr[4000001];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j*i <= N; j++) {
			if (arr[j*i] != true) {
				arr[j*i] = true;
			}
		}
	}

	long long int sum = 0;
	int cnt = 0;

	for (int i = 2; i <= N; i++) {
		if (arr[i] != true) {
			sum = 0;
			for (int j = i; j <= N; j++) {
				if (sum + j > N) break;
				if (arr[j] != true) {
					if (sum + j > N) {
						break;
					}
					else if (sum + j < N) {
						sum += j;
					}
					else if (sum + j == N) {
						cnt++;
					}
				}
			}
		}
	}


	printf("%d", cnt);
}