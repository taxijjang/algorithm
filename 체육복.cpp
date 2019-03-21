#include <iostream>
#include <vector>

using namespace std;

vector<int> lost;
vector<int> reserve;

int max(int a, int b) {
	return a > b ? a : b;
}
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	int arr[31];
	for (int i = 0; i < 31; i++) {
		arr[i] = 1;
	}
	int l_c = 0;
	int r_c = 0;
	//ÀÖ´Ù 0, ÀÒ¾î¹ö¸² 1, ¿©¹ú 2;
	for (int i = 1; i <= n; i++) {
		for (auto a : lost) {
			if (i == a) {
				arr[i]--;
			}
		}
		for (auto a : reserve) {
			if (i == a) {
				arr[i]++;
			}
		}
	}


	for (int i = 2; i < n; i++) {
		if (arr[i] >= 1) answer++;
		else if (arr[i] == 0) {
			if (arr[i - 1] >= 2) {
				arr[i]++;
				arr[i - 1]--;
				answer++;
			}
			else if(arr[i+1] >= 2){
				arr[i]++;
				arr[i + 1]--;
				answer++;
			}
		}
	}
	if (arr[1] >=1) {
		answer++;
	}
	if (arr[n] >= 1) {
		answer++;
	}
	return answer;
}
int main(void) {
	int N;
	scanf("%d", &N);

	lost.push_back(12);
	lost.push_back(13);
	lost.push_back(16);
	lost.push_back(17);
	lost.push_back(19);
	lost.push_back(20);
	lost.push_back(21);
	lost.push_back(22);

	reserve.push_back(1);
	reserve.push_back(22);
	reserve.push_back(16);
	reserve.push_back(18);
	reserve.push_back(9);
	reserve.push_back(10);


	printf("%d", solution(N, lost, reserve));

	return 0;
}