#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>
#include<stack>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

char arr[SIZE][SIZE];
int man_v[SIZE][SIZE];
int fire_v[SIZE][SIZE];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

typedef struct Loc {
	int x, y;
	bool what;
}Loc;
void init() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			man_v[i][j] = -1;
			fire_v[i][j] = -1;
		}
	}
}

queue<Loc> q;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		init();
		int N, M; cin >> M >> N;


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];

				if (arr[i][j] == '@') {
					Loc m; m.x = i; m.y = j; m.what = true;
					q.push(m); man_v[i][j] = 0;
				}
				else if (arr[i][j] == '*') {
					Loc f; f.x = i; f.y = j; f.what = false;
					q.push(f); fire_v[i][j] = 0;
				}
			}
		}


		while (!q.empty()) {
			Loc h = q.front(); q.pop();

			for (int d = 0; d < 4; d++) {
				Loc n; n.x =h.x+  dx[d]; n.y = h.y + dy[d]; n.what = h.what;

				if (n.x < 0 || n.x >= N || n.y < 0 || n.y >= M || arr[n.x][n.y] == '#')
					continue;

				if (h.what == true) {//man
					if (man_v[n.x][n.y] != -1)
						continue;
					else if (man_v[n.x][n.y] == -1) {
						man_v[n.x][n.y] = man_v[h.x][h.y] + 1;
						q.push(n);
					}
				}
				else if (h.what == false) {//fire
					if (fire_v[n.x][n.y] != -1)
						continue;
					else if (fire_v[n.x][n.y] == -1) {
						fire_v[n.x][n.y] = fire_v[h.x][h.y] + 1;
						q.push(n);
					}
				}
			}
		}

		int res = INF;
		for (int i = 0; i < N; i++) {

			if ((man_v[i][0] < fire_v[i][0] || fire_v[i][0] == -1) && man_v[i][0] != -1) {
				res = min(res, man_v[i][0]);
			}
			if ((man_v[i][M - 1] < fire_v[i][M - 1] || fire_v[i][M-1] == -1)&& man_v[i][M - 1] != -1) {
				res = min(res,man_v[i][M-1]);
			}

		}

		for (int j = 0; j < M; j++) {
			if ((man_v[0][j] < fire_v[0][j] || fire_v[0][j] == -1) && man_v[0][j] != -1) {
				res = min(res, man_v[0][j]);
			}
			if ((man_v[N-1][j] < fire_v[N-1][j] || fire_v[N-1][j]) && man_v[N-1][j] != -1) {
				res = min(res, man_v[N-1][j]);
			}
		}

		if (res == INF)
			cout << "IMPOSSIBLE\n";
		else
			cout << res +1 << "\n";
	}
}