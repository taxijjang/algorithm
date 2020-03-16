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

#define SIZE 10100
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int solution(vector<int> weight) {
	sort(weight.begin(), weight.end());

	if (weight[0] != 1) {
		return 1;
	}

	int ans = 1;
	for (int i = 0; i < weight.size(); i++) {
		if (ans >= weight[i]) ans += weight[i];
	}

	return ans;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> weights = { 1,1, };

	cout << solution(weights);
}