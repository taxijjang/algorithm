#include<iostream>

int dfs(int N,int M, int cnt,int sum) {
	if (cnt == M)
		return sum;
	return dfs(N, M, cnt + 1, sum*N);
}
int main(void) {
	for (int t = 1; t <= 10; t++) {
		int N, M,tt; scanf("%d %d %d",&tt, &N, &M);

		printf("#%d %d",t,dfs(N, M, 0,1));
	}
}