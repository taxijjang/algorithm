#include<iostream>
#include<set>

using namespace std;

typedef long long int ll;
int main(void) {
	ios::sync_with_stdio(false);

	ll a, b, c; cin >> a >> b >> c;

	if (b >= c) {
		cout << -1;
		return 0;
	}

	cout << (a / (c - b))+1;
	return 0;

}