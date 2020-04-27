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
typedef pair<int, int> pii;

int solution(vector<int> &A) {
   // write your code in C++14 (g++ 6.2.0)

   int A_size = A.size();

   int res = 0;
   //Â¦¼ö ÀÎµ¦½º 1 È¦¼ö ÀÎµ¦½º 0
   //Â¦¼ö ÀÎµ¦½º 0 È¦¼ö ÀÎµ¦½º 1

   int even = 0;
   int odd = 0;

   for (int i = 0; i < A_size; i++) {
      if (i % 2 == 0) {
         if (A[i] == 0)
            even++;
         if (A[i] == 1)
            odd++;
      }

      else if (i % 2 == 1) {
         if (A[i] == 1)
            even++;
         if (A[i] == 0)
            odd++;
      }
   }

   res = min(even, odd);
   return res;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   vector<int > A = { 0,0,1 };

   cout << solution(A);

}