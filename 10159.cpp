#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e8
#define SIZE 110

using namespace std;

typedef long long int ll;

int arr[SIZE][SIZE];
int cnt[SIZE];

void fill() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			i == j ? arr[i][j] = 0 : arr[i][j] = INF;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fill();

	int N, M; cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int big, small; cin >> big >> small;
		arr[big][small] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (0 <= arr[i][j] && arr[i][j] < INF) {
				cnt[i]++; cnt[j]++;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << N - (cnt[i] - 1) << "\n";
	}
}
