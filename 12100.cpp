#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 22
const int INF = 2000000000;
using namespace std;

typedef long long int ll;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N;
int res;
void copy(int (*arr)[SIZE], int (*tmp)[SIZE] , int (*visited)[SIZE]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			tmp[i][j] = arr[i][j];
			res = max(res, tmp[i][j]);
			visited[i][j] = false;
		}
	}
}

void change(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void combine(int(*arr)[SIZE], int d, int(*visited)[SIZE]) {
	bool judge = false;
	if (d == 0) {//위로 기울이기
		for (int j = 1; j <= N; j++) {
			for (int i = 1; i <= N; i++) {
				if (arr[i][j] == 0) continue;
				for (int k = i - 1; k > 0; k--) {
					if (arr[i][j] == arr[k][j] && visited[k][j] != true) {
						arr[k][j] *= 2; arr[i][j] = 0; visited[k][j] = true;
						break;
					}
					else if (arr[k][j] != 0 && arr[i][j] != 0) {
						change(&arr[k + 1][j], &arr[i][j]);
						break;
					}
					if (k == 1)
						change(&arr[k][j], &arr[i][j]);
				}
			}
		}
	}
	
	else if (d == 1) {//오른쪽으로 기울이기
		for (int i = 1; i <=N ; i++) {
			for (int j = N; j >0; j--) {
				if (arr[i][j] == 0) continue;
				for (int k = j + 1; k <=N ; k++) {
					if (arr[i][j] == arr[i][k] && visited[i][k] != true) {
						arr[i][k] *= 2; arr[i][j] = 0; visited[i][k] = true;
						break;
					}
					else if (arr[i][k] != 0 && arr[i][j] != 0) {
						change(&arr[i][k - 1], &arr[i][j]);
						break;
					}
					if (k == N)
						change(&arr[i][k], &arr[i][j]);
				}				
			}
		}
	}
	else if (d == 2) {//아래로 기울이기
		for (int j = 1; j <= N; j++) {
			for (int i = N; i > 0; i--) {
				if (arr[i][j] == 0) continue;
				for (int k = i + 1; k <= N; k++) {
					if (arr[i][j] == arr[k][j] && visited[k][j] != true) {
						arr[k][j] *= 2; arr[i][j] = 0; visited[k][j] = true;
						break;
					}
					else if (arr[k][j] != 0 && arr[i][j] != 0) {
						change(&arr[k -1 ][j], &arr[i][j]);
						break;
					}
					if (k == N)
						change(&arr[k][j], &arr[i][j]);
				}
			}
		}
	}
	else if (d == 3) {//왼쪽으로 기울이기
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <=N; j++) {
				if (arr[i][j] == 0) continue;
				for (int k = j - 1; k > 0; k--) {
					if (arr[i][j] == arr[i][k] && visited[i][k] != true) {
						arr[i][k] *= 2; arr[i][j] = 0; visited[i][k] = true;
						break;
					}
					else if (arr[i][k] != 0 && arr[i][j] != 0) {
						change(&arr[i][k + 1], &arr[i][j]);
						break;
					}
					if (k == 1)
						change(&arr[i][k], &arr[i][j]);
				}
			}
		}
	}
}

void result(int(*arr)[SIZE]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			res = max(res, arr[i][j]);
		}
	}
}
void dfs(int arr[][SIZE], int cnt) {
	if (cnt >= 5) {
		result(arr);
		return;
	}
	
	for (int d = 0; d < 4; d++) {
		int tmp[SIZE][SIZE], visited[SIZE][SIZE];
		copy(arr, tmp, visited);
		combine(tmp, d, visited);
		dfs(tmp, cnt + 1);
	}

	
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	 cin >> N;

	int board[SIZE][SIZE];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	
	dfs(board, 0);
	cout << res;
}