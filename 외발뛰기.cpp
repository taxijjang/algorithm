#include <iostream>
#define N 100
using namespace std;

int n;
int board[N][N];
int search(int y, int x) {
	//기저 사례 1 밖으로 나갈때
	if (x >= n || y >= n) {
		return 0;
	}
	//기저 사례 2 도착 할 때
	if (x - 1 == n && y - 1 == n) {
		return 1;
	}

	int jumpsize = board[y][x];

	return search(jumpsize + y, x) || search(y, jumpsize + x);
}
int main(void) {
	n = 7;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	//memset(board, -1, sizeof(board));

	cout << search(0, 0);
}