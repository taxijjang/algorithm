#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 55

using namespace std;

typedef long long int ll;

typedef struct Data {
	int x = 0 , y = 0 , wall = 0;
}Data;

struct cmp {
	bool operator()(Data d1, Data d2) {
		return d1.wall > d2.wall;
	}
};
char arr[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

priority_queue < Data, vector<Data>, cmp> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	Data start;

	pq.push(start);
	visited[0][0] = true;

	while (!pq.empty()) {
		Data here = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			Data n;
			n.x = here.x + dx[i];
			n.y = here.y + dy[i];
			n.wall = here.wall;

			if (n.x < 0 || n.y < 0 || n.x >= N || n.y >= N)
				continue;
			if (visited[n.x][n.y] == true)
				continue;

			if (arr[n.x][n.y] == '0')
				n.wall++;

			if (n.x == N - 1 && n.y == N - 1) {
				cout << n.wall;
				return 0;
			}
			visited[n.x][n.y] = true;
			pq.push(n);
		}
	}


}