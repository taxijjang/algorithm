#include <iostream>
#include <cstring>
using namespace std;

int work(int y, int x);

int mountin[501][501];
int cache[501][501];
int X[4] = { 0,0,-1,1 };
int Y[4] = { 1,-1.0,0 };
int N, M;
int high = 10001;
int cnt = 0;
int main(void) {
	cin >> N >> M;
	memset(cache, -1, sizeof(cache));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> mountin[n][m];
		}
	}

	cout << work(0, 0);
}

int work(int y, int x) {
	if (cache[y][x] != -1) {
		return cache[y][x];
	}
	if (y >= N || x >= M || y < 0 || x < 0) {
		return 0;
	}
	if (y == N - 1 && x == M - 1) {
		cnt++;
		return 1;
	}

	cache[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		if (mountin[Y[i] + y][X[i] + y] > mountin[y][x]) {
			cache[y][x] += work(Y[i] + y, X[i] + x);
		}
	}
	return cache[y][x];

}