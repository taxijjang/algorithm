#include <string>
#include <vector>
#include<iostream>

#define INF 10
using namespace std;

int solution(vector<int> stones, int k) {
   int answer = 0;

   int left = 0, right = INF, mid;
   int s_size = stones.size();
   while (left <= right) {
      mid = (left + right) / 2;
      int max_len = 0;
      bool toggle = false;
      int cnt = 0;
      for (int i = 0; i < s_size; i++) {
         if (mid >= stones[i]) {
            if (toggle)
               cnt++;
            else
               cnt = 1;
            toggle = true;
         }
         else {
            toggle = false;
         }
         max_len = max_len < cnt ? cnt : max_len;
      }

      if (max_len >= k) {
         answer = mid;
         right = mid - 1;
      }
      else {
         left = mid + 1;
      }

   }
   return answer;
}

int main(void) {
   vector<int> s; 
   s.push_back(2);
   s.push_back(4);
   s.push_back(5);
   s.push_back(3);
   s.push_back(2);
   s.push_back(1);
   s.push_back(4);
   s.push_back(2);
   s.push_back(5);
   s.push_back(1);
   cout << solution(s, 3);
}