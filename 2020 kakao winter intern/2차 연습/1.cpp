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

#define SIZE 40
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

stack<int> res;
queue<int> b_queue[SIZE];

int solution(vector<vector<int>> board, vector<int> moves) {
   int board_size = board.size();

   for (int j = 0; j < board_size; j++) {
      for (int i = 0; i < board_size; i++) {
         if(board[i][j] != 0)
            b_queue[j].push(board[i][j]);
      }
   }

   int cnt = 0;
   for (auto m: moves) {
      int move = m - 1;
      if (!b_queue[move].empty()) {
         int block = b_queue[move].front();
         b_queue[move].pop();

         if (res.empty()) {
            res.push(block);
         }
         else if(!res.empty()){
            if (res.top() == block) {
               res.pop();
               cnt++;
            }
            else if (res.top() != block) {
               res.push(block);
            }
         }
      }
   }
   
   return cnt * 2;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
   vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
   cout << solution(board, moves);
}