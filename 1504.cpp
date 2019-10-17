#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#define SIZE 810
#define INF 2e10

using namespace std;

typedef long long int ll;
typedef struct Data {
	ll x, y, cost;
}Data;

struct cmp{
	bool operator()(Data d1, Data d2) {
		return d1.cost < d2.cost;
	}
};

ll dist[SIZE];
vector<Data> dijk[SIZE];
priority_queue<Data, vector<Data>, cmp> pq;

void fill_dist() {
	for (int i = 0; i < SIZE; i++)
		dist[i] = INF;
}
ll calc(int start, int end) {
	fill_dist();
	dist[start] = 0;

	Data s; s.x = start; s.y = end; s.cost = 0;
	pq.push(s);

	while (!pq.empty()) {
		Data here = pq.top();
		pq.pop();

		for (auto n : dijk[here.x]) {
			Data next = n;
			if (dist[here.x] + next.cost < dist[next.y]) {
				dist[next.y] = dist[here.x] + next.cost;
				next.x = next.y;
				pq.push(next);
			}
		}
	}

	return dist[end];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, E; cin >> N >> E;

	for (int i = 0; i < E; i++) {
		Data here;
		cin >> here.x >> here.y >> here.cost;
		dijk[here.x].push_back(here);
		int tmp = here.y;
		here.y = here.x;
		here.x = tmp;
		dijk[tmp].push_back(here);
	}

	int point1, point2; cin >> point1 >> point2;

	// 1-> point 1 -> point 2 -> end; route1
	// 1-> point 2 -> point 1 -> end; route2

	ll route1, route2;
	route1 = calc(1, point1);
	route1 += calc(point1, point2);
	route1 += calc(point2, N);

	route2 = calc(1, point2);
	route2 += calc(point2, point1);
	route2 += calc(point1, N);

	if (route1 >= INF && route2 >= INF)
		route1 = -1;
	cout << (route1 < route2 ? route1 : route2);
}