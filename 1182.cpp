#include <iostream>

using namespace std;

int arr[21];
int N, S, ans = 0;

void recursive(int cur, int sum) {
	if (cur == N + 1) {
		if (sum == S) {
			ans++;
		}
		return;
	}
	recursive(cur + 1, sum);
	recursive(cur + 1, sum + arr[cur]);
}
int main(void) {
	scanf("%d %d", &N, &S);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	recursive(0, 1);

	if (S == 0) {
		ans--;
	}

	printf("%d", ans);

	return 0;
}

