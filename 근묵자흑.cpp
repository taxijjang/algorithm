#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

#define SIZE 110
const int INF = 2e9;
using namespace std;

typedef long long int ll;

vector<int> arr;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int num; cin >> num; arr.push_back(num);
	}

	int cnt = 0;
	for (int i = 0; i < arr.size() -1 ; i = i + K - 1) {
		cnt++;
	}

	cout << cnt;
	return 0;
}