#include<iostream>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		int num = i;
		while (num != 0) {
			if (num / 10 == 0) {
				cnt++;
				break;
			}
			num /= 10;
			cnt++;
		}
	}

	printf("%d", cnt);
}