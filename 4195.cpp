#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 201000

using namespace std;

typedef long long int ll;
int N;


int parrent[SIZE];
int num[SIZE];

void fill_p() {
	for (int i = 0; i <= 2 * N; i++) {
		parrent[i] = i;
		num[i] = 1;
	}
}

int find(int node) {
	if (parrent[node] == node)
		return node;
	else
		return parrent[node] = find(parrent[node]);
}
int _union(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot != bRoot) {
		parrent[aRoot] = bRoot;
		num[bRoot] += num[aRoot];
		num[aRoot] = 1;
	}
	return num[bRoot];

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int index = 1;
		map<string, int> m;
		cin >> N;

		fill_p();

		for (int i = 0; i < N; i++) {
			string s1, s2; cin >> s1 >> s2;

			if (m.count(s1) == 0)
				m[s1] = index++;
			if (m.count(s2) == 0)
				m[s2] = index++;

			cout << _union(m[s1], m[s2]) << "\n";
		}
		
	}

}