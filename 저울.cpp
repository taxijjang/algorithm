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

int prefix[SIZE];
map<int, bool> _map;
int solution(vector<int> weight) {
	sort(weight.begin(), weight.end());
	
	if (weight[0] != 1) {
		return 1;
	}

	prefix[0] = 1;
	for (int i = 1; i < weight.size(); i++) {
		prefix[i] = prefix[i - 1] + weight[i];

		if (prefix[i - 1] < weight[i])
			return prefix[i] + 1;
	}

	return prefix[weight.size()-1]+ 1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> weights = { 1,2,3};

	cout << solution(weights);
}