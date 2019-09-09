#include<iostream>
#include<vector>

using namespace std;

bool check(int a, int b, vector<int> &A) {
	return A[a] < A[b];
}
int solution(vector<int> &A) {
	int res = 1;
	int left = 0, right = 0;
	//left > right false 
	//left < right true
	int A_size = A.size();

	if (A_size == 1)
		return res;
	bool toggle = check(0, 1, A);
	for (int i = 1; i < A_size - 1; i++) {
		bool t = check(i, i + 1, A);
		res = res < right - left + 1 ? right - left + 1 : res;

		if (A[i] == A[i + 1]) {
			left = i + 1, right = i + 1;
			i++;
			if (i + 1 < A_size - 1)
				toggle = check(A[i], A[i + 1], A);
			continue;
		}

		if (t != toggle) {
			right = i + 1;
			toggle = t;
			continue;
		}
		else if (t == toggle) {
			right = i + 1;
			left = i;
		}
	}

	res = res < right - left + 1 ? right - left + 1 : res;
	return res;
}