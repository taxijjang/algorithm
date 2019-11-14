#include <vector>
#include <iostream>
#include<algorithm>

#define SIZE 100000
using namespace std;

bool prime[SIZE];

void eratos() {
	prime[1] = true;
	prime[0] = true;
	for (int i = 2; i < SIZE; i++) {
		for (int j = 2; i*j < SIZE; j++) {
			if (prime[i*j] != true)
				prime[i*j] = true;
		}
	}
}
int solution(vector<int> nums) {
	eratos();
	int answer = 0;

	vector<int> idl;
	int n_size = nums.size();
	idl.assign(n_size, 0);
	for (int i = n_size-3; i < n_size; i++) {
		idl[i] = 1;
	}

	do {
		int sum = 0;
		for (int i = 0; i < n_size; i++) {
			if (idl[i] == 1)
				sum += nums[i];
		}

		if (prime[sum] == false)
			answer++;
	} while (next_permutation(idl.begin(), idl.end()));

	return answer;
}

int main(void) {
	vector<int> n;
	n.push_back(1);
	n.push_back(2);
	n.push_back(7);
	n.push_back(6);
	n.push_back(4);
	cout << solution(n);
}