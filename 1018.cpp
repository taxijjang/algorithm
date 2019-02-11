#include <iostream>
#include <string>

using namespace std;

char chess1[8][8];
char chess2[8][8];
char arr[51][51];

int Min(int a, int b) {
	return a < b ? a : b;
}
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j];
		}
	}

	bool W_B = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (W_B == false) {
				chess1[i][j] = 'W';
				chess2[i][j] = 'B';
				W_B = !W_B;
			}
			else {
				chess1[i][j] = 'B';
				chess2[i][j] = 'W';
				W_B = !W_B;
			}
		}
		W_B = !W_B;
	}

	int min = 55;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int cnt1 = 0, cnt2 = 0;
			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					if (arr[i+a][j+b] != chess1[a][b]) {
						++cnt1;
					}
					if (arr[i+a][j+b] != chess2[a][b]) {
						++cnt2;
					}
				}
			}
			min = Min(min, Min(cnt1, cnt2));
		}

	}

	printf("%d", min);
	getchar();
}