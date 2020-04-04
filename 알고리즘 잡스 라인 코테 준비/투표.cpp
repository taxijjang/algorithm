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

#define SIZE 200
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int arr[SIZE];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	int res = 0;
	for (int i = 0; i < N; i++) {
		int left, right; cin >> left >> right;

		for (int j = left;j  < right; j++) {
			arr[j]++;
			res = max(res, arr[j]);
		}
	}
	cout << res;

}