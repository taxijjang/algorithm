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
void _union(ll a, ll b) {
   ll aRoot = _find(parrent[a]);
   ll bRoot = _find(parrent[b]);

   if (aRoot == bRoot)
      return;

   parrent[b] = aRoot;
}
vector<long long> solution(long long k, vector<long long> room_number) {
   vector<long long> answer;

   for (ll room : room_number) {
      ll next = _find(room);
      answer.push_back(next);
      parrent[next] = _find(next + 1);
      /*if (parrent[room] == 0) {
         answer.push_back(room);
         ll next = _find(room+1);
         parrent[room] = next;
      }
      else if (parrent[room] != 0) {
         ll next = _find(room);
         answer.push_back(next);
         ll nnext = _find(next + 1);
         parrent[next] = nnext;
      }*/
   }
   return answer;
}