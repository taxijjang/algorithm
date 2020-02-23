#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 510
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int board[SIZE][SIZE];
bool visited[SIZE][SIZE];

int chul[4][9][9] =
{
	{
		{0,1,0},
		{1,1,1},
		{0,0,0}
	},
	{
		{ 1,1,1 },
		{ 0,1,0 },
		{ 0,0,0 }
	},
	{
		{ 1,0,0 },
		{ 1,1,0 },
		{ 1,0,0 }
	},
	{
		{ 0,1,0 },
		{ 1,1,0 },
		{ 0,1,0 }
	},
};

int N, M;
int res = 0;

int check() {
	int cost = 0;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int d = 0; d < 4; d++) {
				sum = 0;
				for (int di = 0; di < 3; di++) {
					for (int dj = 0; dj < 3; dj++) {
						sum += chul[d][di][dj] * board[i + di][j + dj];
					}
				}
				cost = max(sum, cost);
			}
		}
	}
	return cost;
}
void dfs(int h_x, int h_y, int sum, int cnt) {
	if (cnt == 4) {
		res = max(res, sum);
		return;
	}

	sum += board[h_x][h_y];
	visited[h_x][h_y] = true;

	for (int d = 0; d < 4; d++) {
		int n_x = h_x + dx[d];
		int n_y = h_y + dy[d];

		if (n_x<1 || n_x >N || n_y<1 || n_y>M)
			continue;;

		if (visited[n_x][n_y] == true)
			continue;

		dfs(n_x, n_y, sum, cnt + 1);
	}
	visited[h_x][h_y] = false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	 cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dfs(i, j, 0, 0);
		}
	}

	check();
	res = max(res, check());
	cout << res;
}