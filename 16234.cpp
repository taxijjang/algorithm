
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 60

using namespace std;

typedef long long int ll;

typedef struct Data {
	int x, y;
}Data;
int arr[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dx[4] = { -1,0,1, 0 };
int dy[4] = { 0,1,0,-1 };

int N, L, R;
int cnt, sum;

queue<Data> q;

void fill_v() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			visited[i][j] = false;
		}
	}
}
void dfs(Data here) {
	for (int i = 0; i < 4; i++) {
		Data n;
		n.x = here.x + dx[i];
		n.y = here.y + dy[i];

		int gap = abs(arr[here.x][here.y] - arr[n.x][n.y]);
		if (n.x < 0 || n.y < 0 || n.x >= N || n.y >= N)
			continue;
		if (visited[n.x][n.y] == true)
			continue;
		if (gap < L || gap> R)
			continue;

		if (visited[here.x][here.y] != true) {
			q.push({ here.x,here.y });
			visited[here.x][here.y] = true;
			sum += arr[here.x][here.y];
		}

		visited[n.x][n.y] = true;
		sum += arr[n.x][n.y];
		q.push({ n.x,n.y });

		dfs({ n.x,n.y });

	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	while (1) {
		int judge = 0;
		fill_v();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] != true) {
					sum = 0;
					dfs({ i,j });

					int q_size = q.empty() ? 0 : q.size();
					sum = q_size == 0 ? sum : sum / q_size;

					if (q_size != 0) {
						judge++;
					}
					while (!q.empty()) {
						arr[q.front().x][q.front().y] = sum;
						q.pop();
					}

				}
			}
		}
		if (judge == 0)
			break;
		else
			cnt++;

	}
	cout << cnt;
}