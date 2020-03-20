#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>
#include<stack>

#define SIZE 55
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

map<char, int> _map[SIZE];

bool word_cmp(string here, string next, int index) {
	int cnt = 0;
	for (int i = 0; i < here.size(); i++) {
		if (here.at(i) == next.at(i))
			cnt++;
	}

	if (cnt == here.size() -1)
		return true;
	else
		return false;
}
queue < pair<string, int> >q;
map<pair<string, string>, bool> visited;

int solution(string begin, string target, vector<string> words) {
	pair<string, int> start(begin, 0);

	int answer = 0;
	q.push(start);
	while (!q.empty()) {
		pair<string, int> h = q.front(); q.pop();

		for (int i = 0; i < words.size(); i++) {
			pair<string, int > n(words[i], h.second + 1);

			if (!word_cmp(h.first, n.first, i)) {
				continue;
			}
			
			if (visited[make_pair(h.first, n.first)] == true)
				continue;

			if (words[i] == target)
				return n.second;


			q.push(n);
			visited[make_pair(h.first, n.first)] = true;
		}

		
	}
	
	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string begin = "hit", target = "cog";
	vector<string> words = { "hot","dot","dog","lot","log","cog" };

	cout << solution(begin, target, words);
}