#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 110

using namespace std;

typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int res = 0;
	for (int i = 0; i < 5; i++) {
		int a; cin >> a;
		res += (a * a);
	}

	cout << res % 10;
	return 0;
}