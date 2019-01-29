#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int load[101][101];
int visited[101][101];
int city[25];

int dfs(int x, int y) {
	visited[x][y] = 1;
	int cnt = 1;
	//╩С
	if (visited[x][y - 1] != 1 && load[x][y - 1] == 1) {
		cnt += dfs(x, y - 1);
	}
	//го
	if (visited[x][y + 1] != 1 && load[x][y + 1] == 1) {
		cnt += dfs(x, y + 1);
	}
	//аб
	if (visited[x-1][y ] != 1 && load[x-1][y ] == 1) {
		cnt += dfs(x-1, y);
	}
	//©Л
	if (visited[x+1][y] != 1 && load[x+1][y] == 1) {
		cnt += dfs(x+1, y);
	}
	return cnt;
}

int main(void) {
	int N;
	scanf("%d", &N);

	int x, y;
	string s;

	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= N; j++) {
			load[i][j] = s[j - 1] - '0';
		}
	}

	int cnt = 0;
	int c = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt = 0;
			if (visited[i][j] != 1 && load[i][j] == 1) {
				cnt = dfs(i, j);
			}
			if (cnt != 0) { city[c++] = cnt; }
		}
	}
	
	sort(city, city + c);
	printf("%d\n", c);
	for (int i = 0; i < c; i++) {
		printf("%d\n", city[i]);
	}
}