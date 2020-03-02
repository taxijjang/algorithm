#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
 
#define SIZE 1010
const int INF = 2000000000;
 
using namespace std;
 
typedef long long int ll;
 
 
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T; cin >> T;
 
	while (T--) {
		int n; cin >> n;
		int odd_cnt = 0;
		for(int i =0 ; i <n;i++) {
			int num; cin >> num;
			if (num % 2 == 1)
				odd_cnt++;
			
		}
		if ((n % 2 == 0 && odd_cnt == n) || odd_cnt==0)
			cout << "NO\n";
		else {
			cout << "YES\n";
		}
	}
}