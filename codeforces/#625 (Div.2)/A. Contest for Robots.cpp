#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
 
#define SIZE 110
const int INF = 2e9;
using namespace std;
 
typedef long long int ll;
 
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int n; cin >> n;
 
	vector<int> r1;
	vector<int> r2;
 
	int r1_sum = 0;
	int r2_sum = 0;
 
	int r1_size = 0;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		r1.push_back(num);
		r1_sum += num;
	}
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		r2.push_back(num);
		r2_sum += num;
	}
 
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (r1[i] ==1 && r2[i]==1)
			cnt++;
	}
 
	if (cnt == n || r1_sum==0) {
		cout << -1;
		return 0;
	}
	
	cout << ((r2_sum - cnt) / (r1_sum - cnt)) + 1;
 
	return 0;
}