#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	int n; scanf("%d", &n);

	vector<int> arr;
	arr.push_back(0);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		
		if (arr.back() < k)
			arr.push_back(k);
		else {
			auto index = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
			arr[index] = k;
			cnt++;
		}
	}
	printf("%d", cnt);
}