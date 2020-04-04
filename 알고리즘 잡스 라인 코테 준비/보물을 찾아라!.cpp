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

#define SIZE 33
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int visited[SIZE][SIZE];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int check[SIZE][SIZE];
void init() {
	for (int i = 0; i < SIZE; i++) {
		check[i][0] = 1; check[0][i] = 1;
	}
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			check[i][j] = check[i - 1][j] + check[i][j - 1];
		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();

	int N, M; cin >> N >> M;
	int x, y; cin >> x >> y;

	if (x < 0 || x > N || y <0 || y >M || (x==0 && y==0)) {
		cout << "fail"; return 0;
	}
	
	cout << x + y << "\n" << check[x][y];
	return 0;
}