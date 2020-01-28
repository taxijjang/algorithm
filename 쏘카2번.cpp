#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 101000

using namespace std;

typedef long long int ll;

const int MAX = 2020202;
vector<int> road[SIZE];
bool visited[SIZE];

int dfs(int here) {
	int dest = here;
	if (road[here+1].size() != 0) {
		if (road[here + 1][0] == here && visited[here+1] != true)
			return MAX;
	}

	visited[here] = true;

	for (auto next : road[here]) {
		dest = dfs(next);
	}
		
	return dest;
}
vector<int> solution(vector<vector<int>> paths) {
	int end = 0;
	for (auto path : paths) {
		road[path[0]].push_back(path[1]);
		end = max(end, max(path[0], path[1]));
	}

	vector<int> answer;

	for (int i = 1; i <= end; i++) {
		if (road[i].size() != 0 && visited[i] != true) {
			int tmp = dfs(i);
			if (tmp != MAX) {
				answer.push_back(i);
				answer.push_back(tmp);
			}
			
		}
	}
	
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		vector<int> root;
		root.push_back(a);
		root.push_back(b);
		v.push_back(root);
	}

	vector<int> res = solution(v);
}