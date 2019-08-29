#include<iostream>
#include<vector>
#include<string>
#define SIZE 20
using namespace std;

int arr[SIZE][SIZE];

void calc(int n, int size,int index) {
	int num = n;
	for (int i = size - 1; i >= 0; i--) {
		int na = num % 2;

		
		if (na || arr[index][i])
			arr[index][i] = 1;
		else
			arr[index][i] = 0;
		num /= 2;
	}
}

vector<string> res(int N) {
	vector<string> str;

	for (int i = 0; i < N; i++) {
		string s = "";
		for (int j = 0; j < N; j++) {
			s = s + (arr[i][j] == 1 ? "#" : " ");
		}
		str.push_back(s);
	}
	return str;
}
vector<string>solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	int index = 0;
	for (auto num : arr1) {
		calc(num, n, index++);
	}
	index = 0;
	for (auto num : arr2) {
		calc(num, n, index++);
	}

	answer = res(n);
	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> arr1, arr2;
	arr1.push_back(9);
	arr1.push_back(20);
	arr1.push_back(28);
	arr1.push_back(18);
	arr1.push_back(11);

	arr2.push_back(30);
	arr2.push_back(1);
	arr2.push_back(21);
	arr2.push_back(17);
	arr2.push_back(28);
	vector<string> res = solution(n, arr1, arr2);
	

}