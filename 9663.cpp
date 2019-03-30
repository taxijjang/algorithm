#include <iostream>
#include<cmath>

using namespace std;

int chess[16];
int N;
int cnt = 0;
bool promising(int line) {
	for (int i = 0; i < line; i++) {
		if (chess[line] == chess[i] || abs(chess[line] - chess[i]) == line - i)
			return false;
	}
	return true;
}
void check(int line) {
	if (line == N-1) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		chess[line+1] = i;
		if (promising(line+1)) {
			check(line+1);
		}
	}
}


int main(void) {
	scanf("%d", &N);
	check(-1);
	printf("%d",cnt);
}