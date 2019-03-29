#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int INF = 2000;
vector<int> arr;

int main(void) {
	int N;
	scanf("%d", &N);

	arr.push_back(-INF);

	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);
		int m_num = -num;
		if (arr.back() < m_num) {
			arr.push_back(m_num);
		}
		else {
			auto it = lower_bound(arr.begin(), arr.end(), m_num);
			*it = m_num;
		}
	}
	printf("%d\n", arr.size() - 1);
}