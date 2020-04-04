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

#define SIZE 20010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int arr[SIZE];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<int> index;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			index.push_back(i);
		}
	}
	int res = max(res, max(index[0] - 1, N - index.back()));

	if (index.size() >= 2) {
		for (int i = 1; i < index.size(); i++) {
			res = max(res, (index[i] - index[i - 1]) / 2);
		}
	}

	cout << res;
}