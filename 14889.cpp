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

#define SIZE 22
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int board[SIZE][SIZE];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<int> man;
	vector<int> idx;
	for (int i = 1; i <= N; i++) {
		man.push_back(i);
		if (i > N / 2)
			idx.push_back(1);
		else
			idx.push_back(0);
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	int res = INF;
	do {
		vector<int> start; // 0
		vector<int> link; // 1
		for (int i = 0; i < N; i++) {
			if (idx[i] == 0) { //start
				start.push_back(man[i]);
			}
			else { //link
				link.push_back(man[i]);
			}
		}

		int total_start = 0;
		int total_link = 0;

		for (int i = 0; i < N/2; i++) {
			for (int j = 0; j < N/2; j++) {
				total_start += board[start[i]][start[j]];
				total_link += board[link[i]][link[j]];
			}
		}

		res = min(res, abs(total_start - total_link));
	} while (next_permutation(idx.begin(), idx.end()));

	cout << res;
}