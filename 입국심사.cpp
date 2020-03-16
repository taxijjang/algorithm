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
typedef unsigned long long ull;
long long solution(int n, vector<int> times) {

	//시간을 기준
	ll left = 1, right = 1844674407370955161, mid;

	while (left <= right) {
		mid = (left + right) / 2;

		ll human = 0;
		for (auto time : times) {
			human += mid / (ll)time;

			if (human >= n)
				break;
		}

		if (human >= n) {
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	
	return right +1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 6;
	vector<int> times = { 7,10};

	cout << solution(n, times);

}