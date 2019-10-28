#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

vector<int> v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cout << v[N - 1] - v[0];

}