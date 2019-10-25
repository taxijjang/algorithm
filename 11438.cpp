#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define MAX_DEPTH 20
#define SIZE 101010

using namespace std;

typedef long long int ll;

int parrent[SIZE][MAX_DEPTH];
int depth[SIZE];
vector<int> tree[SIZE];

void fill() {
	for (int i = 0; i < SIZE; i++) {
		depth[i] = -1;
		for (int j = 0; j < MAX_DEPTH; j++) {
			parrent[i][j] = -1;
		}
	}
}

void make_tree(int here) {
	for (auto next : tree[here]) {
		if (depth[next] == -1) {
			parrent[next][0] = here;
			depth[next] = depth[here] + 1;
			make_tree(next);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int n = 0; n < N-1; n++) {
		int u, v; cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	fill();
	depth[1] = 0;

	make_tree(1);

	for (int dep = 0; dep < MAX_DEPTH; dep++) {
		for (int node = 1; node < SIZE; node++) {
			if (parrent[node][dep] != -1)
				parrent[node][dep + 1] = parrent[parrent[node][dep]][dep];
		}
	}

	int query; cin >> query;
	for (int q = 0; q < query; q++) {
		int u, v; cin >> u >> v;

		if (depth[u] < depth[v])
			swap(u, v);
		int diff = depth[u] - depth[v];

		for (int i = 0; diff; i++) {
			if (diff % 2 != 0)
				u = parrent[u][i];
			diff /= 2;
		}

		if (u != v) {
			for (int dep = MAX_DEPTH - 1; dep >= 0; dep--) {
				if (parrent[u][dep] != -1 && parrent[u][dep] != parrent[v][dep]) {
					u = parrent[u][dep];
					v = parrent[v][dep];
				}
			}
			u = parrent[u][0];
		}

		cout << u << "\n";

	}

}