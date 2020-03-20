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

#define SIZE 500
const int INF = 2000000000;
int BLANK = 22222;
using namespace std;

typedef long long int ll;

deque<int> dq[SIZE];
set<pair<int, int>> visited;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M, T;
int calc() {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum += dq[i][j] != BLANK ? dq[i][j] : 0;
		}
	}
	return sum;
}
void check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int n_x = x + dx[i], n_y = y + dy[i];

		if (n_x == N || n_x == -1)
			continue;
		n_x = x + dx[i] == -1 ? N - 1 : (x + dx[i]) % N;
		n_y = y + dy[i] == -1 ? M - 1 : (y + dy[i]) % M;

		if (dq[x][y] == dq[n_x][n_y] && dq[x][y] != BLANK) {
			visited.insert(make_pair(n_x, n_y));
			visited.insert(make_pair(x, y));
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num; cin >> num;
			dq[i].push_back(num);
		}
	}

	for (int t = 0; t < T; t++) {
		int x, d, k; cin >> x >> d >> k;

		//시계 방향
		for (int i = x - 1; i < N; i += x) {
			int t_k = k;
			if (d == 0) {
				while (t_k--) {
					dq[i].push_front(dq[i].back());
					dq[i].pop_back();
				}
			}
			//반시계 방향
			else if (d == 1) {
				while (t_k--) {
					dq[i].push_back(dq[i].front());
					dq[i].pop_front();
				}
			}
		}

		int sum = 0, cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (dq[i][j] == BLANK) continue;
				check(i, j);
				if (dq[i][j] != BLANK) {
					sum += dq[i][j]; cnt++;
				}
			}
		}

		//돌리기 완료
		if (!visited.empty()) {
			for (auto it = visited.begin(); it != visited.end(); it++) {
				dq[it->first][it->second] = BLANK;
			}
		}
		else if (visited.empty()) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (dq[i][j] != BLANK) {
						if (dq[i][j] * cnt < sum)
							dq[i][j]++;
						else if (dq[i][j] * cnt > sum)
							dq[i][j]--;
					}
				}
			}
		}


		visited.clear();
	}

	cout << calc();

}