#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 100

using namespace std;

typedef long long int ll;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int arr[SIZE];
int tmp_arr[SIZE];
int visited[SIZE];

vector<int> idl;
queue<int> bi;

void copy_arr(queue<int> wall) {
	for (int i = 0; i < SIZE; i++) {
		tmp_arr[i] = arr[i];
		visited[i] = false;
	}

	while (!wall.empty()) {
		tmp_arr[wall.front()]= 1;
		wall.pop();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	for (int i = 0; i < N*M; i++) {
		cin >> arr[i];
		if (arr[i] == 2)
			bi.push(i);
	}

	idl.assign(N*M, 0);

	for (int i = N*M - 3; i < M*N; i++)
		idl[i] = 1;

	int res = 0;
	do {
		bool check = false;
		queue<int> wall;
		for (int i = 0; i < N*M; i++) {
			if (idl[i] == 1) {
				if (arr[i] != 0) {
					check = true;
					break;
				}
				wall.push(i);
			}
		}

		if (check)
			continue;

		copy_arr(wall);

		queue<int> virus = bi;
		
		while (!virus.empty()) {
			int h = virus.front();
			int h_x = h / M;
			int h_y = h % M;
			tmp_arr[h] = 2;

			visited[h] = true;
			virus.pop();
			for (int i = 0; i < 4; i++) {
				int n_x = h_x + dx[i];
				int n_y = h_y + dy[i];

				if (n_x < 0 || n_y < 0 || n_x >= N || n_y >= M)
					continue;
				if (visited[n_x*M + n_y%M ])
					continue;
				if (tmp_arr[n_x*M + n_y%M] != 0)
					continue;

				visited[n_x*M + n_y%M] = true;
				virus.push(n_x*M + n_y % M);
			}
		}

		int cnt = 0;
		for (int i = 0; i < N*M; i++) {
			if (tmp_arr[i] == 0)
				cnt++;
		}
		res = res < cnt ? cnt : res;
	} while (next_permutation(idl.begin(), idl.end()));

	cout << res;
}