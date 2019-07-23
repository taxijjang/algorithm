#include<iostream>
#include <queue>
#define SIZE 101

using namespace std;

bool arr[SIZE][SIZE];
int x[4] = { 1,0,-1,0 };
int y[4] = { 0, 1, 0,-1 };

priority_queue<int> pq;
int M, N, K,ss=0;
void dfs(int h_x, int h_y) {
	arr[h_x][h_y] = true;
	
	for (int i = 0; i < 4; i++) {
		int n_x = h_x + x[i];
		int n_y = h_y + y[i];

		if (n_x < 0 || n_y <0 || n_x >= M || n_y >= N)
			continue;
		if (arr[n_x][n_y] != true) {
			ss++;
			dfs(n_x, n_y);
		}
	}
}
int main(void) {
	 scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				arr[i][j] = true;
			}
		}
	}
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++){
			if (arr[i][j] != true) {
				cnt++; ss = 1;
				dfs(i, j);pq.push(-ss);
			}
		}
	}
	printf("%d\n", cnt);
	int pq_size = pq.size();
	for (int i = 0; i < pq_size; i++){
		printf("%d ", -pq.top());
		pq.pop();
	}
}