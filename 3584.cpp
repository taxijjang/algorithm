#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define MAX_DEPTH 20
#define SIZE 20000

using namespace std;

typedef long long int ll;

int parrent[SIZE][MAX_DEPTH];
int depth[SIZE];
vector<int> tree[SIZE];
bool root_find[SIZE];

void make_tree(int here) {
	for (auto next : tree[here]) {
		if (depth[next] == -1) {
			parrent[next][0] = here;
			depth[next] = depth[here] + 1;
			make_tree(next);
		}
	}
}

void fill() {
	for (int i = 0; i < SIZE; i++) {
		depth[i] = -1;
		root_find[i] = false;
		for (int j = 0; j < MAX_DEPTH; j++) {
			parrent[i][j] = -1;
		}
	}

	vector<int> emp[SIZE];
	swap(tree, emp);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		for (int i = 1; i < N; i++) {
			int v1, v2; cin >> v1 >> v2;
			root_find[v2] = true;
			tree[v1].push_back(v2);
			tree[v2].push_back(v1);
		}

		int root;
		for (int i = 1; i <= N; i++) {
			if (root_find[i] == false) {
				root = i;
				break;
			}
		}

		fill();
		depth[root] = 0;
		make_tree(root);

		for (int dep = 0; dep < MAX_DEPTH; dep++) {
			for (int node = 1; node < SIZE; node++) {
				if (parrent[node][dep] != -1)
					parrent[node][dep + 1] = parrent[parrent[node][dep]][dep];
			}
		}

		int n1, n2; cin >> n1 >> n2;

		if (depth[n1] < depth[n2]) swap(n1, n2);
		int diff = depth[n1] - depth[n2];

		for (int i = 0; diff; i++) {
			if (diff % 2 != 0)
				n1 = parrent[n1][i];
			diff /= 2;
		}

		if (n1 != n2) {
			for (int i = MAX_DEPTH - 1; i >= 0; i--) {
				if (parrent[n1][i] != -1 && parrent[n1][i] != parrent[n2][i]) {
					n1 = parrent[n1][i];
					n2 = parrent[n2][i];
				}
			}
			n1 = parrent[n1][0];
		}
		cout << n1 << "\n";
	}
}