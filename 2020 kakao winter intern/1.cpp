#include <string>
#include <vector>
#include<stack>
#include<iostream>

using namespace std;

stack<int> _stack;

int solution(vector<vector<int>> board, vector<int> moves) {
   int answer = 0;
   int b_size = board.size();

   for (auto it = moves.begin(); it != moves.end(); it++) {
      int i = *it - 1;
      for (int j = 0; j < b_size; j++) {
         if (board[j][i] != 0) {
            if (_stack.empty() || _stack.top() != board[j][i]) 
               _stack.push(board[j][i]);
            else if (_stack.top() == board[j][i]) {
               answer+=2;
               _stack.pop();
            }
            board[j][i] = 0;
            break;
         }
      }
   }

   return answer;
}

int main(void) {
   vector<vector<int>> b;
   

   for (int i = 0; i < 5; i++) {
      vector<int> m;
      for (int j = 0; j < 5; j++) {
         int num; cin >> num;
         m.push_back(num);
      }
      b.push_back(m);
   }

   vector<int> m;
   for (int i = 0; i < 8; i++) {
      int num; cin >> num;
      m.push_back(num);
   }

   cout << solution(b, m);
   getchar();
}