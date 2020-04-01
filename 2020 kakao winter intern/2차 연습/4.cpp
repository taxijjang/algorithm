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

map<ll, ll> parrent;
ll _find(ll a) {
   if (parrent[a] == 0)
      return a;
   if (parrent[a] != a) {
      return parrent[a] = _find(parrent[a]);
   }

   return parrent[a];
}

vector<long long> solution(long long k, vector<long long> room_number) {
   vector<long long> answer;

   for (ll room : room_number) {
      ll next = _find(room);
      answer.push_back(next);
      parrent[next] = _find(next + 1);
  
   }
   return answer;
}