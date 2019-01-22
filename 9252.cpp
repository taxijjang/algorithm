#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int DP[4001][4001] = { 0 };

int main(void) {
	int max = 0;

	string A, B;

	cin >> A;
	cin >> B;

	A = "0" + A;
	B = "0" + B;

	int a_size = A.size();
	int b_size = B.size();
	for (int i = 1; i<a_size; i++) {
		for (int j = 1; j < b_size; j++) {
			if (A[i] == B[j]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
				if (max < DP[i][j]) max = DP[i][j];
			}
			else {
				DP[i][j] = DP[i - 1][j] > DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1];
			}
		}
	}

	int min = 99999999;
	string word = "";

	int x = a_size - 1;
	int y = b_size - 1;
	while (x > 0 && y > 0) {
		if (DP[x][y] == DP[x][y - 1]) y--;
		else if (DP[x][y] == DP[x - 1][y]) x--;
		else {
			word = A[x] + word;
			x--; y--;
		}
	}
	cout << max << endl << word;
}