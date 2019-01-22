#include <iostream>
#include <vector>
#include <utility>
#define MAX 510

using namespace std;

vector <pair<int, int>> city[MAX];

int dist[MAX];
int INF = 999999999;
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	int a, b, c;
	for (int m = 1; m <= M; m++) {
		scanf("%d %d %d", &a, &b, &c);
		city[a].push_back(pair<int, int>(b, c));
	}

	//dist √ ±‚»≠
	int start = 1;
	fill(dist, dist + 502, INF);
	dist[start] = 0;

	bool judge = false;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[j] == MAX)
				continue;
			for (auto a : city[j]) {
				int there = a.first;
				int thereCost = a.second;
				if (dist[there] > dist[j] + thereCost) {
					dist[there] = dist[j] + thereCost;
					if (i == N) {
						judge = true;
					}
				}
			}
		}
	}
	if (judge) {
		printf("-1");
		return 0;
	}

	for (int n = 2; n <= N; n++) {
		if (dist[n] >= INF) {
			printf("-1\n");
		}
		else {
			if (dist[n] < INF) {
				printf("%d\n", dist[n]);
			}
		}
	}
	
		

	return 0;
}