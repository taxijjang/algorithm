#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define SIZE 1010
#define INF 2e9
using namespace std;

vector<pair<int, int>> v[SIZE];
int total_dis[SIZE];
int main(void) {
	int N, M, X; scanf("%d%d%d", &N, &M, &X);

	int dis2[SIZE];
	fill(dis2, dis2 + SIZE, INF);

	for (int i = 0; i < M; i++) {
		int n1, n2, w; scanf("%d%d%d", &n1, &n2, &w);
		v[n1].push_back({ -w,n2 });
	}

	dis2[X] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,X });

	while (!pq.empty()) {
		int here = pq.top().second;
		int h_w = -pq.top().first;

		pq.pop();

		for (auto n : v[here]) {
			int next = n.second;
			int n_w = -n.first;

			if (dis2[next] > dis2[here] + n_w) {
				dis2[next] = min(dis2[next], dis2[here] + n_w);
				pq.push({ -n_w,next });
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		total_dis[i] += dis2[i];
	}

	int dis1[SIZE];
	
	int m_n = 0;
	for (int i = 1; i <= N; i++) {
		fill(dis1, dis1 + SIZE, INF);
		dis1[i] = 0;

		pq = priority_queue<pair<int, int>>();
		pq.push({ 0,i });

		while (!pq.empty()) {
			int here = pq.top().second;
			int h_w = -pq.top().first;

			pq.pop();

			for (auto n : v[here]) {
				int next = n.second;
				int n_w = -n.first;

				if (dis1[next] > dis1[here] + n_w) {
					dis1[next] = min(dis1[next], dis1[here] + n_w);
					pq.push({ -n_w,next });
				}
			}
		}

		m_n = m_n < total_dis[i] + dis1[X] ? total_dis[i] + dis1[X] : m_n;
	}

	printf("%d", m_n);

}