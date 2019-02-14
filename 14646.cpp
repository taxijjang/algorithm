#include <iostream>
#include <string>

using namespace std;

int max_(int a, int b) {
	return a > b ? a : b;
}
bool arr[100001];
int main(void) {
	int N;
	scanf("%d", &N);

	int max = 0;
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++) {
		int num;
		scanf("%d", &num);

		if (arr[num] == false) {
			cnt++;
			arr[num] = true;
		}
		else {
			cnt--;
		}
		max = max_(max, cnt);
	}
	printf("%d", max);
}