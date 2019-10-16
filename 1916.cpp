#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#define SIZE 1010
#define INF 2e9
using namespace std;

typedef struct Data {
	int x, y, cost;
}Data;

struct cmp {
	bool operator()(Data d1, Data d2) {
		return d1.cost > d2.cost;
	}
};

int dist[SIZE];
vector<Data> dijk[SIZE];
priority_queue<Data, vector<Data>, cmp> pq;

void fill_dist() {
	for (int i = 0; i < SIZE; i++)
		dist[i] = INF;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill_dist();
	int N, M; cin >> N >> M;

	for (int i = 0; i < M; i++) {
		Data here;
		cin >> here.x >> here.y >> here.cost;
		dijk[here.x].push_back(here);
	}

	int start, end; cin >> start >> end;

	Data s; s.x = start; s.y = end; s.cost = 0;
	dist[s.x] = 0;
	pq.push(s);

	while (!pq.empty()) {
		Data here = pq.top();
		pq.pop();

		for (auto n : dijk[here.x]) {
			Data next = n;
			if (dist[here.x] + next.cost < dist[next.y]) {
				dist[next.y] = dist[here.x] + next.cost;

				next.cost = dist[next.y];
				next.x = next.y;
				pq.push(next);
			}
		}
	}

	cout << dist[end];
}