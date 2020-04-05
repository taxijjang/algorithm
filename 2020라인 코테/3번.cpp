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

#define SIZE 300010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int dp[SIZE];

void init() {
	for (int i = 1; i < SIZE; i++) {
		dp[i] = i;
	}
}
int solution(string road, int n) {
	int road_size = road.size();
	int res = 0;
	vector<int> zero_index = { 0 };
	int cnt = 0;
	for (int i = 0; i < road_size; i++) {
		dp[i] = i;
		if (road[i] == '1')
			cnt++;
		else if (road[i] == '0') {
			zero_index.push_back(i + 1);
			res = max(res, cnt);
			cnt = 0;
		}
	}

	zero_index.push_back(road_size);
	int zero_size = zero_index.size();
	if (n >= zero_size -2) {
		return road_size;
	}

	if (n == 0 ) {
		return res;
	}

	for (int i = 0; i < zero_size - n -1 ; i++) {
		int len = zero_index[i + n +1 ] - zero_index[i] -1 ;
		res = max(res, len);
	}

	return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string road = "11111000001111";
	//string road = "11101111111";
	//string road = "11001";
	int n = 3;
	cout << solution(road, 3);
}