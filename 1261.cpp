#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#define SIZE 110
using namespace std;

string arr[SIZE];
bool visited[SIZE][SIZE];
int dp[SIZE][SIZE];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

typedef struct Data {
	int x, y, cnt = 0,wall=0;
}Data;

struct cmp {
	bool operator()(Data d1, Data d2) {
		return d1.wall > d2.wall;
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> M >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	priority_queue<Data,vector<Data>,cmp> pq;
	Data start; start.x = 0; start.y = 0;
	pq.push(start);
	visited[start.x][start.y] = true;

	int res = 1101111;
	while (!pq.empty()) {
		Data here = pq.top();
		pq.pop();

		if (here.x == N - 1 && here.y == M - 1) {
			res = res < here.wall ? res : here.wall;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			Data next;
			next.x = here.x + dx[i];
			next.y = here.y + dy[i];
			next.cnt = here.cnt + 1;
			next.wall = here.wall;
			if (next.x < 0 || next.y < 0 || next.x >= N || next.y >= M)
				continue;
			if (visited[next.x][next.y] == true)
				continue;

			visited[next.x][next.y] = true;
			if (arr[next.x][next.y] == '1')
				next.wall += 1;

			pq.push(next);
		}
	}
	cout << res;

}