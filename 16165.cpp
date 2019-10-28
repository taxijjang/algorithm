#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

map<string, string> n_g;
map<string, vector<string>> g_n;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string group; cin >> group;
		int people; cin >> people;
		vector<string> n;
		for (int j = 0; j < people; j++) {
			string name; cin >> name;
			n_g.insert({ name,group });
			n.push_back(name);
		}
		g_n.insert({ group,n });
	}

	for (int i = 0; i < M; i++) {
		string word; cin >> word;
		int num; cin >> num;
		if (num == 1) {
			cout << n_g[word] << "\n";
		}
		else {
			sort(g_n[word].begin(), g_n[word].end());
			for (auto it = g_n[word].begin(); it != g_n[word].end(); it++) {
				cout << *it << "\n";
			}
		}
	}
} 