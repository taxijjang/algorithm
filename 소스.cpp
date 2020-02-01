#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define SIZE 1010

using namespace std;

typedef long long int ll;

const int INF = 2000000000;

map<char, int> _map;
priority_queue<int> pq;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		int zari = 1;
		
		for (auto it = s.rbegin(); it != s.rend(); it++) {
			if (_map.find(*it) == _map.end())
				_map[*it] = zari;
			else
				_map[*it] += zari;
			zari *= 10;
		}
	}

	for (auto it = _map.begin(); it != _map.end(); it++) {
		pq.push(it->second);
	}

	int num = 9, sum = 0;
	while (!pq.empty()) {
		sum += pq.top() * num--;
		pq.pop();
	}

	cout << sum;
	
}