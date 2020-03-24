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


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K; cin >> N >> M >> K;

	string res = "";
	for (int i = 0; i < 2*K; i++) {
		for (int j = 0; j < 2; j++) {
			int n; cin >> n;
		}
	}

	for (int i = 0; i < M - 1; i++) {
		res += 'L';
	}
	for (int i = 0; i < N - 1; i++) {
		res += 'U';
	}

	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N-1; i++) {
			if (j % 2 == 0) {
				res = res + 'D';
			}
			else {
				res = res + 'U';
			}
		}
		if(j < M-1)
			res = res + 'R';
	}

	cout << res.size() << "\n" << res;
}