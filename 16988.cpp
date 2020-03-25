#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>
#include<stack>

#define SIZE 25
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int arr[SIZE][SIZE];
bool visited[SIZE][SIZE];
bool tmp[SIZE][SIZE];


priority_queue<int> res;
vector<pair<int, int>> blank;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

bool check = true;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmp[i][j] = visited[i][j];
		}
	}
}

int dfs(int h_x, int h_y) {
	tmp[h_x][h_y] = true;
	int cnt = 1;
	for (int d = 0; d < 4; d++) {
		int n_x = h_x + dx[d];
		int n_y = h_y + dy[d];

		if (n_x < 1 || n_x >N || n_y < 1 || n_y >M || tmp[n_x][n_y] == true || arr[n_x][n_y] == 1)
			continue;

		if (arr[n_x][n_y] == 0) {
			check = false;
			continue;
		}
		
		cnt+= dfs(n_x, n_y);

	}
	return cnt;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				blank.push_back({ i,j });
			}
		}
	}

	vector<int> ids(blank.size(), 0);
	for (int i = ids.size() - 2; i < ids.size(); i++) {
		ids[i] = 1;
	}
	res.push(0);
	do {
		init();

		for (int i = 0; i < ids.size(); i++) {
			if (ids[i] == 1) {
				tmp[blank[i].first][blank[i].second] = true;
			}
		}
	
		check = true;

		int r = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (tmp[i][j] != true && arr[i][j] == 2) {
					int tmp_r= dfs(i, j);
					if (check) {
						r += tmp_r;
						
					}
				}	
				check = true;
			}
		}
		if(r != 0)
			res.push(r);
	} while (next_permutation(ids.begin(), ids.end()));
	

	cout << res.top();


}