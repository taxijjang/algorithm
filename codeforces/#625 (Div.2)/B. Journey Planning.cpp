#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
 
#define SIZE 200100
const int INF = 2000000000;
using namespace std;
 
typedef long long int ll;
 
ll arr[SIZE];
map<int, ll> _map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int n; cin >> n;
 
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
 
		_map[arr[i]-i] += arr[i];
	}
 
	ll res = 0;
	for (auto m : _map) {
		res = max(res, m.second);
	}
 
	cout << res;
 
	return 0;
}