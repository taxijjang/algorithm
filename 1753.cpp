#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int INF = 300001;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> dijk[20001];

bool visited[20001];
int dist[20001];

int main(void) {
	int V, E;
	scanf("%d %d", &V, &E);

	int K;
	scanf("%d", &K);
	fill(dist, dist + 20001, INF); // 시작점인 K를 제외한 나머지 INF 채워줌
	dist[K] = 0; //초기상태

	int u, v, w;
	for (int e = 1; e <= E; e++) {
		scanf("%d %d %d", &u, &v, &w);
		dijk[u].push_back(pair<int, int>(v, w));
	}

	//priority queue의 pair는 first를 비교하고 second를 비교한다.
	//초기상태의 가중치를 pq에 푸쉬함
	pq.push(pair<int, int>(0, K));

	//pq가 없으면 끝남
	while (!pq.empty()) {
		int here;
		here = pq.top().second;
		pq.pop();

		for (auto a : dijk[here]) {
			//here정점의 이어진 간선
			int there = a.first;
			//here정점에서 there로 이어진 간선의 가중치
			int d = a.second;

			if (dist[here] + d < dist[there]) {
				dist[there] = dist[here] + d;
				pq.push(pair<int, int>((-1)*dist[there], there));
			}
		}
	}

	for (int v = 1; v <= V; v++) {
		if (dist[v] > 300000) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[v]);
		}
	}
	return 0;

}