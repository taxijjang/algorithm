#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

#define SIZE 100010
const int INF = 2e9;
using namespace std;

typedef long long int ll;

//움직인 횟수 , 위치에 도착 할수 있는 경우의 수
pair<int,int> v[SIZE];
queue<int> q;

int move(int here, int d) {
	if (d == 0) {
		return here-1;
	}
	else if (d == 1) {
		return here+1;
	}
	else if (d == 2) {
		return here * 2;
	}
}

void init() {
	for (int i = 0; i < SIZE; i++) {
		v[i].first = INF;
		v[i].second = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();
	int N, K; cin >> N >> K;

	if (N == K) {
		cout << 0 <<"\n"<< N;
		return 0;
	}

	q.push(N);
	v[N].first = 0;

	while (!q.empty()) {
		int h = q.front(); q.pop();
		
		for (int d = 0; d < 3; d++) {
			int n = move(h, d);

			//수빈이의 다음 위치
			if (n < 0 || n > 100000)
				continue;

			//수빈이가 가고 하는 위치 비교
			if (v[n].first > v[h].first + 1) {
				q.push(n);
				v[n].first = v[h].first + 1;
				v[n].second = h;

			}
		}

	}

	int index = K;
	vector<int> res;
	res.push_back(index);

	while (1) {
		int previous = v[index].second;
		res.push_back(previous);
		if (previous == N)
			break;
		index = previous;
	}
	cout << v[K].first << "\n";
	for (auto it = res.rbegin(); it != res.rend(); it++) {
		cout << *it << " ";
	}
	
	return 0;
}