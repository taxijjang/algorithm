#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int INF = 1999999999;
vector<int> arr;

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
	}
	printf("%d\n", arr.size() - 1);
}