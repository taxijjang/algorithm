#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define SIZE 1010

using namespace std;

typedef long long int ll;

const int INF = 2000000000;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n; cin >> n;

	while (1) {
		cout << n << " ";
		if (n == 1) break;
		else if (n % 2 == 1)n = (n * 3) + 1;
		else n /= 2;
	}
	cout << "\n";
}