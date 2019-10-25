#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 50500
#define MAX_DEPTH 20
using namespace std;

typedef long long int ll;

vector<int> tree[SIZE];
int parrent[SIZE][MAX_DEPTH];
int depth[SIZE];

// parrent , depth�� -1�� �ʱ�ȭ
void fill() {
	for (int i = 0; i < SIZE; i++) {
		depth[i] = -1;
		for (int j = 0; j < MAX_DEPTH; j++) {
			parrent[i][j] = -1;
		}
	}
}

//Ʈ���� ���� �ϱ�
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

	// 1. Ʈ���� �����(parrent[curr][0]�� ä����, depth[u]���� ä���ش�.
	// 2. 2�� �ݺ����� �̿��Ͽ� parrent[u][2^k]�� ä���ش�
	// 3. ������ �ִ� ���� ������ ���Ѵ�
	// 4. �Է����� ���� depth[u] �� depth[v]�� �ٸ���� ���� ������ش�
	// 5. depth�� ���� ���� �� �θ� �ٸ���� �� ���� dpeth���� ��Ʈ��� ���� �θ� ���� �ش�

	int N; cin >> N;
	for (int n = 0; n < N - 1; n++) {
		int u, v; cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	fill();
	//��Ʈ����� ���� �� 0 �̴�
	depth[1] = 0;

	//Ʈ���� ���� �ϱ�
	make_tree(1);

	//parrent[u][k]�� ä���
	for (int dep = 0; dep < MAX_DEPTH; dep++) {
		for (int node = 1; node < SIZE; node++) {
			if (parrent[node][dep] != -1) {
				parrent[node][dep + 1] = parrent[parrent[node][dep]][dep];
			}
		}
	}

	//query �Է�

	int query; cin >> query;
	for (int q = 0; q < query; q++) {
		int u, v; cin >> u >> v;

		//depth[u] >= depth[v] �� ����� �ֱ� ����
		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		//������ 
		for (int i = 0; diff; i++) {
			if (diff % 2 != 0)
				u = parrent[u][i];
			diff /= 2;
		}

		if (u != v) {
			for (int i = MAX_DEPTH - 1; i >= 0; i--) {
				if (parrent[u][i] != -1 && parrent[u][i] != parrent[v][i]) {
					u = parrent[u][i];
					v = parrent[v][i];
				}
			}
			u = parrent[u][0];
		}

		cout << u << "\n";
	}

}