#include<iostream>
#define SIZE 60

using namespace std;
int arr[SIZE][SIZE];
int mise[SIZE][SIZE];
int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };

int side(int c) {
	return c / 5;
}
int center(int c, int cnt) {
	return c - (c/5)*cnt;
}
int main(void) {
	int R, C, T; scanf("%d%d%d", &R, &C, &T);

	int g[2];
	int g_i = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == -1) {
				g[g_i++] = i;
			}
		}
	}

	//미세먼지 한번 퍼짐
	for (int t = 1; t <= T; t++) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				int h_x = i;
				int h_y = j;
				int cnt = 0;
				for (int s = 0; s < 4; s++) {
					int n_x = h_x + x[s];
					int n_y = h_y + y[s];

					if (arr[n_x][n_y] == -1)
						continue;
					if (n_x < 1 || n_y <1 || n_x > R || n_y > C)
						continue;

					mise[n_x][n_y] += side(arr[h_x][h_y]);
					cnt++;
				}
				mise[h_x][h_y] += center(arr[h_x][h_y],cnt);
			}
		}

		//공기청정기 한번 작동
		//위쪽 돌림
		int x = g[0]; int y = 1;
		while (1) {
			int n_x, n_y;
			
			if (y == 1 && x > 1) {
				n_x = x - 1;
				n_y = y;	
				mise[x][y] = mise[x][y] == -1 ? -1 : mise[n_x][n_y];
				x--;
			}
			else if (x == 1 && y < C) {
				n_x = x;
				n_y = y + 1;
				mise[x][y] = mise[x][y] == -1 ? -1 : mise[n_x][n_y];
				y++;
			}
			else if (y == C && x < g[0]) {
				n_x = x + 1;
				n_y = y;
				mise[x][y] = mise[x][y] == -1 ? -1 : mise[n_x][n_y];
				x++;
			}
			else if (x == g[0] && y > 1) {
				n_x = x;
				n_y = y - 1 ;
				mise[x][y] = mise[x][y] == -1 ? -1 : mise[n_x][n_y];
				y--;
			}
			

			if (mise[n_x][n_y] == -1) {
				mise[n_x][n_y + 1] = 0;
				break;
			}
		}

		 x = g[1]; y = 1;
		while (1) {
			int n_x, n_y;

			if (y == 1 && x <R) {
				n_x = x + 1;
				n_y = y;
				mise[x][y] = mise[x][y] == -1 ? -1 : mise[n_x][n_y];
				x++;
			}
			else if (x ==  R && y < C) {
				n_x = x;
				n_y = y + 1;
				mise[x][y] = mise[x][y] == -1 ? -1 : mise[n_x][n_y];
				y++;
			}
			else if (y == C && x > g[1]) {
				n_x = x - 1;
				n_y = y;
				mise[x][y] = mise[x][y] == -1 ? -1 : mise[n_x][n_y];
				x--;
			}
			else if (x == g[1] && y > 1) {
				n_x = x;
				n_y = y - 1;
				mise[x][y] = mise[x][y] == -1 ? -1 : mise[n_x][n_y];
				y--;
			}


			if (mise[n_x][n_y] == -1) {
				mise[n_x][n_y + 1] = 0;
				break;
			}
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				arr[i][j] = mise[i][j];
				mise[i][j] = 0;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] != -1)
				sum += arr[i][j];
		}
	}
	printf("%d", sum);
}