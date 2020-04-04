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

priority_queue<int,vector<int>,greater<int>> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;

	for (int i = 0; i < K; i++) {
		pq.push(0);
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		int time; cin >> time;
		int top = pq.top() + time; pq.pop();
		res = max(top, res);
		pq.push(top);
	}

	cout << res;
}