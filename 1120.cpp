#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string A, B;
	cin >> A >> B;

	int a_size = A.size();
	int b_size = B.size();
	int gap = b_size - a_size;
	int min = 55;

	for (int i = 0; i <= gap; i++) {
		int cnt = 0;

		for (int j = 0; j < a_size; j++) {
			if (A[j] != B[j + i]) cnt++;
		}
		min = min >= cnt ? cnt : min;
	}

	printf("%d", min);
	
}
