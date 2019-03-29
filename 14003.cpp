#include<iostream>
#include<algorithm>
#include<vector>
#include <stack>

using namespace std;
const int INF = 1999999999;
vector<int> arr;
stack<pair<int, int>> st;
stack<int> st2;
int main(void) {
	int N;
	scanf("%d", &N);

	arr.push_back(-INF);

	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);
		if (arr.back() < num) {
			arr.push_back(num);
		}
		else {
			auto it = lower_bound(arr.begin(), arr.end(), num);
			*it = num;
		}

		st.push(pair<int, int>(lower_bound(arr.begin(), arr.end(), num) - arr.begin(), num));
	}


	printf("%d\n", arr.size() - 1);

	int size = arr.size() - 1;

	while (!st.empty()) {
		if (st.top().first == size) {
			st2.push(st.top().second);
			size--;
		}
		st.pop();
	}
	while (!st2.empty()) {
		printf("%d ", st2.top());
		st2.pop();
	}
}