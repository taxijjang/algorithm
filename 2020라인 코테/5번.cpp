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

map<string, set<string>> _map;
map<string, int> res;

struct cmp {
   bool operator()(pair<int, string> p1, pair<int, string> p2) {
      if (p1.first == p2.first)
         return p1.second > p2.second;
      return p1.first < p2.first;
   }
};
vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
   //만번 돌고
   for (auto tag : tags) {
      _map[tag].insert(" ");
   }

   //여기서 10만번 돌고
   for (auto data : dataSource) {
      int data_size = data.size();
      for (int i = 1; i < data_size; i++) {
         if (_map.find(data[i]) != _map.end()) {
            _map[data[i]].insert(data[0]);
            res[data[0]]++;
         }
      }
   }
   vector<string> answer;
   priority_queue<pair<int,string>, vector<pair<int, string>>,cmp> tmp;
   for (auto r : res) {
      tmp.push({ r.second,r.first });
   }

   while(!tmp.empty()){
      answer.push_back(tmp.top().second);
      if (answer.size() >= 10)
         break;
      tmp.pop();
   }

   return answer;
}
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   vector<vector<string>> data = {
      {"doc1", "t1", "t2", "t3"},
      {"doc2", "t0", "t2", "t3"},
      {"doc3", "t1", "t6", "t7"},
      {"doc4", "t1", "t2", "t4"},
      {"doc5", "t6", "t100", "t8"},
      { "doc6", "t6", "t100", "t8" },
      { "doc7", "t6", "t100", "t8" },
      { "doc8", "t6", "t100", "t8" },
      { "doc9", "t6", "t100", "t8" },
      { "doc10", "t6", "t100", "t8" },
      { "doc11", "t6", "t100", "t8" },
      { "doc12", "t6", "t100", "t8" },
      { "doc12", "t6", "t100", "t8" }
   };

   vector<string> tags = { "t1","t2","t3","t6" };
   vector<string> sol = solution(data, tags);

}