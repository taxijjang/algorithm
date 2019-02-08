#include <iostream>
#include <string>
using namespace std;

int arr[65][65];

void solution(int x, int y, int size) {
	if (size == 1) {
		printf("%d", arr[x][y]);
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
			printf("%d", arr[x][y]);
			return;
		}
		else {
			printf("(");
			solution(x, y, size / 2);
			solution(x, y + size / 2, size / 2);
			solution(x + size / 2, y, size / 2);
			solution(x + size / 2, y + size / 2, size / 2);
			printf(")");
		}
	}
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j + 1] = s[j] - '0';
		}
	}

	solution(1, 1, N);
	getchar();
}