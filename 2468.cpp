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

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool visited[SIZE][SIZE];

int N;

void dfs(Data here, int w_h) {
	visited[here.x][here.y] = true;

	for (int d = 0; d < 4; d++) {
		Data n;
		n.x = here.x + dx[d];
		n.y = here.y + dy[d];

		if (n.x < 0 || n.y < 0 || n.x >= N || n.y >= N)
			continue;

		if (visited[n.x][n.y] == true)
			continue;

		if (arr[n.x][n.y] <= w_h)
			continue;
		dfs(n,w_h);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int max_h = 0;
	 cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			max_h = max_h < arr[i][j] ? arr[i][j] : max_h;
		}
	}

	int res = 0;
	for (int water = 0; water <= max_h; water++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Data here; here.x = i, here.y = j;
				if (visited[i][j] != true && arr[i][j] > water) {
					dfs(here, water);
					cnt++;
					
				}
				res = res < cnt ? cnt : res;
			}
		}
		memset(visited, false, sizeof(visited));
	}

	cout << res;
}