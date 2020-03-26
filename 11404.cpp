#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstring>
#include<string>

#define SIZE 110
using namespace std;

int INF = 2e7;
int city[SIZE][SIZE];

void init() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i == j) {
				city[i][j] = 0;
				continue;
			}
			city[i][j] = INF;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	init();

	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		city[a][b] = min(city[a][b], c);
	}

	for (int k = 1; k <= N; k++) {

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)continue;
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << (city[i][j] == INF ? 0 : city[i][j]) << " ";
		}
		cout << "\n";
	}

}