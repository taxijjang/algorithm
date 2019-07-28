#include<iostream>
#define SIZE 101

using namespace std;
char arr[SIZE][SIZE];

int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };

bool v1[SIZE][SIZE];
bool v2[SIZE][SIZE];
void dfs1(int h_x, int h_y,int N, char color) {
	v1[h_x][h_y] = true;

	for (int i = 0; i < 4; i++) {
		int n_x = h_x + x[i];
		int n_y = h_y + y[i];

		if (color != arr[n_x][n_y])
			continue;
		if (n_x < 0 || n_y < 0 || n_x >= N || n_y >= N)
			continue;
		if (v1[n_x][n_y] != true)
			dfs1(n_x, n_y, N, color);
	}
}

void dfs2(int h_x, int h_y, int N, int color) {
	v2[h_x][h_y] = true;

	for (int i = 0; i < 4; i++) {
		int n_x = h_x + x[i];
		int n_y = h_y + y[i];

		if ((color == 'B' && (arr[n_x][n_y] == 'R' || arr[n_x][n_y] == 'G')) ||
			((color =='R' || color =='G') && arr[n_x][n_y] == 'B'))
			continue;
		if (n_x < 0 || n_y < 0 || n_x >= N || n_y >= N)
			continue;
		if (v2[n_x][n_y] != true)
			dfs2(n_x, n_y, N, color);
	}
}
int main(void) {
	int N; scanf("%d", &N);
	
	int cnt1 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v1[i][j] != true) {
				cnt1++;
				dfs1(i, j, N, arr[i][j]);
			}
		}
	}

	int cnt2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v2[i][j] != true) {
				cnt2++;
				dfs2(i, j, N, arr[i][j]);
			}
		}
	}
	cout << cnt1 << " " << cnt2;
}