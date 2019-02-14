#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> sum;
int main(void) {
	int N,K;
	scanf("%d %d", &N,&K);

	for (int i = 0; i < N; i++) {
		int ss;
		scanf("%d", &ss);
		arr.push_back(ss);
	}
	
	sort(arr.begin(),arr.end());
	arr.erase(unique(arr.begin(), arr.end()),arr.end());

	int start = arr[0];
	int size = arr.size();

	for (int i = 0; i < size-1; i++) {
		sum.push_back(arr[i + 1] - arr[i]);
	}

	sort(sum.begin(),sum.end());

	int s = 0;
	int sum_size = sum.size();
	for (int i = 0; i < sum_size - (K - 1); i++) {
		s += sum[i];
	}

	printf("%d", s);
	getchar();
}