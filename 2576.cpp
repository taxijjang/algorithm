#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int min_num = INF;
	int sum = -1;
	for (int i = 0; i < 7; i++) {
		int num; cin >> num;
		if (num % 2 == 1) {
			sum += num;
			min_num = min(min_num, num);
		}
	}

	if (sum == -1)
		cout << -1;
	else {
		cout << sum + 1 << "\n" << min_num;
	}



}