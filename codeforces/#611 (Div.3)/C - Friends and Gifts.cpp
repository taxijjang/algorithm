#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 200010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int arr[SIZE];
int dp[2][SIZE];

deque<int> out, in;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int OUT = 0;
	int IN = 1;

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] != 0) {
			dp[OUT][i] = arr[i];
			dp[IN][arr[i]] = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dp[OUT][i] == 0 && dp[IN][i] == 0)
			out.push_front(i);
		else if (dp[OUT][i] == 0)
			out.push_back(i);

		if (dp[IN][i] == 0)
			in.push_back(i);
	}

	while (!out.empty()) {
		int o_num = out.front();
		out.pop_front();

		do {
			if (o_num == in.front()) {
				in.push_back(in.front());
				in.pop_front();
			}
			else if (o_num != in.front()) {
				dp[OUT][o_num] = in.front();
				in.pop_front();
				break;
			}
		} while (1);
	}


	for (int i = 1; i <= n; i++) {
		cout << dp[OUT][i] << " ";
	}


}