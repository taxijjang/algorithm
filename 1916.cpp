#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#define SIZE 1010
#define INF 2e9
using namespace std;

int dist[SIZE];
vector<pair<int, int>> v[SIZE];
void fill_city() {
	for (int i = 0; i < SIZE; i++) {
		dist[i] = INF;
	}
}

priority_queue<pair<int,int>> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill_city();
	int N, M; cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int dx, dy, dcost;
		cin >> dx >> dy >> dcost;
		v[dx].push_back({ dcost,dy });
	}

	int start, end; cin >> start >> end;

	dist[start] = 0;
	
	pq.push({ 0,start });

	
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();
		for (auto n : v[here]) {
			int n_cost = n.first;
			int next = n.second;

			if (dist[here] + n_cost < dist[next]) {
				dist[next] = dist[here] + n_cost;
				pq.push({ -dist[next],next });
			}
		}
	}

	cout << dist[end];

}