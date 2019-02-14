#include <iostream>
#include <string>
#include <vector>
using namespace std;


int rec(int x, int y, vector<string> &B, int size) {
	int cnt = 1;
	if (x < 0 || y < 0 || y >= size) {
		return 0;
	}
	if (B[x][y] == 'X' || B[x-1][y-1] == '.' || B[x - 1][y + 1] == '.') {
		return 0;
	}
	else {
		cnt += rec(x - 2, y - 2, B, size);
		cnt += rec(x - 2, y + 2, B, size);
	}

	return cnt;
}

int solution(vector<string> &B) {
	int j_x, j_y;
	int N = B[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (B[i][j] == 'O') {
				j_x = i; j_y = j;
			}
		}
	}

	return rec(j_x, j_y, B, N);
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector <string> B;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		B.push_back(s);
	}

	printf("%d",solution(B));
	getchar();

}