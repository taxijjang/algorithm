#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int size_a = A.size();
	int size_b = B.size();

	int j = 0;
	for (int i = 0; i < size_a; i++) {
		for (; j < size_b;) {
			if (A[i] < B[j]) {
				answer++;
				j++;
				break;
			 }
			j++;
		}
	}
	return answer;
}
int main(void) {
	vector<int> A, B;
	int N;
	scanf("%d", &N);
	
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		A.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		B.push_back(num);
	}

	printf("%d", solution(A, B));
}