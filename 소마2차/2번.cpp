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

#define SIZE 300010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

typedef struct Data {
   ll x, y;
}Data;

typedef struct Rec {
   //시계방향으로
   ll left_x=100000000, right_x=1;
   ll down_y = 100000000, up_y = 1;
};
vector<Data> loc;
vector<int> man[SIZE];

bool visited[SIZE];

Rec r;

void check(Data d) {
   if (d.x < r.left_x)
      r.left_x = d.x;
   if (d.x > r.right_x)
      r.right_x = d.x;
   if (d.y < r.down_y)
      r.down_y = d.y;
   if (d.y > r.up_y)
      r.up_y = d.y;
}

ll calc(Rec l) {
   ll garo = (l.right_x - l.left_x) * 2;
   ll sero = (l.up_y - l.down_y) * 2;

   return garo + sero;
}
void dfs(int here) {
   check(loc[here]);
   visited[here] = true;
   for (auto next : man[here]) {
      if (visited[next] == true)
         continue;

      dfs(next);
   }
}
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int N, M; cin >> N >> M;

   for (int i = 0; i < N; i++) {
      Data l; cin >> l.x >> l.y;
      loc.push_back(l);
   }
   for (int j = 0; j < M; j++) {
      int a, b; cin >> a >> b;
      man[a-1].push_back(b-1);
      man[b-1].push_back(a-1);
   }

   ll res = 0;
   for (int i = 0; i < N; i++) {
      if (visited[i] != true) {
         Rec tmp; r = tmp;
         dfs(i);
         res = max(res, calc(r));
      }
   }

   cout << res;

}