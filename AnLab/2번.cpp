#include <string>
#include <vector>

#define SIZE 5
using namespace std;

//방향 배열
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

//방문 체크 배열
bool visited[SIZE][SIZE];

//가장 긴 값 저장
int cnt = 0;

void dfs(vector<vector<string>> board, int h_x, int h_y, int len, bool trick){
    cnt = cnt < len ? len : cnt; //큰 길이 갱신

    visited[h_x][h_y] = true;//방문 체크

    for(int i= 0; i <4 ; i++){ // 상하좌우 방문
        int n_x = h_x + dx[i];
        int n_y =h_y + dy[i];

        if (n_x <0 || n_y <0 || n_x >=SIZE || n_y >=SIZE) //범위 벗어 나는지 체크
          continue;

        if(visited[n_x][n_y] == true)//방문 했는지 확인
            continue;

        if((board[h_x][h_y] >= board[n_x][n_y]) && trick == true) //trick 를 이용한 상태에서 다음 값이 작은지 체크
            continue;

        if(board[h_x][h_y] < board[n_x][n_y]) //다음 값이 클 때
            dfs(board,n_x,n_y, len+1, trick);

        if((board[h_x][h_y] > board[n_x][n_y]) && trick == false){ //다음 값이 작지만 trick 를 이용하지 않았을 때
            trick = true;
            dfs(board,n_x,n_y, len+1, trick);
            trick = false;
        }

        visited[n_x][n_y] = false;
    }

    visited[h_x][h_y] =false;
}

//백트래킹을 이용하였습니다.
int solution(vector<vector<string>> board) {
    int answer = 0;

    for(int i =0 ; i <SIZE ; i++){
        for(int j =0 ; j <SIZE ; j++){
            dfs (board,i,j,1,false);
        }
    }

    answer = cnt;
    return answer;
}