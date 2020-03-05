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

	//dp[here][visited] == -1 �̱� ������ �ִ밪�� INF�� �ٲپ� �ּҰ��� �������־�� �Ѵ�.
	res = INF;

	//0��°���� N-1 ��°���� ������ �湮 üŷ
	for (int next = 0; next < N; next++) {
		//next�� �湮������ ������ ��Ʈ�ڸ��� ������ �ֱ� ������ &���� �Ͽ� �湮 Ȯ��
		//here ���� next�� ������ �� �ڱ� �ڽ� -> �ڱ� �ڽ� ���� �湮 �ϴ� ������ Ȯ��
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