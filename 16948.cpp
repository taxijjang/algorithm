#include<iostream>
#include<queue>

#define SIZE 210
#define INF 2e9
using namespace std;

typedef struct Data {
	int x, y,cnt;
}Data;

bool visited[SIZE][SIZE];
int arr[SIZE][SIZE];
int x[6] = { -2,-2,0,0,2,2 };
int y[6] = { -1,1,-2,2,-1,1 };

int main(void) {
	ios::sync_with_stdio(false);

	int N; cin >> N;

	Data s, d;

	cin >> s.x >> s.y >> d.x >> d.y;
	s.cnt = 0; d.cnt = INF;
	for (int i = 0; i <= SIZE; i++) {
		for (int j = 0; j <= SIZE; j++) {
			arr[i][j] = INF;
		}
	}

	arr[s.x][s.y] = 0;
	
	queue<Data> q;
	q.push(s);

	while (!q.empty()) {
		int h_x = q.front().x;
		int h_y = q.front().y;
		int h_c = q.front().cnt;
		visited[h_x][h_y] = true;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int n_x = h_x + x[i];
			int n_y = h_y + y[i];
			int n_c = h_c + 1;

			/*if (visited[n_x][n_y] == true) {
				if (arr[n_x][n_y] <= n_c)
					continue;
			}*/
			if (n_x < 0 || n_y < 0 || n_x >= N || n_y >= N)
				continue;
			if (arr[n_x][n_y] <= n_c)
				continue;

			visited[n_x][n_y] = true;
			arr[n_x][n_y] = n_c;
			q.push({ n_x,n_y,n_c });
		}
	}
	int res = arr[d.x][d.y] == INF ? -1 : arr[d.x][d.y];
	cout << res;
}