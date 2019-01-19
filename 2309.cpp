#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int height[10];
	int cnt = 9;
	int sum = 0;
	for (int i = 1; i <= cnt; i++) {
		scanf("%d", &height[i]);
		sum += height[i];
	}

	sort(height + 1, height + cnt + 1);

	int tmp;

	int i_t, j_t;
	for (int i = 1; i < cnt; i++) {
		tmp = sum;
		tmp -= height[i];
		for (int j = 1; j <= cnt; j++) {
			if (i == j) continue;
			tmp -= height[j];
			if (tmp == 100) {
				i_t = i; j_t = j;
				i = cnt;
				break;
			}
			tmp += height[j];
		}
	}

	for (int i = 1; i <= cnt;i++) {
		if (i == i_t || i == j_t) {
			continue;
		}
		printf("%d\n", height[i]);
	}

}