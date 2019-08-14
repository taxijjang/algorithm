#include<iostream>
#include<queue>
#include<vector>
#define SIZE 130
#define INF 2e9
using namespace std;

typedef struct Data {
	int x, y, w;
}Data;

struct cmp {
	bool operator()(const Data &d1, const Data &d2) {
		return d1.w > d2.w;
	}
};
priority_queue <Data, vector<Data>,cmp> pq;

int cost[SIZE][SIZE];
int arr[SIZE][SIZE];
bool visited[SIZE][SIZE];
int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };

int dis[SIZE];

int main(void) {
	int index = 1;
	while (1) {
		int n; scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		fill(&visited[0][0], &visited[0][0] + SIZE*SIZE, false);
		fill(&cost[0][0], &cost[0][0] + SIZE*SIZE, INF);
		pq.push({1,1,arr[1][1]});
		visited[1][1] = true;
		while (!pq.empty()) {
			int h_x = pq.top().x;
			int h_y = pq.top().y;
			int h_w = pq.top().w;
			pq.pop();
			visited[h_x][h_y] = true;
			for (int i = 0; i < 4; i++) {
				int n_x = h_x + x[i];
				int n_y = h_y + y[i];
				int n_w = h_w + arr[n_x][n_y];

				if (visited[n_x][n_y] == true)
					continue;
				if (n_x <1 || n_y < 1 || n_x > n || n_y >n)
					continue;
				if (cost[n_x][n_y] > n_w)
					cost[n_x][n_y] = n_w;
				else
					continue;
				pq.push({ n_x,n_y,n_w });
			}
		}
		printf("Problem %d: %d\n", index++, cost[n][n]);
	}
}