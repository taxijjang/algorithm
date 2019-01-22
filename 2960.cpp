#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int arr[1010];
vector<int> erase;
int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);


	for (int i = 0; i <= N; i++) {
		arr[i] = 0;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (arr[j] == 0) {
				arr[j] = 1;
				erase.push_back(j);
			}
		}
		if (erase.size() == K) break;
	}

	printf("%d", erase[K - 1]);
	return 0;
}