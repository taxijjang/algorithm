#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 100100

using namespace std;

typedef long long int ll;

int arr[SIZE];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	if (K == 1) {
		cout << sum;
		return 0;
	}

	int left = 1, right = sum + 1, mid;

	int res = INF;
	while (left <= right) {
		mid = (left + right) / 2;

		int group_cnt = 1;
		int group_sum = 0;
		int m_n = INF;
		for (int i = 0; i < N; i++) {
			if (group_sum < mid) {
				group_sum += arr[i];
			}
			else {
				m_n = m_n < group_sum ? m_n : group_sum;
				group_sum = arr[i];
				group_cnt++;
			}
		}

		if (group_sum < mid)
			group_cnt--;
		else 
			m_n = m_n < group_sum ? m_n : group_sum;

		if (group_cnt < K ) {
			right = mid - 1;
		}
		else {
			if (group_cnt == K) {
				res = m_n;
			}
			left = mid + 1;
		}

	}

	cout << res;

	return 0;
}