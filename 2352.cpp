#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;
vector<int> res;

const int INF = 9999999;
int main(void) {
	int N;
	scanf("%d", &N);

	res.push_back(INF);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		arr.push_back(num);
	}

	for (auto it = arr.begin(); it != arr.end(); it++) {
		if (res.back() < *it) {
			res.push_back(*it);
		}
		else {
			auto itt = lower_bound(res.begin(), res.end(), *it);
			*itt = *it;
		}
	}

	getchar();
	printf("%d", res.size() - 1);
	
}