#include <iostream>
#include <string>

using namespace std;

char arr[51][51];

int x[5] = {0, -1,0,1,0 };
int y[5] = {0, 0,1,0,-1 };

int Max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= N; j++) {
			arr[i][j] = s[j - 1];
		}
	}

	int max = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int l = 0; l < 5; l++) {
				if (arr[i + x[l]][j + y[l]] != NULL) {
					char tmp = arr[i][j];
					arr[i][j] = arr[i + x[l]][j + y[l]];
					arr[i + x[l]][j + y[l]] = tmp;

					int cnt1 = 0;
					int cnt2 = 0;
					for (int x = 1; x <= N; x++) {
						char tmp1 = arr[1][1];
						char tmp2 = arr[1][1];
						for (int y = 1; y <= N; y++) {
							if (tmp1 == arr[x][y])
								max = Max(max,++cnt1);
							else {
								cnt1 = 0;
								tmp1 == arr[x][y];
							}

							if (tmp2 == arr[y][x])
								max = Max(max, ++cnt2);
							else {
								cnt2 = 0;
								tmp2 == arr[y][x];
							}
						}
					}

					tmp = arr[i][j];
					arr[i][j] = arr[i + x[l]][j + y[l]];
					arr[i + x[l]][j + y[l]] = tmp;
				}
			}
		}
	}

	printf("%d", max);
}