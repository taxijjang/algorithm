#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>
#include<stack>

#define SIZE 3000
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int arr[SIZE];
int N, K;
int res = INF;
void dfs(int left, int right, int cnt, int calc ,int sum) {
   if (left > N || right > N)
      return;
   if (N == right + K - cnt) {
      if(cnt < K)
         res = res < sum + arr[right] - arr[left] ? res : sum + arr[right] - arr[left];
      else {
         res = res < sum + arr[N] - arr[left] ? res : sum + arr[N] - arr[left];
      }
      return;
   }
   //오른쪽으로 한칸 증가
   dfs(left, right+1, cnt, arr[right+1] - arr[left], sum);

   //오른쪽 증가 하지 않고 계산 하고 cnt 증가
   dfs(right +1, right+ 1, cnt+1, calc, sum + arr[right]- arr[left]);

}
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

   for (int i = 1; i <= N; i++) {
      cin >> arr[i];
   }

   for (int i = 1; i <= N - K + 1; i++) {
      dfs(1, i, 1, 0,arr[i] - arr[1]);
   }

   cout << res;
}