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

map<int, int> _map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		if (_map.find(n) == _map.end())
			_map[n] = 1;
		else
			_map[n]++;
	}

	int M; cin >> M;

	for (int i = 0; i < M; i++) {
		int n; cin >> n;

		if (_map.find(n) == _map.end())
			cout << "0 ";
		else
			cout << _map[n] << " ";
	}

}