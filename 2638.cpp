#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 110

using namespace std;

typedef long long int ll;
typedef struct Data {
	int x, y;
}Data;

int arr[SIZE][SIZE];
bool visited[SIZE][SIZE];
bool out[SIZE][SIZE];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0 ,1,0,-1 };

int N, M;
int chz = 0;

queue<Data> q;

void dfs(Data h) {
	if (out[h.x][h.y] == true)
		return;

	out[h.x][h.y] = true;
	for (int i = 0; i < 4; i++) {
		Data n;
		n.x = h.x + dx[i];
		n.y = h.y + dy[i];

		if (n.x < 0 || n.y < 0 || n.x >= N || n.y >= M)
			continue;
		if(arr[n.x][n.y] != 0 || out[n.x][n.y] == true)
			continue;

		dfs(n);
	}
}
void fill_v() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			visited[i][j] = false;
			out[i][j] = false;
		}
	}

	dfs({ 0,0 });
}

void chz_check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				chz++;
				q.push({ i,j });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	 cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int res = 0;
	while (true) {
		chz = 0;
		chz_check();
		fill_v();
		if (chz == 0)
			break;

		bool toggle = true;
		while (!q.empty()) {
			Data h = q.front();
			q.pop();

			visited[h.x][h.y] = true;
			int empty_cnt = 0;
			for (int i = 0; i < 4; i++) {
				Data n;
				n.x = h.x + dx[i];
				n.y = h.y + dy[i];

				if (n.x < 0 || n.y < 0 || n.x >= N || n.y >= M)
					continue;
				if (visited[n.x][n.y] == true || arr[n.x][n.y] != 0 || out[n.x][n.y] != true)
					continue;

				empty_cnt++;
			}
			if (empty_cnt >= 2) {
				arr[h.x][h.y] = 0;
				toggle = false;
			}

		}
		if (toggle)
			break;
		res++;
	}

	cout << res;
}