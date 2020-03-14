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

#define SIZE 60
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

//12시방향부터 11시방향까지 시계방향
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int board[SIZE][SIZE];
bool check(int x, int y) {
   //시계방향
   bool c = false;
   for (int r = 0; r < 8; r= r + 2) {
      bool tc = true;
      int d = r;
      for (int cnt = 0; cnt < 3; cnt ++) {
         if (board[x + dx[(d)%8]][y + dy[(d)%8]] != 1) {
            d++;
            tc = false;
            break;
         }
         d++;
      }
      if (tc == true)
         return true;
   }

   return false;
}
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int T; cin >> T;
   while(T--) {
      int N, M; cin >> N >> M;

      for (int i = 1; i <= N; i++) {
         for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
         }
      }

      bool c = true;
      for (int i = 1; i <= N; i++) {
         for (int j = 1; j <= M; j++) {
            if (board[i][j] == 0)
               continue;

            if (check(i,j) == false) {
               i = N;
               c = false;
               break;
            }
         }
      }

      if (c) {
         cout << "YES\n";
      }
      else {
         cout << "NO\n";
      }
   }
}
