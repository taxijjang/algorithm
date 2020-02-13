#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#define INF 2e9
#define SIZE 110

using namespace std;

typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	vector<int> arr;
	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
	}

	for (int i = 0; i < N; i++) {
		if (M == 1) {
			cout << arr[i];
			cout << "\n";
		}

		else if (N == M) {
			for (auto a : arr)
				cout << a << " ";

			break;
		}
		else {
			for (int j = i; j < N; j++) {
				if (i == j) continue;
				cout << arr[i] << " " << arr[j];
				cout << "\n";
			}
		}
	}
}