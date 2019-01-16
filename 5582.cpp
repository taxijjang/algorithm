#include <iostream>
#include <string>
using namespace std;

char A[4001];
char B[4001];
int DP[4001][4001] = { 0 };

int main(void) {
	int max = 0;
	string a, b;

	scanf("%s", A);
	scanf("%s", B);

	for (int i = 0; A[i] != NULL; i++) {
		for (int j = 0; B[j] != NULL; j++) {
			if (A[i] == B[j]) {
				if (i == 0 || j == 0)
					DP[i][j] = 1;
				else
					DP[i][j] = DP[i - 1][j - 1] + 1;
				if (max < DP[i][j])
					max = DP[i][j];
			}
		}
	}
	printf("%d", max);
}