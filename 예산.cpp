#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 1e9
#define SIZE 110000

using namespace std;

typedef long long int ll;

int solution(vector<int> budgets, int M) {
	sort(budgets.begin(), budgets.end());
	int left = budgets.size() , right = budgets.back(), mid;
	int answer = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		int sum = 0, cnt = 0;
		for (auto b : budgets) {
			if (b <= mid) {
				sum += b;
			}
			else if (b > mid) {
				sum += mid;
			}
		}

		if (sum <= M) {
			left = mid + 1;
			answer = max(answer,mid);
		}
		else {
			right = mid - 1;	
		}
	}

	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> b;
	for (int i = 0; i < 4; i++) {
		int cost; cin >> cost;
		b.push_back(cost);
	}

	int M; cin >> M;

	cout << solution(b, M);
	return 0;
}