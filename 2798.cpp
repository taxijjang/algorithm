#include<iostream>
#include<set>

using namespace std;

int arr[110];

set<int> s;
int N, M;
void dfs(int h,int len, int sum) {
	if (len == 0) {
		s.insert(sum);
		return;
	}

	for (int i = h; i < N; i++) {
		if (sum + arr[i] > M)
			continue;
		sum += arr[i];
		dfs(i + 1, len-1, sum);
		sum -= arr[i];
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i <= N - 2; i++) {
		dfs(i, 3, 0);
	}

	cout << *s.rbegin();
}