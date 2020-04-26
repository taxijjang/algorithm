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

#define SIZE 101000
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int arr[SIZE];
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int N; cin >> N;

   
   for (int i = 0; i < N; i++) {
      cin >> arr[i];
   }

   if (N == 1) {
      cout << arr[0];
      return 0;
   }

   int res = arr[0];
   int tmp = arr[0];


   for (int i = 1; i < N; i++) {   
      if (tmp < 0) {
         if (arr[i] < 0) {
            if (tmp < arr[i])
               tmp = arr[i];
         }
         else if (arr[i] >= 0) {
            tmp = arr[i];
         }
      }
      else if (tmp >= 0) {
         if (arr[i] < 0) {
            if (tmp + arr[i] >= 0) {
               tmp += arr[i];
            }
            else if (tmp + arr[i] < 0) {
               tmp = arr[i];
            }
         }
         else if (arr[i] >= 0) {
            tmp += arr[i];
         }
      }
      res = max(res, tmp);
   }
   cout << res;
}