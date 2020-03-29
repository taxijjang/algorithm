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

map<int, int> _map;
int solution(vector<int> &A) {
   // write your code in C++14 (g++ 6.2.0)
   for (auto a : A) {
      _map[a]++;
   }

   for (auto it = _map.rbegin(); it != _map.rend(); it++) {
      if (it->first == it->second)
         return it->first;
   }

   return 0;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   vector<int> A = {5,5,5,5,5};
   cout << solution(A);
}