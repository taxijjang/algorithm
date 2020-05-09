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

#define SIZE 1010
const int INF = 20000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

set<string> _set;
deque<string> dq;

map<string, int> gem_check;
set<string> gem_set;

vector<int> solution(vector<string> gems) {
	int gems_size = gems.size();

	if (gems_size == 1) {
		return{ 1,1 };
	}

	for (auto gem : gems) {
		if (_set.find(gem) == _set.end()) {
			gem_check[gem] = 0;
		}
		_set.insert(gem);
	}

	int _set_size = _set.size();

	int left = 0;

	vector<int> res = { 0,gems_size-1 };
	int dis = INF;
	for (int right = 0; right < gems_size; right++) {
		dq.push_back(gems[right]);
		gem_check[gems[right]] ++;
		
		string left_gem = dq.front();
		gem_set.insert(gems[right]);

		if (gem_set.size() == _set_size) {
			if (res[1] - res[0] > right - left) {
				res = { left,right };
			}
		}

		while(gem_check[left_gem] - 1 > 0 && (gem_set.size() == _set_size)) {
			dq.pop_front();
			gem_check[left_gem]-=1;
			left++;

			if (res[1] - res[0] > right - left) {
				res = { left,right };
			}
			left_gem = dq.front();
		}
	}
	res[0] += 1; res[1]+=1;
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
	//vector<string> gems = { "ZZZ","YYY","NNNN","YYY","BBB" };
	//vector<string> gems = { "AA","AB","AC","AA","AC" };
	vector<string> gems = { "XYZ","XYZ","XYZ" };
	vector<int> res = solution(gems);

	cout << res[0] << res[1];

}