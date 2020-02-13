#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<unordered_set>
#define SIZE 550

using namespace std;

typedef long long int ll;
typedef struct Data {
	int x, y, w;
}Data;

const int INF = 2000000000;
int dis[SIZE];
int N, M;
vector<pair<int, int>> arr[SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(dis, dis + SIZE, INF);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;

		arr[a].push_back(make_pair(b, c));
	}


	dis[1] = 0;

	bool cycle = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto e : arr[j]) {
				int b, c;
				tie(b, c) = e;
				if (dis[j] != INF && dis[b] > dis[j] + c) {
					dis[b] = dis[j] + c;
					if (i == N) cycle = true;
				}
			}
		}

	}

	if (cycle)
		cout << -1;
	else
		for (int i = 2; i <= N; i++) {

			cout << (dis[i] == INF ? -1 : dis[i]) << "\n";
		}

}