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
const int INF = 20000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1, 0 ,-1 };

char board[SIZE][SIZE];

//0Àº man    1Àº fire
int cnt[SIZE][SIZE][2];
bool visited[SIZE][SIZE][2];

queue<pair<int, pair<int, int>>> q;

bool is_escape(int N, int M) {
	int res = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
				if (cnt[i][j][0] < cnt[i][j][1]) {
					res = min(res, cnt[i][j][0] + 1);
				}
			}
		}
	}

	if (res != INF) {
		cout << res;
		return true;
	}
	return false;
}

void init(int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cnt[i][j][0] = cnt[i][j][1] = INF;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	int N, M; cin >> N >> M;

	init(N,M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'J') {
				q.push({ i,{j,0} });
				cnt[i][j][0] = 0;
			}
			else if (board[i][j] == 'F') {
				q.push({ i,{j,1} });
				cnt[i][j][1] = 0;
			}
		}
	}

	while (!q.empty()) {
		pair<int, pii> h = q.front(); q.pop();
		
		visited[h.first][h.second.first][h.second.second] = true;
	
		for (int d = 0; d < 4; d++) {
			pair<int, pii> n;
			n.first = h.first + dx[d];
			n.second.first = h.second.first + dy[d];
			n.second.second = h.second.second;

			if (n.first < 0 || n.first >= N || n.second.first < 0 || n.second.first >= M)
				continue;

			if (visited[n.first][n.second.first][n.second.second] == true)
				continue;

			if (board[n.first][n.second.first] == '#')
				continue;
			cnt[n.first][n.second.first][n.second.second] = cnt[h.first][h.second.first][h.second.second] + 1;
			visited[n.first][n.second.first][n.second.second] = true;

			q.push(n);
		}
	}

	if (is_escape(N, M)) {
		return 0;
	}
	else {
		cout << "IMPOSSIBLE";
	}

	return 0;


}