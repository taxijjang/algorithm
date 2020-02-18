#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define SIZE 110
const int INF = 2e9;
using namespace std;

typedef long long int ll;

priority_queue<int,vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
	for (auto s : scoville) {
		pq.push(s);
	}

	int mix = 0;
	int res = 0;
	while (pq.top() < K) {
		if (pq.size() == 1) {
			cout << -1;
			return 0;
		}
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		mix = a + (b * 2);
		pq.push(mix);
		res++;
	}
	
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> sc;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		sc.push_back(num);
	}

	int K; cin >> K;

	cout << solution(sc, K);
	return 0;
}