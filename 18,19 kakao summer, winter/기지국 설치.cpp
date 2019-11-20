#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

vector<int> arr;
int solution(int n, vector<int> stations, int w){
	int s_size = stations.size();

	arr.push_back(stations[0] - w - 1);
	for (int i = 1; i < s_size; i++) {
		arr.push_back((stations[i] - w - 1) -( stations[i - 1] + w));
	}
	arr.push_back(n - (stations[s_size - 1] + w));

	int arr_size = arr.size();
	int answer=0;

	for (int i = 0; i < arr_size; i++) {
		if (arr[i] <= 0)
			continue;
		answer += (arr[i] / ((w * 2) + 1));
		answer += (arr[i] % ((w * 2) + 1)) > 0 ? 1 : 0;
	}
	return answer;
}

int main(void) {
	vector<int> s;
	s.push_back(4);
	s.push_back(11);

	cout << solution(11, s, 1);
}