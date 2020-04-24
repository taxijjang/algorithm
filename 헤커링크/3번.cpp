#include <iostream>
#include <stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define SIZE 100010
#define EVEN 0
#define ODD 1
using namespace std;


int dp[SIZE][2];
int even_sum, odd_sum;

bool check(int index, vector<int> & arr, int arr_size) {
	int left_even, left_odd, right_even, right_odd;
	left_even = left_odd = right_even = right_odd = 0;

	if (index % 2 == EVEN) {
		if (index != 0) {
			left_even = dp[index - 2][EVEN];
			left_odd = dp[index - 1][ODD];
		}

		right_even = even_sum - dp[index][EVEN];

		right_odd = odd_sum - left_odd;

		
	}
	else if (index % 2 == ODD) {
		if (index != 1) {
			left_odd = dp[index - 2][ODD];
		}

		left_even = dp[index - 1][EVEN];
		right_even = even_sum - left_even;

		right_odd = odd_sum - dp[index][ODD];
		
	}

	if (left_even + right_odd == left_odd + right_even)
		return true;
	return false;
}
int countBalancingElements(vector<int> arr) {
	
	int arr_size = arr.size();

	for (int i = 0; i < arr_size; i++) {
		if (i == 0) {
			dp[i][EVEN] = arr[i];continue;
		}
		else if (i == 1) {
			dp[i][ODD] = arr[i]; continue;
		}
		
		if (i % 2 == EVEN) { // EVEN
			dp[i][EVEN] = dp[i - 2][EVEN] + arr[i];
			even_sum = dp[i][EVEN];
		}
		else if (i % 2 == ODD) { // ODD
			dp[i][ODD] = dp[i - 2][ODD] + arr[i];
			odd_sum = dp[i][ODD];
		}
	}

	int res = 0;
	for (int i = 0; i < arr_size; i++) {
		if (check(i, arr, arr_size)) {
			res++;
		}
	}
	return res;
}

int main() {
	//vector<int> arr = { 5,5,2,5,8,1,7,2,3,7,6,3 };
	//vector<int> arr = { 5,5,2,5,8 };
	vector<int> arr = { 8,5,2,5,5 };
	cout << countBalancingElements(arr);
}