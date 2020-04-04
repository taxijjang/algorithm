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
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

vector<int> arr;
vector<string> res;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		int num; cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	do {
		string r = "";
		for (auto a : arr) {
			r += to_string(a);
		}
		res.push_back(r);
	} while (next_permutation(arr.begin(), arr.end()));

	sort(res.begin(), res.end());
	int K; cin >> K;

	for (auto r : res[K - 1]) {
		cout << r << " ";
	}
}