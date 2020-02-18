#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 15

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef struct Data {
	int x, y, d, cnt = 0;
}Data;

const int INF = 2000000000;

int dx[4] = { -1,0,1, 0 };
int dy[4] = { 0,1,0,-1 };

bool visited[SIZE][SIZE][SIZE][SIZE];
char board[SIZE][SIZE];
int N, M;
bool r_g,b_g;
queue<pair<Data,Data>> q;

Data move(Data l, int *m,int d) {
	while (board[l.x + dx[d]][l.y + dy[d]] != '#' && board[l.x][l.y] != 'O') {
		l.x += dx[d];
		l.y += dy[d];
		*m += 1;
	}
	
	l.cnt++;
	return l;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	Data r_l, b_l;
	pii h;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') r_l.x = i, r_l.y = j;
			else if (board[i][j] == 'B') b_l.x = i, b_l.y = j;
			else if (board[i][j] == 'O') h = { i,j };
		}
	}
	q.push({ r_l,b_l });

	while (!q.empty()) {
		pair<Data,Data> h = q.front();
		Data h_r = h.first; Data h_b = h.second;
		q.pop();

		visited[h_r.x][h_r.y][h_b.x][h_b.y] = true;
		r_g = b_g = false;
		for (int d = 0; d < 4; d++) {
			int r_m = 0;
			int b_m = 0;
			r_g = b_g = false;
			Data n_r = move(h_r, &r_m, d);
			Data n_b = move(h_b, &b_m, d);

			if (n_r.cnt >= 10 || n_b.cnt >= 10)
				continue;

			if (board[n_r.x][n_r.y] =='O' && board[n_b.x][n_b.y] =='O') {
				continue;
			}
			else if (board[n_r.x][n_r.y] == 'O' && board[n_b.x][n_b.y] != 'O') {
				cout << 1;
				return 0;
			}
			if (n_r.x == n_b.x && n_r.y == n_b.y) {
				if (r_m < b_m) {
					n_b.x -= dx[d]; n_b.y -= dy[d];
				}
				else {
					n_r.x -= dx[d]; n_r.y -= dy[d];
				}
			}

			
			if (visited[n_r.x][n_r.y][n_b.x][n_b.y] == true)
				continue;

			visited[n_r.x][n_r.y][n_b.x][n_b.y] = true;
			q.push({ n_r,n_b });
		}
	}

	cout << 0;
	return 0;

}
