#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		vector<int> arr;
		int a, b, c, n; cin >> a >> b >> c >> n;
		arr = { a,b,c };

		sort(arr.begin(), arr.end());

		int ab = arr[1] - arr[0];
		int bc = arr[2] - arr[1];

		n -= ab + bc * 2;

		if (n < 0 || n % 3 != 0)
			cout << "NO\n";
		else
			cout << "YES\n";

	}
}