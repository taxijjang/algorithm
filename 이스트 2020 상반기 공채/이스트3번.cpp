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

int solution(vector<int> &A) {
   // write your code in C++14 (g++ 6.2.0)
   int A_size = A.size();
   int res = 0;
   int error_cnt = 0;
   for (int Tree = 0; Tree <=A_size; Tree++) {
      int tree = Tree - 1;
      bool error = false;
      for (int i = 0; i < A_size; i++) {
         if (i == tree) continue;

         int left = i - 1, right = i + 1;

         if (left == tree) left--;
         if (right == tree) right++;

         if (left<0 || right >=A_size||(A[left] > A[i] && A[right] > A[i]) ||
            (A[left] < A[i] && A[right] < A[i]) ) {}
         else {
            error = true;
            error_cnt++;
            break;
         }
      }

      if (error == false) {
         if (tree == -1)
            return 0;
         res++;
      }
   }   
   return (error_cnt == A_size+1 ? -1 : res);
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   vector<int> A = {3,4,5,3,7 };
   cout << solution(A);
}