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

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

map<int, int> _map;

void init() {
	_map[29900] = 300; _map[34900] = 1000; _map[39900] = 2000;
	_map[49900] = 6000; _map[59900] = 11000; _map[69900] = INF;

}

int H_cost(int cost, int use) {
	int res = 0;

	if (_map[cost] < use) {
		int use_gap = use - _map[cost];
		if (use_gap >= 5000) {
			res += use_gap * 20;
		}
		else if (use_gap < 5000) {
			if (use_gap * 20 >= 25000)
				res += 25000;
			else
				res += use_gap * 20;
		}
	}
	return res >= 180000 ? cost + 180000 : cost + res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();
	
	int cost, use; cin >> cost >> use;

	int r_cost, h_cost, r_res = INF;
	for (auto _m : _map) {
		int ccost = H_cost(_m.first, use);
		if (r_res > ccost) {
			r_cost = _m.first;
			r_res = ccost;
		}
	}

	cout << r_cost << " " << H_cost(cost, use) << " " << r_res;
	//cout << H_cost(cost,use);
}