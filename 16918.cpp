#include<iostream>
#define SIZE 210

using namespace std;

char arr[SIZE][SIZE];
int time[SIZE][SIZE];
int x[4] = { -1,0,1,0 };
int y[4] = { 0, 1, 0 ,-1 };
int R, C, N;

void init_arr() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'O')
				time[i][j] = 0;
		}
	}
}
void set_arr(int t) {
	for(int i =1 ; i<=R;i++)
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] == '.') {
				arr[i][j] = 'O';
				time[i][j] = t;
			}
		}
}
void explosive(int t) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (time[i][j] == t - 3) {
				arr[i][j] = '.';
				for (int k = 0; k < 4; k++) {
					int n_x = i + x[k];
					int n_y = j + y[k];
					arr[n_x][n_y] = '.';
				}
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] == '.')
				time[i][j] = 0;
		}
	}
}

void print_arr() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}
int main(void) {
	ios::sync_with_stdio(false);

	cin >> R >> C >> N;



	init_arr();
	for (int t = 2; t <= N; t++) {
		if (t % 2 == 0)
			set_arr(t);
		else
			explosive(t);
	}

	print_arr();
}