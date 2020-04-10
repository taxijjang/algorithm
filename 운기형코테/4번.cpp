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
typedef pair<int, int> pii;

pair<int,int> pre;
map<int, int> check;

int time;
int divisor(int num) {
	time = 0;
	int cnt = 0;
	int sqrt_num = sqrt(num);
	for (int i = 1; i <= sqrt_num; i++) {
		if (num % i == 0) {
			cnt += 2;
		}
		time++;
	}

	if (sqrt_num* sqrt_num == num)
		cnt--;
	return cnt;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	pre = { 1,1 };
	check[1] = 1;
	int cnt = 0;
	for (int i = 2;; i++) {
		int here_num = pre.first + i;

		int here_divisor = divisor(here_num);

		pre = { here_num, here_divisor };
		check[here_num] = here_divisor;
		cnt = cnt + 1 + time;
		if (pre.second >= 500) {
			cout << pre.first << "\n" << cnt;
			return 0;
		}	
	}
}