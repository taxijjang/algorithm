#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 20
const int INF = 987654321;

using namespace std;

typedef long long int ll;

int W[SIZE][SIZE];
ll dp[SIZE][1 << 18];
int N;

ll TSP(int here, int visited) {
	if (visited == (1 << N) - 1) {
		if (W[here][0] != 0)
			return W[here][0];
		return INF;
	}
	
	ll &res = dp[here][visited];
	
	if (res != -1)
		return res;

	//dp[here][visited] == -1 이기 때문에 최대값인 INF로 바꾸어 최소값을 갱신해주어야 한다.
	res = INF;

	//0번째부터 N-1 번째까지 돌려서 방문 체킹
	for (int next = 0; next < N; next++) {
		//next가 방문한점이 있으면 비트자리가 같은게 있기 때문에 &연산 하여 방문 확인
		//here 에서 next가 같은점 즉 자기 자신 -> 자기 자신 으로 방문 하는 점인지 확인
		if (visited & (1 << next) || W[here][next] == 0)
			continue;
		res = min(res, TSP(next, visited | (1 << next)) + W[here][next]);
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	ll res = TSP(0, 1);
	cout << res << "\n";

	return 0;
}