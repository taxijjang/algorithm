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

typedef struct Data {
	int j = 0, o = 0, i = 0;

	Data operator - (Data d) {
		Data n; n.j = j -d.j; n.o =o - d.o; n.i = i -d.i;
		return n;
	}
	Data operator +(Data d) {
		Data n; n.j = d.j + j; n.o = d.o + o; n.i = d.i + i;
		return n;
	}
}Data;
char board[SIZE][SIZE];
Data arr[SIZE][SIZE];
Data dp[SIZE][SIZE];

void check(char what , Data &d ) {
	if (what == 'J') {
		d.j++;
	}
	else if (what == 'O')
		d.o++;
	else if (what == 'I')
		d.i++;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K; cin >> N >> M >> K;

	//정글 J , 바다 O, 얼음 I
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			check(board[i][j], arr[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j];
		}
	}
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			arr[i][j] = arr[i][j - 1] + arr[i][j];
		}
	}

	
	for (int i = 0; i < K; i++) {
		//a b 왼쪽 상단  c d 오른쪽 하단
		int a, b, c, d; cin >> a >> b >> c >> d;

		Data res = arr[c][d] + arr[a - 1][b - 1] - arr[c][b-1] - arr[a - 1][d] ;

		cout << res.j << " " << res.o << " " << res.i << "\n";
	}
}