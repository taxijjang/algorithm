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
	fill(dist, dist + 20001, INF); // �������� K�� ������ ������ INF ä����
	dist[K] = 0; //�ʱ����

	int u, v, w;
	for (int e = 1; e <= E; e++) {
		scanf("%d %d %d", &u, &v, &w);
		dijk[u].push_back(pair<int, int>(v, w));
	}

	//priority queue�� pair�� first�� ���ϰ� second�� ���Ѵ�.
	//�ʱ������ ����ġ�� pq�� Ǫ����
	pq.push(pair<int, int>(0, K));

	//pq�� ������ ����
	while (!pq.empty()) {
		int here;
		here = pq.top().second;
		pq.pop();

		for (auto a : dijk[here]) {
			//here������ �̾��� ����
			int there = a.first;
			//here�������� there�� �̾��� ������ ����ġ
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