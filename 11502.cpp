#include <iostream>
#include <vector>

using namespace std;

int arr[1001];
vector<int> prime;
int main(void) {

	for (int i = 2; i <= 1000; i++) {
		for (int j = i; j <= 1000; j++) {
			if (i*j > 1000) break;
			if (arr[i*j] == 0)
				arr[i*j] = 1;
		}
	}

	for (int i = 2; i <= 1000; i++) {
		if (arr[i] == 0)
			prime.push_back(i);
	}
	int T, K;
	scanf("%d", &T);

	int judge;
	int size = prime.size();
	for (int i = 0; i < T; i++) {
		judge = 0;
		scanf("%d", &K);
		for (int j = 0; j < size; j++) {
			for (int n = 0; n < size; n++) {
				for (int m = 0; m < size; m++) {
					if (prime[j] + prime[n] + prime[m] == K) {
						printf("%d %d %d\n", prime[j], prime[n], prime[m]);
						n = size;
						j = size;
						judge = 1;
						break;
					}
				}
			}
		}
		if(judge == 0)
			printf("%d\n", 0);
	}
	getchar();
}