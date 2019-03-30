#include<iostream>
#include<cmath>

using namespace std;

int chess[11];
int cnt = 0;
int N;

bool promising(int line) {
	for(int i=0;i<line;i++){
		if (chess[line] == chess[i] || abs(chess[line] - chess[i]) == line - i) {
			return false;
		}
	}
	return true;
}

void check(int line) {
	if (line == N-1) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			chess[line + 1] = i;
			if (promising(line + 1)) {
				check(line + 1);
			}
		}
	}
}
int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		fill(chess, chess + 11, 0);
		cnt = 0;

		scanf("%d", &N);
		check(-1);
		printf("#%d %d\n",t, cnt);
	}
}