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

#define SIZE 100100
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

map<int, map<string,int>> _map;
map<string,bool> visited;
vector<int> solution(string s) {
   int comma_cnt = 0;
   string num = "";
   map<string, int> _m;
   bool inner_comma= true;
   int inner_cnt = 0;
   for (int i = 1; i < s.size() - 1; i++) {
      if (s.at(i) == '{') {
         num = "";
         comma_cnt = 0;
         _m.clear();
         inner_comma = true;
         inner_cnt = 0;
      }
      else if (s.at(i) == '}') {
         _m[num] = true;
         _map[comma_cnt + 1] = _m;
         inner_comma = false;
      }
      else if (s.at(i) == ',') {
         if (inner_comma == true) {
            _m[num] = true;
            comma_cnt++;
            num = "";
            inner_cnt++;
         }

      }
      else {//숫자 일때
         num+= s.at(i);
      }
   }
   vector<int> answer;

   int m_size = _map.size();
   for (int i = 1; i <= m_size; i++) {
      for (auto _map : _map[i]) {
         if (visited[_map.first] == false) {
            answer.push_back(stoi(_map.first));
            visited[_map.first] = true;
         }
      }
   }
   return answer;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
   vector<int> res = solution(s);
}