#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define SIZE 1010

using namespace std;

typedef long long int ll;
typedef struct Data {
	int x, y, cnt, wall;
}Data;
const int INF = 2000000000;


char board[SIZE][SIZE];
bool visited[SIZE][SIZE][2];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K; cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	Data s;
	s.x = 0; s.y = 0, s.cnt = 1, s.wall = 0;

	queue<Data> q;

	q.push(s);

	while (!q.empty()) {
		Data h = q.front();
		q.pop();

		visited[s.x][s.y][s.wall] = true;

		if (h.x == N - 1 && h.y == M - 1) {
			cout << h.cnt;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			Data n;
			n.x = h.x + dx[i], n.y = h.y + dy[i], n.cnt = h.cnt + 1;
			n.wall = h.wall + board[n.x][n.y] - '0';

			if (n.x < 0 || n.x >= N || n.y < 0 || n.y >= M)
				continue;
			if (visited[n.x][n.y][n.wall] == true)
				continue;
			if (n.wall > K)
				continue;

			visited[n.x][n.y][n.wall] = true;
			q.push(n);
		}
	}

	cout << -1;
	return 0;
}