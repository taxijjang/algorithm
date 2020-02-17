#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 1010

using namespace std;

typedef long long int ll;

const int INF = 2000000000;

int res = 0;
void dfs(int left, int right, int cnt, int n) {
	if (left < right || left > n || right > n)
		return;
	if (cnt == n * 2) {
		res++;
		return;
	}
	dfs(left + 1, right, cnt + 1, n);
	dfs(left, right + 1, cnt + 1, n);
}
int solution(int n) {
	dfs(1, 0, 1, n);
	int answer = res;
	return answer;

}