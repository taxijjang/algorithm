#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

#define SIZE 100010
const int INF = 2e9;
using namespace std;

typedef long long int ll;

pair<int,int> visited[SIZE];
queue<int> q;

int move(int here, int d) {
	if (d == 0) {
		return here-1;
	}
	else if (d == 1) {
		return here+1;
	}
	else if (d == 2) {
		return here * 2;
	}
}

void init() {
	for (int i = 0; i < SIZE; i++) {
		visited[i].first = INF;
		visited[i].second = 0;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();
	int N, K; cin >> N >> K;

	if (N == K) {
		cout << 0 <<"\n"<< 1;
		return 0;
	}

	q.push(N);
	visited[N].first = 0;
	visited[N].second = 1;
	while (!q.empty()) {
		int h = q.front(); q.pop();
		
		for (int d = 0; d < 3; d++) {
			int n = move(h,d);

			if (n< 0 || n > 100000)
				continue;

			if (visited[n].first >= visited[h].first + 1) {
				if (visited[n].first == visited[h].first +1) {
					visited[n].first = visited[h].first + 1;
					visited[n].second += visited[h].second;
					continue;
				}

				else if (visited[n].first > visited[h].first + 1) {
					q.push(n);
					visited[n].first = visited[h].first + 1;
					visited[n].second = visited[h].second;
				}
			}
		}
	}

	cout << visited[K].first << "\n" << visited[K].second;
	return 0;
}