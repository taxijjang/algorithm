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

int solution(int N) {
   // write your code in C++14 (g++ 6.2.0)
   string num = to_string(N);

   string res = "";
   bool check = false;

   if (N >= 0) {
      for (auto n : num) {
         if (n >= '5' || check) {
            res = res + n;
         }
         else if(n < '5'){
            res = res + "5";
            res = res + n;
            check = true;
         }
      }
   }
   else {
      for (auto n : num) {
         if (n == '-') {
            res = res + '-';
            continue;
         }
         if (n <= '5' || check) {
            res = res + n;
         }
         else if (n > '5') {
            res = res + "5";
            res = res + n;
            check = true;
         }
      }
   }

   if (check == false)
      res += '5';
   
   return stoi(res);
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int N; cin >> N;
   cout << solution(N);

}