#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 110
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool visited[SIZE][SIZE];

int dfs(int h_x, int h_y, int h_num, int m ,int n, vector<vector<int>> &picture) {
	int cnt = 1;
	visited[h_x][h_y] = true;
	for (int d = 0; d < 4; d++) {
		int n_x = h_x + dx[d];
		int n_y = h_y + dy[d];

		if (n_x < 0 || n_x >= m || n_y < 0 || n_y >= n)
			continue;

		if (visited[n_x][n_y] == true)
			continue;
		if (picture[n_x][n_y] != h_num)
			continue;

		cnt += dfs(n_x, n_y, h_num,m, n, picture);
	}

	return cnt;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	memset(visited, false, sizeof(visited));

	int area = 0;
	int group = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && visited[i][j] != true) {
				area = max(area,dfs(i, j, picture[i][j], m , n, picture));
				group++;
			}
		}
	}

	vector<int> answer = { group, area };

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, n; cin >> m >> n;

	vector<vector<int>> picture;
	for (int i = 1; i <= m; i++) {
		vector<int> p;
		for (int j = 1; j <= n; j++) {
			int color; cin >> color;
			p.push_back(color);
		}
		picture.push_back(p);
	}
	vector<int> res = solution(m, n, picture);

	return 0;
}