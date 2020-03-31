#include<iostream>
#include<vector>
#include<algorithm>

#define SIZE 15
using namespace std;

int arr[SIZE];
int main(void) {
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> idx(N, 0);

	for (int i = N - 1; i >= N - 4; i--) {
		idx[i] = 1;
	}

	int res = 0;
	do {
		vector<int> list;
		for (int i = 0; i < N; i++) {
			if (idx[i] == 1)
				list.push_back(i);
		}

		int left = -1, right, tmp = 0;

		for (auto l : list) {
			int t = 1;
			for (int i = left + 1; i <= l; i++) {
				t *= arr[i];
			}
			left = l;
			tmp += t;
		}

		res = max(res, tmp);
	} while (next_permutation(idx.begin(), idx.end()));

	cout << res;
}