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

#define SIZE 100010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int prefix_A[SIZE];
int prefix_B[SIZE];
int solution(vector<int> &A, vector<int> &B) {
   // write your code in C++14 (g++ 6.2.0)
   int size = A.size();

   prefix_A[0] = A[0];
   prefix_B[0] = B[0];

   for (int i = 1; i < size; i++) {
      prefix_A[i] = prefix_A[i - 1] + A[i];
      prefix_B[i] = prefix_B[i - 1] + B[i];
   }

   int res = 0;
   for (int i = 0; i < size -1; i++) {
      set<int> _set;

      int left_A = prefix_A[i];
      int right_A = prefix_A[size - 1] - left_A;

      int left_B = prefix_B[i];
      int right_B = prefix_B[size - 1] - left_B;

      _set.insert(left_A); _set.insert(right_A);
      _set.insert(left_B); _set.insert(right_B);
      
      if (_set.size() == 1)
         res++;
   }

   return res;
}
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   //vector<int> A = { 4,-1,0,3 };
   //vector<int> B = { -2,5,0,3 };

   vector<int > A = { 3,2,6 };
   vector<int> B = { 4,1,6 };
   cout << solution(A, B);
}