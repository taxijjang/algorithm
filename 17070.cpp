#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 20

#define GARO 0
#define DAGAK 1
#define SERO 2

using namespace std;

typedef long long int ll;

typedef struct Data {
	int x= 0 , y=0;
}Data;


int arr[SIZE][SIZE];
int dp[SIZE][SIZE];

int dx[3] = { 0,1,1 };
int dy[3] = { 1,1,0 };

int N;

bool move_check(Data next, int loc) {
	if (loc == GARO) {
		if (arr[next.x][next.y] == 1)
			return true;
	}
	else if (loc == DAGAK) {
		if (arr[next.x][next.y] == 1 || arr[next.x - 1][next.y] == 1 || arr[next.x][next.y - 1] == 1)
			return true;
	}
	else if (loc == SERO) {
		if (arr[next.x][next.y] == 1)
			return true;
	}
	return false;
}
void dfs(Data here, int loc) {
	if (here.x == N - 1 && here.y == N - 1 && arr[here.x][here.y] != 1) {
		dp[N - 1][N - 1]++;
		return;
	}
	if (loc == GARO) {
		for (int direct = GARO; direct <= DAGAK; direct++) {
			Data n; 
			n.x = here.x + dx[direct];
			n.y = here.y + dy[direct];

			if (n.x < 0 || n.y < 0 || n.x >= N || n.y >= N)
				continue;

			if (move_check(n,direct)) {
				continue;
			}
			dfs(n, direct);
		}
	}
	else if (loc == DAGAK) {
		for (int direct = GARO; direct <= SERO; direct++) {
			Data n;
			n.x = here.x + dx[direct];
			n.y = here.y + dy[direct];

			if (n.x < 0 || n.y < 0 || n.x >= N || n.y >= N)
				continue;
			if (arr[n.x][n.y] == 1)
				continue;
			dfs(n, direct);
		}
	}
	else if (loc == SERO) {
		for (int direct = DAGAK; direct <= SERO; direct++) {
			Data n;
			n.x = here.x + dx[direct];
			n.y = here.y + dy[direct];

			if (n.x < 0 || n.y < 0 || n.x >= N || n.y >= N)
				continue;
			if (arr[n.x][n.y] == 1)
				continue;
			dfs(n, direct);
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	Data start;
	start.y = 1;
	dfs(start, GARO);

	cout << dp[N - 1][N - 1];

}