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
typedef struct Data {
   string what, name, cost;
}Data;

map<string, int > acc;
map<string, Data> tran;

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
   for (auto snap : snapshots) {
      acc[snap[0]] = stoi(snap[1]);
   }

   for (auto t : transactions) {
      string id = t[0];
      Data d; d.what = t[1]; d.name = t[2]; d.cost = t[3];
      if(tran.find(id) == tran.end())
         tran[id] = d;
   }

   for (auto it = tran.begin(); it != tran.end(); it++) {
      string id = it->first;
      Data d = it->second;

      if (d.what == "SAVE") {
         acc[d.name] += stoi(d.cost);
      }
      else if (d.what == "WITHDRAW") {
         acc[d.name] -= stoi(d.cost);
      }
   }
   vector<vector<string>> answer;

   for (auto ac : acc) {
      vector<string> a = { ac.first, to_string(ac.second) };
      answer.push_back(a);
   }
   return answer;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   vector<vector<string>> snapshots = { {"ACCOUNT1", "100"},{"ACCOUNT2", "150"} };
   vector<vector<string>> transaction = {
      {"1", "SAVE", "ACCOUNT2", "100"},
         {"2", "WITHDRAW", "ACCOUNT1", "50"},
         {"1", "SAVE", "ACCOUNT2", "100"},
         {"4", "SAVE", "ACCOUNT3", "500"},
         {"3", "WITHDRAW", "ACCOUNT2", "30"}
   };
   vector<vector<string>> s = solution(snapshots, transaction);
}