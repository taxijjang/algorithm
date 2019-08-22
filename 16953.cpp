#include<iostream>
#define INF 2e9
using namespace std;

int res;
int mul(int n) {
	return n * 2;
}
int sib(int n) {
	return (n * 10) + 1;
}
void dfs(int num,int des, int cnt) {
	if (num > des)
		return;
	if (num == des) {
		res = res > cnt ? cnt : res;
		return;
	}
	
	dfs(mul(num), des, cnt + 1);
	dfs(sib(num), des, cnt + 1);
	
}
int main(void) {
	ios::sync_with_stdio(false);

	int A, B; cin >> A >> B;
	res = INF;
	dfs(A, B, 0);

	if (res == INF)
		cout << -1;
	else
		cout << res + 1;
}