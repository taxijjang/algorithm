#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;

vector<int> odd;
vector<int> even;

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);

		if (num % 2 == 0) even.push_back(num);
		else odd.push_back(num);
	}

	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());

	int e_size = even.size();
	int o_size = odd.size();
	int sum = 0;

	if (e_size == o_size) {
		sum = 0;
	}
	else if (abs(o_size- e_size) == 1) {
		sum = 0;
	}
	else if (abs(o_size - e_size) > 1) {
		if (o_size > e_size) {
			for (int i = 0; i < o_size - e_size - 1; i++) {
				sum += odd[i];
			}
		}
		else if (e_size > o_size) {
			for (int i = 0; i < e_size - o_size - 1; i++) {
				sum += even[i];
			}
		}
	}

	printf("%d", sum);
}