#include<iostream>
#define SIZE 110

using namespace std;

int arr[SIZE][SIZE];
int main(void) {
	ios::sync_with_stdio(false);

	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	int sum = 2 * N*M;

	//菊率

	for (int j = 1; j <= M; j++) {
		for (int i = N; i >= 1; i--) {
			sum += arr[i][j] - arr[i + 1][j] < 0 ? 0 : arr[i][j] - arr[i + 1][j];
		}
	}

	//第率
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			sum += arr[i][j] - arr[i - 1][j] < 0 ? 0 : arr[i][j] - arr[i - 1][j];
		}
	}

	//哭率
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			sum += arr[i][j] - arr[i][j - 1] < 0 ? 0 : arr[i][j] - arr[i][j - 1];
		}
	}

	//坷弗率
	for (int i = 1; i <= N; i++) {
		for (int j = M; j >= 1; j--) {
			sum += arr[i][j] - arr[i][j + 1] < 0 ? 0 : arr[i][j] - arr[i][j + 1];
		}
	}
	cout << sum;
}