#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair<int, int> arr[510];

vector<int> result;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[i].first = a;
		arr[i].second = b;
	}

	sort(arr, arr+N);

	int cnt = 0;
	int left = 0;

	result.push_back(arr[0].second);
	for (auto i = 1; i < N; i++) {
		if (result.back() < arr[i].second) {
			result.push_back(arr[i].second);
		}
		else {
			auto itt = lower_bound(result.begin(), result.end(), arr[i].second);
			*itt = arr[i].second;
			cnt++;
		}
	}

	printf("%d", cnt);
	
}