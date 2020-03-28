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

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
int solution(vector<int> stones, int k) {
   int left = 1, right = 200000000, mid;

   while (left <= right) {
      mid = (left + right) / 2;
      vector<int> tmp(stones.begin(),stones.end());
      for (int i = 0; i < stones.size(); i++) {
         tmp[i] -= mid;
      }
      
      int cnt = 0;
      bool check = false;
      for (int i = 0; i < tmp.size(); i++) {
         if (tmp[i] <= 0)
            cnt++;
         else {
            cnt = 0;
         }

         if (cnt >= k) {
            check = true;
            break;
         }
      }

      if (check == true) {
         right = mid - 1;
      }
      else
         left = mid + 1;

   }
   return left;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   vector<int> stones = { 2,4,5,3,2,1,4,2,5,1 };
   int k = 3;
   cout << solution(stones, k);

}