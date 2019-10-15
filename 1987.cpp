#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define SIZE 22
using namespace std;

string board[SIZE];
int dx[4] = { -1 ,0 , 1 , 0 };
int dy[4] = { 0 , 1, 0, -1 };
bool visited[30];
int res;
int R, C;
void dfs(int h_x, int h_y,int cnt) {
	res = res < cnt ? cnt : res;
	visited[board[h_x][h_y] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int n_x = h_x + dx[i];
		int n_y = h_y + dy[i];

		if (n_x < 0 || n_y < 0 || n_x >= R || n_y >= C)
			continue;
		if (visited[board[n_x][n_y] - 'A'] == true)
			continue;
		dfs(n_x, n_y, cnt + 1);
		visited[board[n_x][n_y]-'A'] = false;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}

	dfs(0, 0, 1);
	cout << res;
}