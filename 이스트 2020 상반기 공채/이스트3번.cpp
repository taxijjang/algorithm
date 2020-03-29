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

   //지우고자 하는 나무를 탐색
   for (int Tree = 0; Tree <=A_size; Tree++) {
	  //아예 지우지 않고 탐색을 먼저 해야되기 때문에
	  //-1로도 시작하여 나무를 제거하지 않고 탐색 하도록함
      int tree = Tree - 1;
      bool error = false;

	  //나무를 제거하고 조건에 맞는지 탐색
      for (int i = 0; i < A_size; i++) {
         if (i == tree) continue;

         int left = i - 1, right = i + 1;

		 //탐색을 하고 있는 나무를 기준으로 왼쪽과 오른쪽이
		 //제거된 나무라면 한번더 이동 하도록 함
         if (left == tree) left--;
         if (right == tree) right++;

		 //왼쪽과 오른쪽이 나무가 있는 범위를 벗어나면 항상 조건에 만족
		 //그리고 나머지 조건
         if (left<0 || right >=A_size||(A[left] > A[i] && A[right] > A[i]) ||
            (A[left] < A[i] && A[right] < A[i]) ) {}
         else {
            error = true;
            error_cnt++;
            break;
         }
      }

	  //탐색한 나무가 모두 조건에 맞다면 경우의수 증가
      if (error == false) {
		 //나무를 제거 하지 않았는데 조건에 맞다면 바로 0 return
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