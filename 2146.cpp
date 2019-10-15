#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define SIZE 110
using namespace std;

typedef struct Data {
	int x, y, cnt = 0;
}Data;

int arr[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0 ,1, 0 , -1 };
int res;
int N;
//
void init_dfs(int h_x, int h_y, int group) {
	if (arr[h_x][h_y] != 1)
		return;
	arr[h_x][h_y] = group;

	for (int i = 0; i < 4; i++) {
		int n_x = h_x + dx[i];
		int n_y = h_y + dy[i];

		if (n_x < 0 || n_y < 0 || n_x >= N || n_y >= N)
			continue;
		if (arr[n_x][n_y] != 1)
			continue;
		init_dfs(n_x, n_y, group);
	}
}

void fill_v() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			visited[i][j] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	 cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	//전처리
	int group = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				init_dfs(i, j, group++);
			}
		}
	}

	//검사
	res = 100101010;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0)
				continue;
			queue<Data> q;
			Data start; 
			start.x = i; start.y = j; start.cnt = 0;
			q.push(start);

			while (!q.empty()) {
				int h_x = q.front().x;
				int h_y = q.front().y;
				int h_cnt = q.front().cnt;

				if (arr[h_x][h_y] != arr[i][j] && arr[h_x][h_y] != 0) {
					res = res < h_cnt-1 ? res : h_cnt-1;
					break;
				}
				visited[h_x][h_y] = true;
				q.pop();

				for (int k = 0; k < 4; k++) {
					Data next;
					next.x = h_x + dx[k];
					next.y = h_y + dy[k];
					next.cnt = h_cnt + 1;

					if (next.x < 0 || next.y < 0 || next.x >= N || next.y >= N)
						continue;
					if (arr[next.x][next.y] == arr[i][j])
						continue;
					if (visited[next.x][next.y] == true)
						continue;

					visited[next.x][next.y] = true;

					q.push(next);
				}
			}
			fill_v();
		}
	}

	cout << res;
}