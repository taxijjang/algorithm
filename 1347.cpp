#include<iostream>
#define SIZE 1000
using namespace std;

char maze[SIZE][SIZE];

int x[4] = { 1,0,-1,0 };
int y[4] = { 0,-1,0,1 };
int l_x = SIZE, l_y = SIZE, r_x = 0, r_y = 0;
void loction(int h_x,int  h_y) {
	l_x = l_x > h_x ? h_x : l_x;
	l_y = l_y > h_y ? h_y : l_y;

	r_x = r_x < h_x ? h_x : r_x;
	r_y = r_y < h_y ? h_y : r_y;
}
int main(void) {
	ios::sync_with_stdio(false);

	int n; cin >> n;

	int h_x = 100, h_y = 100;
	loction(h_x, h_y);
	fill(&maze[0][0], &maze[0][0] + SIZE*SIZE, 'X');
	maze[h_x][h_y] = '.';
	int see = 0; //0 巢率 , 1 辑率 , 2 合率 , 3 悼率
	for (int i = 0; i < n; i++) {
		char q; cin >> q;
		if (q == 'R')
			see = (see + 1) % 4;
		else if (q == 'L')
			see = see - 1 < 0 ? 3 : see - 1;
		else if (q == 'F') {
			h_x += x[see], h_y += y[see];
			maze[h_x][h_y] = '.';
			loction(h_x, h_y);
		}
	}

	for (int i = l_x; i <= r_x; i++) {
		for (int j = l_y; j <= r_y; j++) {
			if (maze[i][j] == 'X')
				cout << "# ";
			else
				cout << maze[i][j] << " ";
		}
		cout << "\n";
	}
}