#include <string>
#include <vector>
#include<iostream>
#include<set>
#include<map>
#define SIZE 100100
using namespace std;

bool visited[SIZE];

map<int, vector<int>> _map;
vector<int> res;
vector<int> solution(string s) {
   vector<int> answer;

   int s_size = s.size();
   string num = "";
   int cnt = 0;
   bool toggle = false;

   for (int i = 0; i < s_size; i++) {
      if (s[i] >= '0' && s[i] <= '9') {
         num += s[i];
      }
      else {
         if (s[i] == '{') {
            cnt = 1;
            toggle = true;
         }
         else if (s[i] == ',' && toggle) {
            res.push_back(stoi(num));
            cnt++;
         }
         else if (s[i] == '}' && toggle) {
            res.push_back(stoi(num));
            _map[cnt] = res;
            res.clear();
            toggle = false;
         }   
         num = "";
      }
   }

   int _map_size = _map.size();

   for (int i = 1; i <= _map_size; i++) {
      int m_size = _map[i].size();

      for (int j = 0; j< m_size; j++) {
         if (visited[_map[i][j]] != true) {
            answer.push_back(_map[i][j]);
            visited[_map[i][j]] = true;
         }
      }
   }
   return answer;
}

int main(void) {
   string s; cin >> s;
   for (auto it = solution(s).begin(); it != solution(s).end(); it++) {
      cout << *it << "\n";
   }
}