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

#define SIZE 1010000
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int arr[1 << 22];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, S; cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[(1 << i)];
	}

	int cnt = 0;
	for (int i = 1; i <(1 << N); i++) {
		int sum = 0;
		for (int j = 0; (1 << j) <= i; j++) {
			if (i & (1 << j)) {
				sum += arr[(1 << j)];
			}
		}
		if (sum == S) {
			cnt++;
		}
	}
	cout << cnt;
}