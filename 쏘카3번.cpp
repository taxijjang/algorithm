#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

map<string, set<string>> _map;
map<string, int> cnt;

int max_cnt = 0;
void dfs(string name, map<string,bool> visited) {
	visited[name] = true;

	for (auto fri : _map[name]) {
		if (visited[fri] == true)
			continue;

		cnt[fri]++;
		max_cnt = max(cnt[fri], max_cnt);
		dfs(fri, visited);
		visited[fri] = false;
	}
}
vector<string> solution(vector<vector<string>> freinds, string user_id) {
	int f_size = freinds.size();

	for (int i = 0; i < f_size; i++) {
		vector<string> f = freinds[i];
		string f1 = f[0];
		string f2 = f[1];
		_map[f1].insert(f2);
		_map[f2].insert(f1);

		cnt[f1] = 0;
		cnt[f2] = 0;
	}

	map<string, bool> visited;
	visited[user_id] = true;
	for (auto fri : _map[user_id]) {
		visited[fri] = true;
	}

	for (auto fri : _map[user_id])
		dfs(fri, visited);
	vector<string> answer;
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		if (it->second == max_cnt)
			answer.push_back(it->first);
	}
	sort(answer.begin(),answer.end());

	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<string>> f;

	int n; cin >> n; 
	for (int i = 0; i < n; i++) {
		string a, b; cin >> a >> b;
		vector<string> v;
		v.push_back(a);
		v.push_back(b);

		f.push_back(v);
	}

	string u; cin >> u;
	vector<string> res = solution(f, u);
}