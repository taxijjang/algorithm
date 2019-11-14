#include <iostream>
#include <vector>
#include<algorithm>
#define SIZE 60
#define INF 2e8


using namespace std;

int arr[SIZE][SIZE];

void fill_arr() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else
				arr[i][j] = INF;
		}
	}
}
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 1;

	fill_arr();
	int v_size = road.size();

	for (int i = 0; i < v_size; i++) {
		vector<int> r = road[i];
		arr[r[0]][r[1]] = min(arr[r[0]][r[1]],r[2]);
		arr[r[1]][r[0]] = min(arr[r[0]][r[1]],r[2]);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (arr[1][i] > 0 && arr[1][i] <= K)
			answer++;
	}
	return answer;
}

int main(void) {
	vector<vector<int>> road;
	int N; cin >> N;
	for (int i = 0; i <= N; i++) {
		int a, b, c; cin >> a >> b >> c;
		vector<int> r; 
		r.push_back(a);
		r.push_back(b);
		r.push_back(c);
		road.push_back(r);
	}
	int K; cin >> K;
	cout << solution(N, road, K);
}