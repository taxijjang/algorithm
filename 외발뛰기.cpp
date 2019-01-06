#include <iostream>
#define N 100
using namespace std;

int n;
int board[N][N];
int search(int y, int x) {
	//���� ��� 1 ������ ������
	if (x >= n || y >= n) {
		return 0;
	}
	//���� ��� 2 ���� �� ��
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