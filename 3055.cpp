#include<iostream>
#include<queue>
#include<iomanip>
#define SIZE 60

using namespace std;

int R, C;

int go[SIZE][SIZE];
int wa[SIZE][SIZE];

bool v1[SIZE][SIZE];
bool v2[SIZE][SIZE];

int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,-0,-1 };
typedef struct Data {
	int x, y, cnt;
}Data;
void gosm() {
	int s_x, s_y;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (go[i][j] == -6) {
				s_x = i, s_y = j;
				i = R;
				break;
			}
		}
	}

	queue<Data> q;

	q.push({ s_x,s_y, 1 });

	while (!q.empty()) {
		int h_x = q.front().x;
		int h_y = q.front().y;
		int h_c = q.front().cnt;
		go[h_x][h_y] = h_c;
		q.pop();
		v1[h_x][h_y] = true;
		for (int i = 0; i < 4; i++) {
			int n_x = h_x + x[i];
			int n_y = h_y + y[i];
			int n_c = h_c + 1;

			if (v1[n_x][n_y] == true)
				continue;
			if (n_x < 1 || n_y < 1 || n_x >R || n_y >C)
				continue;
			if (go[n_x][n_y] == -7 || go[n_x][n_y] == -4 || go[n_x][n_y] == -1)
				continue;
			v1[n_x][n_y] = true;
			q.push({ n_x,n_y,n_c });
		}
	}

	getchar();
}

void water() {
	queue<Data> q;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (wa[i][j] == -7)
				q.push({ i,j,1 });
		}
	}

	while (!q.empty()) {
		int h_x = q.front().x;
		int h_y = q.front().y;
		int h_c = q.front().cnt;
		wa[h_x][h_y] = h_c;
		q.pop();
		v2[h_x][h_y] = true;
		for (int i = 0; i < 4; i++) {
			int n_x = h_x + x[i];
			int n_y = h_y + y[i];
			int n_c = h_c + 1;

			if (v2[n_x][n_y] == true)
				continue;
			if (n_x < 1 || n_y < 1 || n_x >R || n_y >C)
				continue;
			if (wa[n_x][n_y] == -7 || wa[n_x][n_y] == -4 || wa[n_x][n_y] == -1)
				continue;
			v2[n_x][n_y] = true;
			q.push({ n_x,n_y,n_c });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> R >> C;

	int d_x, d_y;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			char a; cin >> a;
			if (a == '.')
				go[i][j] = 0;
			else if (a == '*')
				go[i][j] = -7;
			else if (a == 'X')
				go[i][j] = -4;
			else if (a == 'D')
				go[i][j] = -1;
			else if (a == 'S')
				go[i][j] = -6;
			if (a == 'D')
				d_x = i, d_y = j;
			wa[i][j] = go[i][j];
		}
	}

	gosm();
	water();
	/*
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << setw(3) << go[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << setw(3) << wa[i][j] << " ";
		}
		cout << "\n";
	}*/


	bool toggle = false;
	int min_cnt = 2000000000;
	for (int i = 0; i < 4; i++) {
		int n_x = d_x + x[i];
		int n_y = d_y + y[i];

		if (go[n_x][n_y] >= 0 && wa[n_x][n_y] >=0) {
			if (wa[n_x][n_y] == 0 && go[n_x][n_y] != 0) {
				min_cnt = min_cnt < go[n_x][n_y] ? min_cnt : go[n_x][n_y];
				toggle = true;
			}
			else if ((go[n_x][n_y] > 0) && go[n_x][n_y] < wa[n_x][n_y]) {
				min_cnt = min_cnt < go[n_x][n_y] ? min_cnt : go[n_x][n_y];
				toggle = true;
			}
		}
	}

	if (toggle)
		cout << min_cnt;
	else
		cout << "KAKTUS";
}
