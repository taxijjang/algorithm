1번
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int t; cin >> t;
	for (int T = 0; T < t; T++) {
		int n; cin >> n;
		int arr[110];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		int res = sum / n;
		res = res*n < sum ? res + 1 : res;

		cout << res << '\n';
	}
}