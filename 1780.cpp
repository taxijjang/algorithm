#include <iostream>

int arr[3000][3000];

//0 -> 0 , 1 -> 1; 2 -> -1;
int cnt[4] = { 0 };

void solution(int x, int y, int size) {
	if (size == 1) {
		if (arr[x][y] == -1) cnt[2]++;
		else if (arr[x][y] == 0) cnt[0]++;
		else cnt[1]++;
		return;
	}

	else {
		int judge = 0;
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (arr[x][y] != arr[i][j]) {
					judge = 1;
					i = x + size;
					break;
				}
			}
		}

		if (judge == 0) {
			if (arr[x][y] == -1) cnt[2]++;
			else cnt[arr[x][y]]++;
		}

		else {
			solution(x, y, size / 3);
			solution(x, y + size / 3, size / 3);
			solution(x, y + (size / 3) * 2, size / 3);
			solution(x + size / 3, y, size / 3);
			solution(x + size / 3, y + size / 3, size / 3);
			solution(x + size / 3, y + (size / 3) * 2, size / 3);
			solution(x + (size / 3) * 2, y, size / 3);
			solution(x + (size / 3) * 2, y + size / 3, size / 3);
			solution(x + (size / 3) * 2, y + (size / 3) * 2, size / 3);
		}
	}
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	solution(1, 1, N);

	printf("%d\n%d\n%d", cnt[2], cnt[0], cnt[1]);
}