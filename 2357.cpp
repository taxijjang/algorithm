#include<iostream>
#define SIZE 300000
#define INF 2e9
using namespace std;

int max_arr[SIZE];
int min_arr[SIZE];

int start_index(int N) {
	int size = 1;
	while (size <= N) {
		size *= 2;
	}

	return size;
}

void init(int last_index) {
	
	
	for (int i = last_index - 1; i > 0; i--) {
		max_arr[i / 2] = max_arr[i / 2] > max_arr[i] ? max_arr[i / 2] : max_arr[i];
		min_arr[i / 2] = min_arr[i / 2] < min_arr[i] ? min_arr[i / 2] : min_arr[i];
	}	
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M; cin >> N >> M;

	int start = start_index(N);
	for (int i = 0; i < SIZE; i++) {
		min_arr[i] = INF;
	}
	for (int i = start; i < N + start; i++) {
		cin >> max_arr[i];
		min_arr[i] = max_arr[i];
	}

	init(start * 2);

	

	
	for (int i = 0; i < M; i++) {
		int left, right; cin >> left >> right;

		left = left - 1 + start;
		right = right - 1 + start;

		int min = INF, max = 0;

		while (left <= right) {
			if (left % 2 == 1) {
				min = min_arr[left] < min ? min_arr[left] : min;
				max = max_arr[left] > max ? max_arr[left] : max;
				left++;
			}
			if (right % 2 == 0) {
				min = min_arr[right] < min ? min_arr[right] : min;
				max = max_arr[right] > max ? max_arr[right] : max;
				right--;
			}

			left /= 2; right /= 2;
		}
		cout << "\n          " <<  min << " " << max << "\n\n";
	}

	
	getchar();
}