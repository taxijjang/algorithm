#include<iostream>
#include<string>
#include<set>

using namespace std;
bool visited[10];
int N, M;
set<string> _set;
void dfs(string h_n,int len) {
	if (len == M) {
		_set.insert(h_n);
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == true)
			continue;
		string n_n = h_n + " " + to_string(i);
		visited[i] = true;
		dfs(n_n, len + 1);
		visited[i] = false;
	}
}
int main(void) {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		visited[i] = true;
		dfs(to_string(i),1);
		visited[i] = false;
	}

	for (auto it = _set.begin(); it != _set.end(); it++) {
		cout << *it << "\n";
	}
}