#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int arr[SIZE][SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int R, C, Q; cin >> R >> C >> Q;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
		}
	}
	for (int j = 1; j <= C; j++) {
		for (int i = 2; i <= R; i++) {
			arr[i][j] += arr[i - 1][j];
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 2; j <= C; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}

	for (int q = 1; q <= Q; q++) {
		int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

		int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);

		int sum = arr[r2][c2] - arr[r2][c1 - 1] - arr[r1 - 1][c2] + arr[r1-1][c1-1];

		cout << sum / cnt << "\n";
		getchar();
	}
}