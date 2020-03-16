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

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

priority_queue<pair<int,int>> pq;
int solution(vector<vector<int>> routes) {
	for (int i = 0; i < routes.size(); i++) {
		pq.push(make_pair(-routes[i][1], routes[i][0]));
	}

	pair<int, int> start = pq.top(); pq.pop();
	int cnt = 1;
	while (!pq.empty()) {
		pair<int, int> next = pq.top(); pq.pop();

		if (-start.first < next.second) {
			cnt++;
			start = next;
		}
	}
	getchar();
	int answer = 0;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> routes = {
		{-20,15}, {-14,-5},{-18,-13},{-5,-3}
	};

	cout << solution(routes);
}