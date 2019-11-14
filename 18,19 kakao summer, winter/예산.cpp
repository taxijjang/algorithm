#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;

	sort(d.begin(), d.end());

	for (auto it = d.begin(); it != d.end(); it++) {
		if (*it <= budget) {
			answer++;
			budget -= *it;
		}
	}
	return answer;
}

int main(void) {
	vector<int> d;
	d.push_back(1);
	d.push_back(3);
	d.push_back(2);
	d.push_back(5);
	d.push_back(4);

	cout << solution(d, 9);
}